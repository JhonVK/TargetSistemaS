#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>



int main() {
    char *string;

    int tamanhoString=50, i=0;
    string=(char *)malloc(sizeof(char)*tamanhoString);

    fgets(string, tamanhoString, stdin);

    int tamanhofinal = (strlen(string)-1);//tirei o \n que o fgets coloca, pois buga caso eu o mantenha
    if (string[tamanhofinal] == '\n') {
        string[tamanhofinal] = '\0';
        tamanhofinal--;

    }

    while(i<tamanhofinal){
        char temp=*(string+i);
        *(string+i)=*(string+tamanhofinal);
        *(string+tamanhofinal)=temp;
        i++;
        tamanhofinal--;
    }
    printf("%s", string);
    return 0;
}