//Joao vitor kauer schuck
//gcc faturamento.c cJSON_Parser/cJSON.c -o faturamento -lm
//./faturamento
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON_Parser/cJSON.h"

int main() {

    double soma = 0.0;
    int count = 0, maior=0, menor=__INT_MAX__, dias=0;
    cJSON *item = NULL;

    FILE *file = fopen("arquivoJSON/dados.json", "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    char memoria[4096];
    size_t tamanho_arquivo = fread(memoria, 1, sizeof(memoria), file);
    fclose(file);

    if (tamanho_arquivo == 0) {
        printf("Arquivo vazio ou erro na leitura.\n");
        return 1;
    }

    memoria[tamanho_arquivo] = '\0'; 


    cJSON *json = cJSON_Parse(memoria);

    cJSON_ArrayForEach(item, json) {
        cJSON *valor = cJSON_GetObjectItem(item, "valor");
        if (cJSON_IsNumber(valor)) {
            if(valor->valuedouble>maior){
                maior=valor->valuedouble;
            }
            if(valor->valuedouble<menor){
                menor=valor->valuedouble;
            }
            soma += valor->valuedouble;
            count++;
        }
    }
    double media = soma / count;

       cJSON_ArrayForEach(item, json) {
        cJSON *valor = cJSON_GetObjectItem(item, "valor");
        if (cJSON_IsNumber(valor)) {
            if(valor->valuedouble>media){
                dias++;
            }
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Maior valor: %d\n", maior);
    printf("Dias que faturamento foi maior que a media mensal: %d\n ", dias);

    cJSON_Delete(json);
    return 0;
}