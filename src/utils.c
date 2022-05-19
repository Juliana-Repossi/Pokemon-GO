#include "../include/utils.h"

int filtraInteiroPositivo()
{
  int valido = 1, tam = 0, resultado = 0;
  char string[128] = {0};
  do
  {
    fgets(string, 128, stdin);
    //removendo \n
    string[strlen(string) - 1] = 0;

    tam = strlen(string);
    valido = 1;
    //verificando se algum caractere nao e numero
    for(int i = 0; i < tam; i++)
    {
      if(string[i] < '0' || string[i] > '9')
      {
        valido = 0;
        printf("Digite uma entrada válida!\n");
        break;
      }
    }
  }while(valido != 1);

  //transformando em inteiro
  int j = 0;
  for(int i = tam - 1; i >= 0; i--)
  {
    resultado += (string[j] - '0') * pow(10, i);
    j++; 
  }

  return resultado;
}

