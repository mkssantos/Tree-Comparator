#ifndef RB_H 
#define RB_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct RecordRB RecordRB;
typedef struct TreeRB TreeRB;

struct RecordRB{
	double key;
};

struct TreeRB{
	RecordRB reg;
	TreeRB*esq, *dir;
	TreeRB*pai; //específico para rubro negra
	bool cor;  //específico para rubro negra (FALSE = VERMELHOR, TRUE = PRETO)
};


void CreateTreeRB(TreeRB **raiz);
void rotacaoSimplesEsquerda(TreeRB**raiz, TreeRB*child);
void rotacaoSimplesDireita(TreeRB**raiz, TreeRB*child);

void insertFixUp(TreeRB**raiz, TreeRB*child);
void insertTreeRB(TreeRB**t, TreeRB**pai, TreeRB**raiz, RecordRB r);
double pesquisaRB(TreeRB **t, RecordRB r);

void preordem(TreeRB*t);
void central(TreeRB*t);
void posordem(TreeRB*t);

void RB_delete(TreeRB **raiz, TreeRB* z,TreeRB* y,TreeRB *x);
void RB_delete_fix(TreeRB **raiz, TreeRB *x,TreeRB *w);
void RB_transplant(TreeRB **raiz, TreeRB *aux,TreeRB *auxchild);

void searchRB(TreeRB *aux, RecordRB z, double *quant);
void search_delete(TreeRB **raiz, TreeRB *aux, RecordRB z);

TreeRB *tree_successor(TreeRB *aux_succ);


#endif