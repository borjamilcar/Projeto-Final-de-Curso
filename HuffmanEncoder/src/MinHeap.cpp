#include "MinHeap.h"
#include "stdlib.h"
#include "stdio.h"

MinHeap::MinHeap()
{
    //ctor
}

MinHeap::~MinHeap()
{
    //dtor
    //delete _arr;
}

//
unsigned MinHeap::getCapacity()
{
    return _capacity;
}

//
unsigned MinHeap::getSize()
{
    return _size;
}

//
struct MinHeapNode* MinHeap::getArr(unsigned idx)
{
    return _arr[idx];
};

//
struct MinHeapNode* MinHeap::newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;

    return temp;
};

//
void MinHeap::setValue(char data[], unsigned freq[], unsigned capacity)
{
    // Set das variáveis locais
    _size = 0;
    _capacity = capacity;
    _arr = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));

    // Preencher o array "_arr"
    for (unsigned i = 0; i < capacity; i++) {
        _arr[i] = newNode(data[i], freq[i]);
        _size++;
    }

    buildMinHeap();
}

//
void MinHeap::print()
{
    printf("Data\tFreq\n");
    for (unsigned i = 0; i < _capacity; i++) {
        printf("%c\t%d\n", _arr[i]->data, _arr[i]->freq);
    }
}

//
void MinHeap::buildMinHeap()
{
    unsigned n = _size - 1;

    for (int i = (n - 1) / 2; i >= 0; i--)
        minHeapify(i);
}

//
void MinHeap::minHeapify(unsigned idx)
{
    unsigned smallest = idx;
    unsigned left = 2 * idx + 1;
    unsigned right = 2 * idx + 2;

    if (left < _size && _arr[left]->freq < _arr[smallest]->freq)
        smallest = left;

    if (right < _size && _arr[right]->freq < _arr[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(smallest, idx);
        minHeapify(smallest);
    }
}

//
void MinHeap::swapMinHeapNode(unsigned idxA, unsigned idxB)
{
    struct MinHeapNode* aux = _arr[idxA];

    _arr[idxA] = _arr[idxB];
    _arr[idxB] = aux;
}

//
bool MinHeap::isSizeOne()
{
    return (_size == 1);
}

//
struct MinHeapNode* MinHeap::extractMin()
{
    struct MinHeapNode* m = _arr[0];
    _arr[0] = _arr[_size - 1];
    --_size;

    minHeapify(0);

    return m;
};

//
void MinHeap::insertMinHeapNode(struct MinHeapNode* node)
{
    ++_size;
    unsigned i = _size - 1;

    while (i && node->freq < _arr[(i-1)/2]->freq) {
        _arr[i] = _arr[(i-1)/2];
        i = (i-1)/2;
    }

    _arr[i] = node;
}
