#include "Huffman.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

Huffman::Huffman()
{
    //ctor
    _top = 0;
    _cont2dictionary = 0;
    _bits2compress = 0;
    _bytes2compress = 1;
}

Huffman::~Huffman()
{
    //dtor
    delete _root;
}

//
void Huffman::setValue(char data[], unsigned freq[], unsigned size)
{
    _minHeap.setValue(data, freq, size);
}

//
void Huffman::dictionary()
{
    unsigned arr[MAX_TREE_HT], top = 0;
    buildDictionary(_root, arr, top);

    //printEncoderContent();
}

void Huffman::printDictinary()
{
    printf("Data:\tCode:\n");
    for (int i = 0; i < _cont2dictionary; i++) {
        printf("%c\t", _data[i]);
        for (int j = 0; j < 8; j++) {
            if (_code[i][j] == -1) break;
            printf("%d", _code[i][j]);
        }
        printf("\n");
    }
}

unsigned Huffman::contTreeLevel(struct MinHeapNode* root)
{
    if (root == NULL) return 0;

    return (1 + contTreeLevel(root->left));
}

void Huffman::printTreeLevel(struct MinHeapNode* root, unsigned level)
{
    if (root != NULL && level == 0) {
        printf("%c", root->data);
    } else if (root != NULL) {
        printTreeLevel(root->left, level - 1);
        printTreeLevel(root->right, level - 1);
    }
}

//
void Huffman::printEncoderContent()
{
    unsigned n = contTreeLevel(_root);

    for (unsigned i = 0; i < n; i++)
        printTreeLevel(_root, i);
}




//
bool Huffman::isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right);
}

//
void Huffman::printArr(unsigned arr[], unsigned n)
{
    for (unsigned i = 0; i < n; i++) {
        //printf("%d", arr[i]);
        _code[_cont2dictionary][i] = arr[i];
    }

    _code[_cont2dictionary][n] = -1;
    //printf("\n");
}

//
void Huffman::buildDictionary(struct MinHeapNode* root, unsigned arr[], unsigned top)
{
    if (root->left){
        arr[top] = 0;
        buildDictionary(root->left, arr, top + 1);
    }

    if (root->right){
        arr[top] = 1;
        buildDictionary(root->right, arr, top + 1);
    }

    if (isLeaf(root)){
        //printf("%c: ", root->data);
        printArr(arr, top);
        _data[_cont2dictionary] = root->data;
        _cont2dictionary++;
    }
}

//
void Huffman::encoder(char* file_content)
{
    struct MinHeapNode *left, *right, *top;

    while (!_minHeap.isSizeOne())
    {
        left = _minHeap.extractMin();
        right = _minHeap.extractMin();

        top = _minHeap.newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        _minHeap.insertMinHeapNode(top);
    }

    _root = _minHeap.extractMin();
    dictionary();
    compress(file_content);
}

//
void Huffman::auxCompress(unsigned short idx)
{
    for (unsigned short i = 0; i < 9; i++) {
        if (_code[idx][i] == -1) break;

        _content_encode[_bits2compress++] = _code[idx][i];

        /* Cálculo do número de bytes usados na compressão */
        // sempre que o número de bits que já foram usados na compressão (_bits2compress)
        // forem maior que 1 BYTE - 1 (INICIAL); 9 (2 BYTES); 17 (3 BYTES), ETC...
        if (_bits2compress > ((_bytes2compress * NUM_BITS_IN_1BYTE) + 1)) {
            _bytes2compress += 1;
        }
    }
}

//
void Huffman::compress(char* file_content)
{
    char c;
    unsigned short i;

    /* Compressão */
    for (i = 0; i < strlen(file_content); i++) {
        c = file_content[i];

        for (unsigned short j = 0; j < _cont2dictionary; j++) {
            if (c == _data[j])  // Quando o caracter é encontrado no dicionário de caracteres
                auxCompress(j); // Set dos bits deste caracter
        }
    }

    /* Cálculo do número de bits em falta para completar 1 byte */
    // _bytes2compress - contém o número de bytes que devem ser usados nesta compressão
    // _bits2compress - contém o número de bits que já foram usados na compressão
    // 1 BYTE = 8 BITS
    // ---------------
    // _bytes2compress * 8 - indique o número de bits que contém que devem ser usados nesta compressão
    // subtrair esse valor por _bits2compress - ficamos a saber o número de bits que faltam
    _final_idx = (_bytes2compress * NUM_BITS_IN_1BYTE) - _bits2compress;

    /* Completar a compressão com os bits em falta */
    for (unsigned short i = 0; i < _final_idx; i++)
        _content_encode[_bits2compress++] = 0;

    // break da compressão
    _content_encode[_bits2compress] = COMPRESS_BREAK;
}

//
void Huffman::printCEncode()
{
    printf("String Encode....: ");
    for (unsigned short i = 0; i < MAX_TREE_HT; i++) {
        if (_content_encode[i] == COMPRESS_BREAK) break;
        printf("%d", _content_encode[i]);
    }

    printf("\nBytes Ocupados...: %d\n", _bytes2compress);
    printf("Bits Adicionados.: %d x 0 a direita\n", _final_idx);
}

//
void Huffman::printCDedcode()
{
    printf("String Decode....: %s\n", _content_decode);
}

//
void Huffman::decode()
{
    struct MinHeapNode* curr = _root;
    unsigned cont = 0;

    for (unsigned i = 0; i < (_bytes2compress * NUM_BITS_IN_1BYTE) - _final_idx; i++) {
        if (_content_encode[i] == 0)
            curr = curr->left;
        else
            curr = curr->right;

        if (isLeaf(curr)) {
            _content_decode[cont++] = curr->data;
            curr = _root;
        }
    }

    _content_decode[cont] = '\0';
}
