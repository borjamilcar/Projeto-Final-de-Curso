#include "stdio.h"
#include "Huffman.h"
#include "MinHeap.h"
#include "GetData.h"

#include "string.h"

#define FILENAME "teste2.txt"

int main()
{
    GetData g;
    g.begin(FILENAME);

    printf("------------------------------\n");
    printf("String Inicial...: %s\n", g.getFileContent());
    printf("------------------------------\n");

    printf("Data:\tFreq:\n");
    for (unsigned i = 0; i < g.getSize(); i++) {
        printf("%c\t%d\n", g.getData()[i], g.getFreq()[i]);
    }
    printf("------------------------------\n");

    Huffman h;

    h.setValue(g.getData(), g.getFreq(), g.getSize());
    h.encoder(g.getFileContent());

    h.printDictinary();
    printf("------------------------------\n");
    h.printCEncode();
    printf("------------------------------\n");

    h.decode();
    h.printCDedcode();
    printf("------------------------------\n");

    return 0;
}
