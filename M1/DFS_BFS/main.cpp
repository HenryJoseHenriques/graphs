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

//bool caminharDFS(const int **&matriz, int tam ,int *&visited, int v, stack<int> &pilha){
bool caminharDFS(const int **&matriz, const int tam ,int *&visited, int v){
    //E se nenhum foi visitado?
    //E se todos foram visitados?
    //E se um não está conectado com ninguém?
    
    if(visited[v] == 0){
        visited[v] = 1;
        cout << v << " ";
        int k = 0;
        while(k < tam){
            if(matriz[v][k] == 1){
                return caminharDFS(matriz, tam, visited, k);
            }
            k++;
        }
    }else if(visited[v] ==  1){
        
        return caminharDFS(matriz, tam, visited, v);
    }
    
}

void DFS(const int **&matriz, int tam, int *visited){
    stack<int> pilha;
    initStack(pilha);
    int *vertice;
    bool *visited = new bool[tam];
    for(int i = 0; i < tam; i++) visited[i] = 0;

    int v;
    cout << "\nEscolha um vertice para dar inicio ao caminho:(-1 ou menor para sair)\n";
    cin >> v;
    if(v <= -1) return;
    if(v != 0) v = v - 1;
    caminharDFS(matriz,tam,visited,v);
}

int main()
{
    int **matriz;
    int tam;
    cout << "\nEscreva o tamanho da matriz:\n";
    cin >> tam;
    matriz = criarMatriz(tam);
    bool *visited = initVisited(tam);
    preencherMatriz(matriz,tam);
    exibirMatriz(matriz,tam);

    /*BFS*/
    queue<int> fila;
    initQueue(fila);

    liberarMemoria(matriz,tam);
    return 0;
}