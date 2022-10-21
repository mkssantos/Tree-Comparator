#include "files.hpp"
 
void CreateFile(int num){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(1, 100);

    string path;
    path.assign("files/FIle").append(to_string(num).append(".txt"));
    ofstream myfile;
    myfile.open (path);
    
    for (int i = 0; i < num; i++){
        myfile << dist(gen) << endl;   
    }  
    myfile.close();
}

void ReadFile(int num,Tree** Tree,TreeAVL** TreeAVL,TreeRB** TreeRB,vector <double>* vec,map <double,int>* mapa,unordered_map <double,int>* umapa){
    *Tree = CreateTree();
    *TreeAVL = CreateTreeAVL();
    CreateTreeRB(TreeRB);
    Record r1;
    RecordAVL r2;
    RecordRB r3;
    double value;


    double resultB,resultAVL,resultRB,resultMap,resultUMap,resultVector;
    resultB=resultAVL=resultRB=resultMap=resultUMap=resultVector=0;
    clock_t start, end;
    string path;
    path.assign("files/FIle").append(to_string(num).append(".txt"));

    ifstream myfile(path);
	string line;

	if (myfile.is_open()) {
		while (getline(myfile, line)){
            value = stod(line);

            r1.key = value;
            r2.key = value;
            r3.key = value;

            start = clock();
            insertTree(Tree,r1);
            end = clock();
            resultB += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            insertTreeAVL(TreeAVL,r2);
            end = clock();
            resultAVL += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            insertTreeRB(TreeRB,TreeRB,TreeRB,r3);
            end = clock();
            resultRB += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            mapa->insert({value,0});
            end = clock();
            resultMap += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            umapa->insert({value,0});
            end = clock();
            resultUMap += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            vec->push_back(value);
            end = clock();
            resultVector += double(end - start) / double(CLOCKS_PER_SEC);
        }
        sort(vec->begin(),vec->end());
		cout << "Tempo Inserção Binaria " << resultB << endl;
        cout << "Tempo Inserção AVL " << resultAVL << endl;	
        cout << "Tempo Inserção RB " << resultRB << endl;	
        cout << "Tempo Inserção MAP " << resultMap << endl;	
        cout << "Tempo Inserção UMAP " << resultUMap << endl;	
        cout << "Tempo Inserção Vector " << resultVector << endl;		

		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}

void CreateFile10000(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(1, 100);

    int cont =0;
    string aux;
    ofstream myfile("files/File10000.txt");

    ifstream File1;
    File1.open("files/FIle500.txt");  

    if(File1.is_open()){
        while(getline(File1,aux)){
        if(cont == 250){
            break;
        } else {
            myfile << aux << endl;
            cont++;
        }
    }
    File1.close();
    cont = 0;
    }

    ifstream File2;
    File2.open("files/FIle5000.txt");  

    if(File2.is_open()){
        while(getline(File2,aux)){
        if(cont == 1250){
            break;
        } else {
            myfile << aux << endl;
            cont++;
        }
    }
    File2.close();
    cont = 0;
    }

    ifstream File3;
    File3.open("files/FIle50000.txt");  

    if(File3.is_open()){
        while(getline(File3,aux)){
        if(cont == 2500){
            break;
        } else {
            myfile << aux << endl;
            cont++;
        }
    }
    File3.close();
    cont = 0;
    }

    ifstream File4;
    File4.open("files/FIle500000.txt");  

    if(File4.is_open()){
        while(getline(File4,aux)){
        if(cont == 5000){
            break;
        } else {
            myfile << aux << endl;
            cont++;
        }
    }
    File4.close();
    cont = 0;
    }

    for(int i = 0; i < 1000; i++){
        myfile << dist(gen) << endl;   
    }    

    myfile.close();
}

void SearchFile(int num,Tree** Tree,TreeAVL** TreeAVL,TreeRB** TreeRB,vector <double>* vec,map <double,int>* mapa,unordered_map <double,int>* umapa){
    Record r1;
    RecordAVL r2;
    RecordRB r3;
    double value;
    vector <double>:: iterator it1;
    map <double,int>:: iterator it2;
    unordered_map <double,int>:: iterator it3;

    double resultB,resultAVL,resultRB,resultMap,resultUMap,resultVector;
    resultB=resultAVL=resultRB=resultMap=resultUMap=resultVector=0;
    clock_t start, end;
    string path;
    path.assign("files/File10000.txt");

    ifstream myfile(path);
	string line;

	if (myfile.is_open()) {
		while (getline(myfile, line)){
            value = stod(line);

            r1.key = value;
            r2.key = value;
            r3.key = value;

            start = clock();
            cout << pesquisa(Tree, r1) << endl;
            end = clock();

            resultB += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            cout << pesquisaAVL(TreeAVL, r2) << endl;

            end = clock();
            resultAVL += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            cout << pesquisaRB(TreeRB,r3) << endl;
            
            end = clock();
            resultRB += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            it2 = mapa->find(value);
            if(it2 != mapa->end()){  
                cout << value << endl;
            }
            end = clock();
            resultMap += double(end - start) / double(CLOCKS_PER_SEC);
            
            start = clock();
            it3 = umapa->find(value);
            if(it3 != umapa->end()){
                cout << value << endl;
            }
            end = clock();
            resultUMap += double(end - start) / double(CLOCKS_PER_SEC);
            
            start = clock();  
            if(binary_search(vec->begin(),vec->end(),value)){
                cout << value << endl;
            }  
            end = clock();
            resultVector += double(end - start) / double(CLOCKS_PER_SEC);
        }
		cout << "Tempo Pesquisa Binaria " << resultB << endl;
        cout << "Tempo Pesquisa AVL " << resultAVL << endl;	
        cout << "Tempo Pesquisa RB " << resultRB << endl;	
        cout << "Tempo Pesquisa MAP " << resultMap << endl;	
        cout << "Tempo Pesquisa UMAP " << resultUMap << endl;	
        cout << "Tempo Pesquisa Vector " << resultVector << endl;		

		myfile.close();
	}else cout << "Nao foi possivel abrir o arquivo" << endl;
}

void RemoveFile(int num, Tree** Tree,TreeAVL** TreeAVL,TreeRB** TreeRB,vector <double>* vec,map <double,int>* mapa,unordered_map <double,int>* umapa){
    Record r1;
    RecordAVL r2;
    RecordRB r3;
    double value;
    vector <double>:: iterator it1;
    map <double,int>:: iterator it2;
    unordered_map <double,int>:: iterator it3;

    double resultB,resultAVL,resultRB,resultMap,resultUMap,resultVector;
    resultB=resultAVL=resultRB=resultMap=resultUMap=resultVector=0;
    clock_t start, end;
    string path;
    path.assign("files/File10000.txt");
    ifstream myfile(path);
	string line;

	if (myfile.is_open()) {
		while (getline(myfile, line)){
            value = stod(line);

            r1.key = value;
            r2.key = value;
            r3.key = value;

            start = clock();
            removeTree(Tree, r1);
            end = clock();

            resultB += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            removeTreeAVL(TreeAVL,TreeAVL, r2);
            end = clock();

            resultAVL += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            search_delete(TreeRB,*TreeRB, r3);
            end = clock();
            resultRB += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            it2 = mapa->find(value);
            if(it2 != mapa->end()){
                mapa->erase(it2);
            }
            end = clock();
            resultMap += double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            it3 = umapa->find(value);
            if(it3 != umapa->end()){
                umapa->erase(it3);
            }
            end = clock();
            resultUMap += double(end - start) / double(CLOCKS_PER_SEC);
            if(binary_search(vec->begin(),vec->end(),value)){
                it1 = find(vec->begin(),vec->end(), value);
                if(it1 != vec->end()){
                vec->erase(it1);
            }
            }


            start = clock();
            
            end = clock();
            resultVector += double(end - start) / double(CLOCKS_PER_SEC);
        }
		cout << "Tempo Remoção Binaria " << resultB << endl;
        cout << "Tempo Remoção AVL " << resultAVL << endl;	
        cout << "Tempo Remoção RB " << resultRB << endl;	
        cout << "Tempo Remoção MAP " << resultMap << endl;	
        cout << "Tempo Remoção UMAP " << resultUMap << endl;	
        cout << "Tempo Remoção Vector " << resultVector << endl;		

		myfile.close();
	}else cout << "Nao foi possivel abrir o arquivo" << endl;
}



