#include "../include/pokemon.h"

struct tpokemon
{
   int id; //id do pokemon
   char nome[10]; //nome do pokemon
   float hp; //hp do pokemon
   int ataque; //atributo de ataque
   int defesa; //atributo de defesa
   float interacoes[6]; //vetor de interações (o numero da posicao é o id do pokemon que defende)
   //quantidade de turno paralisado
   int paralisa;
   //quantidade de turno protegido
   int protegido;
   //até que rodada o efeito especial vale
   int rodada;
   //para o cavar
   float dano;
  
   int queimar; //se o pokemon está queimando 
   int jaAtacou; //quantidade de turnos que ja atacaou 
   int dorme; //quantidade de turnos dormindo (ataque dormir)
   int dormirPo; //quantidade de turnos dormindo(recebeu o dormir do ataque do adversário)
};

struct tlistapoke
{
  tPokemon *poke; //pokemon da posicao
  tListapoke *prox; //ponteiro para o proximo da lista
};

//0 = eletrico, 1 = fogo, 2 = agua, 3 = planta, 4 = metal, 5 = psiquico
//as interaçoes levam em consideração o pokemon na defesa e o listado acima no ataque
void interacoesPikachu(tPokemon *poke)
{
    poke->interacoes[0] = 1/2.0;
    poke->interacoes[1] = 1;
    poke->interacoes[2] = 2;
    poke->interacoes[3] = 1/2.0;
    poke->interacoes[4] = 1;
    poke->interacoes[5] = 1;
}

void interacoesCharizard(tPokemon *poke)
{
    poke->interacoes[0] = 1;
    poke->interacoes[1] = 1/2.0;
    poke->interacoes[2] = 1/2.0;
    poke->interacoes[3] = 2;
    poke->interacoes[4] = 2;
    poke->interacoes[5] = 1;
}

void interacoesBlastoise(tPokemon *poke)
{
    poke->interacoes[0] = 1;
    poke->interacoes[1] = 2;
    poke->interacoes[2] = 1/2.0;
    poke->interacoes[3] = 1/2.0;
    poke->interacoes[4] = 1;
    poke->interacoes[5] = 1;
}

void interacoesVenusaur(tPokemon *poke)
{
    poke->interacoes[0] = 1;
    poke->interacoes[1] = 1/2.0;
    poke->interacoes[2] = 2;
    poke->interacoes[3] = 1/2.0;
    poke->interacoes[4] = 1/2.0;
    poke->interacoes[5] = 1;
}

void interacoesSteelix(tPokemon *poke)
{
    poke->interacoes[0] = 1/2.0;
    poke->interacoes[1] = 1/2.0;
    poke->interacoes[2] = 1/2.0;
    poke->interacoes[3] = 1;
    poke->interacoes[4] = 1/2.0;
    poke->interacoes[5] = 1;
}

void interacoesMew(tPokemon *poke)
{
    poke->interacoes[0] = 1;
    poke->interacoes[1] = 1;
    poke->interacoes[2] = 1;
    poke->interacoes[3] = 1;
    poke->interacoes[4] = 1/2.0;
    poke->interacoes[5] = 1/2.0;
}

void inicializaPikachu(tPokemon *poke)
{
  strcpy(poke->nome, "Pikachu"); 
  poke->ataque = 110;
  poke->defesa = 100;
  poke->id = 0;
  poke->hp = 200;
  interacoesPikachu(poke);
  poke->paralisa=0;
  poke->protegido=0;
  poke->rodada=0;
  poke->jaAtacou=0;
  poke->dorme=0;
  poke->queimar = 0;
  poke->dormirPo = 0;
  poke->dano=0;
  
}

void inicializaCharizard(tPokemon *poke)
{
  strcpy(poke->nome, "Charizard"); 
  poke->ataque = 160;
  poke->defesa = 150;
  poke->id = 1;
  poke->hp = 260;
  interacoesCharizard(poke);
  poke->paralisa=0;
  poke->protegido=0;
  poke->rodada=0;
  poke->jaAtacou=0;
  poke->dorme=0;
  poke->queimar = 0;
  poke->dormirPo = 0;
  poke->dano=0;
}

void inicializaBlastoise(tPokemon *poke)
{
  strcpy(poke->nome, "Blastoise"); 
  poke->ataque = 180;
  poke->defesa = 200;
  poke->id = 2;
  poke->hp = 280;
  interacoesBlastoise(poke);
  poke->paralisa=0;
  poke->protegido=0;
  poke->rodada=0;
  poke->jaAtacou=0;
  poke->dorme=0;
  poke->queimar = 0;
  poke->dormirPo = 0;
  poke->dano=0;
}

void inicializaVenusaur(tPokemon *poke)
{
  strcpy(poke->nome, "Venusaur"); 
  poke->ataque = 160;
  poke->defesa = 160;
  poke->id = 3;
  poke->hp = 300;
  interacoesVenusaur(poke);
  poke->paralisa=0;
  poke->protegido=0;
  poke->rodada=0;
  poke->jaAtacou=0;
  poke->dorme=0;
  poke->queimar = 0;
  poke->dormirPo = 0;
  poke->dano=0;
}

