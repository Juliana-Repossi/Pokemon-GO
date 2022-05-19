#include "../include/batalha.h"


void imprimePartida(FILE *arq,int n)
{
  fprintf(arq,"%d.",n);
}

void imprimeDuelos(FILE *arq,int n)
{
  fprintf(arq,"  %d- ",n);
}

void imprimeDuelo(FILE *arq,tPokemon *Ai, tPokemon *j)
{
  fprintf(arq,"%s vs %s\n",retornaNome(j),retornaNome(Ai)); 
}

void imprimeCaptura(FILE *arq,int n)
{
  fputs("     Tentativa de Captura\n",arq);
  if(n==1)
  {
    //Sucesso
    fputs("     Sucesso\n\n",arq);
  }
  else
  {
    fputs("     Fracasso\n\n",arq);
  }
}

void imprimeFuga(FILE *arq,int n)
{
  fputs("     Tentativa de Fuga\n",arq);
  if(n==1)
  {
    //Sucesso
    fputs("     Sucesso\n\n",arq);
  }
  else
  {
    fputs("     Fracasso\n\n",arq);
  }
}


void imprimePikachu(tUsuario *j)
{
  printf("Escolha um movimento:\n");
  printf("1- Choque do Trovão\n");
  printf("2- Onda de Choque\n");
  printf("3- Bater\n");
  printf("4- Pokebola(%d disponíveis)\n",quantidadePokebolas(j));
  printf("5- Fugir\n\n");
}

void imprimeCharizard(tUsuario *j)
{
  printf("Escolha um movimento:\n");
  printf("1- Lança Chamas\n");
  printf("2- Dormir\n");
  printf("3- Bater\n");
  printf("4- Pokebola(%d disponíveis)\n",quantidadePokebolas(j));
  printf("5- Fugir\n\n");
}

void imprimeBlastoise(tUsuario *j)
{
  printf("Escolha um movimento:\n");
  printf("1- Arma de Água\n");
  printf("2- Proteger\n");
  printf("3- Bater\n");
  printf("4- Pokebola(%d disponíveis)\n",quantidadePokebolas(j));
  printf("5- Fugir\n\n");
}

void imprimeVenusaur(tUsuario *j)
{
  printf("Escolha um movimento:\n");
  printf("1- Pó de sono\n");
  printf("2- Bomba de Semente\n");
  printf("3- Dois Gumes\n");
  printf("4- Pokebola(%d disponíveis)\n",quantidadePokebolas(j));
  printf("5- Fugir\n\n");
}

void imprimeSteelix(tUsuario *j)
{
  printf("Escolha um movimento:\n");
  printf("1- Rabo de Ferro\n");
  printf("2- Dormir\n");
  printf("3- Cavar\n");
  printf("4- Pokebola(%d disponíveis)\n",quantidadePokebolas(j));
  printf("5- Fugir\n\n");
}

void imprimeMew(tUsuario *j)
{
  printf("Escolha um movimento:\n");
  printf("1- Metronomo\n");
  printf("2- Bater\n");
  printf("3- Auto-Destruir\n");
  printf("4- Pokebola(%d disponíveis)\n",quantidadePokebolas(j));
  printf("5- Fugir\n\n");
}

fptrImprimeGolpe golpe[6];

void inicializaGolpe()
{
  golpe[0]=imprimePikachu;
  golpe[1]=imprimeCharizard;
  golpe[2]=imprimeBlastoise;
  golpe[3]=imprimeVenusaur;
  golpe[4]=imprimeSteelix;
  golpe[5]=imprimeMew;
}

int validaGolpe(int idPoke, int bolas)
{
  int op=0;

  while(1)
  {
    op=filtraInteiroPositivo()-1;

    if(op>=0 && op<5)
    {
      if(op==3 && bolas>0)
      {
       break;
      }
      if(op!=3)
      {
        break;
      }
    }

    printf("Digite uma opção válida\n");

  }
  if(op==3)
  {
    //penultima posição da lista
    return 18;
  }
  if(op==4)
  {
    return 19;
  }
  //para ficar de acordo com a fptr
  return idPoke*3+op;
}

