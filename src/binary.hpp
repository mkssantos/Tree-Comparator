#ifndef TREE_H 
#define TREE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <iostream>
typedef struct Record Record;
typedef struct Tree Tree;

using namespace std;

struct Record{
	double key;
	double value;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
};

Tree* CreateTree();
bool TVazia(Tree **t);
void insertTree(Tree **t, Record r);
double pesquisa(Tree **t, Record r);
int isInTree(Tree *t, Record r);

void removeTree(Tree **t, Record r);
void antecessor(Tree **t, Tree *aux);

void preordem(Tree *t);
void central(Tree *t);
void posordem(Tree *t);
void widthPath(Tree *t);

#endif