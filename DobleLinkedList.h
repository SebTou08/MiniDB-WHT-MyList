#ifndef __DOBLELINKEDLIST_H__
#define __DOBLELINKEDLIST_H__

#include <iostream>
#include <sstream>

#include <stdlib.h>
#include <ctime>
#include <functional>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
template <typename TipoGen>
class DobleLinkedList;

template <typename TipoGen>
class Node
{
private:
    TipoGen data;
    Node<TipoGen> *next;
    Node<TipoGen> *prev;
    friend class DobleLinkedList<TipoGen>;

public:
    Node(TipoGen _data, Node<TipoGen> *_next = NULL, Node<TipoGen> *_prev = NULL)
    {
        data = _data;
        next = _next;
        prev = _prev;
    }
};

template <typename TipoGen>
class DobleLinkedList
{
    Node<TipoGen> *beginning;
    Node<TipoGen> *end;
    int size;

public:
    DobleLinkedList()
    {
        beginning = end = nullptr;
        size = 0;
    }

    //METODOS PARA AGREGAR
    void BeginningAddition(TipoGen v)
    {
        Node<TipoGen> *_new = new Node<TipoGen>(v);
        if (size == 0)
        {
            beginning = end = _new;
        }
        else
        {
            _new->next = beginning;
            beginning->prev = _new;
            beginning = _new;
        }
        ++size;

    }

    void FinalAddition(TipoGen v)
    {
        Node<TipoGen> *_new = new Node<TipoGen>(v);
        if (size == 0)
        {
            beginning = end = _new;
        }
        else
        {
            end->next = _new;
            _new->prev = end;
            end = _new;
        }
        ++size;
    }

    void MiddleAddition(TipoGen v, int p)
    {
        Node<TipoGen> *aux = beginning;
        Node<TipoGen> *_new = new Node<TipoGen>(v);
        for (size_t i = 0; i < p - 1; ++i)
        {
            aux = aux->next;
        }

        _new->next = aux->next;
        _new->prev = aux;
        aux->next->prev = _new;
        aux->next = _new;
        ++size;
    }

 

    //ELIMINACION
    void BeginningDisposal()
    {
        Node<TipoGen> *aux = beginning;
        beginning = aux->next;
        delete aux;
        --size;
    }

    void FinalDisposal()
    {
        Node<TipoGen> *aux = end->prev;
        delete aux->next;
        aux->next = nullptr;
        end = aux;
        --size;
    }

    //Ways to get po

    TipoGen *getpo(int p)
    {
        if (p == 1)
        {
            return beginning->data;
        }
        else if (p > size)
        {
            return 0;
        }
        else
        {
            Node<TipoGen> *aux = beginning;
            int i = 0;
            while (i != p - 1)
            {
                aux = aux->next;
                i++;
            }
            return aux->data;
        }
    }

    TipoGen *getposition(int pos)
    {
        Node<TipoGen> *aux = beginning;
        int i = 0;
        while (i != pos)
        {
            aux = aux->next;
            i++;
        }
       return aux->data;
    }

    //ordenamientos

    void change(int p, TipoGen _data)
    {
        Node<TipoGen> *aux = beginning;
        int i = 0;
        while (i < p - 1)
        {
            aux = aux->next;
            i++;
        }
        aux->data = _data;
    }


int getsize(){ return size;}



    //Mostrar
   /* void Show()
    {
        int i = 1;
        Node<TipoGen> *aux = beginning;
        while (aux != nullptr)
        {
            car *obj = aux->data;
            cout << "-------------Caroo" << i << " -----------------" << endl;
            cout << obj->mostrar();
            ++i;
            aux = aux->next;
        }
    }*/
};

#endif // !__DOBLELINKEDLIST_H__