void inicializaSteelix(tPokemon *poke)
{
  strcpy(poke->nome, "Steelix"); 
  poke->ataque = 170;
  poke->defesa = 400;
  poke->hp = 280;
  poke->id = 4;
  interacoesSteelix(poke);
  poke->paralisa=0;
  poke->protegido=0;
  poke->rodada=0;
  poke->jaAtacou=0;
  poke->dorme=0;
  poke->queimar = 0;
  poke->dormirPo = 0;
  poke->dano=0;
}

void inicializaMew(tPokemon *poke)
{
  strcpy(poke->nome, "Mew"); 
  poke->ataque = 200;
  poke->defesa = 200;
  poke->hp = 320;
  poke->id = 5;
  interacoesMew(poke);
  poke->paralisa=0;
  poke->protegido=0;
  poke->rodada=0;
  poke->jaAtacou=0;
  poke->dorme=0;
  poke->queimar = 0;
  poke->dormirPo = 0;
  poke->dano=0;
}

fptrInicializaPoke pokemon[6]={NULL};

void inicializaFptrPoke()
{
  pokemon[0] = inicializaPikachu;
  pokemon[1] = inicializaCharizard;
  pokemon[2] = inicializaBlastoise;
  pokemon[3] = inicializaVenusaur;
  pokemon[4] = inicializaSteelix;
  pokemon[5] = inicializaMew;
}

tPokemon *inicializaPokesBase()
{
  
  inicializaFptrPoke();

  tPokemon *pokes = (tPokemon *)calloc(6, sizeof(tPokemon));

  fptrInicializaPoke funcao;

    for(int i=0;i<6;i++)
    {
      funcao=pokemon[i];
      funcao(&pokes[i]);
    }

  return pokes;
}

void listaPokemon(int *escolhido,tPokemon *pokesBase)
{
  int p=1;
  for(int i=0;i<6;i++)
  {
    if(i!=escolhido[0] && i!=escolhido[1] && i!=escolhido[2])
    {
    printf("%d- %s\n",p,pokesBase[i].nome);
    p++;
    }
  }
}

tPokemon *copiaPokemon(int poke)
{
  tPokemon *p=(tPokemon *)malloc(sizeof(tPokemon));

  fptrInicializaPoke aux=pokemon[poke];
  aux(p);  

  return p;
}

tListapoke *inserePokemon(tListapoke *lista, int pok)
{
  tListapoke *nova=(tListapoke *)malloc(sizeof(tListapoke));

  nova->poke=copiaPokemon(pok);

  nova->prox=lista;

  return nova;
}

static int adequaPosicao(int quantEscolhido, int *escolhido)
{
  if(quantEscolhido==1)
  {
    if(escolhido[quantEscolhido]>=escolhido[0])
    {
      escolhido[quantEscolhido]++;
    }
  }
  if(quantEscolhido==2)
  {
    if(escolhido[0]>escolhido[1])
    {
      if(escolhido[quantEscolhido]>=escolhido[1])
      {
      escolhido[quantEscolhido]++;
      }
      if(escolhido[quantEscolhido]>=escolhido[0])
      {
      escolhido[quantEscolhido]++;
      }
    }
    else
    {
      if(escolhido[quantEscolhido]>=escolhido[0])
      {
      escolhido[quantEscolhido]++;
      }
      if(escolhido[quantEscolhido]>=escolhido[1])
      {
      escolhido[quantEscolhido]++;
      }
    }
  }

 return escolhido[quantEscolhido];
} 

tListapoke *selecionaPokemons(tPokemon *pokesBase, tListapoke *PokenaJogada, int *numPokes, int *numBolas)
{

  int escolhido[3]={-1,-1,-1};
  int quantEscolhido=0;

 
  for(int i=0;i<3;i++)
  {
    listaPokemon(escolhido,pokesBase);
    
    while(1)
    {
      if(quantEscolhido==3)
      {
        //segurança
        break;
      }

      //menos um devido a contagem começar do 0
      escolhido[quantEscolhido]=(filtraInteiroPositivo())-1;
      //adequar a posição quando um for tirado
      escolhido[quantEscolhido]=adequaPosicao(quantEscolhido, escolhido);     

      if((escolhido[quantEscolhido]>=0 && escolhido[quantEscolhido]<6)&&(escolhido[quantEscolhido]!=escolhido[0]||escolhido[quantEscolhido]!=escolhido[1]))
      {
        quantEscolhido++;
        system("clear");
        break;
      }
      else
      {
        printf("A opção escolhida é inválida, digite uma opção válida\n");
        escolhido[quantEscolhido]=-1;
      }
    }
  }
  *numPokes=3;
  *numBolas=3;

  tListapoke *l=NULL;

  //alocar na lista
  for(int j=0;j<3;j++)
  {
    l=inserePokemon(l,escolhido[j]);
    
    //printf("\n %d \n",j);
    //printaListaPokes(l); 
  }
  return l;
}

tListapoke *pokeJogada(tListapoke *lista,int tamLista)
{
  tListapoke *aux=lista;

  for(int i=1;i<tamLista;i++)
  {
    aux=aux->prox;
  }
  return aux;
}

