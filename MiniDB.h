#ifndef __MINIDB_H__
#define __MINIDB_H__
#include "DobleLinkedList.h"
#include "BinaryTree.h"
#include <fstream>
#include <sstream>
using namespace std;

class MiniDB
{
    ifstream archivo;
    DobleLinkedList<DobleLinkedList<string>> minidb;
    string cadena;
    BinaryTree<DobleLinkedList<DobleLinkedList<string>> *> *IndexTree;

public:
    MiniDB()
    {

        IndexTree = new BinaryTree<DobleLinkedList<DobleLinkedList<string>> *>;
    }
    void reading(string nombre, char ans)
    {
        archivo.open(nombre);
        while (getline(archivo, cadena))
        {
            stringstream ss(cadena);
            if (ans == 's') 
                cout << cadena<< endl;
            divideField(ss);
        }
    }

    void divideField(istream &registro){
        DobleLinkedList<string>fila;
        string tmp;
        while (getline(registro,tmp,';'))
        {
           fila.FinalAddition(tmp);
        }
        minidb.FinalAddition(fila);
    }

    void ShowValues(){
        cout<<endl<<"Cantidad de filas: "<<minidb.getsize()<<endl;
      //TODO:  cout<<endl<<"Cantidad de columnas: "<<minidb[0].getsize()<<endl;
    }
};

#endif
