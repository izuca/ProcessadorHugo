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

    //1001 1000 0000 1100 1010 0000 0000 1110  | lda C ldb E
    memoria[1] = "10011000";
    memoria[2] = "00001100";
    memoria[3] = "10100000";
    memoria[4] = "00001110";
    hello();

}

