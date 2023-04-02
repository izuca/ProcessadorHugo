//gcc processador.c instrucoes.c -o programa
#include <stdio.h>
#include "instrucoes.h"

//Declarando variáveis
unsigned int mbr;
unsigned short int mar, ibr, imm, pc, a, b, t;
unsigned char ir,lr,e,l,g,memoria[154];


void busca(){
    //MAR recebe a posição de PC para buscar a instrução
    mar = pc;
    
    //Loop para mbr receber mar das demais instruções
    for(int i = 0; i < 4; i++){
        mbr += memoria[mar+i];
        if(i != 3)
            mbr = mbr << 8;
        pc++; 
    }
}

void decodifica(){
    unsigned int inst1,inst2;
    
    inst1 = mbr >> 16;
    inst2 = mbr & 0x0000FFFF;
    ibr = inst2;
    ir = inst1 >> 8;
    mar = inst1 & 0x00FF;
    imm = mar;
    lr = 0;

    printf("ibr: %x\n",ibr);
    printf("ir: %x\n",ir);
    printf("mar: %x\n",mar);
    printf("imm: %x\n",imm);
    printf("lr: %x\n",lr);
    printf("pc: %d\n",pc);
}

void executa(){

}

// Função main
int main (){
    pc = 0;
    mbr = 0;
    //testando ...

    //1001 1000 0000 1100 1010 0000 0000 1110  | lda C ldb E
    
    memoria[0x00] = 0x98;
    memoria[0x01] = 0xC;
    memoria[0x02] = 0xA0;
    memoria[0x03] = 0xE;
    
    busca();
    printf("O valor do mbr após o busca é: %x\n",mbr);
    decodifica();
    

}

