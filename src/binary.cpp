#include "binary.hpp"
#include"fila.hpp"


bool TVazia(Tree **t){
  return *t == NULL;
}
Tree* CreateTree(){
	return NULL;
}

void insertTree(Tree **t, Record r){

  if(TVazia(t)){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  
  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
    }
  
  }

}

double pesquisa(Tree **raiz, Record valor){
  if ((*raiz)==nullptr)
      return -1;
  if ((*raiz)->reg.key>valor.key){
      return pesquisa(&(*raiz)->esq,valor);
  }
  else if ((*raiz)->reg.key<valor.key){
      return pesquisa(&(*raiz)->dir,valor);
  }
  else
      return (*raiz)->reg.key;
  return -1;
}


int isInTree(Tree *t, Record r) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}


void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->dir != NULL){ 
		antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  free(aux);
} 


void removeTree(Tree **t, Record r){
	Tree *aux;
  	
  	if (*t == NULL){ 
  		
    	return;
  	}

  	if (r.key < (*t)->reg.key){ removeTree(&(*t)->esq, r); return; }
  	if (r.key > (*t)->reg.key){ removeTree(&(*t)->dir, r); return; }

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	free(aux);
    	return;
  	}

  	if ((*t)->esq != NULL){ antecessor(&(*t)->esq, *t); return; }

  	aux = *t;  
  	*t = (*t)->dir;
  	free(aux);
}


void preordem(Tree *t)
{
  if(!(t == NULL)){
    printf("%f ", t->reg.key);
    preordem(t->esq); 
    preordem(t->dir); 
  }
}


void central(Tree *t)
{
  if(!(t == NULL)){
    central(t->esq); 
    printf("%f ", t->reg.key);
    central(t->dir); 
  }
}

void posordem(Tree *t)
{
  if(!(t == NULL)){
    posordem(t->esq); 
    posordem(t->dir); 
    printf("%f ", t->reg.key);
  }
}

void widthPath(Tree *t){
  Fila q;
  Item no, filho;
  
  FFVazia(&q);
  no.p = t;
  Enfileira(&q, no);

  while (!isVazia(&q)){

    Desenfileira(&q, &no);
    printf("%f ", no.p->reg.key);

    if(no.p->esq != NULL){
      filho.p = no.p->esq;
      Enfileira(&q, filho);
      //printf(" Entrei esquerda! ");
    }

    if(no.p->dir != NULL){
      filho.p = no.p->dir;
      Enfileira(&q, filho);
      //printf(" Entrei direita! ");
    }

  }
}

