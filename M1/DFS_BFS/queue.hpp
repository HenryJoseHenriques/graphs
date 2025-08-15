#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
using namespace std;

template <typename T> 
struct elementos {
  T dado;
  elementos *prox;
};

template <typename T>
struct queue {
    elementos<T> *inicio;
    elementos<T> *fim;
};

template <typename T> void initQueue(queue<T> &Fila) {
  Fila.inicio = NULL;
}

//DEQUEUE: retira o primeiro elemento da Fila e retorna ele
template <typename T> 
T dequeue(queue<T> *Fila) {
    if (Fila->inicio == NULL) {
        cout << "\nTentativa de remover de fila vazia\n";
    }
    elementos<T> *temp = Fila->inicio;
    T dado = temp->dado;
    Fila->inicio = temp->prox;
    delete temp;
    return dado;
}


//QUEUE: insere um elemento no final da Fila  
template <typename T>
void insertQueue(queue<T> &Fila, T dado) {
    elementos<T> *NovoDado = new elementos<T>{dado, nullptr};
    if (Fila.inicio == nullptr) {
        Fila.inicio = Fila.fim = NovoDado;
    } else {
        Fila.fim->prox = NovoDado;
        Fila.fim = NovoDado;
    }
}

template <typename T> 
void printQueue(queue<T> Fila){
  elementos<T> * Temp;
  Temp = Fila.inicio;
    while (Temp != NULL) {
      cout << Temp->dado << "\n";
      Temp = Temp->prox;
    }
}

#endif