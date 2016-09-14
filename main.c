#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main (void) {
  FILA alunos = novaFila();

  inserirFinal(alunos, 9);
  inserirFinal(alunos, 8);
  inserirFinal(alunos, 3);
  inserirFinal(alunos, 10);
  inserirInicio(alunos, 1);
  inserirFinal(alunos, 7);
  inserirInicio(alunos, -1);

  imprimirFila(alunos);

  //while(!filaVazia(alunos))
    printf ("removido final: %d \n", removerFinal(alunos));
  imprimirFila(alunos);

  /*
  while(!filaVazia(alunos))
    printf ("removido inicio: %d \n", removerInicio(alunos));
  imprimirFila(alunos);
  */

  inserirFinal(alunos, 15);
  inserirFinal(alunos, 32);

  imprimirFila(alunos);

  destroiFila(alunos);

  return EXIT_SUCCESS;
}
