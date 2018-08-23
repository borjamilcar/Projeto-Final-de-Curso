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

#define MAX_TREE_HT 25
#define NUM_BITS_IN_1BYTE 8
#define COMPRESS_BREAK -1

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
        void dictionary();

        void printDictinary();

        /***/
        void buildDictionary(struct MinHeapNode* root, unsigned arr[], unsigned top);

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
        void encoder(char* file_content);

        /***/
        void compress(char* file_content);

        /***/
        void auxCompress(unsigned short idx);

        void printCEncode();

        /***/
        void decode();

        /***/
        void printCDedcode();
    protected:

    private:
        MinHeap _minHeap;
        MinHeapNode* _root;
        unsigned _arr[MAX_TREE_HT];
        unsigned _top;
        char _data[MAX_TREE_HT];
        signed _code[9][9];
        signed _content_encode[MAX_TREE_HT];
        char _content_decode[MAX_TREE_HT];
        unsigned short _cont2dictionary;
        unsigned short _bits2compress;
        unsigned short _bytes2compress;
        unsigned short _final_idx;

};

#endif // HUFFMAN_H
