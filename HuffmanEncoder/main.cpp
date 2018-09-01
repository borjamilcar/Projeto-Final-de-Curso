#include "stdio.h"
#include "Huffman.h"
#include "MinHeap.h"
#include "GetData.h"

#include "string.h"

#define FILENAME "Tem2018-08-22-aux.txt"

int main()
{
    GetData g;
    g.begin(FILENAME);

    printf("\t====== EXECUCAO NO ARDUINO ======\n\n");
    printf("String Inicial......: %s\n", g.getFileContent());
    printf("Bytes Ocupados......: %d\n", strlen(g.getFileContent()));
    printf("------------------------------------------------------------\n");

    printf("Data:\tFreq:\n");
    for (unsigned i = 0; i < g.getSize(); i++) {
        printf("%c\t%d\n", g.getData()[i], g.getFreq()[i]);
    }
    printf("------------------------------------------------------------\n");

    Huffman h;

    h.setValue(g.getData(), g.getFreq(), g.getSize());
    h.encoder(g.getFileContent());

    h.printDictinary();
    printf("------------------------------------------------------------\n");
    h.printCEncode();
    printf("------------------------------------------------------------\n");

    printf("\n\t====== EXECUCAO NA APLICACAO WEB ======\n\n");

    h.decode();
    h.printCDedcode();
    printf("------------------------------------------------------------\n");
    h.printHexCDecode();
    printf("------------------------------------------------------------\n");
    h.hexToBynary();
    h.printHexToBinCEncode();
    printf("------------------------------------------------------------\n");

    return 0;
}
