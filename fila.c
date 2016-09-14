#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

link novoNo(int item, link next) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit (-1);
  }
  t->item = item;
  t->next = next;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->maisNovo = f->maisAntigo = NULL;
  return f;
}

void inserirInicio(FILA f, int e) {
  if(f->maisAntigo == NULL) {
    f->maisAntigo = f->maisNovo->next = novoNo(e, NULL);
  } else {
    f->maisAntigo = novoNo(e, f->maisAntigo);
  }
}

int removerInicio(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return EXIT_SUCCESS;
  }

  x = f->maisAntigo->item;
  t = f->maisAntigo;
  f->maisAntigo = f->maisAntigo->next;

  if(f->maisAntigo == NULL)
    f->maisNovo = NULL;

  free(t);
  return x;
}

void inserirFinal(FILA f, int e) {
  link t = f->maisAntigo;

  if(f->maisAntigo == NULL) {
    f->maisAntigo = f->maisNovo = novoNo(e, NULL);
  } else {
    while (t->next != NULL)
      t = t->next;
    f->maisNovo = t;
    f->maisNovo->next = novoNo(e, NULL);
  }
}

int removerFinal(FILA f){
  printf ("ultimo %d\n", f->maisNovo->next->item);
  printf ("penultimo %d\n", f->maisNovo->item);
  int x;
  link t, y;

  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return EXIT_SUCCESS;
  }

  x = f->maisNovo->next->item;
  t = f->maisNovo->next;
  y = f->maisAntigo;

  while (y->next->next != NULL)
    y = y->next;

  f->maisNovo = y;
  f->maisNovo->next->next = NULL;

  if(f->maisAntigo == NULL)
    f->maisNovo = NULL;

  free(t);
  return x;
}

int filaVazia(FILA f) {
  return ((f->maisNovo == NULL) || (f->maisAntigo == NULL));
}
void imprimirFila(FILA f) {
  link t;
  for(t = f->maisAntigo; t != NULL; t = t->next)
    printf ("%d ", t->item);
  printf ("\n");
}
void destroiFila(FILA f) {
  while (!filaVazia(f))
    removerInicio(f);
  free(f);
}
