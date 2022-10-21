#ifndef FILA_H 
#define FILA_H
#include "binary.hpp"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item{
	Tree *p;
};

struct Block{
	Item data;
	Block *prox;
};

struct Fila{
	Block *first;
	Block *last;
};


void FFVazia(Fila *f);
bool isVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);

#endif