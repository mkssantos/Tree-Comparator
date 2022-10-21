#ifndef FILES_H
#define FILES_H
#include "binary.hpp"
#include "avl.hpp"
#include "rb.hpp"
#include<time.h>
#include<stdbool.h>
#include <random>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

void CreateFile(int num);
void ReadFile(int num, Tree** Tree,TreeAVL** TreeAVL,TreeRB** TreeRB,vector <double>* vec,map <double,int>* mapa,unordered_map <double,int>* umapa);
void CreateFile10000();
void SearchFile(int num, Tree** Tree,TreeAVL** TreeAVL,TreeRB** TreeRB,vector <double>* vec,map <double,int>* mapa,unordered_map <double,int>* umapa);
void RemoveFile(int num, Tree** Tree,TreeAVL** TreeAVL,TreeRB** TreeRB,vector <double>* vec,map <double,int>* mapa,unordered_map <double,int>* umapa);

#endif