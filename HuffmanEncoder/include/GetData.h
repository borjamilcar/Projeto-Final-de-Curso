#ifndef GETDATA_H
#define GETDATA_H

/**
 *  GetData
 *  GetData.cpp
 *  Objetivo:
 *  (1) Ler o conte�do de um ficheiro separar cada caracter �nico e inserir num array - char _data[]
 *  (2) Calcular a frequ�ncia de cada caracter �nico e inserir num array - unsigned _freq[]
 *
 *  @author Am�lcar Borja
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
         *  Retorna um conjunto de caracter �nico retirados do ficheiro
         *
         *  @param O index
         *  @return Array de caracteres �nicos
         */
        char* getData();

        /**
         *  Retorna a frequ�ncia de cada caracter �nico retirados do ficheiro
         *
         *  @param O index
         *  @return Array de frequ�ncia dos caracteres �nicos
         */
        unsigned* getFreq();

        /**
         *  Retorna o n�mero de caracteres �nicos que foram retirados do ficheiro
         *
         *  @return N�mero de caracteres �nicos
         */
        unsigned getSize();

        /**
         *  Leitura dos caracteres do ficheiro
         *  Inser��o dos caracteres �nicos num array de dados
         *  C�lculo da frequ�ncia de cada caracter �nico
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
         *  Isola cada caracter �nico e insere no array de dados
         *  Calcula a frequ�ncia de cada caracter �nico
         *
         *  @param Todos os caracteres do ficheiro
         */
        void createArrayDataAndFreq();

        /**
         *  Retorna a frequ�ncia com um caracter se repete num ficheiro
         *
         *  @param O caracter �nico
         *  @param O conte�do do ficheiro
         *  @return Frequ�ncia do caracter �nico
         */
        unsigned calcDataFreq(char c, char* file_content);

        /**
         *  Retorna true se o caracter j� foi inserido no array de dados - char _data
         *  Retorna false se o caracter ainda n�o foi inserido
         *
         *  @param O caracter a verificar
         *  @return False - caracter n�o inserido
         *  @return True - caracter inserido
         */
        bool isDataAlreadySet(char c);

        char* _file_content;
        char _data[60];        // conjunto de caracteres �nicos
        unsigned _freq[60];    // frequ�ncia de cada caracteres
        unsigned _size;     // n�mero de caracteres �nicos
};

#endif // GETDATA_H
