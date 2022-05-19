#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

/*estrtura Usuario*/
typedef struct tusuario tUsuario;
/*estrutura para historico de pontuação*/
typedef struct thistorico tHistorico;
/*estrutura para informações de alocação do historico*/
typedef struct ttam tTam;

/*
* Recebe o nome e verifica se é valido, caso não seja, lê até que um seja válido e o retorna
*/
void validaNome(tUsuario *j);

/*
* Inicializa e aloca a struct usuario com o jogador da vez e seus pokemons com  ajuda da selecionaPokemons
* Retorna o ponteiro da estrutura alocada
*/
tUsuario *inicializaUsuario(tPokemon *pokesBase);

/*
* Realloca o historico de acordo com um critério de aumento, mantendo os dados anteriores e retornando o novo ponteiro em que foi alocado e liberando o antigo
*/
tHistorico *reallocHistorico(tHistorico *antigo,tTam *tamanho);

/*
* insere os dados de uma partida no historico
*/
tHistorico *preencheHistorico(tUsuario *j,tHistorico *Hist,tTam *tamanho);

/*
* Inicializa uma estrutura dinamica com os dados de lotação do historico
* Retorna o ponteiro da estrutura
*/
tTam *inicializaTam();

/*
* Aloca dinamicamente uma estrutura do tipo tHistorico para ordenar os placares e atualiza os valores de de tamanho de acordo com a estrutura
* Retorna o ponteiro da estrutura alocada
*/
tHistorico *inicializaHistorico(tTam *tamanho);

/*
* Retorna a quantidade de pokemons que o usuario tem
*/
int quant(tUsuario *j);

/*
* Atualiza o numero de pokemons na lista somando o valor atual ao int valor
*/
void atualizaQuant(tUsuario *j, int valor);

/*
* Coloca na variavel da struct usuario "pokenaJogada" o ultimo pokemon da lista com o auxilio da função pokeJogada
*/
void primeiroPoke(tUsuario *j);

/*
* retorna o endereço do pokenaJogada
*/
tListapoke *enderecoPrimeiro(tUsuario *j);

/*
* Retorna a quantidade de pokebolas
*/
int quantidadePokebolas(tUsuario *j);

/*
* Escreve na tela e no arquivo mensagem de vitoria
*/
void vitoria(tUsuario *j, FILE *arq);

/*
* Retorna a posiçao do usuario no placar
*/
int qualPosicao(tHistorico *hist, tUsuario *j, tTam *tamanho);

/*
* Copia dados do historico antigo na posição "i" para o novo na posição "posição"
*/
void copiaHist(tHistorico *antigo,int i, tHistorico *novo, int posicao);

/*
* Aloca uma nova estrutura historico com os mesmos dados da antiga, copia os dados da antiga para a nova de forma ordenada, desaloca a antiga e retorna a nova
*/
tHistorico *ordenaHistorico(tHistorico *hist, tTam *tamanho);

/*
* Coloca o jogador no historico e ordena o historico chamando funções auxiliares, printa na tela e no arquivo a mensagem de final do jogo, e retorna um ponteiro do historico ordenado.
*/
tHistorico *fimJogo(tUsuario *j,FILE *arq, int numPartida,tHistorico *hist, tTam *tamanho);

/*
* Incrementa o numero de pokebolas pela quant
*/
void atualizaPokebola(tUsuario *j,int quant);

/*
* Retorna o endereço do ultimo item da lista alocado
*/
tListapoke *retornaLista(tUsuario *j);

/*
* Soma um ao numero de batalhas vencidas desde a ultima pokebola
*/
void atualizaBatalhasPB(tUsuario *j);

/*
* Soma um a quantidade de vitorias do jogador
*/
void atualizaVitoria(tUsuario *j);

/*
* Retorna a quantidade de vitorias
*/
int retornaVitoria(tUsuario *j);

/*
* Soma um ao numero de batalhas vencidas desde o ultimo mew no AI
*/
void atualizaBatalhasMew(tUsuario *j);

/*
* Zera o numero de vitorias desde o ultimo Ai ser o mew
*/
void zeraBatalhasMew(tUsuario *j);

/*
* Zera o numero de vitorias desde a ultima pokebola
*/
void zeraBatalhasPB(tUsuario *j);

/*
* retorna o numero de vitorias desde a ultima pokebola
*/
int retornaBatalhasPB(tUsuario *j);

/*
* retorna o numero de vitorias desde o ultimo Ai ser o mew
*/
int retornaBatalhasMew(tUsuario *j);

/*
* Incrementa rodada por um valor(rodadas);
*/
void atualizaRodada(tUsuario *j,int rodadas);

/*
* Retorna o numero de rodadas
*/
int  numRodada(tUsuario *j);

/*
* Libera a estrutura alocada tamanho
*/
void liberaTam(tTam *tamanho);

/*
* Libera a estrutura alocada historico
*/
void liberaHistorico(tHistorico *hist);

/*
* Libera a estrutura alocada usuario
*/
void liberaUsuario(tUsuario *j);

/*
* Imprime e grava no arquivo a mensagem que o jogador perdeu o duelo
*/
void perdeu(tUsuario *j,FILE *arq);

/*
* Se não tiver tido partidas imprime "Ainda não há ranking a ser exibido", caso contrário imprime o ranking
*/
void placar(int partidas, tHistorico *hist, tTam *tamanho);

/*
* salva no arq o placar de pontuações 
*/
void salvaPlacar(tHistorico *hist, tTam *tamanho,FILE *arq);

/*
* Adiciona um pokemon na lista e incrementa o numero de pokemons do jogador
*/
void adicionaPokemon(tUsuario *j, int poke);

#endif