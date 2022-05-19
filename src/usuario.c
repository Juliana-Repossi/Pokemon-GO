#include "../include/usuario.h"

#define TAM 10
#define CTE_AUMENTO 15

struct tusuario
{
    //guarda o nome do jogador
    char nome[128];
    //guarda o endereço do ultimo poke alocado
    tListapoke *pokemons;
    //guarda o endereço do poke da vez 
    tListapoke *PokenaJogada;
    //numero de pokemons que o usuario tem
    int numPokes;
    //numero de pokeblas
    int numBolas;
    //numero de batalhas/rodadas ganhas
    int rodadas;
    //posição no placar
    int placar;
    //para calcular a probabilidade de ganhar PB (batalhas vencidas desde a ultima pokebola)
    int BatVencPB;
    //para calcular a probabilidade do Mew (batalhas vencidas desde o ultimo mew)
    int BatVencMew;
    //Para o numumero de batalhas vencidas
    int vitoria;
    
};

struct thistorico
{
  char nome[128]; //nome do jogador
  int rodadas; //quantiadade de rodadas ganhas
  int copiado; // auxiliar para a ordenação
};

struct ttam
{
  int total; //capacidade total do array liberaHistorico
  int usado; //capacidade usada do array historico
};


void validaNome(tUsuario *j)
{  
  char nome[128];
  int tam=0;

  while(1)
  {
    scanf("%[^\n]",nome);
    getchar();
    tam=strlen(nome);
    int ok=0;

    for(int i=0;i<tam;i++)
    {
      if((nome[i]>64 && nome[i]>91)||(nome[i]>96 && nome[i]>123)||(nome[i]==95))
      {
        ok++;
      }
    }

    if(ok==tam)
    {
      for(int k=0;k<tam;k++)
      {
      j->nome[k]=nome[k];
      }
      j->nome[tam]='\0';
      break;
    }
    else
    {
      printf("Digite um nome válido!\n");
    }
  }
}

tUsuario *inicializaUsuario(tPokemon *pokesBase)
{
  tUsuario *j=(tUsuario *)malloc(sizeof(tUsuario));
  printf("Qual seu nome?\n");
  validaNome(j);
  system("clear");
  
  //inicializa lista de pokemons escolhidos
  j->pokemons=selecionaPokemons(pokesBase,j->PokenaJogada,&j->numPokes, &j->numBolas); 

  j->placar=0;
  j->PokenaJogada=NULL;
  j->rodadas=0;
  j->BatVencPB=0;
  j->BatVencMew=0;
  j->vitoria=0;

  return j;     
}


tTam *inicializaTam()
{
  tTam *tamanho=(tTam*)malloc(sizeof(tTam));
  tamanho->total=0;
  tamanho->usado=0;
  return tamanho;
}

tHistorico *inicializaHistorico(tTam *tamanho)
{
  tHistorico *h=(tHistorico *)calloc(TAM,sizeof(tHistorico));
  tamanho->usado=0;
  tamanho->total=TAM;
  return h;
}

tHistorico *reallocHistorico(tHistorico *antigo,tTam *tamanho)
{
  int tam=tamanho->total+CTE_AUMENTO;
  tHistorico *novo=(tHistorico *)calloc(tam,sizeof(tHistorico));

  //copiar dados
  for(int i=0;i<tamanho->usado;i++)
  {
    strcpy(novo[i].nome,antigo[i].nome);
    novo[i].rodadas=antigo[i].rodadas;
    novo[i].copiado=antigo[i].copiado;
  }
  //atualizando
  tamanho->total=tam;

  liberaHistorico(antigo);

  return novo;
}


tHistorico *preencheHistorico(tUsuario *j,tHistorico *Hist,tTam *tamanho)
{
  if(tamanho->usado==tamanho->total)
  {
    Hist=reallocHistorico(Hist,tamanho);
  }
  strcpy(Hist[tamanho->usado].nome,j->nome);
  Hist[tamanho->usado].rodadas=j->vitoria;
  tamanho->usado+=1;

  return Hist;
}

int quant(tUsuario *j)
{
  return j->numPokes;
}

void atualizaQuant(tUsuario *j, int valor)
{
   j->numPokes=j->numPokes + valor;
}

void primeiroPoke(tUsuario *j)
{
  j->PokenaJogada=pokeJogada(j->pokemons,j->numPokes);
}

tListapoke *enderecoPrimeiro(tUsuario *j)
{
  return j->PokenaJogada;
}

int quantidadePokebolas(tUsuario *j)
{
  return j->numBolas;
}

void vitoria(tUsuario *j, FILE *arq)
{
  printf("%s venceu!\n\n",j->nome);
  fprintf(arq,"     %s venceu!\n\n",j->nome);
}

void copiaHist(tHistorico *antigo, int i, tHistorico *novo, int posicao)
{
  strcpy(novo[posicao].nome,antigo[i].nome);
  novo[posicao].rodadas=antigo[i].rodadas;
  antigo[i].copiado=1;
}

