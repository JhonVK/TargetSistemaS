#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char estado[10];
    double faturamento;
} Distribuidora;


int main() {
double soma;
int tamanho;

Distribuidora x[] = {
    {"SP", 67836.43},
    {"RJ", 36678.66},
    {"MG", 29229.88},
    {"ES", 27165.48},
    {"Outros", 19849.53},
    };

tamanho = sizeof(x)/sizeof(x[0]);
for(int i=0; i<tamanho; i++){
    soma+=x[i].faturamento;
}
for(int i=0; i<tamanho; i++){
    printf("%s", x[i].estado);
    printf(" %.3f %%\n", ((x[i].faturamento)/soma)*100);
}

    return 0;
}