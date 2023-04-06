//gcc main.c instrucoes.c  -o programa
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
    token = strtok(inst[2],";");
    char teste[30][50];
    int readcounter = 0;
    int instype = 0;

    while(token != NULL){
        strcpy(teste[readcounter],token);
        
        if(readcounter == 2 && strcmp(teste[1],"i") == 0){
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
    
    char instrucoes [13][40];
    strcpy(instrucoes[0],"hlt");
    strcpy(instrucoes[1], "nop");
    strcpy(instrucoes[2], "add");
    strcpy(instrucoes[3], "sub");
    strcpy(instrucoes[4], "mul");
    strcpy(instrucoes[5], "div");
    strcpy(instrucoes[6], "cmp");
    strcpy(instrucoes[7], "xchg");
    strcpy(instrucoes[8], "and");
    strcpy(instrucoes[9], "or");
    strcpy(instrucoes[10], "xor");
    strcpy(instrucoes[11], "not");
    strcpy(instrucoes[12], "ldrb");
    // Parei aqui
    // - - - - - - - - - - - - -
    //Agora que consigo identificar o caso, basta fazer o mesmo pro teste[2] e seguir o uso sem usar o strtoken( , " ")
    for (int i = 0;i < 13; i++){
        if(strcmp(instrucoes[i],teste[2]) == 0){
            instype++;
            break;
        }else if (i == 12 && strcmp(instrucoes[i],teste[2]) != 0)
            printf("A instrução não se encaixa");
    }
    
    // Na última parte, inserir o \n, se não o strcmp não passará
    for (int i = 0;i < 13; i++){
        if(strcmp(strcat(instrucoes[i],"\n"),teste[3]) == 0){
            instype = instype + 3;
            break;
        }else if (i == 12 && strcmp(instrucoes[i],teste[3]) != 0)
            printf("A instrucao nao se encaixa\n");
    }
    
    // Analisando o tipo de instrução
    switch (instype){
        //AMBAS inst precisem de endereço
        case 0:
            char insAndAdd [4][50];

            token = strtok(teste[2]," ");
            strcpy(insAndAdd[0],token);
            token = strtok(NULL," ");
            strcpy(insAndAdd[1],token);
            
            token = strtok(teste[3]," ");
            strcpy(insAndAdd[2],token);
            token = strtok(NULL," ");
            strcpy(insAndAdd[3],token);

            for(int i = 0; i < 4;i++){
                strcpy(teste[i+2],insAndAdd[i]);
                printf("%s\n",teste[i+2]);
            }
        break;

        //Apenas a segunda instrução irá utilizar end.
        case 1:
            
            token = strtok(teste[3]," ");
            strcpy(insAndAdd[0], token);
            token = strtok(NULL," ");
            strcpy(insAndAdd[1],token);

            for(int i = 0;i < 2; i++){
                strcpy(teste[i+3],insAndAdd[i]);
                printf("%s\n",teste[i+2]);
            }
        break;
        
        // Caso nenhuma precise utilizar end
        default:
            printf("Prontin");
        break;
    }
    
    printf("\nTestando...\n");

    printf("%s %s %s %s %s %s\n",teste[0],teste[1],teste[2],teste[3], teste[4],teste[5]);
    // printf("%s e %s %s e %s\n",insAndAdd[0],insAndAdd[1],insAndAdd[2],insAndAdd[3]);
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

