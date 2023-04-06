//gcc main.c instrucoes.c  -o programa
#include <stdio.h>
#include <string.h>
#include "instrucoes.h"


//Declarando variáveis
unsigned int mbr;
unsigned short int mar, ibr, imm, pc, a, b, t;
unsigned char ir,lr,e,l,g,memoria[154];

//Variáveis do leitor de arquivo
FILE *instructions;

//inst vai armazenar cada linha do arquivo de texto
char buffer[1024], inst[30][50]; 
char*token;


//Funções

void lerArquivo(){
    int count = 0;
    instructions = fopen("instrucoes.txt","rt");

    if(instructions == NULL){
        printf("Erro ao ler arquivo de texto\n");
    }

    while(fgets(buffer, sizeof(buffer), instructions) != NULL){
        strcpy(inst[count],buffer);
        count++;
    }
    
    for(int i = 0; i < 30; i++){
        if(strlen(inst[i]) == 0){
            printf("\nLinha vazia, saindo da funcao...\n");
            break;
        } else{
            printf("%s",inst[i]);
            // token = strtok(inst[i],";");
            // int readcounter = 0;
            // while(token != NULL){
            //     printf("O token e: %s\n", token);
            //     if(readcounter == 2)
            //         token = strtok(NULL,"/");
            //     else
            //         token = strtok(NULL,";");
            //     readcounter++;
            // }
            // 0 - Pos Memoria
            // 1 - instrucao/dado
            // 2 - instrução 1 e 2/dado
        }

    }

    //Testando a strtok()
    token = strtok(inst[0],";");
    char teste[30][50];
    int readcounter = 0;
    
    while(token != NULL){
        strcpy(teste[readcounter],token);
        printf("%s\n",teste[readcounter]);
        
        if(readcounter == 2 && strcmp(teste[1],"i") == 0){
            printf("Entrei\n");
            token = strtok(token,"/");
            
            while(readcounter < 4){
                strcpy(teste[readcounter],token);
                token = strtok(NULL,"/");
                readcounter++;
            }
              
            break;
        }
        token = strtok(NULL,";");
        readcounter++;
    }
    
    printf("%d",readcounter);
    
    printf("\nTestando...\n");
    printf("%s %s %s %s\n",teste[0],teste[1],teste[2],teste[3]);
    // faz o readcounter ir até 3(lda 96/ldb 98) daí reinicia o processo a partir das intrucoes...
    //printf("%s\n",inst[2]);
    fclose(instructions);
}



void busca(){
    //MAR recebe a posição de PC para buscar a instrução(Talvez tenha que alterar isso)
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
    lerArquivo();
    busca();
    printf("O valor do mbr após o busca é: %x\n",mbr);
    decodifica();
    

}

