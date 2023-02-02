//////////////////////identificar placa///////////////////////////////////////////////////////////


#include "identificar_placa.h"

//Identificar placa
//SAIDA VALOR 1 IDENTIFICOU OU 0 NAO IDENTIFICOU

int identificar_placa(std::string placas)
{
    ////////////////salvar placas/////////////////////////////
    std::ofstream arquivo;
    arquivo.open("placas.txt", std::ios::app);
    arquivo << std::endl << placas;
    arquivo.close();


    std::string gravar;
    std::ifstream arquivo_leitura;
    int aux2,retorno_p=0;
    char placa[50];
    int tam = 0, cont1, cont2, aux = 0;
    char* conteudo;
    FILE* arq;

    arquivo_leitura.open("placas_cadastradas.txt");
    for( int aux2=0; aux2<=2; aux2++)
    {

        getline(arquivo_leitura,gravar);
        strcpy(placa,gravar.c_str());

        arq = fopen("placas.txt", "r");
        fseek(arq, 0, SEEK_END);
        tam = ftell(arq);
        fseek(arq, 0, SEEK_SET);  // ou rewind(arq);
        conteudo = (char*)malloc(tam);
        fread(conteudo,sizeof(char),tam,arq);
        fclose(arq);

        for (cont1 = 0, cont2 = 0; cont1 < tam; cont1++)
        {
            if (conteudo[cont1]==placa[cont2])
            {
                cont2++;

                if (placa[cont2] == '\0')
                {
                    aux++;
                    cont2 = 0;
                }
            }
            else
                cont2 = 0;
        }
        free(conteudo);
    }

    arquivo_leitura.close();



    //////////////Limpar placas///////////////////////////////
    arquivo.open("placas.txt", std::ios::trunc);
    arquivo.close();

    ////////////CRIAR RELATORIO////////////////////////////////
    std::ofstream relatorio;
    relatorio.open("relatorio.txt", std::ios::app);
    relatorio << std::endl << placas;
    relatorio.close();




    if (aux!=0)
    {
        retorno_p++;
        std::cout << "CADASTRADA" << std::endl;
        return retorno_p;
    }
    else
    {
        std::cout << "NAO CADASTRADA" << std::endl;
        return retorno_p;
    }


}



