#include "../include/menu.h"

int main(int argc, char **argv)
{
  //estrutura alocada de um array de pokemons
  tPokemon *pokesBase = inicializaPokesBase();

  //especificações do histórico
  tTam *tamanho=inicializaTam();

  //estrutura do historico
  tHistorico *hist=inicializaHistorico(tamanho);
  
  //jogador da partida
  tUsuario *jogador = NULL;

  int *numPartidas = (int *)calloc(1,sizeof(int));

  //arquivo de pontuações
  FILE *arqPont = fopen(argv[1], "w");
  if(arqPont==NULL)
  {
    printf("Erro na abertura do arquivo Log de Pontuações\n");
    exit(1);
  }

  //arquivo de batalha
  FILE *arqLog = fopen(argv[2], "w");
  if(arqLog==NULL)
  {
    printf("Erro na abertura do arquivo Log de Batalhas\n");
    exit(1);
  }

  //semente
  int semente=atoi(argv[3]);
  
  char op;
 
  while(1)
  {
    op=menuPrincipal();

    switch(op)
    {
      case '1': //jogar    
      
      jogador=inicializaUsuario(pokesBase);
      hist=jogar(jogador, arqLog, numPartidas,hist,tamanho,semente); 


      //libera jogador para uma nova partida
      liberaUsuario(jogador);
      //abre o arquivo em modo append para nao perder informações e registrar próximo jogador
      fclose(arqLog);
      arqLog = fopen(argv[2], "a");
      if(arqLog==NULL)
       {
         printf("Erro na abertura do arquivo Log de Batalhas\n");
         exit(1);
       }

      break;

      case '2': //ordenação

      placar(*numPartidas, hist, tamanho);
      
      break;  
  
      case '3': //sair
    
      salvaPlacar(hist,tamanho,arqPont);
      fclose(arqPont);
      liberaTam(tamanho);
      liberaHistorico(hist);
      liberaPokesBase(pokesBase);
      fclose(arqLog);
      
      if(numPartidas!=NULL)
      {
        free(numPartidas);
      }
      return 0;
    }
  }
}