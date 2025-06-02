// filmes.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filmes.h"

static filme_t filmes[MAX_FILMES];
static int num_filmes = 0;

int filmes_menor(filme_t *f1, filme_t *f2)
{
    if (strcmp(f1->titulo, f2->titulo) < 0)
        return -1;
    if (strcmp(f1->titulo, f2->titulo) > 0)
        return 1;
    return 0;
}

int filmes_carrega(char *nome_arq)
{
    FILE *f = fopen(nome_arq, "r");
    if (f == NULL)
        return 0;
    char linha[TAM_TITULO + 1];
    while (1)
    {
        if (num_filmes >= MAX_FILMES)
            break;

        // Lê o ID do filme
        if (fgets(linha, TAM_TITULO + 1, f) == NULL)
            break;
        filmes[num_filmes].id = atoi(linha);

        // Lê o título do filme
        if (fgets(filmes[num_filmes].titulo, TAM_TITULO + 1, f) == NULL)
            break;
        int t = strlen(filmes[num_filmes].titulo);
        if (filmes[num_filmes].titulo[t - 1] == '\n')
            filmes[num_filmes].titulo[t - 1] = '\0';

        // Lê o ano de lançamento do filme
        if (fgets(linha, TAM_TITULO + 1, f) == NULL)
            break;
        filmes[num_filmes].lancamento = atoi(linha);

        // Lê o ID do diretor do filme
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        int diretor_id = atoi(linha);
        filmes[num_filmes].diretor = diretores_obtem_diretor_id(diretor_id);

        ++num_filmes;
    }
    fclose(f);
    return 1;
}

int filmes_num_filmes()
{
    return num_filmes;
}

filme_t *filmes_obtem_filme_id(int id)
{
    for (int i = 0; i < num_filmes; ++i)
        if (filmes[i].id == id)
            return &filmes[i];
    return NULL;
}

filme_t *filmes_obtem_filme_indice(int indice)
{
    if (indice < 0 || indice >= num_filmes)
        return NULL;
    return &filmes[indice];
}

void filmes_mostra_filme(filme_t *filme)
{
    // printf("[%d] %s (%d) - Diretor ID: %d\n", filme->id, filme->titulo, filme->lancamento, filme->diretor_id);
    printf("[%d] %s (%d) - %s\n",
           filme->id,
           filme->titulo,
           filme->lancamento,
           filme->diretor->nome);
}

void filmes_mostra()
{
    for (int i = 0; i < num_filmes; ++i)
        filmes_mostra_filme(&filmes[i]);
}

void filmes_ordena()
{
    for (int i = 0; i < num_filmes - 1; ++i)
    {
        int menor = i;
        for (int j = i + 1; j < num_filmes; ++j)
        {
            if (filmes_menor(&filmes[j], &filmes[menor]) < 0)
                menor = j;
        }
        if (menor != i)
        {
            filme_t temp = filmes[i];
            filmes[i] = filmes[menor];
            filmes[menor] = temp;
        }
    }
}

int filmes_salva(char *nome_arq)
{
    FILE *f = fopen(nome_arq, "w");
    if (f == NULL)
        return 0;

    for (int i = 0; i < num_filmes; ++i)
    {
        fprintf(f, "%d\n", filmes[i].id);
        fprintf(f, "%s\n", filmes[i].titulo);
        fprintf(f, "%d\n", filmes[i].lancamento);
        fprintf(f, "%d\n", filmes[i].diretor->id);
    }

    fclose(f);
    return 1;
}