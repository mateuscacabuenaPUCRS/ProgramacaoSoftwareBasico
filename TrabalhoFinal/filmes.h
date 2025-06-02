// filmes.h

#include "diretores.h"
#define MAX_FILMES 100
#define TAM_TITULO 60

typedef struct
{
    int id;
    char titulo[TAM_TITULO + 1];
    int lancamento;
    diretor_t *diretor;
} filme_t;

int filmes_menor(filme_t *f1, filme_t *f2);
int filmes_carrega(char *nome_arq);
int filmes_num_filmes();
filme_t *filmes_obtem_filme_id(int id);
filme_t *filmes_obtem_filme_indice(int indice);
void filmes_mostra_filme(filme_t *filme);
void filmes_mostra();
void filmes_ordena();
int filmes_salva(char *nome_arq);