int GolpeAI(int idPoke)
{
  int op=rand() % 3;
  
  //para ficar de acordo com a fptr
  return idPoke*3+op;
}

fptrAtaque ataques[18];

void inicializaAtaques()
{
  ataques[0] = choqueDoTrovao;
  ataques[1] = ondaDeChoque;
  ataques[2] = bater;
  ataques[3] = lancaChamas;
  ataques[4] = dormir;
  ataques[5] = bater;
  ataques[6] = armaDeAgua;
  ataques[7] = proteger;
  ataques[8] = bater;
  ataques[9] = poDeSono;
  ataques[10] = bombaDeSemente;
  ataques[11] = doisGumes;
  ataques[12] = raboDeFerro;
  ataques[13] = dormir;
  ataques[14] = cavar;
  ataques[15] = metronomo;
  ataques[16] = bater;
  ataques[17] = autoDestruir;
}

fptrAtaque retornaAtaque(int id)
{
  return ataques[id];
}

int duelo(tPokemon *Ai,tUsuario *j, FILE *arq)
{
  //return 4: os dois morreram
  //return 3 : fugiu
  //return 2 : capturou pokemon
  //return 1 : ganhou duelo
  //return 0 : perdeu

  int qtdFuga = 0;

  //para aux na logica quando o autodestruir for usado
  int pulaVez=0;

  //aloca estrutura com os 6 pokemons
  tPokemon *pokesBase = inicializaPokesBase();

  fptrAtaque ataque = NULL;

  int op;
  

  //loop infinito ate o adversario ser derrotado  
  do
  {
    //pegar o ultimo da lista e colocar em pokenajogada
    primeiroPoke(j);
    //guardar o endereço do ultimo da lista
    tListapoke *pokeJogador=enderecoPrimeiro(j);
    //o endereço do pokemon da ultima posição da lista(primeiro a jogar)
    tPokemon *primeiroPoke = retornaEndPoke(pokeJogador);
    //imprime mensagem inicial
    ImprimeHp(Ai,pokeJogador,pokesBase);
    imprimeDuelo(arq,Ai,primeiroPoke);
   
    do
    {
      if(pulaVez==0)
      {
        ///////////////Jogador/////////////////////
        //testa se ha dano do cavar para ser aplicado
        testaCavar(Ai);

        if(testaImpedimentoJogador(primeiroPoke,arq,Ai, pokesBase)==0)
        {
          //vez do pokeJogador
          fptrImprimeGolpe funcao=golpe[idPokemon(pokeJogador)];
          //imprime as possibilidades de golpe
          funcao(j);
          //inicializa
          op=20;
          op=validaGolpe(idPokemon(pokeJogador),quantidadePokebolas(j));
        }
        else 
        {
          //jogador não vai jogar
          op=20;
        }        
              
        //se for um ataque específico do pokemon
        if(op < 18)
        {        
          //contabiliza ataque para o fugir
          atualizaAtaque(primeiroPoke);
          //retorna a função de ataque 
          ataque = retornaAtaque(op);
          //aplica o ataque, ou seja, atualiza o hp
          //se o AI nao esta imune
          ataque(Ai, primeiroPoke,arq,numRodada(j),0);
          //printar no arq
          printaHpJogador(Ai,primeiroPoke,arq, pokesBase);
        }
                
        if(op == 18)
        {
          //opção: pokebola 
          printf("Tentativa de Captura\n");             
          atualizaAtaque(primeiroPoke);
      
          //atualiza a quantidade de pokebola
          atualizaPokebola(j,-1);

          float chanceCapt = (float)rand()/(float)(RAND_MAX);
          //Conseguiu capturar
          
            if(chanceCapt <= chanceCapturar(Ai, pokesBase))
            {
              imprimeCaptura(arq,1);
              printf("Sucesso\n");
              atualizaVitoria(j);
              soma10Hp(pokeJogador);
              atualizaBatalhasPB(j);
              atualizaBatalhasMew(j);
              adicionaPokemon(j,idPoke(Ai));
              liberaPokesBase(pokesBase);
              return 2; 
            }               
            else
            {
              //Nao conseguiu
              imprimeCaptura(arq,0);
              printf("Fracasso\n");
            }
        }  
            
        if(op == 19)
        {
          //opção: fuga 
          printf("Tentativa de Fuga\n ");
                      
          qtdFuga++;

          float chanceFugir=0;

            if(jaAtacou(primeiroPoke)>0)
            {
              chanceFugir=1/(float)16.0;
            }
            else
            {
                chanceFugir=qtdFuga/(float)4.0;
            }
            
            float chanceFuga = (float)rand()/(float)(RAND_MAX);
            //Conseguiu fugir
              if(chanceFuga <= chanceFugir)
              {
                printf("Sucesso\n");
                //se nao perdeu recupera 10hp
                 soma10Hp(pokeJogador);
                  imprimeFuga(arq,1); 
                  liberaPokesBase(pokesBase);               
                //terminar batalha
                return 3;            
              }
              else
              {
                //Nao conseguiu fugir
                printf("Fracasso\n");
                imprimeFuga(arq,0);
              }
        }      
        
        printf("pressione enter para continuar\n");
        getchar();

        //verificar por conta do auto Destruir
        if(hpPokemon(pokeJogador)==0)
        {
          pulaVez=1;
        }
      }
      else
      {
        pulaVez=0;
      }
      

      //verificar se morreu o adversario
      if(hpPoke(Ai)==0)
      {
          if(hpPokemon(pokeJogador)==0)
          {          
            //morreram juntos
            //atualiza a quantidade de pokes do pokeJogador
            atualizaQuant(j,-1);
            //se acabou os pokemons encerra a partida 
            if(quant(j)==0)
            {
              perdeu(j,arq);
              printf("Fim de jogo!\n");
              printf("pressione enter para continuar\n");
              getchar();
              liberaPokesBase(pokesBase);
              return 0;
              //acabou o jogo, voltar ao menu
            }
            else
            {
              perdeu(j,arq);
              liberaPokesBase(pokesBase);
              return 4;
            }
          }
          else
          {
            //Ai morre
            soma10Hp(pokeJogador);
            atualizaVitoria(j);
            atualizaBatalhasPB(j);
            atualizaBatalhasMew(j);
            liberaPokesBase(pokesBase);
            return 1;
            //acabou o duelo, nao o jogo
          }
      }

      if(hpPokemon(pokeJogador)==0)
      {          
        //poke do jogador morreu
        //atualiza a quantidade de pokes do pokeJogador
        atualizaQuant(j,-1);
        //se acabou os pokemons encerra a partida 
        if(quant(j)==0)
        {
          perdeu(j,arq);
          printf("Fim de jogo!\n");
          printf("pressione enter para continuar\n");
          getchar();
          liberaPokesBase(pokesBase);
          return 0;
          //acabou o jogo, voltar ao menu
        }
        else
        {
          perdeu(j,arq);
          atualizaRodada(j,1);
          imprimeDuelos(arq,numRodada(j));
          break;
        }
      }
            
      ///////////////AI/////////////////////
      //testa se ha dano do cavar para ser aplicado
      testaCavar(primeiroPoke);
      if(pulaVez==0)
      {
          if(testaImpedimentoAi(primeiroPoke,arq,Ai, pokesBase)==0 )
          {
            op=20;
            //golpe da AI
            op=GolpeAI(idPoke(Ai));
            //retorna a função de ataque 
            ataque = retornaAtaque(op);
            //aplica o ataque, ou seja, atualiza o hp
            ataque(primeiroPoke,Ai,arq,numRodada(j),0);
            //printar no arq
            printaHpAi(Ai,primeiroPoke,arq, pokesBase); 

            printf("pressione enter para continuar\n");
            getchar();

            if(hpPoke(Ai)==0)
            {
              if(hpPokemon(pokeJogador)==0)
              {           
                //morreram juntos
                //atualiza a quantidade de pokes do pokeJogador
                atualizaQuant(j,-1);
                //se acabou os pokemons encerra a partida 
                if(quant(j)==0)
                {
                  perdeu(j,arq);
                  printf("Fim de jogo!\n");
                  printf("pressione enter para continuar\n");
                  getchar();
                  liberaPokesBase(pokesBase);
                  return 0;
                  //acabou o jogo, voltar ao menu
                }
                else
                {
                  perdeu(j,arq);
                  liberaPokesBase(pokesBase);
                  return 4;
                }
              }
              else
              {
                //Ai morre
                soma10Hp(pokeJogador);
                atualizaVitoria(j);
                atualizaBatalhasPB(j);
                atualizaBatalhasMew(j);
                liberaPokesBase(pokesBase);
                return 1;
                //acabou o duelo, nao o jogo
              }   
            }

            //verificar se o jogador morreu
            if(hpPokemon(pokeJogador)==0)
            {
              //zera efeito especial AI
              zeraEspeciais(Ai);
              
              //um poke do jogador morreu
              //atualiza a quantidade de pokes do pokeJogador
              atualizaQuant(j,-1);
              //se acabou os pokemons encerra a partida 
              if(quant(j)==0)
              {
                perdeu(j,arq);
                printf("Fim de jogo!\n");
                printf("pressione enter para continuar\n");
                getchar();
                liberaPokesBase(pokesBase);
                return 0;
                //acabou o jogo, voltar ao menu
              }
              else
              {
              perdeu(j,arq);
              atualizaRodada(j,1);
              imprimeDuelos(arq,numRodada(j));
              }
            }
          }

      }

    }while(hpPokemon(pokeJogador)!=0);
  }while(quant(j)!=0);
  return 10;
}