void liberaPoke(tListapoke *lista,int tamLista)
{
  tListapoke *aux=lista;
  tListapoke *prox=lista->prox;
  
  for(int i=1;i<tamLista-1;i++)
  {
    aux=aux->prox;
    prox=prox->prox;
  }
  if(prox!=NULL)
  {
    if(prox->poke!=NULL)
    {
      free(prox->poke);
    }
    free(prox);
  }
  aux->prox=NULL;
}

void ImprimeMensagemInicial(tPokemon *Ai)
{
  printf("Um %s selvagem aparece\n\n",Ai->nome);
}

void ImprimeHp(tPokemon *Ai,tListapoke *lista, tPokemon *pokesBase)
{
  printf("%s: %.2f%% HP\n",Ai->nome,100 * (Ai->hp/pokesBase[Ai->id].hp));
  printf("%s: %.2f%% HP\n\n",lista->poke->nome, 100 *(lista->poke->hp/pokesBase[lista->poke->id].hp));
}

int idPokemon(tListapoke *p)
{
  return  p->poke->id;
}

int idPoke(tPokemon *p)
{
  return  p->id;
}

float chanceCapturar(tPokemon *AI, tPokemon *pokesBase)
{
  return ((pokesBase[AI->id].hp) / AI->hp) / (float)20.0;
}

float hpPokemon(tListapoke *p)
{
  return  p->poke->hp;
}

float hpPoke(tPokemon *p)
{
  return  p->hp;
}

void zeraEspeciais(tPokemon *p)
{
  //reseta status
  p->protegido=0;
  p->dormirPo=0;
  p->dorme=0;
  p->paralisa=0;
  p->dano=0;
  p->queimar=0;

}

void soma10Hp(tListapoke *p)
{
  p->poke->hp=p->poke->hp+10;
  fptrInicializaPoke funcao=pokemon[p->poke->id];
  tPokemon poke;
  funcao(&poke);
  if((p->poke->hp)>(poke.hp))
  {
    p->poke->hp=poke.hp;
  }

  //reseta status
  zeraEspeciais(p->poke);
  
}

void printaHpJogador(tPokemon *Ai,tPokemon *j,FILE *arq, tPokemon *pokesBase)
{
  tPokemon jogadorBase, AiBase;
  fptrInicializaPoke funcao1=pokemon[Ai->id];
  fptrInicializaPoke funcao2=pokemon[j->id];
  //inicializa um pokemon igual ao passado na função
  funcao1(&AiBase);
  funcao2(&jogadorBase);

  if(j->queimar > 0) danoQueimar(j, pokesBase);
  if(j->hp < 0) j->hp = 0;
  float hpJogador=(j->hp*100.0)/jogadorBase.hp;
  float hpAi=(Ai->hp*100.0)/AiBase.hp;


  fprintf(arq,"     %s: %.2f%% HP ",Ai->nome,hpAi); 
  printaStatusArquivo(Ai, arq);
  fprintf(arq,"\n"); 

  fprintf(arq,"     %s: %.2f%% HP",j->nome,hpJogador); 
  printaStatusArquivo(j, arq);
  fprintf(arq,"\n\n"); 

  printf("%s: %.2f%% HP ",Ai->nome,hpAi);
  printaStatusConsole(Ai);
  printf("\n");
  printf("%s: %.2f%% HP ",j->nome,hpJogador);
  printaStatusConsole(j);
  printf("\n\n"); 


}

void printaHpAi(tPokemon *Ai,tPokemon *j,FILE *arq, tPokemon *pokesBase)
{
  tPokemon jogadorBase, AiBase;
  fptrInicializaPoke funcao1=pokemon[Ai->id];
  fptrInicializaPoke funcao2=pokemon[j->id];
  //inicializa um pokemon igual ao passado na função
  funcao1(&AiBase);
  funcao2(&jogadorBase);

  if(Ai->queimar > 0) danoQueimar(Ai, pokesBase);
  if(Ai->hp < 0) Ai->hp = 0;

  float hpJogador=(j->hp*100.0)/jogadorBase.hp;
  float hpAi=(Ai->hp*100.0)/AiBase.hp;

  fprintf(arq,"     %s: %.2f%% HP ",Ai->nome,hpAi); 
  printaStatusArquivo(Ai, arq);
  fprintf(arq,"\n"); 

  fprintf(arq,"     %s: %.2f%% HP",j->nome,hpJogador); 
  printaStatusArquivo(j, arq);
  fprintf(arq,"\n\n"); 

  printf("%s: %.2f%% HP ",Ai->nome,hpAi);
  printaStatusConsole(Ai);
  printf("\n");
  printf("%s: %.2f%% HP ",j->nome,hpJogador);
  printaStatusConsole(j);
  printf("\n\n"); 


}

