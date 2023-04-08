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
                        strcpy(comparado[compPos],"00");
                        break;

                    case 1: //nop
                        strcpy(comparado[compPos],"01");
                        break;

                    case 2: //add
                        strcpy(comparado[compPos],"02");
                        break;
                    
                    case 3: //sub
                        strcpy(comparado[compPos],"03");
                        break;
                    
                    case 4: //mul
                        strcpy(comparado[compPos],"04");
                        break;

                    case 5: //div
                        strcpy(comparado[compPos],"05");
                        break;

                    case 6: //cmp
                        strcpy(comparado[compPos],"06");
                        break;

                    case 7: //xchg
                        strcpy(comparado[compPos],"07");
                        break;

                    case 8: //and
                        strcpy(comparado[compPos],"08");
                        break;

                    case 9: //or
                        strcpy(comparado[compPos],"09");
                        break;

                    case 10: //xor
                        strcpy(comparado[compPos],"0A");
                        break;

                    case 11: //not
                        strcpy(comparado[compPos],"0B");
                        break;

                    case 12: //ldrb
                        strcpy(comparado[compPos],"17");
                        break;

                    case 13: //je
                        strcpy(comparado[compPos],"0C");
                        break;

                    case 14: //jne
                        strcpy(comparado[compPos],"0D");
                        break;

                    case 15: //jl
                        strcpy(comparado[compPos],"0E");
                        break;

                    case 16: //jle
                        strcpy(comparado[compPos],"0F");
                        break;

                    case 17: //jg
                        strcpy(comparado[compPos],"10");
                        break;

                    case 18: //jge
                        strcpy(comparado[compPos],"11");
                        break;

                    case 19: //jmp
                        strcpy(comparado[compPos],"12");
                        break;

                    case 20: //lda
                        strcpy(comparado[compPos],"13");
                        break;

                    case 21: //ldb
                        strcpy(comparado[compPos],"14");
                        break;

                    case 22: //sta
                        strcpy(comparado[compPos],"15");
                        break;

                    case 23: //stb
                        strcpy(comparado[compPos],"16");
                        break;

                    case 24: //movial
                        strcpy(comparado[compPos],"18");
                        break;

                    case 25: //moviah
                        strcpy(comparado[compPos],"19");
                        break; 

                    case 26: //addia
                        strcpy(comparado[compPos],"1A");
                        break;
                    
                    case 27: //subia
                        strcpy(comparado[compPos],"1B");
                        break;
                    
                    case 28: //mulia
                        strcpy(comparado[compPos],"1C");
                        break;
                    
                    case 29: //divia
                        strcpy(comparado[compPos],"1D");
                        break;
                    
                    case 30: //lsh
                        strcpy(comparado[compPos],"1E");
                        break;
                    
                    case 31: //rsh
                        strcpy(comparado[compPos],"1F");
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
    char concat [1][30];
    strcpy(concat[0],"");
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
            

        }

    }

    //Testando a strtok()
    token = strtok(inst[1],";");
    char teste[30][50], testeTemp[1][50];
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
    
    if(strcmp(teste[1],"i") == 0){
        for (int i = 0;i < 13; i++){
            //Se a instrução da esquerda não precisar de End. Mem ou IMM...
            if(strcmp(instrucoes[i],teste[2]) == 0){
                instype++;
                break;
            }else if (i == 12 && strcmp(instrucoes[i],teste[2]) != 0)
                printf("A instrucao nao se encaixa\n");
        }
    
        char breakliner[30]; // Criei essa função temp para evitar quebra de linha no strcat
        // Na última parte, inserir o \n, se não o strcmp não passará
        for (int i = 0;i < 13; i++){
            //Se a instrução da direita não precisar de End. Mem ou IMM...
            strcpy(breakliner,instrucoes[i]);
            if(strcmp(strcat(breakliner,"\n"),teste[3]) == 0){
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

                for(int i = 0; i < 4; i++){
                    strcat(concat[0],teste[i+2]);
                }
                
            break;

            //Apenas a segunda instrução irá utilizar end.
            case 1:
                printf("Caso 1\n");
                token = strtok(teste[1]," ");
                strcpy(insAndAdd[0], token);
                token = strtok(NULL," ");
                strcpy(insAndAdd[1],token);

                //Atribuindo o insAndAdd pro teste
                for(int i = 0;i < 2; i++){
                    strcpy(teste[i+3],insAndAdd[i]);
                    printf("%s\n",teste[i+3]);
                }
                //Tirando o \n
                for(int i = 0; i < 50; i++){
                    if(teste[3][i] != '\n'){
                        testeTemp[0][i] = teste[3][i];
                        printf("o negocio e %c\n",teste[3][i]);
                    } else
                        break;
                }

                dictionaryIterator(instrucoes,testeTemp,0);
                strcpy(teste[3],testeTemp[0]);
                for(int i = 0; i < 3; i++){
                    strcat(concat[0],teste[i+2]);
                }
            break;
            //So vai ter endereço no primeiro
            case 3:
                printf("Caso 3\n");
                token = strtok(teste[2]," ");
                strcpy(insAndAdd[0], token);
                token = strtok(NULL," ");
                strcpy(insAndAdd[1],token);
                
                //passando o teste[3] para teste[4]
                strcpy(teste[4],teste[3]);

                //Atribuindo o insAndAdd pro teste
                for(int i = 0;i < 2; i++){
                    strcpy(teste[i+2],insAndAdd[i]);
                    printf("%s\n",teste[i+2]);
                }
                printf("aaaaatchim %s\n",teste[4]);
                //Tirando o \n
                for(int i = 0; i < 50; i++){
                    if(teste[4][i] != '\n'){
                        testeTemp[0][i] = teste[4][i];
                        printf("o negocio e %c\n",teste[4][i]);
                    } else
                        break;
                }
                dictionaryIterator(instrucoes,teste,2);
                dictionaryIterator(instrucoes,testeTemp,0);
                strcpy(teste[4],testeTemp[0]);
                for(int i = 0; i < 3; i++){
                    strcat(concat[0],teste[i+2]);
                }
                break;
            
            
            // Caso nenhuma precise utilizar end
            case 4:
                printf("Caso 4\n");
                printf("%s %s",instrucoes[7], teste[3]);
                printf("\n%d\n", strcmp(instrucoes[3],teste[2]));
                //Tirando o \n
                for(int i = 0; i < 50; i++){
                    if(teste[3][i] != '\n'){
                        testeTemp[0][i] = teste[3][i];
                        printf("o negocio e %c\n",teste[3][i]);
                    } else
                        break;
                }
                
                dictionaryIterator(instrucoes,teste,2);
                dictionaryIterator(instrucoes,testeTemp,0);
                strcpy(teste[3],testeTemp[0]);
                printf("nao aguento mais %s\n",teste[3]);
                for(int i = 0; i < 2; i++){
                    strcat(concat[0],teste[i+2]);
                }
            break;
        }


    }
    //Alocando na memória...
    // for(int i = 0; i < 4; i++){
    //     printf("%X",teste[0])
    // }
    // printf("em hexa e %s\n",teste[0]);
    // char locTemp[1][4];
    // char loc = "0x";
    // strcpy(locTemp[0], "0x");
    // strcat(locTemp[0],teste[0]);
    printf("concatenando... %s\n",concat[0]);


    
    
    //Testando...
    printf("\nTestando...\n");
    if(instype == 0)
        printf("%s %s %s %s %s %s\n",teste[0],teste[1],teste[2],teste[3], teste[4], teste[5]);
    else if(instype == 1)
        printf("%s %s %s %s %s\n",teste[0],teste[1],teste[2],teste[3], teste[4]);
    else if(instype == 3)
        printf("%s %s %s %s %s\n",teste[0],teste[1],teste[2],teste[3], teste[4]);
    else
        printf("%s %s %s %s\n",teste[0],teste[1],teste[2],teste[3]);
        
    
    //printf("em hexa e %X\n",memoria[locTemp[0]]);
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
    //checando a instrução            
    switch (ir)
    {
    case 0x00: //hlt
        hlt();
        break;

    case 0x01: //nop
        nop(pc,lr);
        break;

    case 0x02: //add
        add(a,b);
        break;
    
    case 0x03: //sub
        sub(a,b);
        break;
    
    case 0x04: //mul
        mul(a,b);
        break;

    case 0x05: //div
        div(a,b);
        break;

    case 0x06: //cmp
        cmp(a,b,e,l,g);
        break;

    case 0x07: //xchg
        xchg(a,b,t);
        break;

    case 0x08: //and
        land(a,b);
        break;

    case 0x09: //or
        lor(a,b);
        break;

    case 0x0a: //xor
        lxor(a,b);
        break;

    case 0x0b: //not
        lnor(a);
        break;

    case 0x17: //ldrb
        ldrb(mar,a,b);
        break;

    case 0x0c: //je
        je(mar,pc,e);
        break;

    case 0x0d: //jne
        jne(mar,pc,e);
        break;

    case 0x0e: //jl
        jl(mar,l,pc);
        break;

    case 0x0f: //jle
        jle(mar,l,e,pc);
        break;

    case 0x10: //jg
        strcpy(comparado[compPos],"10");
        break;

    case 0x11: //jge
        strcpy(comparado[compPos],"11");
        break;

    case 0x12: //jmp
        strcpy(comparado[compPos],"12");
        break;

    case 0x13: //lda
        strcpy(comparado[compPos],"13");
        break;

    case 0x14: //ldb
        strcpy(comparado[compPos],"14");
        break;

    case 0x15: //sta
        strcpy(comparado[compPos],"15");
        break;

    case 0x16: //stb
        strcpy(comparado[compPos],"16");
        break;

    case 0x18: //movial
        strcpy(comparado[compPos],"18");
        break;

    case 0x19: //moviah
        strcpy(comparado[compPos],"19");
        break; 

    case 0x1a: //addia
        strcpy(comparado[compPos],"1A");
        break;
    
    case 0x1b: //subia
        strcpy(comparado[compPos],"1B");
        break;
    
    case 0x1c: //mulia
        strcpy(comparado[compPos],"1C");
        break;
    
    case 0x1d: //divia
        strcpy(comparado[compPos],"1D");
        break;
    
    case 0x1e: //lsh
        strcpy(comparado[compPos],"1E");
        break;
    
    case 0x1f: //rsh
        strcpy(comparado[compPos],"1F");
        break;

    default:
        printf("Erro na checagem do opcode");
        break;
    }
    
                
            

}

// Função main
int main (){
    pc = 0;
    mbr = 0;
    
    //testando ...
    //1001 1000 0000 1100 1010 0000 0000 1110  | lda 96 ldb 98
    memoria[0x00] = 0x13;
    memoria[0x01] = 0x96;
    memoria[0x02] = 0x14;
    memoria[0x03] = 0x98;
    lerArquivo();
    busca();
    printf("O valor do mbr ap0s o busca 0: %x\n",mbr);
    
    decodifica();
    
}

