#include <stdio.h>
#include "fila.h"

int main () {
  FILA alunos = novaFila();
  inserirFinal(alunos, 9);
  inserirFinal(alunos, 8);
  inserirFinal(alunos, 3);
  inserirFinal(alunos, 10);

  imprimirFila(alunos);

  while(!filaVazia(alunos))
    printf ("removido: %d \n", removerInicio(alunos));


  inserirFinal(alunos, 10);
  inserirFinal(alunos, 32);
  
  imprimirFila(alunos);

  destroiFila(alunos);
  return 0;
}
