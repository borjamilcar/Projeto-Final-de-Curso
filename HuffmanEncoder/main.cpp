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

    printf("%s\n", g.getFileContent());
    printf("++++++\n");
    for (unsigned i = 0; i < g.getSize(); i++) {
        printf("%c\t%d\n", g.getData()[i], g.getFreq()[i]);
    }
    printf("++++++\n");

    Huffman h;

    h.setValue(g.getData(), g.getFreq(), g.getSize());
    h.encoder();
    h.print();

    /*
    char dec[] = {'1','0','1','0','1','1','1','0','0','1','0','1','0','1','1','1','1','0','1','1','0'};
    char* decode = h.decode(dec);

    for (int i = 0; i < strlen(decode); i++)
        printf("%c", decode[i]);
    */

    return 0;
}