tHistorico *jogar(tUsuario *j, FILE *arq, int *numPartidas,tHistorico *hist, tTam *tamanho,int semente)
{
  srand(semente);
  inicializaGolpe();
  inicializaAtaques();

  *numPartidas=*numPartidas+1;
  //imprime n arq a partida que vai começar
  imprimePartida(arq,*numPartidas);
  
  //ainda ha poke para jogar
  int proxAcao = -1;
  tPokemon *AI = NULL;
  do
  {
    atualizaRodada(j,1);

    //imprime numero da batalha
    imprimeDuelos(arq,numRodada(j));
    
    // gerando valores aleatórios na faixa de 0 a 5    
    //qual vai ser o pokemon adversário
    int pokeAi = -1;
    if(proxAcao != 4)
    {
       float aleatorioMew = (float)rand()/(float)(RAND_MAX);
        if(aleatorioMew <= retornaBatalhasMew(j)/128.0)
        {
          pokeAi=5;
          zeraBatalhasMew(j);
        }
        else
        {
          pokeAi=rand() % 5; 
        }
      
    //inicializa o pokemon adversário
    AI=copiaPokemon(pokeAi);

    ImprimeMensagemInicial(AI);
    }

    //ate que o Ai morra a batalha é feita aqui
    proxAcao=duelo(AI,j,arq);

    if(AI!=NULL)
    {
      free(AI);
    }

    if(proxAcao==2 || proxAcao==1)
    {
      //se nao perdeu tem chance de ganhar pokebola
      float ganharBola = (float)rand()/(float)(RAND_MAX);
      if(ganharBola <= retornaBatalhasPB(j)/12.0)
      {
       atualizaPokebola(j,1);
       zeraBatalhasPB(j);
       fputs("     Você ganhou uma pokebola\n\n",arq);
       printf("Você ganhou uma pokebola\n\n");
      }

      if(proxAcao==1)
      {
       //se ganhou 
       vitoria(j,arq);
      }           
    }


    
  }while(quant(j)>0);

  system("clear");  

  return fimJogo(j,arq,*numPartidas,hist,tamanho);
}