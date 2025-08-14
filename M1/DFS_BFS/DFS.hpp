#include <iostream>
#include "grafos_dirigidos_e_nao_dirigidos.hpp"
#include "elementos.cpp"
#include "pilha.hpp"
#include "fila.hpp"
using namespace std;

bool *initVisited(int tam){
    bool *visited = new bool[tam];
    for(int i = 0; i < tam; i++)
        visited[i] = 0;
    return visited;
}

void freeVisited(bool *&visited){
    delete[] visited;
}

void walkDFS(int **matriz, int tam ,bool *&visited, int v){
    int k;
    if(visited[v] == 0){
        visited[v] = 1;
        cout << v << " ";
        k = 0;
        while(k < tam){
            if(matriz[v][k] == 1 && visited[k] == 0){
                walkDFS(matriz, tam, visited, k);
            }
            k++;
        }
    }else if(visited[v] ==  1){
        k = 0;  
        while(k < tam){
            if(visited[k] == 0){
                v = k;
                break;
            }
            k++;
        }
        walkDFS(matriz, tam, visited, v);
    }
}



void callDFS(int **matriz, int tam, bool *&visited){
    //stack<int> pilha;
    //initStack(pilha);
    int *vertice;
    int v;

    cout << "\nEscolha um vertice para dar inicio ao caminho:(-1 ou menor para sair)\n";
    cin >> v;
    if(v <= -1) return;
    if(v != 0) v = v - 1;
    
    walkDFS(matriz,tam,visited,v);
}