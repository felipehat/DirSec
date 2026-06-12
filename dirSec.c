#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAX 256
    int main(int argc, char *argv[]){
        // out => argv[1]; key => argv[2]; fun => argv[3];
        FILE *open, *closer;
        int buff = 0;
        char names[MAX] = {""};
        int key = atoi(argv[2]);
        int digito = 0;
        int arg = atoi(argv[3]);


        if(arg == 0){
            strcpy(names, argv[1]);
            strcat(names, ".sub");
            open = fopen(argv[1], "rb");
            if(open == NULL){
                perror("Caminho errado?");
                exit(1);
            }
            
            closer = fopen(names, "wb");
            if(open == NULL){
                perror("Impossível criptografar");
                exit(1);
            }

            

            while((buff = getc(open)) != EOF){
                digito = buff + key;
                
                fprintf(closer, "%c", digito);
                
            }
            fclose(open);
            fclose(closer);
            
        }

        else if(arg == 1){

            open = fopen(argv[1], "rb");
            if(open == NULL){
                perror("Caminho errado?");
                exit(1);
            }
            argv[1][strlen(argv[1])-4] = '\0';
            closer = fopen(argv[1], "wb");
            if(open == NULL){
                perror("Impossível criptografar");
                exit(1);
            }
            while((buff = getc(open)) != EOF){
                digito = buff - key;
                fprintf(closer, "%c", digito);
            }
            fclose(open);
            fclose(closer);
            
        }

        else{
            printf("Uso: 'dirsec <addr dir> <password> <0/1>'\n");
            printf("0 -> criptografa/1 -> descriptografa\n");
        }


        return 0;
    }