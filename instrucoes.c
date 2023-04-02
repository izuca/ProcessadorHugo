//Incluindo o arquivo de cabeçalho
#include "instrucoes.h"
#include <stdio.h>
//Configurando as instruções a serem utilizadas

void hlt(){
    printf("Programa Finalizado.\n");
}

void nop(unsigned short int pc, unsigned char lr){
    if(lr == 1){
        pc++;
    }
    printf("O valor de pc após o nop: %d\n",pc);
}

void add(unsigned short int a, unsigned short int b){
    a += b;
    printf("O valor de A após o add: %d\n",a);
}
void sub(unsigned short int a, unsigned short int b){
    a -= b;
    printf("O valor de A após o sub: %d\n",a);
}
void mul(unsigned short int a, unsigned short int b){
    a *= b;
    printf("O valor de A após o mul: %d\n",a);
}
void div(unsigned short int a, unsigned short int b){
    a /= b;
    printf("O valor de A após o div: %d\n",a);
}

void cmp(unsigned short int a, unsigned short int b, unsigned char e, unsigned char l, unsigned char g ){
    if(a == b){
        e = '1';
        l = '0';
        g = '0';
    } else if(a < b){
        l = '1';
        e = '0';
        g = '0';
    } else {
        g = '1';
        e = '0';
        l = '0';
    }
    printf("o valor dos registradores internos são: E = %c\t L = %c\t G = %c\n",e,l,g);
}
void xchg(unsigned short int a, unsigned short int b, unsigned short int t){
    t = a;
    a = b;
    b = t;
    printf("A = %d\t B = %d\t T = %d\n",a,b,t);
}

void land(unsigned short int a, unsigned short int b){
    a = a & b;
    printf("O valor de A após o and: A = %d\n",a);
}
void lor(unsigned short int a, unsigned short int b){
    a = a | b;
    printf("O valor de A após o or: A = %d\n",a);
}
void lxor(unsigned short int a, unsigned short int b){
    a = a ^ b;
    printf("O valor de A após o xor: A = %d\n",a);
}
void lnor(unsigned short int a){
    a = !a;
    printf("O valor de A após o not: A = %d\n",a);
}

void je(int endereco, unsigned short int pc, unsigned char e){
    if(e == '1'){
        pc = endereco;
    }
    printf("pc após o je: %d\n",pc);
}
void jne(int endereco, unsigned short int pc, unsigned char e){
    if(e == '0'){
        pc = endereco;
    }
    printf("pc após o jne: %d\n",pc);
}
void jl(int endereco, unsigned char l, unsigned short int pc){
    if(l == '1'){
        pc = endereco;
    }
    printf("pc após o jl: %d\n",pc);
}
void jle(int endereco, unsigned char l, unsigned char e, unsigned short int pc){
    if(l == '1' || e == '1'){
        pc = endereco;
    }
    printf("pc após o jle: %d\n",pc);
}
void jg(int endereco, unsigned char g, unsigned short int pc){
    if(g == 1){
        pc = endereco;
    }
    printf("pc após o jg: %d\n",pc);
}
void jge(int endereco, unsigned char g, unsigned char e, unsigned short int pc){
    if(g == 1 || e == 1){
        pc = endereco;
    }
    printf("pc após o jge: %d\n",pc);
}
void jmp(int endereco, unsigned short int pc){
    pc = endereco;
    printf("pc após o jmp: %d\n",pc);
}

void lda(unsigned short int mar, unsigned short int a, unsigned char memoria[]){
    a = memoria[mar];
    printf("O valor de a é: %x\n",a);
}
void ldb(unsigned short int mar, unsigned short int b, unsigned char memoria[]){
    b = memoria[mar];
    printf("O valor de b é: %x\n",b);
}
void ldrb(unsigned short int mar, unsigned short int a, unsigned short int b){
    a = b;
    printf("O valor de a é: %x\n",a);
}

void sta(unsigned short int mar, unsigned char memoria[], unsigned short int a){
    memoria[mar] = a;
    printf("a memória recebeu o valor: %x\n",memoria[mar]);
}
void stb(unsigned short int mar, unsigned char memoria[], unsigned short int b){
    memoria[mar] = b;
    printf("a memória recebeu o valor: %x\n",memoria[mar]);
}

void movial(unsigned short int a, unsigned short int imm){
    a = 0x0;
    a = a << 8;
    a += imm;
    printf("A = %x\n",a);
}
void moviah(unsigned short int a, unsigned short int imm){
    a = a & 0x00FF;
    a += imm;
    printf("A = %x\n",a);
}

void addia(unsigned short int a, unsigned short int imm){
    a += imm;
    printf("A = %x\n",a);
}
void subia(unsigned short int a, unsigned short int imm){
    a -= imm;
    printf("A = %x\n",a);
}
void mulia(unsigned short int a, unsigned short int imm){
    a *= imm;
    printf("A = %x\n",a);
}
void divia(unsigned short int a, unsigned short int imm){
    a /= imm;
    printf("A = %x\n",a);
}

void lsh(unsigned short int a, unsigned short int imm){
    a = a << imm;
    printf("A = %x\n",a);
}
void rsh(unsigned short int a, unsigned short int imm){
    a = a >> imm;
    printf("A = %x\n",a);
}
