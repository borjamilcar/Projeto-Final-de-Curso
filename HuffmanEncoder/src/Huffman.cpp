#include "Huffman.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

Huffman::Huffman()
{
    //ctor
    _top = 0;
    _cont = 0;
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
void Huffman::print()
{
    unsigned arr[MAX_TREE_HT], top = 0;
    printDictionary(_root, arr, top);

    for (int i = 0; i < _cont; i++) {
        printf("%c: ", _data[i]);
        for (int j = 0; j < 8; j++) {
            if (_dict[i][j] == -1) break;
            printf("%d", _dict[i][j]);
        }
        printf("\n");
    }

    //printEncoderContent();
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
        printf("%d", arr[i]);
        _dict[_cont][i] = arr[i];
    }

    _dict[_cont][n] = -1;
    printf("\n");
}

//
void Huffman::printDictionary(struct MinHeapNode* root, unsigned arr[], unsigned top)
{
    if (root->left){
        arr[top] = 0;
        printDictionary(root->left, arr, top + 1);
    }

    if (root->right){
        arr[top] = 1;
        printDictionary(root->right, arr, top + 1);
    }

    if (isLeaf(root)){
        printf("%c: ", root->data);
        printArr(arr, top);
        _data[_cont] = root->data;
        //_dict[_cont] = arr;
        _cont++;
    }
}

//
void Huffman::encoder()
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
}

//
char* Huffman::decode(char* code)
{
    char* result = "";
    struct MinHeapNode* curr = _root;
    unsigned cont = 0;

    for (unsigned i = 0; i < strlen(code); i++) {
        if (code[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (isLeaf(curr)) {
            result[cont++] = curr->data;
            curr = _root;
        }
    }

    result[cont] = '\0';

    return result;
}
