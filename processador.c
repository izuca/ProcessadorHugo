//gcc processador.c instrucoes.c -o programa
#include <stdio.h>
#include "instrucoes.h"

// Função main
int main (){
    
    //Declarando variáveis
    unsigned int mbr;
    unsigned short int mar, ibr, imm, pc, a, b, t;
    unsigned char ir,e,l,g,memoria[154];
    
    //testando ...
    memoria[1] = "10011000";
    memoria[2] = "10011000";
    hello();

}

