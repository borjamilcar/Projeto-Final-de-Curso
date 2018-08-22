#ifndef MINHEAP_H
#define MINHEAP_H

/**
 *  MinHeap
 *  MinHeap.cpp
 *  Objetivo:
 *  (1) Criar uma Priority Queue para implementar Min Heap
 *
 *  @author Amílcar Norja
 *  @version 1.0 19/07/2018
 */


/**
 *  Nó da Min Heap
 *  Contém:
 *  (1) dado
 *  (2) frequência do dado
 *  (3) apontadores para o filho da esquerda e direita
 */
struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
};

class MinHeap
{
    public:
        MinHeap();
        virtual ~MinHeap();

        /**
         *  Retorna o atual número de Nós inseridos na Min Heap
         *
         *  @return O atual número de Nós
         */
        unsigned getSize();

        /**
         *  Retorna o número máximo de Nós que podem ser inseridos na Min Heap
         *
         *  @return A capacidade da Min Heap
         */
        unsigned getCapacity();

        /**
         *  Retorna o Nó de index "idx" da Min Heap
         *
         *  @param Index do Nó
         *  @return Nó com o index "idx"
         */
        struct MinHeapNode* getArr(unsigned idx);

        /**
         *  Set dos valores para comprimir, das suas frequências e do número de valores
         *
         *  @param Valores para comprimir
         *  @param Frequência de cada valor
         *  @param Número de valores inseridos
         */
        void setValue(char data[], unsigned freq[], unsigned size);

        /**
         *  Imprime no ecran os valores para comprimir, as suas frequências
         */
        void print();

        /**
         *  Cria um novo Nó para a Min Heap
         *
         *  @param Um caracter único
         *  @param Frequência deste caracter
         *  @return Um novo Nó
         */
        struct MinHeapNode* newNode(char data, unsigned freq);

        /***/
        void buildMinHeap();

        /***/
        void minHeapify(unsigned idx);

        /***/
        void swapMinHeapNode(unsigned idxA, unsigned idxB);

        /***/
        bool isSizeOne();

        /***/
        struct MinHeapNode* extractMin();

        /***/
        void insertMinHeapNode(struct MinHeapNode* node);

    protected:

    private:
        unsigned _size;             // tamanho atual da Min Heap
        unsigned _capacity;         // capacidade máxima da Min Heap
        struct MinHeapNode **_arr;  // Min Heap - árvore/array de nós
};

#endif // MINHEAP_H
