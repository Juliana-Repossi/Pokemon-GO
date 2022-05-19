#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/*
* Estrutura que representa um pokemon. Armazena os status e as características pertencentes ao pokemon.
*/
typedef struct tpokemon tPokemon;

/*
* Estrutura de lista para armazenar os pokemons.
*/
typedef struct tlistapoke tListapoke;

/*
* Tipo função de ponteiro para as funções de inicialização de pokemons.
*/
typedef void(*fptrInicializaPoke)(tPokemon *);

/*
* Tipo função de ponteiro para as funções de ataque.
*/
typedef void (*fptrAtaqueMetronomo)(tPokemon *, tPokemon *,FILE *,int , int);

/*
* Inicializa o vetor de interações do pikachu. As posições do vetor estão definidas de acordo com o id do pokemon que está se defendendo do ataque do pikachu.
*/
void interacoesPikachu(tPokemon *poke);

/*
* Inicializa o vetor de interações do charizard. As posições do vetor estão definidas de acordo com o id do pokemon que está se defendendo do ataque do charizard.
*/
void interacoesCharizard(tPokemon *poke);

/*
* Inicializa o vetor de interações do blastoise. As posições do vetor estão definidas de acordo com o id do pokemon que está se defendendo do ataque do blastoise.
*/
void interacoesBlastoise(tPokemon *poke);

/*
* Inicializa o vetor de interações do venusaur. As posições do vetor estão definidas de acordo com o id do pokemon que está se defendendo do ataque do venusaur.
*/
void interacoesVenusaur(tPokemon *poke);

/*
* Inicializa o vetor de interações do steelix. As posições do vetor estão definidas de acordo com o id do pokemon que está se defendendo do ataque do steelix.
*/
void interacoesSteelix(tPokemon *poke);

/*
* Inicializa o vetor de interações do mew. As posições do vetor estão definidas de acordo com o id do pokemon que está se defendendo do ataque do mew.
*/
void interacoesMew(tPokemon *poke);

/*
* Inicializa as informações do pikachu em uma estrutura de pokemon.
*/
void inicializaPikachu(tPokemon *poke);

/*
* Inicializa as informações do charizard em uma estrutura de pokemon.
*/
void inicializaCharizard(tPokemon *poke);

/*
* Inicializa as informações do blastoise em uma estrutura de pokemon.
*/
void inicializaBlastoise(tPokemon *poke);

/*
* Inicializa as informações do venusaur em uma estrutura de pokemon.
*/
void inicializaVenusaur(tPokemon *poke);

/*
* Inicializa as informações do steelix em uma estrutura de pokemon.
*/
void inicializaSteelix(tPokemon *poke);

/*
* Inicializa as informações do mew em uma estrutura de pokemon.
*/
void inicializaMew(tPokemon *poke);

/*
* Inicializa a tabela de dispersão das funções que inicializam os pokemons.
*/
void inicializaFptrPoke();

/*
* Inicializa uma estrutura dinamica com todos os tipos de pokemon
* Retorna um ponteiro da estrutura alocada
*/
tPokemon *inicializaPokesBase();

/*
* Imprime na tela os pokemons ainda não escolhidos pelo usuario 
* int *escolhido: array com as ids dos pokemons já escolhidos;
*/
void listaPokemon(int *escolhido,tPokemon *pokesBase);

/*
* Aloca uma estrutura do tipo tPokemon e inicaliza o mesmo de acordo com o id(int poke) passado
* retorna o endereço que ele foi alocado
*/
tPokemon *copiaPokemon(int poke);

/*
* Aloca pokemons em lista
* recebe o endereço do ultimo alocado e o id do pokemon a ser alocado
* retorna o endereço que o novo item da lista foi alocado
*/
tListapoke *inserePokemon(tListapoke *lista, int pok);

/*
* Transforma a opção digitada pelo usuario para escolher os pokemons  disponiveis, na id dos pokemons
*/
static int adequaPosicao(int quantEscolhido, int *escolhido);

/*
* Faz a gerencia dos menus com as opçoes de pokemons, recebe opções validas escolhidas e alloca em lista (com auxilio de outras funções)
* retorna o endereço do ultimo pokemon alocado na lista 
*/
tListapoke *selecionaPokemons(tPokemon *pokesBase, tListapoke *PokenaJogada, int *numPokes, int *numBolas);

