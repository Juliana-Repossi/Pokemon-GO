# Trabalho Prático  II - TEP - Pokemon
Prof. Vinicíus Mota 
DI/UFES

Alunos: 
  - Juliana Repossi - 2020100631
  - Christian Junji - 2020100735

## Considerações

- Criamos uma lógica para organizar o array de ataques, em que cada pokemon, na ordem que aparece na especificação do trabalho, ficaria com três posiçoes  e cada uma delas seria um ataque (também na ordem da especificação). Dessa forma, o array ficaria da forma que foi feito na "void inicializaAtaques()" e a relação entre id e numero digitado pelo usuario "idPoke*3+op" levaria ao golpe escolhido pelo jogador.

- A opção capturar com uma pokebola e fugir tiveram tratamento separado fora do array para simplificar, já que é válida para todos os pokemons independentemente do id;



## Bibliotecas
Decidimos por separar as funções em 5 bibliotecas, da forma mais modularizada possivel, com o objetivo de atender às regras de implementação de TADs.
### batalha.h:
Reúne as duas funções mais importantes: a jogar e a duelo.Elas contém a dinâmica piloto do jogo, chamando funções de outras TADs para desempenhar a lógica do programa. Além delas tem funções auxiliares de imprimir no arquivo informações da batalha e validar entradas, por exemplo.

### pokemon.h:
Biblioteca responsável por manipular os pokemons, desde ataques, frees, alocações, alteração e verificação de status, etc. Define, também os tipos necessários para a manipulação dos pokemons em lista.

### menu.h:
Responsável por printar o menu principal e fazer o tratamento da entrada.

### usuario.h:
Faz o tratamento dos componentes da struct usuario, do histórico e do tam. Inicializando, alocando,alterando, retornando valores ou liberando as suas estruturas alocadas.

### utils.h:
Biblioteca que reúne as funções utilitárias que não se encaixariam em outras bibliotecas.

