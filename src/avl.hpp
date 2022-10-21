#ifndef AVL_H 
#define AVL_H

#include <iostream>
#include <queue>
#include <ctime>
#include <fstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct RecordAVL RecordAVL;
typedef struct TreeAVL TreeAVL;

struct RecordAVL{
	double key;
	double value;
};

struct TreeAVL{
	RecordAVL reg;
	TreeAVL*left, *right;
	double weight;
};

TreeAVL* CreateTreeAVL();
void insertTreeAVL(TreeAVL **t, RecordAVL r);
double pesquisaAVL(TreeAVL **t, RecordAVL r);
int isInTree(TreeAVL*t, RecordAVL r);

//muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void removeTreeAVL(TreeAVL**t, TreeAVL**f, RecordAVL r);
void antecessorAVL(TreeAVL**t, TreeAVL*aux);
void rebalanceTree(TreeAVL**t);

void preordem(TreeAVL*t);
void central(TreeAVL*t);
void posordem(TreeAVL*t);


int getWeight(TreeAVL**t);
int getMaxWeight(int left, int right);


void rotacaoSimplesDireita(TreeAVL**t);
void rotacaoSimplesEsquerda(TreeAVL**t);
void rotacaoDuplaDireita(TreeAVL**t);
void rotacaoDuplaEsquerda(TreeAVL**t);


#endif