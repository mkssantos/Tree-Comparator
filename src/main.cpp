#include "files.hpp"
#include "avl.hpp"
#include "binary.hpp"
#include "rb.hpp"
#include "files.hpp"
#include "menus.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <unordered_map>
using namespace std;

void GeneratorFile(){
    CreateFile(500);    //Criação do arquivo de 500 consultas
    CreateFile(5000);   //Criação do arquivo de 5000 consultas
    CreateFile(50000);  //Criação do arquivo de 50000 consultas
    CreateFile(500000); //Criação do arquivo de 500000 consultas
}

int main(){
    //GeneratorFile();     Geração de Arquivos 
    //CreateFile10000();   Criação do arquivo de 10000 consultas
    
    Tree* Tree;
    TreeAVL* TreeAVL;
    TreeRB* TreeRB;
    vector <double> vec;
    map <double,int> mapa;
    unordered_map <double,int> umapa;
    Record r1;

    int op = 0,op2 = 0,op3 = 0;
    TreeMenu();
    do{
        menu();
        cin >> op;
        if(op == 1){
            do{
                FileMenu();
                cin >> op2;
                if(op2 == 1){  
                    ReadFile(500,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);
                    cout << "" << endl;
                    cout << "Insercao Completa" << endl;

                }else if(op2 == 2){
                    for(int i = 0; i< 10 ; i++){
                        cout << i+1 << endl;
                        RemoveFile(500,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);   
                        cout << "" << endl; 
                    }
                    cout << "" << endl;
                    cout << "Remoção Completa" << endl;  

                }else if(op2 == 3){
                    SearchFile(500,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);
                    cout << "" << endl;
                    cout << "Fim da Pesquisa" << endl;
                }
            }while(op2 != 0);
        }else if(op == 2){
               do{
                FileMenu();
                cin >> op2;
                if(op2 == 1){  
                    ReadFile(5000,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);
                    cout << "" << endl;
                    cout << "Insercao Completa" << endl;

                }else if(op2 == 2){
                    RemoveFile(5000,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);    
                    cout << "" << endl;
                    cout << "Remoção Completa" << endl;  

                }else if(op2 == 3){
                    SearchFile(5000,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);
                    cout << "" << endl;
                    cout << "Fim da Pesquisa" << endl;
                }
            }while(op2 != 0);
        }else if(op == 3){
           do{
                FileMenu();
                cin >> op2;
                if(op2 == 1){  
                    ReadFile(500000,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);
                    cout << "" << endl;
                    cout << "Insercao Completa" << endl;

                }else if(op2 == 2){
                    RemoveFile(500000,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);    
                    cout << "" << endl;
                    cout << "Remoção Completa" << endl;  

                }else if(op2 == 3){
                    SearchFile(500000,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);
                    cout << "" << endl;
                    cout << "Fim da Pesquisa" << endl;
                }
            }while(op2 != 0);
        }else if(op == 4){
        do{
            FileMenu();
            cin >> op2;
            if(op2 == 1){  
                ReadFile(500000,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);
                cout << "" << endl;
                cout << "Insercao Completa" << endl;

            }else if(op2 == 2){
                RemoveFile(500000,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);    
                cout << "" << endl;
                cout << "Remoção Completa" << endl;  

            }else if(op2 == 3){
                SearchFile(500000,&Tree,&TreeAVL,&TreeRB,&vec,&mapa,&umapa);
                cout << "" << endl;
                cout << "Fim da Pesquisa" << endl;
            }
        }while(op2 != 0);
        }else{
            op = 0;
        }
    }while(op != 0);
    
return 0;    
}