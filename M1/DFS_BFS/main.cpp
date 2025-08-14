#include <iostream>
#include "DFS.hpp"
using namespace std;

int main()
{
    int **matriz;
    int tam;
    cout << "\nEscreva o tamanho da matriz:\n";
    cin >> tam;
    matriz = criarMatriz(tam);
    
    preencherMatriz(matriz,tam);
    exibirMatriz(matriz,tam);

    bool *visited = initVisited(tam);
    int v;
    //DFS
    callDFS(matriz,tam, visited);


    /*BFS*/
    //queue<int> fila;
    //initQueue(fila);

    liberarMemoria(matriz,tam);
    return 0;
}