void choqueDoTrovao(tPokemon *defensor, tPokemon *atacante,FILE *arq, int rodada, int metronomo)
{
  if(metronomo == 0)
  {
    printf("%s usou Choque do Trovão\n\n", atacante->nome);
    fprintf(arq,"     %s usa Choque de Trovão\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Choque do Trovão)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Choque do Trovão)\n");
  }
  int poder = 40, critico = 0;
  float mt = 1.5, dano = 0, tipo = 0, modificador = 0;

  tipo = atacante->interacoes[defensor->id];
  
  float chanceCritico = (float)rand()/(float)(RAND_MAX);
  if(chanceCritico <= (float)1.0/(float)24.0)
  {
    critico = 2;
  }
  else
  {
    critico = 1;
  }

  modificador = critico * mt * tipo;

  dano = (((14 * (float)poder * atacante->ataque / defensor->defesa) / 50) + 2) * modificador;


  if(defensor->protegido <= 0)
  {
    defensor->hp -= dano;
    if(defensor->hp < 0) defensor->hp = 0;
  }
    
  float chanceParalizar = (float)rand()/(float)(RAND_MAX);
  if(chanceParalizar <= (float)1.0/(float)10.0 && defensor->protegido <= 0)
  {
    defensor->paralisa = 1;
  }

  if(defensor->protegido > 0) defensor->protegido--;
}

