#ifndef HUFFMAN_H
#define HUFFMAN_H

/**
 *  Huffman
 *  Huffman.cpp
 *  Objetivo:
 *  (1) Compress�o de dados utilizando o algoritmo Huffman
 *
 *  @author Am�lcar Borja
 *  @version 1.0 19/07/2018
 */

#include "MinHeap.h"

#define MAX_TREE_HT 100

class Huffman
{
    public:
        Huffman();
        virtual ~Huffman();

        /**
         *  Set dos valores para comprimir, das suas frequ�ncias e do n�mero de valores
         *  Chama a fun��o setValue da Min Heap para inserir estes dados na Min Heap
         *
         *  @param Valores para comprimir
         *  @param Frequ�ncia de cada valor
         *  @param N�mero de valores inseridos
         */
        void setValue(char data[], unsigned freq[], unsigned size);

        /**
         *  Imprime no ecran os valores para comprimir, as suas frequ�ncias e
         *  o c�digo, em zero e um, dos valores ap�s serem comprimidos
         */
        void print();

        /***/
        void printDictionary(struct MinHeapNode* root, unsigned arr[], unsigned top);

        /***/
        void printEncoderContent();

        /***/
        unsigned contTreeLevel(struct MinHeapNode* root);

        /***/
        void printTreeLevel(struct MinHeapNode* root, unsigned level);

        /***/
        bool isLeaf(struct MinHeapNode* root);

        /***/
        void printArr(unsigned arr[], unsigned top);

        /***/
        void encoder();

        /***/
        char* decode(char* code);

    protected:

    private:
        MinHeap _minHeap;
        MinHeapNode* _root;
        unsigned _arr[MAX_TREE_HT];
        unsigned _top;
        char _data[MAX_TREE_HT];
        signed _dict[8][8];
        unsigned _cont;
};

#endif // HUFFMAN_H
