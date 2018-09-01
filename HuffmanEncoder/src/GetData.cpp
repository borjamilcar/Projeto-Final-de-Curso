#include "GetData.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"


GetData::GetData()
{
    //ctor
}

GetData::~GetData()
{
    //dtor

}

//
char* GetData::getFileContent()
{
    return _file_content;
}

//
char* GetData::getData()
{
    return _data;
}

//
unsigned* GetData::getFreq()
{
    return _freq;
}

//
unsigned GetData::getSize()
{
    return _size;
}

//
void GetData::begin(char *file_name)
{
    _file_content = readFile(file_name);
    createArrayDataAndFreq();
}

//
char* GetData::readFile(char* file_name)
{
    FILE* file;
    char c;
    char* str;
    size_t index = 0;

    if ((file = fopen(file_name, "r")) == NULL)
        return NULL;

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    str = (char*)malloc(file_size);

    while ((c = fgetc(file)) != EOF) {
        //if (c != '\n')
        str[index++] = c;
    }

    str[index] = '\0';

    return str;
}

//
void GetData::createArrayDataAndFreq()
{
    for (unsigned i = 0; i < strlen(_file_content); i++)
    {
        if (i == 0) {
            _size = i + 1;
            _data[_size - 1] = _file_content[i];
            _freq[_size - 1] = calcDataFreq(_file_content[i], _file_content);
        } else if(i > 0 && !isDataAlreadySet(_file_content[i])) {
            _size++;
            _data[_size - 1] = _file_content[i];
            _freq[_size - 1] = calcDataFreq(_file_content[i], _file_content);
        }
    }
}

//
bool GetData::isDataAlreadySet(char c)
{
    for (unsigned i = 0; i < strlen(_data); i++) {
        if (c == _data[i]){
            return true;
        }
    }

    return false;
}

//
unsigned GetData::calcDataFreq(char c, char* file_content)
{
    unsigned cont = 0;

    for (unsigned i = 0; i < strlen(file_content); i++) {
        if (c == file_content[i])
            cont++;
    }

    return cont;
}
