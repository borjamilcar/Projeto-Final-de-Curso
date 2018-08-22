#ifndef GETDATA_H
#define GETDATA_H

/**
 *  GetData
 *  GetData.cpp
 *  Objetivo:
 *  (1) Ler o conteúdo de um ficheiro separar cada caracter único e inserir num array - char _data[]
 *  (2) Calcular a frequência de cada caracter único e inserir num array - unsigned _freq[]
 *
 *  @author Amílcar Borja
 *  @version 1.0 19/07/2018
 */

class GetData
{
    public:
        GetData();
        virtual ~GetData();

        /***/
        char* getFileContent();

        /**
         *  Retorna um conjunto de caracter único retirados do ficheiro
         *
         *  @param O index
         *  @return Array de caracteres únicos
         */
        char* getData();

        /**
         *  Retorna a frequência de cada caracter único retirados do ficheiro
         *
         *  @param O index
         *  @return Array de frequência dos caracteres únicos
         */
        unsigned* getFreq();

        /**
         *  Retorna o número de caracteres únicos que foram retirados do ficheiro
         *
         *  @return Número de caracteres únicos
         */
        unsigned getSize();

        /**
         *  Leitura dos caracteres do ficheiro
         *  Inserção dos caracteres únicos num array de dados
         *  Cálculo da frequência de cada caracter único
         *
         *  @param Caminho/Nome do ficheiro
         */
        void begin(char *file_name);

    protected:

    private:

        /**
         *  Retorna todos os caracteres da leitura do ficheiro
         *
         *  @param Caminho do ficheiro
         *  @return Todos os caracteres do ficheiro
         */
        char* readFile(char* file_name);

        /**
         *  Isola cada caracter único e insere no array de dados
         *  Calcula a frequência de cada caracter único
         *
         *  @param Todos os caracteres do ficheiro
         */
        void createArrayDataAndFreq();

        /**
         *  Retorna a frequência com um caracter se repete num ficheiro
         *
         *  @param O caracter único
         *  @param O conteúdo do ficheiro
         *  @return Frequência do caracter único
         */
        unsigned calcDataFreq(char c, char* file_content);

        /**
         *  Retorna true se o caracter já foi inserido no array de dados - char _data
         *  Retorna false se o caracter ainda não foi inserido
         *
         *  @param O caracter a verificar
         *  @return False - caracter não inserido
         *  @return True - caracter inserido
         */
        bool isDataAlreadySet(char c);

        char* _file_content;
        char _data[60];        // conjunto de caracteres únicos
        unsigned _freq[60];    // frequência de cada caracteres
        unsigned _size;     // número de caracteres únicos
};

#endif // GETDATA_H