/*
* Retorna o endereço do ultimo pokemon da lista, que vai ser o pokemon da vez
*/
tListapoke *pokeJogada(tListapoke *lista,int tamLista);

/*
* Libera o primeiro pokemon da lista.
*/
void liberaPoke(tListapoke *lista,int tamLista);

/*
* Imprime a mensagem do inicio do duelo sobre o Ai sorteado
*/
void ImprimeMensagemInicial(tPokemon *Ai);

/*
* Imprime o hp dos pokemons Ai e o contido na lista.
*/
void ImprimeHp(tPokemon *Ai,tListapoke *lista, tPokemon *pokesBase);

/*
* Retorna o id do pokemon inserido na lista.
*/
int idPokemon(tListapoke *p);

/*
* Retorna o id do pokemon da estrutura.
*/
int idPoke(tPokemon *p);

/*
* Retorna o hp do pokemon inserido na lista.
*/
float hpPokemon(tListapoke *p);

/*
* Retorna o hp do pokemon na estrutura.
*/
float hpPoke(tPokemon *p);

/*
* Reseta os status especiais do pokemon.
*/
void zeraEspeciais(tPokemon *p);

/*
* Soma 10 de hp ao pokemon inserido na lista e reseta os status especiais.
*/
void soma10Hp(tListapoke *p);

/*
* Printa no arquivo e no console o hp dos pokemons, com o dano do queimar no jogador se está queimando.
*/
void printaHpJogador(tPokemon *Ai,tPokemon *j,FILE *arq, tPokemon *pokesBase);

/*
* Printa no arquivo e no console o hp dos pokemons, com o dano do queimar no Ai se está queimando.
*/
void printaHpAi(tPokemon *Ai,tPokemon *j,FILE *arq, tPokemon *pokesBase);

/*
* Função responsável por realizar a funcionalidade do ataque choque de trovão.
*/
void choqueDoTrovao(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque onda de choque.
*/
void ondaDeChoque(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque bater.
*/
void bater(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque lança chamas.
*/
void lancaChamas(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque dormir.
*/
void dormir(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque arma de água.
*/
void armaDeAgua(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque proteger.
*/
void proteger(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque pó de sono.
*/
void poDeSono(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque bomba de semente.
*/
void bombaDeSemente(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque dois gumes.
*/
void doisGumes(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque rabo de ferro.
*/
void raboDeFerro(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque cavar.
*/
void cavar(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque metronomo.
*/
void metronomo(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Função responsável por realizar a funcionalidade do ataque auto-destruir..
*/
void autoDestruir(tPokemon *defensor, tPokemon *atacante,FILE *arq,int rodada,int metronomo);

/*
* Calcula a chance de capturar um pokemon.
*/
float chanceCapturar(tPokemon *AI, tPokemon *pokesBase);

/*
* Retorna o endereço do pokemon inserido na lista.
*/
tPokemon *retornaEndPoke(tListapoke *lista);

/*
* Retorna o nome do pokemon.
*/
char *retornaNome(tPokemon *p);

/*
* Verifica se há algo que impeça o ataque do jogador.
*/
int testaImpedimentoJogador(tPokemon *p,FILE *arq,tPokemon *Ai, tPokemon *pokesBase);

/*
* Verifica se há algo que impeça o ataque do Ai.
*/
int testaImpedimentoAi(tPokemon *p,FILE *arq,tPokemon *Ai, tPokemon *pokesBase);

/*
* Adiciona um na variável jaAtacou da estrutura do pokemon.
*/
void atualizaAtaque(tPokemon *p);

/*
* Retorna o valor da variavel jaAtacou da estrutura do pokemon.
*/
int jaAtacou(tPokemon *p);

/*
* Libera o ponteiro do vetor de pokemons base.
*/
void liberaPokesBase(tPokemon *pokes);

/*
* Printa os status do pokemon no arquivo.
*/
int printaStatusArquivo(tPokemon *poke, FILE *arq);

/*
* Verifica se há dano do cavar para ser aplicado e aplica esse dano.
*/
void testaCavar(tPokemon *p);

/*
* Aplica o dano do status queimar no pokemon.
*/
void danoQueimar(tPokemon *poke, tPokemon *pokesBase);

/*
* Printa os status do pokemon no console.
*/
void printaStatusConsole(tPokemon *poke);

/*
* Libera a lista de pokemons da memória.
*/
void liberaLista(tListapoke *lista);

#endif