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

void dictionaryIterator(char dictionary[][40], char comparado[][50], int compPos){
    for (int i = 0;i < 32; i++){
                if(strcmp(dictionary[i],comparado[compPos]) == 0){
                    switch (i)
                    {
                    case 0: //hlt
                        strcpy(comparado[compPos],"0x00");
                        break;

                    case 1: //nop
                        strcpy(comparado[compPos],"0x01");
                        break;

                    case 2: //add
                        strcpy(comparado[compPos],"0x02");
                        break;
                    
                    case 3: //sub
                        strcpy(comparado[compPos],"0x03");
                        break;
                    
                    case 4: //mul
                        strcpy(comparado[compPos],"0x04");
                        break;

                    case 5: //div
                        strcpy(comparado[compPos],"0x05");
                        break;

                    case 6: //cmp
                        strcpy(comparado[compPos],"0x06");
                        break;

                    case 7: //xchg
                        strcpy(comparado[compPos],"0x07");
                        break;

                    case 8: //and
                        strcpy(comparado[compPos],"0x08");
                        break;

                    case 9: //or
                        strcpy(comparado[compPos],"0x09");
                        break;

                    case 10: //xor
                        strcpy(comparado[compPos],"0x0A");
                        break;

                    case 11: //not
                        strcpy(comparado[compPos],"0x0B");
                        break;

                    case 12: //ldrb
                        strcpy(comparado[compPos],"0x17");
                        break;

                    case 13: //je
                        strcpy(comparado[compPos],"0x0C");
                        break;

                    case 14: //jne
                        strcpy(comparado[compPos],"0x0D");
                        break;

                    case 15: //jl
                        strcpy(comparado[compPos],"0x0E");
                        break;

                    case 16: //jle
                        strcpy(comparado[compPos],"0x0F");
                        break;

                    case 17: //jg
                        strcpy(comparado[compPos],"0x10");
                        break;

                    case 18: //jge
                        strcpy(comparado[compPos],"0x11");
                        break;

                    case 19: //jmp
                        strcpy(comparado[compPos],"0x12");
                        break;

                    case 20: //lda
                        strcpy(comparado[compPos],"0x13");
                        break;

                    case 21: //ldb
                        strcpy(comparado[compPos],"0x14");
                        break;

                    case 22: //sta
                        strcpy(comparado[compPos],"0x15");
                        break;

                    case 23: //stb
                        strcpy(comparado[compPos],"0x16");
                        break;

                    case 24: //movial
                        strcpy(comparado[compPos],"0x18");
                        break;

                    case 25: //moviah
                        strcpy(comparado[compPos],"0x19");
                        break; 

                    case 26: //addia
                        strcpy(comparado[compPos],"0x1A");
                        break;
                    
                    case 27: //subia
                        strcpy(comparado[compPos],"0x1B");
                        break;
                    
                    case 28: //mulia
                        strcpy(comparado[compPos],"0x1C");
                        break;
                    
                    case 29: //divia
                        strcpy(comparado[compPos],"0x1D");
                        break;
                    
                    case 30: //lsh
                        strcpy(comparado[compPos],"0x1E");
                        break;
                    
                    case 31: //rsh
                        strcpy(comparado[compPos],"0x1F");
                        break;

                    default:
                        printf("Erro na checagem do opcode");
                        break;
                    }
                    break;
                }
            }
}

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
    token = strtok(inst[1],";");
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
    
    char instrucoes[32][40];
    strcpy(instrucoes[0], "hlt");
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

    //Instruções que requerem endereço ou imediato
    strcpy(instrucoes[13], "je");
    strcpy(instrucoes[14], "jne");
    strcpy(instrucoes[15], "jl");
    strcpy(instrucoes[16], "jle");
    strcpy(instrucoes[17], "jg");
    strcpy(instrucoes[18], "jge");
    strcpy(instrucoes[19], "jmp");
    strcpy(instrucoes[20], "lda");
    strcpy(instrucoes[21], "ldb");
    strcpy(instrucoes[22], "sta");
    strcpy(instrucoes[23], "stb");
    strcpy(instrucoes[24], "movial");
    strcpy(instrucoes[25], "moviah");
    strcpy(instrucoes[26], "addia");
    strcpy(instrucoes[27], "subia");
    strcpy(instrucoes[28], "mulia");
    strcpy(instrucoes[29], "divia");
    strcpy(instrucoes[30], "lsh");
    strcpy(instrucoes[31], "rsh");

    for (int i = 0;i < 13; i++){
        //Se a instrução da esquerda não precisar de End. Mem ou IMM...
        if(strcmp(instrucoes[i],teste[2]) == 0){
            instype++;
            break;
        }else if (i == 12 && strcmp(instrucoes[i],teste[2]) != 0)
            printf("A instrucao nao se encaixa\n");
    }
    
    // Na última parte, inserir o \n, se não o strcmp não passará
    for (int i = 0;i < 13; i++){
        //Se a instrução da direita não precisar de End. Mem ou IMM...
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
            printf("Caso 0\n");
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

            // Colocar a função iteradora do dicionario aqui
            dictionaryIterator(instrucoes, teste, 2);
            dictionaryIterator(instrucoes, teste, 4);
            
        break;

        //Apenas a segunda instrução irá utilizar end.
        case 1:
            printf("Caso 1\n");
            token = strtok(teste[3]," ");
            strcpy(insAndAdd[0], token);
            token = strtok(NULL," ");
            strcpy(insAndAdd[1],token);

            for(int i = 0;i < 2; i++){
                strcpy(teste[i+3],insAndAdd[i]);
                printf("%s\n",teste[i+2]);
            }
            dictionaryIterator(instrucoes,teste,3);            
        break;
        //So vai ter endereço no primeiro
        case 3:
            printf("Caso 3\n");
            token = strtok(teste[2]," ");
            strcpy(insAndAdd[0], token);
            token = strtok(NULL," ");
            strcpy(insAndAdd[1],token);

            dictionaryIterator(instrucoes,teste,2);            
            break;
        
        
        // Caso nenhuma precise utilizar end
        case 4:
            printf("Caso 4\n");
            printf("%s %s",teste[2], instrucoes[2]);
            printf("\n%d\n", strcmp(instrucoes[3],teste[2]));
            dictionaryIterator(instrucoes,teste,2);
            dictionaryIterator(instrucoes,teste,3);
        break;
    }
    for(int i = 0; i < 32; i++){
        printf("%s\n",instrucoes[i]);
    }
    
    printf("\nTestando...\n");
    if(instype == 0)
        printf("%s %s %s %s %s %s\n",teste[0],teste[1],teste[2],teste[3], teste[4], teste[5]);
    else if(instype == 1)
        printf("%s %s %s %s %s\n",teste[0],teste[1],teste[2],teste[3], teste[4]);
    else if(instype == 3)
        printf("%s %s %s %s %s\n",teste[0],teste[1],teste[2],teste[3], teste[4]);
    else
        printf("%s %s %s %s\n",teste[0],teste[1],teste[2],teste[3]);
        
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

