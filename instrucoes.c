//Incluindo o arquivo de cabeçalho
#include "instrucoes.h"
#include <stdio.h>
//Configurando as instruções a serem utilizadas

void hlt(){
    printf("Programa Finalizado.\n")
}

void nop(){
    if(lr == 1){
        pc++;
    }
    printf("O valor de pc após o nop: %d\n",pc);
}

void add(){
    a += b;
    printf("O valor de A após o add: %d\n",a);
}
void sub(){
    a -= b;
    printf("O valor de A após o sub: %d\n",a);
}
void mul(){
    a *= b;
    printf("O valor de A após o mul: %d\n",a);
}
void div(){
    a /= b;
    printf("O valor de A após o div: %d\n",a);
}

void cmp(){
    if(a == b){
        e = 1;
        l = 0;
        g = 0;
    } else if(a < b){
        l = 1;
        e = 0;
        g = 0
    } else {
        g = 1;
        e = 0;
        l = 0;
    }
    printf("o valor dos registradores internos são: E = %d\t L = %d\t G = %d\n",e,l,g);
}
void xchg(){
    t = a;
    a = b;
    b = t;
    printf("A = %d\t B = %d\t T = %d\n",a,b,t);
}

void land(){
    a = a & b;
    printf("O valor de A após o and: A = %d\n",a);
}
void lor(){
    a = a | b;
    printf("O valor de A após o or: A = %d\n",a);
}
void lxor(){
    a = a ^ b;
    printf("O valor de A após o xor: A = %d\n",a);
}
void lnor(){
    a = !a;
    printf("O valor de A após o not: A = %d\n",a);
}

void je(int endereco){
    if(e == 1){
        pc = endereco;
    }
    printf("pc após o je: %d\n",pc);
}
void jne(int endereco){
    if(e == 0){
        pc = endereco;
    }
    printf("pc após o jne: %d\n",pc);
}
void jl(int endereco){
    if(l == 1){
        pc = endereco;
    }
    printf("pc após o jl: %d\n",pc);
}
void jle(int endereco){
    if(l == 1 || e == 1){
        pc = endereco;
    }
    printf("pc após o jle: %d\n",pc);
}
void jg(int endereco){
    if(g == 1){
        pc = endereco;
    }
    printf("pc após o jg: %d\n",pc);
}
void jge(int endereco){
    if(g == 1 || e == 1){
        pc = endereco;
    }
    printf("pc após o jge: %d\n",pc);
}
void jmp(int endereco){
    pc = endereco;
    printf("pc após o jmp: %d\n",pc);
}

void lda(int mar){
    a = memoria[mar];
    printf("O valor de a é: %x\n",a);
}
void ldb(int mar){
    b = memoria[mar];
    printf("O valor de b é: %x\n",b);
}
void ldrb(int mar){
    a = b;
    printf("O valor de a é: %x\n",a);
}

void sta(int mar){
    memoria[mar] = a;
    printf("a memória recebeu o valor: %x\n",memoria[mar]);
}
void stb(int mar){
    memoria[mar] = b;
    printf("a memória recebeu o valor: %x\n",memoria[mar]);
}

void movial(){
    a = 0x0;
    a = a << 8;
    a += imm;
    printf("A = %x\n",a);
}
void moviah(){
    a = a & 0x00FF;
    a += imm;
    printf("A = %x\n",a);
}

void addia(){
    a += imm;
    printf("A = %x\n",a);
}
void subia(){
    a -= imm;
    printf("A = %x\n",a);
}
void mulia(){
    a *= imm;
    printf("A = %x\n",a);
}
void divia(){
    a /= imm;
    printf("A = %x\n",a);
}

void lsh(){
    a = a << imm;
    printf("A = %x\n",a);
}
void rsh(){
    a = a >> imm;
    printf("A = %x\n",a);
}
