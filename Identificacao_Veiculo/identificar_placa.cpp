//////////////////////identificar placa///////////////////////////////////////////////////////////


#include "identificar_placa.h"
using namespace std;

//Identificar placa
//SAIDA VALOR 1 IDENTIFICOU OU 0 NAO IDENTIFICOU

int ID(char *palavra)
{

    char *conteudo;
    //palavra=placa;
    int tam, contagem = 0, i1, i2;

    FILE* fp = fopen("placas_cadastradas.txt", "r");

    fseek(fp, 0, SEEK_END);
    tam = ftell(fp);
    rewind(fp);
    conteudo = (char*) malloc(tam);
    fread(conteudo, sizeof(char), tam, fp);
    fclose(fp);


    for(i1=0, i2=0; i1<tam; i1++)
    {
        if(conteudo[i1]==palavra[i2])
        {
            i2++;
            if(palavra[i2]=='\0')
            {
                contagem++;
                i2=0;
            }
        }
        else
            i2=0;
    }

    //printf("'%s' ocorre %d vezes no arquivo .\n",palavra, contagem);
    free(conteudo);


    if(contagem!=0)
    {
        //printf("1\n\n");
        return 1;
    }
    else
    {   //printf("0\n\n");
        return 0;
    }

}