void ondaDeChoque(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{
  if(metronomo == 0)
  {
    printf("%s usou Onda de Choque\n\n", atacante->nome);
    fprintf(arq,"     %s usa Onda de Choque\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Onda de Choque)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Onda de Choque)\n");
  }
  if(defensor->protegido <= 0)
  {
    defensor->paralisa = 1;
  }

  if(defensor->protegido > 0) defensor->protegido--;
}

void bater(tPokemon *defensor, tPokemon *atacante,FILE *arq, int rodada,int metronomo)
{
  if(metronomo == 0)
  {
    printf("%s usou Bater\n\n", atacante->nome);
    fprintf(arq,"     %s usa Bater\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Bater)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Bater)\n");
  }
  int poder = 40, critico = 0;
  float mt = 1.0, dano = 0, tipo = 0, modificador = 0;

  tipo = atacante->interacoes[defensor->id];
  
  float chanceCritico = (float)rand()/(float)(RAND_MAX);
  if(chanceCritico <= (float)1.0/(float)24.0)
  {
    critico = 2;
  }
  else
  {
    critico = 1;
  }

  modificador = critico * mt * tipo;

  dano = (((14 * (float)poder * atacante->ataque / defensor->defesa) / 50) + 2) * modificador;

  if(defensor->protegido <= 0)
  {
    defensor->hp -= dano;
    if(defensor->hp < 0) defensor->hp = 0;
  }

  if(defensor->protegido > 0) defensor->protegido--;
}

void lancaChamas(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{
  if(metronomo == 0)
  {
    printf("%s usou Lança Chamas\n\n", atacante->nome);
    fprintf(arq,"     %s usa Lança Chamas\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Lança Chamas)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Lança Chamas)\n");
  }
  int poder = 90, critico = 0;
  float mt = 1.5, dano = 0, tipo = 0, modificador = 0;

  tipo = atacante->interacoes[defensor->id];
  
  float chanceCritico = (float)rand()/(float)(RAND_MAX);
  if(chanceCritico <= (float)1.0/(float)24.0)
  {
    critico = 2;
  }
  else
  {
    critico = 1;
  }

  float chanceQueimar = (float)rand()/(float)RAND_MAX;
  if(chanceQueimar <= 0.1 && defensor->id != 1 && defensor->protegido <= 0)
  {
    defensor->queimar = 1;
  }

  modificador = critico * mt * tipo;

  dano = (((14 * (float)poder * atacante->ataque / defensor->defesa) / 50) + 2) * modificador;

  if(defensor->protegido <= 0)
  {
    defensor->hp -= dano;
    if(defensor->hp < 0) defensor->hp = 0;
  }
  if(defensor->protegido > 0) defensor->protegido--;
}

void dormir(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{
  if(metronomo == 0)
  {
    printf("%s usou Dormir\n\n", atacante->nome);
    fprintf(arq,"     %s usa Dormir\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Dormir)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Dormir)\n");
  }
  atacante->dorme = 2;
}

void armaDeAgua(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{
  if(metronomo == 0)
  {
    printf("%s usou Arma de Água\n\n", atacante->nome);
    fprintf(arq,"     %s usa Arma de Água\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Arma de Água)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Arma de Água)\n");
  }
  int poder = 40, critico = 0;
  float mt = 1.5, dano = 0, tipo = 0, modificador = 0;

  tipo = atacante->interacoes[defensor->id];
  
  float chanceCritico = (float)rand()/(float)(RAND_MAX);
  if(chanceCritico <= (float)1.0/(float)24.0)
  {
    critico = 2;
  }
  else
  {
    critico = 1;
  }

  modificador = critico * mt * tipo;

  dano = (((14 * (float)poder * atacante->ataque / defensor->defesa) / 50) + 2) * modificador;

  if(defensor->protegido <= 0)
  {
    defensor->hp -= dano;
    if(defensor->hp < 0) defensor->hp = 0;
  }
  if(defensor->protegido > 0) defensor->protegido--;
}

void proteger(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{
  if(metronomo == 0)
  {
    printf("%s usou Proteger\n\n", atacante->nome);
    fprintf(arq,"     %s usa Proteger\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Proteger)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Proteger)\n");
  }
  atacante->protegido = 1;
}

void poDeSono(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{
  if(metronomo == 0)
  {
    printf("%s usou Pó de Sono\n\n", atacante->nome);
    fprintf(arq,"     %s usa Pó de Sono\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Pó de Sono)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Pó de Sono)\n");
  }
  int qtdTurnos = 0;
  qtdTurnos = (rand() % 3) + 1;
  if(defensor->protegido <= 0)
  {
    defensor->dormirPo = qtdTurnos;
  }
  if(defensor->protegido > 0) defensor->protegido--;
}

void bombaDeSemente(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{

  if(metronomo == 0)
  {
    printf("%s usou Bomba de Semente\n\n", atacante->nome);
    fprintf(arq,"     %s usa Bomba de Semente\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Bomba de Semente)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Bomba de Semente)\n");
  }
  
  int poder = 80, critico = 0;
  float mt = 1.5, dano = 0, tipo = 0, modificador = 0;

  tipo = atacante->interacoes[defensor->id];
  
  float chanceCritico = (float)rand()/(float)(RAND_MAX);
  if(chanceCritico <= (float)1.0/(float)24.0)
  {
    critico = 2;
  }
  else
  {
    critico = 1;
  }

  modificador = critico * mt * tipo;

  dano = (((14 * (float)poder * atacante->ataque / defensor->defesa) / 50) + 2) * modificador;

  if(defensor->protegido <= 0)
  {
    defensor->hp -= dano;
    if(defensor->hp < 0) defensor->hp = 0;
  }
  if(defensor->protegido > 0) defensor->protegido--;
}

void doisGumes(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{

  if(metronomo == 0)
  {
    printf("%s usou Dois Gumes\n\n", atacante->nome);
    fprintf(arq,"     %s usa Dois Gumes\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Dois Gumes)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Dois Gumes)\n");
  }
  
  
  int poder = 120, critico = 0;
  float mt = 1.0, dano = 0, tipo = 0, modificador = 0;

  tipo = atacante->interacoes[defensor->id];
  
  float chanceCritico = (float)rand()/(float)(RAND_MAX);
  if(chanceCritico <= (float)1.0/(float)24.0)
  {
    critico = 2;
  }
  else
  {
    critico = 1;
  }

  modificador = critico * mt * tipo;

  dano = (((14 * (float)poder * atacante->ataque / defensor->defesa) / 50) + 2) * modificador;

  if(defensor->protegido <= 0)
  {
    defensor->hp -= dano;
    if(defensor->hp < 0) defensor->hp = 0;
  }

  dano=dano*1/3.0;
  atacante->hp-=dano;
  if(atacante->hp < 0) atacante->hp = 0;

  if(defensor->protegido > 0) defensor->protegido--;
}

void raboDeFerro(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{
  if(metronomo == 0)
  {
    printf("%s usou Rabo de Ferro\n\n", atacante->nome);
    fprintf(arq,"     %s usa Rabo de Ferro\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Rabo de Ferro)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Rabo de Ferro)\n");
  }
  
  
  int poder = 100, critico = 0;
  float mt = 1.5, dano = 0, tipo = 0, modificador = 0;

  tipo = atacante->interacoes[defensor->id];
  
  float chanceCritico = (float)rand()/(float)(RAND_MAX);
  if(chanceCritico <= (float)1.0/(float)24.0)
  {
    critico = 2;
  }
  else
  {
    critico = 1;
  }

  modificador = critico * mt * tipo;

  dano = (((14 * (float)poder * atacante->ataque / defensor->defesa) / 50) + 2) * modificador;

  if(defensor->protegido <= 0)
  {
    defensor->hp -= dano;
    if(defensor->hp < 0) defensor->hp = 0;
  }
  if(defensor->protegido > 0) defensor->protegido--;
}

void cavar(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{

  if(metronomo == 0)
  {
    printf("%s usou Cavar\n\n", atacante->nome);
    fprintf(arq,"     %s usa Cavar\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Cavar)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Cavar)\n");
  }

  int poder = 80, critico = 0;
  float mt = 1.0, dano = 0, tipo = 0, modificador = 0;

  tipo = atacante->interacoes[defensor->id];
  
  float chanceCritico = (float)rand()/(float)(RAND_MAX);
  if(chanceCritico <= (float)1.0/(float)24.0)
  {
    critico = 2;
  }
  else
  {
    critico = 1;
  }

  modificador = critico * mt * tipo;

  dano = (((14 * (float)poder * atacante->ataque / defensor->defesa) / 50) + 2) * modificador;

  atacante->protegido=1;
  defensor->dano=dano;
}

void autoDestruir(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{
  if(metronomo == 0)
  {
    printf("%s usou Auto-Destruir\n\n", atacante->nome);
    fprintf(arq,"     %s usa Auto-Destruir\n",atacante->nome);
  }
  else
  {
    printf("Mew usou Metrônomo (Auto-Destruir)\n\n");
    fprintf(arq,"     Mew usa Metrônomo (Auto-Destruir)\n");
  }
  

  int poder = 200, critico = 0;
  float mt = 1.0, dano = 0, tipo = 0, modificador = 0;

  tipo = atacante->interacoes[defensor->id];
  
  float chanceCritico = (float)rand()/(float)(RAND_MAX);
  if(chanceCritico <= (float)1.0/(float)24.0)
  {
    critico = 2;
  }
  else
  {
    critico = 1;
  }

  modificador = critico * mt * tipo;

  dano = (((14 * (float)poder * atacante->ataque / defensor->defesa) / 50) + 2) * modificador;

  if(defensor->protegido <= 0)
  {
    defensor->hp -= dano;
    if(defensor->hp < 0) defensor->hp = 0;
  }
  atacante->hp = 0;
  if(defensor->protegido > 0) defensor->protegido--;
}


fptrAtaqueMetronomo ataquesMetronomo[13];

void inicializaAtaquesMetronomo()
{
  ataquesMetronomo[0] = choqueDoTrovao;
  ataquesMetronomo[1] = ondaDeChoque;
  ataquesMetronomo[2] = bater;
  ataquesMetronomo[3] = lancaChamas;
  ataquesMetronomo[4] = dormir;
  ataquesMetronomo[5] = armaDeAgua;
  ataquesMetronomo[6] = proteger;
  ataquesMetronomo[7] = poDeSono;
  ataquesMetronomo[8] = bombaDeSemente;
  ataquesMetronomo[9] = doisGumes;
  ataquesMetronomo[10] = raboDeFerro;
  ataquesMetronomo[11] = cavar;
  ataquesMetronomo[12] = autoDestruir;
}

fptrAtaqueMetronomo retornaAtaqueMetronomo(int id)
{
  return ataquesMetronomo[id];
}

void metronomo(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo)
{
  inicializaAtaquesMetronomo();

  int metro = rand() % 13;

  fptrAtaqueMetronomo ataq = retornaAtaqueMetronomo(metro);

  ataq(defensor, atacante, arq, rodada,1);
}

tPokemon *retornaEndPoke(tListapoke *lista)
{
  return lista->poke;
}

char *retornaNome(tPokemon *p)
{
  return p->nome;
}

int testaImpedimentoJogador(tPokemon *p,FILE *arq,tPokemon *Ai, tPokemon *pokesBase)
{
  if(p->paralisa>0)
  {
  printf("Jogador paralizado\n");
  if(p->dorme > 0)
  {
    p->dorme--;
    if(p->dorme==0)
    {
      p->hp=pokesBase[p->id].hp;
    }
    p->dorme++;
  }
  if(p->queimar > 0) danoQueimar(p, pokesBase);
  if(p->hp < 0) p->hp = 0;
  float hpAi = ((float)Ai->hp * 100 / pokesBase[Ai->id].hp);
    float hpJogador = ((float)p->hp * 100 / pokesBase[p->id].hp);
  fprintf(arq,"     %s: %.2f%% HP ",Ai->nome,hpAi);
  printaStatusArquivo(Ai, arq);
  fprintf(arq,"\n");    
  fprintf(arq,"     %s: %.2f%% HP ",p->nome,hpJogador); 
  printaStatusArquivo(p, arq);
  fprintf(arq,"\n\n"); 
  printf("%s: %.2f%% HP ",Ai->nome,hpAi);
  printaStatusConsole(Ai);
  printf("\n");
  printf("%s: %.2f%% HP ",p->nome,hpJogador);
  printaStatusConsole(p);
  printf("\n\n"); 
  if(Ai->protegido > 0) Ai->protegido--;
  p->paralisa=p->paralisa-1;
  if(p->dormirPo > 0) p->dormirPo -= 1; 
  if(p->dorme > 0) p->dorme--;
  
  return 1;
  }
  if(p->dormirPo > 0)
  {
    printf("Jogador dormindo\n");
    if(p->dorme > 0)
    {
      p->dorme--;
      if(p->dorme==0)
      {
       p->hp=pokesBase[p->id].hp;
      }
      p->dorme++;
    }
    if(p->queimar > 0) danoQueimar(p, pokesBase);
    if(p->hp < 0) p->hp = 0;
    float hpAi = ((float)Ai->hp * 100 / pokesBase[Ai->id].hp);
    float hpJogador = ((float)p->hp * 100 / pokesBase[p->id].hp);
    fprintf(arq,"     %s: %.2f%% HP ",Ai->nome,hpAi);
    printaStatusArquivo(Ai, arq);
    fprintf(arq,"\n");    
    fprintf(arq,"     %s: %.2f%% HP ",p->nome,hpJogador); 
    printaStatusArquivo(p, arq);
    fprintf(arq,"\n\n"); 
    printf("%s: %.2f%% HP ",Ai->nome,hpAi);
    printaStatusConsole(Ai);
    printf("\n");
    printf("%s: %.2f%% HP ",p->nome,hpJogador);
    printaStatusConsole(p);
    printf("\n\n"); 
    p->dormirPo -= 1; 
    if(p->paralisa > 0) p->paralisa--;
    if(Ai->protegido > 0) Ai->protegido--;
    if(p->dorme > 0) p->dorme--;
    return 1;
  }
  if(p->dorme > 0)
  {
    printf("Jogador dormindo\n");
    p->dorme -= 1; 
    if(p->dorme==0)
    {
      p->hp=pokesBase[p->id].hp;
    }
    p->dorme++;
    if(p->queimar > 0) danoQueimar(p, pokesBase);
    if(p->hp < 0) p->hp = 0;
    float hpAi = ((float)Ai->hp * 100 / pokesBase[Ai->id].hp);
    float hpJogador = ((float)p->hp * 100 / pokesBase[p->id].hp);
    fprintf(arq,"     %s: %.2f%% HP ",Ai->nome,hpAi);
    printaStatusArquivo(Ai, arq);
    fprintf(arq,"\n");    
    fprintf(arq,"     %s: %.2f%% HP ",p->nome,hpJogador); 
    printaStatusArquivo(p, arq);
    fprintf(arq,"\n\n"); 
    printf("%s: %.2f%% HP ",Ai->nome,hpAi);
    printaStatusConsole(Ai);
    printf("\n");
    printf("%s: %.2f%% HP ",p->nome,hpJogador);
    printaStatusConsole(p);
    printf("\n\n"); 
    
    if(p->paralisa > 0) p->paralisa--;
    if(Ai->protegido > 0) Ai->protegido--;
    p->dorme--;
    return 1;
  }
  else
  {
    return 0;
  }
}

int testaImpedimentoAi(tPokemon *p,FILE *arq,tPokemon *Ai, tPokemon *pokesBase)
{
  if(Ai->paralisa>0)
  {
    printf("Adversário paralizado\n");
    if(Ai->dorme > 0)
    {
      Ai->dorme--;
      if(Ai->dorme==0)
      {
      Ai->hp=pokesBase[Ai->id].hp;
      }
      Ai->dorme++;
    }
    if(Ai->queimar > 0) danoQueimar(Ai, pokesBase);
    if(Ai->hp < 0) Ai->hp = 0;
    float hpAi = ((float)Ai->hp * 100 / pokesBase[Ai->id].hp);
    float hpJogador = ((float)p->hp * 100 / pokesBase[p->id].hp);
    fprintf(arq,"     %s: %.2f%% HP ",Ai->nome,hpAi);
    printaStatusArquivo(Ai, arq);
    fprintf(arq,"\n");    
    fprintf(arq,"     %s: %.2f%% HP ",p->nome,hpJogador); 
    printaStatusArquivo(p, arq);
    fprintf(arq,"\n\n"); 
    printf("%s: %.2f%% HP ",Ai->nome,hpAi);
    printaStatusConsole(Ai);
    printf("\n");
    printf("%s: %.2f%% HP ",p->nome,hpJogador);
    printaStatusConsole(p);
    printf("\n\n"); 
    Ai->paralisa--;
    if(Ai->dormirPo > 0) Ai->dormirPo--;
    if(p->protegido > 0) p->protegido--;
    if(Ai->dorme > 0) Ai->dorme--;
  
  return 1;
  }
  if(Ai->dormirPo > 0)
  {
    printf("Adversario dormindo\n");
    if(Ai->dorme > 0)
    {
      Ai->dorme--;
      if(Ai->dorme==0)
      {
      Ai->hp=pokesBase[Ai->id].hp;
      }
      Ai->dorme++;
    }
     
    if(Ai->queimar > 0) danoQueimar(Ai, pokesBase);
    if(Ai->hp < 0) Ai->hp = 0;
    float hpAi = ((float)Ai->hp * 100 / pokesBase[Ai->id].hp);
    float hpJogador = ((float)p->hp * 100 / pokesBase[p->id].hp);
    fprintf(arq,"     %s: %.2f%% HP ",Ai->nome,hpAi);
    printaStatusArquivo(Ai, arq);
    fprintf(arq,"\n");    
    fprintf(arq,"     %s: %.2f%% HP ",p->nome,hpJogador); 
    printaStatusArquivo(p, arq);
    fprintf(arq,"\n\n"); 
    printf("%s: %.2f%% HP ",Ai->nome,hpAi);
    printaStatusConsole(Ai);
    printf("\n");
    printf("%s: %.2f%% HP ",p->nome,hpJogador);
    printaStatusConsole(p);
    printf("\n\n"); 
    if(p->protegido > 0) p->protegido--;
    Ai->dormirPo--;
    if(Ai->dorme > 0) Ai->dorme--;
    if(Ai->paralisa > 0) Ai->paralisa--;
    return 1;
  }
  if(Ai->dorme > 0)
  {
    printf("Adversario dormindo\n");
    Ai->dorme--;
    
    if(Ai->dorme==0)
    {
      Ai->hp=pokesBase[Ai->id].hp;
    }
    Ai->dorme++;
    if(Ai->queimar > 0) danoQueimar(Ai, pokesBase);
    if(Ai->hp < 0) Ai->hp = 0;
    float hpAi = ((float)Ai->hp * 100 / pokesBase[Ai->id].hp);
    float hpJogador = ((float)p->hp * 100 / pokesBase[p->id].hp);
    fprintf(arq,"     %s: %.2f%% HP ",Ai->nome,hpAi);
    printaStatusArquivo(Ai, arq);
    fprintf(arq,"\n");    
    fprintf(arq,"     %s: %.2f%% HP ",p->nome,hpJogador); 
    printaStatusArquivo(p, arq);
    fprintf(arq,"\n\n"); 
    printf("%s: %.2f%% HP ",Ai->nome,hpAi);
    printaStatusConsole(Ai);
    printf("\n");
    printf("%s: %.2f%% HP ",p->nome,hpJogador);
    printaStatusConsole(p);
    printf("\n\n"); 
    if(p->protegido > 0) p->protegido--;
    
    if(Ai->paralisa > 0) Ai->paralisa--;
    if(Ai->dormirPo > 0) Ai->dormirPo--;
    Ai->dorme--;
    return 1;
  }
  else
  {
    return 0;
  }
}

void atualizaAtaque(tPokemon *p)
{
  p->jaAtacou=p->jaAtacou+1;
}

int jaAtacou(tPokemon *p)
{
  if(p->jaAtacou>0)
  {
    return 1;
  }
  else
  {
    return 0;
  }

}

int queimar(tPokemon *poke)
{
  if(poke != NULL)
  {
    if(poke->queimar > 0)
    {
      //poke->queimar--;
      return 1;
    }
  }
  return 0;
}

void danoQueimar(tPokemon *poke, tPokemon *pokesBase)
{
  poke->hp -= (pokesBase[poke->id].hp / 16);
  if(poke->hp < 0) poke->hp = 0;
}

int dormindo(tPokemon *poke)
{
  if(poke != NULL)
  {
    if(poke->dorme > 0)
    {
      //poke->dorme--;
      return 1;
    }
    if(poke->dormirPo > 0)
    {
      //poke->dormirPo--;
      return 1;
    }
  }
  return 0;
}

int paralizado(tPokemon *poke)
{
  if(poke != NULL)
  {
    if(poke->paralisa > 0)
    {
      //poke->paralisa--;
      return 1;
    }
  }
  return 0;
}

int printaStatusArquivo(tPokemon *poke, FILE *arq)
{
  int queimando = 0, dorm = 0, paral = 0; 
  if(poke != NULL)
  {
    queimando = queimar(poke);
    dorm = dormindo(poke);
    paral = paralizado(poke);

    if(queimando == 1 && dorm == 0 && paral == 0)
    {
      fprintf(arq, "(queimando)");
    }
    if(queimando == 1 && dorm == 1 && paral == 0)
    {
      fprintf(arq, "(dormindo, queimando)");
    }
    if(queimando == 1 && dorm == 1 && paral == 1)
    {
      fprintf(arq, "(paralizado, dormindo, queimando)");
    }
    if(queimando == 1 && dorm == 0 && paral == 1)
    {
      fprintf(arq, "(paralizado, queimando)");
    }
    if(queimando == 0 && dorm == 1 && paral == 0)
    {
      fprintf(arq, "(dormindo)");
    }
    if(queimando == 0 && dorm == 1 && paral == 1)
    {
      fprintf(arq, "(paralizado, dormindo)");
    }
    if(queimando == 0 && dorm == 0 && paral == 1)
    {
      fprintf(arq, "(paralizado)");
    }

    
  }
  return queimando;
}

void printaStatusConsole(tPokemon *poke)
{
  int queimando = 0, dorm = 0, paral = 0; 
  if(poke != NULL)
  {
    queimando = queimar(poke);
    dorm = dormindo(poke);
    paral = paralizado(poke);

    if(queimando == 1 && dorm == 0 && paral == 0)
    {
      printf("(queimando)");
    }
    if(queimando == 1 && dorm == 1 && paral == 0)
    {
      printf("(dormindo, queimando)");
    }
    if(queimando == 1 && dorm == 1 && paral == 1)
    {
      printf("(paralizado, dormindo, queimando)");
    }
    if(queimando == 1 && dorm == 0 && paral == 1)
    {
      printf("(paralizado, queimando)");
    }
    if(queimando == 0 && dorm == 1 && paral == 0)
    {
      printf("(dormindo)");
    }
    if(queimando == 0 && dorm == 1 && paral == 1)
    {
      printf("(paralizado, dormindo)");
    }
    if(queimando == 0 && dorm == 0 && paral == 1)
    {
      printf("(paralizado)");
    }
  }
}


void liberaPokesBase(tPokemon *pokes)
{
  if(pokes!=NULL)
  {
    free(pokes);
  }
}

void testaCavar(tPokemon *p)
{
  if(p->dano>0)
  {
   if(p->protegido <= 0)
    {
      p->hp -= p->dano;
      if(p->hp < 0) p->hp = 0;
    }
   p->dano=0;
   if(p->protegido > 0) p->protegido--;
  }
}

void liberaLista(tListapoke *lista)
{
  tListapoke *aux=NULL;
  tListapoke *prox=NULL;

  for(aux=lista;aux!=NULL;)
  {
    if(aux->poke!=NULL)
    {
      free(aux->poke);
    }
    prox=aux->prox;
    free(aux);
    aux=prox;
  }

}