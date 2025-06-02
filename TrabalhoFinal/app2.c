// app2.cpp (Mateus Cacabuena; 05 junho 2025)

#include <stdio.h>
#include "diretores.h"

int main() {
  if ( !diretores_carrega("diretores.txt") ) return 0;
  printf("----------\n");
  diretores_mostra();
  diretores_ordena();
  if ( !diretores_salva("diretores.txt.out") ) return 0;
  printf("----------\n");
  diretores_mostra();
  printf("----------\n");
  return 0;
}
