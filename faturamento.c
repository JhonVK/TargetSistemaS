//Joao vitor kauer schuck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON_Parser/cJSON.h"

int main() {
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
    char *json_string = cJSON_Print(json);
    printf("%s\n", json_string);


    free(json_string);
    cJSON_Delete(json);
    return 0;
}