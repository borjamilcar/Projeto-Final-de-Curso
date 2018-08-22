#ifndef MINHEAP_H
#define MINHEAP_H

/**
 *  MinHeap
 *  MinHeap.cpp
 *  Objetivo:
 *  (1) Criar uma Priority Queue para implementar Min Heap
 *
 *  @author Am�lcar Norja
 *  @version 1.0 19/07/2018
 */


/**
 *  N� da Min Heap
 *  Cont�m:
 *  (1) dado
 *  (2) frequ�ncia do dado
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
         *  Retorna o atual n�mero de N�s inseridos na Min Heap
         *
         *  @return O atual n�mero de N�s
         */
        unsigned getSize();

        /**
         *  Retorna o n�mero m�ximo de N�s que podem ser inseridos na Min Heap
         *
         *  @return A capacidade da Min Heap
         */
        unsigned getCapacity();

        /**
         *  Retorna o N� de index "idx" da Min Heap
         *
         *  @param Index do N�
         *  @return N� com o index "idx"
         */
        struct MinHeapNode* getArr(unsigned idx);

        /**
         *  Set dos valores para comprimir, das suas frequ�ncias e do n�mero de valores
         *
         *  @param Valores para comprimir
         *  @param Frequ�ncia de cada valor
         *  @param N�mero de valores inseridos
         */
        void setValue(char data[], unsigned freq[], unsigned size);

        /**
         *  Imprime no ecran os valores para comprimir, as suas frequ�ncias
         */
        void print();

        /**
         *  Cria um novo N� para a Min Heap
         *
         *  @param Um caracter �nico
         *  @param Frequ�ncia deste caracter
         *  @return Um novo N�
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
        unsigned _capacity;         // capacidade m�xima da Min Heap
        struct MinHeapNode **_arr;  // Min Heap - �rvore/array de n�s
};

#endif // MINHEAP_H
