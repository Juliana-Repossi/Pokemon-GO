#include "../include/menu.h"


char validaOp1()
{
  char string[128];
  char ch;
  while(1)
  {
    int i=0;
    scanf("%c",&ch);
    while(ch!='\n')
    {
     string[i]=ch;
     scanf("%c",&ch);
     i++;
    }
    string[i]='\0';

    
    if(i==1 && (string[0]=='1' || string[0]=='2' || string[0]=='3'))
      {
        break;
      }
      
    printf("Digite uma opção válida\n");
  }  
  return string[0];
}

char menuPrincipal()
{
  printf("1-Jogar\n");
  printf("2-Melhores Pontuações\n");
  printf("3-Sair\n");
  //retornar opção válida  
  return validaOp1();
}