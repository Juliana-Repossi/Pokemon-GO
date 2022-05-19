#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "batalha.h"

/*
* Valida a operação do menu principal, e retorna a mesma valida
*/
char validaOp1();

/*
* Printa o primeiro menu e usa a validaOp1 para retornar uma operação 
*/
char menuPrincipal();

#endif