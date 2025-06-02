// app3.cpp (Mateus Cacabuena; 05 junho 2025)

#include <stdio.h>
#include "filmes.h"

int main() {
  if ( !diretores_carrega("diretores.txt") ) return 0;
  if ( !filmes_carrega("filmes.txt") ) return 0;
  printf("----------\n");
  filmes_mostra();
  filmes_ordena();
  if ( !filmes_salva("filmes.txt.out") ) return 0;
  printf("----------\n");
  filmes_mostra();
  printf("----------\n");
  return 0;
}
