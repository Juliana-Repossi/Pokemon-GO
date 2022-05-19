#ifndef BATALHA_H
#define BATALHA_H

#include <stdlib.h>
#include <stdio.h>
//que de quebra inclui a pokemon
#include "usuario.h"

/*
* Define o ponteiro de função para as funções que imprimem os golpes disponíveis.
*/
typedef void (*fptrImprimeGolpe)(tUsuario *);

/*
* Define o ponteiro de funções de ataques dos pokemons.
*/
typedef void (*fptrAtaque)(tPokemon *, tPokemon *,FILE *,int ,int );

/*
* Imprime o numero da partida no arquivo
*/
void imprimePartida(FILE *arq,int n);

/*
* Imprime o numero de batalhas/duelos no arquivo
*/
void imprimeDuelos(FILE *arq,int n);

/*
* Imprime a mensagem de quais dois pokemons estão no duelo
*/
void imprimeDuelo(FILE *arq,tPokemon *Ai, tPokemon *j);

/*
* Imprme que houve tentativa de captura e caso o n=1, com sucesso e n=0, fracasso 
*/
void imprimeCaptura(FILE *arq,int n);

/*
* Imprme que houve tentativa de fuga e caso o n=1, com sucesso e n=0, fracasso 
*/
void imprimeFuga(FILE *arq,int n);

/*menu de golpes disponiveis para o Pikachu */
void imprimePikachu(tUsuario *j);

/*menu de golpes disponiveis para o Charizard */
void imprimeCharizard(tUsuario *j);

/*menu de golpes disponiveis para o Blastoise */
void imprimeBlastoise(tUsuario *j);

/*menu de golpes disponiveis para o Venusaur */
void imprimeVenusaur(tUsuario *j);

/*menu de golpes disponiveis para o Steelix */
void imprimeSteelix(tUsuario *j);

/*menu de golpes disponiveis para o Mew */
void imprimeMew(tUsuario *j);

/*
* Inicializa o array de ponteiro de função que vai printar o respectivo menu de opção de golpes de cada pokemon 
*/
void inicializaGolpe();

/*
* Filtra a entrada de ataque escolhida e coloca a mesma de acordo com a logica criada pelo array ataque explicado no README
*/
int validaGolpe();

/*
* Sorteia o golpe AI e coloca o mesmo de acordo com a logica criada pelo array ataque explicado no README
*/
int GolpeAI(int idPoke);

/*
* Inicializa o array de ponteiro de função que vai chamar o respectivo ataque escolhido pelo pokemon para aplicar dano ao adversário 
*/
void inicializaAtaques();

fptrAtaque retornaAtaque(int id);

/*
* Faz todo o tratamento do duelo, até que o AI morra, ou o jogo acabe.
  //return 4: os dois morreram
  //return 3 : fugiu
  //return 2 : capturou pokemon
  //return 1 : ganhou duelo
  //return 0 : perdeu
*/
int duelo(tPokemon *Ai,tUsuario *j, FILE *arq);

/*
* Faz todo  tratamento da partida, sorteando um AI, chamando a duelo, até que a partida termine e as informações sejam salvas;
*/
tHistorico *jogar(tUsuario *j, FILE *arq, int *numPartidas, tHistorico *hist,tTam *tamanho,int semente);


#endif