tHistorico *ordenaHistorico(tHistorico *hist, tTam *tamanho)
{
  tHistorico *ordenado=(tHistorico *)calloc(tamanho->total,sizeof(tHistorico));

  int maior=hist[0].rodadas;
  char nomeDoMaior[128];
  strcpy(nomeDoMaior,hist[0].nome);
  int posicao=0;
  int somaCopiados=0;

  do
  {
    for(int i=0;i<tamanho->usado;i++)
    {
      if(hist[i].rodadas>=maior && hist[i].copiado==0)
      {
        if(hist[i].rodadas==maior)
        {
          //desempate 
          int compara=strcmp(hist[i].nome,nomeDoMaior);

          if(compara<=0)
          {
            maior=hist[i].rodadas;
            strcpy(nomeDoMaior,hist[i].nome);
            posicao=i;
          }         
          
        }
        else
        {
          maior=hist[i].rodadas;
          strcpy(nomeDoMaior,hist[i].nome);
          posicao=i;
        }
      }
    }
    copiaHist(hist,posicao,ordenado,somaCopiados);
    somaCopiados++;
    //pegar o proximo ainda não copiado
    for(int j=0;j<tamanho->usado;j++)
    {
      if(hist[j].copiado==0)
      {
        maior=hist[j].rodadas;
        strcpy(nomeDoMaior,hist[j].nome);
        posicao=j;
        break;
      }
    }
  }while(somaCopiados!=tamanho->usado);
  
  liberaHistorico(hist);

  return ordenado;
}

int qualPosicao(tHistorico *hist, tUsuario *j, tTam *tamanho)
{
  for(int i=0;i<tamanho->usado;i++)
  {
    if((strcmp(hist[i].nome,j->nome)==0)&&(hist[i].rodadas==j->vitoria))
    {
      return i+1;
    }
  }
}

tHistorico *fimJogo(tUsuario *j,FILE *arq, int numPartida,tHistorico *hist, tTam *tamanho)
{
  hist=preencheHistorico(j,hist,tamanho);

  hist=ordenaHistorico(hist, tamanho);

  j->placar=qualPosicao(hist,j,tamanho);


  printf("%s sobreviveu %d rodadas e está em %d lugar no placar!\n\n",j->nome,j->vitoria,j->placar);

  fprintf(arq,"Fim do jogo %d %s sobreviveu %d batalhas\n\n",numPartida,j->nome,j->vitoria);

  return hist;
}

void atualizaPokebola(tUsuario *j,int quant)
{
  j->numBolas=j->numBolas+quant;
}

tListapoke *retornaLista(tUsuario *j)
{
  return j->pokemons;
}

void atualizaBatalhasPB(tUsuario *j)
{
  j->BatVencPB+=1;
}

void atualizaVitoria(tUsuario *j)
{
  j->vitoria+=1;
}

int retornaVitoria(tUsuario *j)
{
  return j->vitoria;
}

void atualizaBatalhasMew(tUsuario *j)
{
  j->BatVencMew+=1;
}

void zeraBatalhasMew(tUsuario *j)
{
  j->BatVencMew=0;
}

void zeraBatalhasPB(tUsuario *j)
{
  j->BatVencPB=0;
}

int retornaBatalhasPB(tUsuario *j)
{
  return j->BatVencPB;
}

int retornaBatalhasMew(tUsuario *j)
{
  return j->BatVencMew;
}

void atualizaRodada(tUsuario *j,int rodadas)
{
  j->rodadas+=rodadas;
}

int  numRodada(tUsuario *j)
{
  return j->rodadas;
}

void liberaTam(tTam *tamanho)
{
  if(tamanho!=NULL)
  {
    free(tamanho);
  }
}

void liberaHistorico(tHistorico *hist)
{
  if(hist!=NULL)
  {
    free(hist);
  }
}

void liberaUsuario(tUsuario *j)
{
  if(j!=NULL)
  {
    //liberar lista
    liberaLista(j->pokemons);

    free(j);
  }
}

void perdeu(tUsuario *j,FILE *arq)
{
  printf("%s perde!\n\n",j->nome);
  fprintf(arq,"     %s perde!\n\n",j->nome);
}

void placar(int partidas, tHistorico *hist, tTam *tamanho)
{
  if(partidas==0)
  {
    //ainda não houveram jogos
    printf("Ainda não há ranking a ser exibido\n");
  }
  else
  {
    for(int i=0;i<tamanho->usado;i++)
    {
      printf("%d- %s: %d\n",i+1,hist[i].nome,hist[i].rodadas);
    }
  }
}

void salvaPlacar(tHistorico *hist, tTam *tamanho,FILE *arq)
{
  for(int i=0;i<tamanho->usado;i++)
  {
    fprintf(arq,"%s %d\n",hist[i].nome,hist[i].rodadas);
  }
}

void adicionaPokemon(tUsuario *j, int poke)
{
  j->pokemons=inserePokemon(j->pokemons,poke);
  j->numPokes=j->numPokes+1;
}