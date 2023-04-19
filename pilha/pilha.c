#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../lista/lista_encadeada_dupla.c"

void push(Lista*, Nodo*); //ok
Nodo* pop(Lista*); //ok
bool pilhaVazia(Lista*); //ok
void percorrePilha(Lista*); //ok
Nodo* topPilha(Lista*); //ok
void liberaPilha(Lista*); //ok
void testePilha(Lista**); //ok

Nodo* topPilha(Lista* pilha) {
  if (pilha != NULL && pilha->size > 0)
  {
    return pilha->tail;
  }
  return NULL;
}

void push(Lista* pilha, Nodo* no) {
  if (pilha != NULL && no != NULL)
  {
    insereElementoLista(pilha, topPilha(pilha), no->dado);
  }
}

Nodo* pop(Lista* pilha) {
  if (pilha != NULL && pilha->size > 0)
  {
    return removeElementoLista(pilha, topPilha(pilha));
  }
  return NULL;
}

bool pilhaVazia(Lista* pilha) {
  if (pilha != NULL && pilha->size == 0)
  {
    return true;
  }
  return false;
}

void percorrePilha(Lista* pilha) {
  Nodo* no = pilha->tail;
  printf("Pilha: ");
  for (int i = 0; i < pilha->size; i++)
  {
    printf(" %d", no->dado);
    no = no->prev;
  }
  printf("\n");
}

void liberaPilha(Lista* pilha) {
  if (pilha != NULL)
  {
    liberaMemoriaLista(pilha);
  }
}

void testePilha(Lista** pilha) {
  Nodo* no;
  *pilha = criaLista();
  push(*pilha, criaNodo(1));
  push(*pilha, criaNodo(2));
  push(*pilha, criaNodo(3));
  push(*pilha, criaNodo(4));
  push(*pilha, criaNodo(5));

  while (pilhaVazia(*pilha) == false)
  {
    percorrePilha(*pilha);
    no = pop(*pilha);
    printf("Elemento removido: %d", no->dado);
    printf("\n");
  }
}

/* int main() {
  Lista* pilha;
  testePilha(&pilha);
  liberaPilha(pilha);
  return 0;
} */