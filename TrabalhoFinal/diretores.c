// diretores.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "diretores.h"

static diretor_t diretores[MAX_DIRETORES];
static int num_diretores = 0;

int diretores_menor(diretor_t *d1, diretor_t *d2)
{
    if (strcmp(d1->nome, d2->nome) < 0)
        return -1;
    if (strcmp(d1->nome, d2->nome) > 0)
        return 1;
    return 0;
}

int diretores_carrega(char *nome_arq)
{
    FILE *f = fopen(nome_arq, "r");
    if (f == NULL)
        return 0;
    char linha[TAM_NOME + 1];
    while (1)
    {
        if (num_diretores >= MAX_DIRETORES)
            break;

        // Lê o ID do diretor
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].id = atoi(linha);

        // Lê o nome do diretor
        if (fgets(diretores[num_diretores].nome, TAM_NOME + 1, f) == NULL)
            break;
        int t = strlen(diretores[num_diretores].nome);
        if (diretores[num_diretores].nome[t - 1] == '\n')
            diretores[num_diretores].nome[t - 1] = '\0';

        // Lê a cidade de nascimento do diretor
        if (fgets(diretores[num_diretores].cidade_nascimento, TAM_CIDADE + 1, f) == NULL)
            break;
        t = strlen(diretores[num_diretores].cidade_nascimento);
        if (diretores[num_diretores].cidade_nascimento[t - 1] == '\n')
            diretores[num_diretores].cidade_nascimento[t - 1] = '\0';

        // Lê a data de nascimento do diretor
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].nascimento.dia = atoi(linha);
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].nascimento.mes = atoi(linha);
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].nascimento.ano = atoi(linha);

        // Lê a cidade de falecimento do diretor
        if (fgets(diretores[num_diretores].cidade_falecimento, TAM_CIDADE + 1, f) == NULL)
            break;
        t = strlen(diretores[num_diretores].cidade_falecimento);
        if (diretores[num_diretores].cidade_falecimento[t - 1] == '\n')
            diretores[num_diretores].cidade_falecimento[t - 1] = '\0';

        // Lê a data de falecimento do diretor
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].falecimento.dia = atoi(linha);
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].falecimento.mes = atoi(linha);
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].falecimento.ano = atoi(linha);

        ++num_diretores;
    }
    fclose(f);
    return 1;
}

int diretores_num_diretores()
{
    return num_diretores;
}

diretor_t *diretores_obtem_diretor_id(int id)
{
    for (int i = 0; i < num_diretores; ++i)
        if (diretores[i].id == id)
            return &diretores[i];
    return NULL;
}

diretor_t *diretores_obtem_diretor_indice(int indice)
{
    if (indice < 0 || indice >= num_diretores)
        return NULL;
    return &diretores[indice];
}

void diretores_mostra_diretor(diretor_t *diretor)
{
    printf("[%d] %s (* ", diretor->id, diretor->nome);
    printf("%s, %02d/%02d/%4d", diretor->cidade_nascimento, diretor->nascimento.dia, diretor->nascimento.mes, diretor->nascimento.ano);
    if (diretor->falecimento.dia != -1)
        printf(";+ %s, %02d/%02d/%4d", diretor->cidade_falecimento, diretor->falecimento.dia, diretor->falecimento.mes, diretor->falecimento.ano);
    printf(")\n");
}

void diretores_mostra()
{
    for (int i = 0; i < num_diretores; ++i)
        diretores_mostra_diretor(&diretores[i]);
}

void diretores_ordena()
{
    for (int i = 0; i < num_diretores - 1; ++i)
    {
        int menor = i;
        for (int j = i + 1; j < num_diretores; ++j)
        {
            if (diretores_menor(&diretores[j], &diretores[menor]) < 0)
                menor = j;
        }
        if (menor != i)
        {
            diretor_t aux = diretores[menor];
            diretores[menor] = diretores[i];
            diretores[i] = aux;
        }
    }
}

int diretores_salva(char *nome_arq)
{
    FILE *f = fopen(nome_arq, "w");
    if (f == NULL)
        return 0;
    for (int i = 0; i < num_diretores; ++i)
    {
        fprintf(f, "%d\n", diretores[i].id);
        fprintf(f, "%s\n", diretores[i].nome);
        fprintf(f, "%s\n", diretores[i].cidade_nascimento);
        fprintf(f, "%d\n%d\n%d\n", diretores[i].nascimento.dia, diretores[i].nascimento.mes, diretores[i].nascimento.ano);
        fprintf(f, "%s\n", diretores[i].cidade_falecimento);
        fprintf(f, "%d\n%d\n%d\n", diretores[i].falecimento.dia, diretores[i].falecimento.mes, diretores[i].falecimento.ano);
    }
    fclose(f);
    return 1;
}