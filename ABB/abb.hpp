//
//  abb.hpp
//  ABB
//
//  Created by Carlos NG on 6/9/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#ifndef abb_hpp
#define abb_hpp

#include <stdio.h>
#include <iostream>


using namespace std;

template <class T>
class Tree;

template <class T>
class Node
{
private:
    Node<T>* left;
    Node<T>* right;
    T data;
public:
    Node();
    Node<T>* getLeft()
    {
        return left;
    }
    Node<T>* getRight()
    {
        return right;
    }
    void setRight(Node<T>* value)
    {
        right = value;
    }
    void setLeft(Node<T>* value)
    {
        left = value;
    }
    void setData(T value)
    {
        data = value;
    }
    T getData()
    {
        return data;
    }
    friend class Tree<T>;
};

template <class T>
class Tree
{
private:
    Node<T>* root;
public:
    Tree();
    void setRoot(Node<T>* value)
    {
        root = value;
    }
    Node<T>* getRoot(){return root;};
    void Insert(Node<T>*,T);
    void Remove(Node<T>*, T);
    void Preorder(Node<T>* node);
    void Postorder(Node<T>* node);
    int prueba_algoritmo();
    int magic(Node<T>* node);
    Node<T>* Search(Node<T>*,T);
};


template <class T>
Node<T>::Node()
{
    right = nullptr;
    left = nullptr;
}

template <class T>
Tree<T>::Tree()
{
    root = nullptr;
}



template <class T>
Node<T>* Tree<T>::Search(Node<T>* node, T value)
{
    if(node != nullptr)
    {
        if(value < node -> data)
        {
            return Search(node -> left, value);
        }
        else
        {
            if(value > node -> data)
            {
                return Search(node -> right, value);
            }
            else
            {
                return node;
            }
        }
    }
    else
    {
        cout << "Node not found." << endl;
        return nullptr;
    }
}

template<class T>
void Tree<T>::Insert(Node<T>* p,T value)
{
    // Verifica si el nodo es mayor o menor a al raiz
    // Si es menor, se va a la izquierda, de lo contrario, a la derecha.
    // Si no existe la raíz, solo se inserta.
    Node<T>* aux;
    if(p != NULL) // Verifica si existe raíz.
    {
       if(value < p -> getData())
       {
           Insert(p -> getLeft(),value);
           p -> setLeft(root);
       }
        else
        {
            if(value > p -> getData())
            {
                Insert(p -> getRight(), value);
                p -> setRight(root);
            }
        }
        root = p;
        
    }
    else
    {
        // Creates new node
        aux = new Node<T>;
        aux -> setData(value);
        setRoot(aux);
       
    }
    
    
}

template <class T>
void Tree<T>::Preorder(Node<T>* node)
{
    if(node != NULL)
    {
        cout << node -> data << " ";
        Preorder(node -> left);
        Preorder(node -> right);
    }
}
template <class T>
void Tree<T>::Postorder(Node<T>* node)
{
    if(node != NULL)
    {
        Preorder(node -> left);
        cout << node -> data << " ";
        Preorder(node -> right);
    }
}

template <class T>
void Tree<T>::Remove(Node<T>* p, T value)
{ // Elimina el nodo encontrado. Si tiene ambos hijos el padre será el nodo que esté
  // más a la derecha del subarbol izquierdo.
  // Si es una hoja se elimina directamente.
  // Si tiene un hijo, el nodo se remplaza por este.
    if(p != NULL)
    {
        if(value < p -> getData())
        {
            Remove(p -> getLeft(), value);
            p -> setLeft(root);
        }
        else
        {
            if(value > p -> getData()) // Si el nodo no es mayor ni menor al valor de busqueda
                                       // se asume que ese es el nodo a eliminar, entonces.
            {
                Remove(p -> getRight(), value);
                p -> setRight(root);
            }
            else
            {
                Node<T>* aux1, *aux2, *aux3;
                aux3 = p;
                if(aux3 -> getRight() == NULL)
                {
                    if(aux3 -> getLeft() == NULL)
                    {
                        p = NULL;
                    }
                    else
                    {
                        p = aux3 -> getLeft();
                    }
                }
                else  // Si tiene solo un hijo, entonces p solo se replaza por el hijo. Ya sea hijo
                      // hijo izquierdo o derecho.
                {
                    if(aux3 -> getLeft() == NULL)
                    {
                        p = aux3 -> getRight();
                    }
                    else
                    {
                        aux1 = aux3 -> getLeft();
                        aux2 = aux3;
                        while(aux1 -> getRight() != NULL)
                        {
                            aux2 = aux1;
                            aux1 = aux1 -> getRight();
                        }
                        aux3 -> setData(aux1 -> getData());
                        if(aux3 == aux2)
                        {
                            aux3 -> setLeft(NULL);
                        }
                        else
                        {
                            if(aux1 -> getLeft() == NULL)
                            {
                                aux2 -> setRight(NULL);
                            }
                            else
                            {
                                aux2 -> setRight(aux1 -> getLeft());
                            }
                        }
                        aux3 = aux1;
                    }
                    
                }
                delete(aux3);
            }
            
        }
        root = p;
    }
}


template<class T>
int Tree<T>::magic(Node<T>* node)
{
    if (node!=0)
    {
        return node->getData()+magic(node->getRight())-magic(node->getLeft());
    }
    return 0;
}

template<class T>
int Tree<T>::prueba_algoritmo() {
    return magic(root);
}

#endif /* abb_hpp */
