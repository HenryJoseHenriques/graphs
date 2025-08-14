#include <iostream>
using namespace std;
#include "vertex.hpp"
#include "DFS.hpp"
#include "BFS.hpp"

int main()
{
    int **matriz;
    int tam;
    cout << "\nEscreva o tamanho da matriz:\n";
    cin >> tam;
    matriz = createMatrix(tam);
    
    fillMatrix(matriz,tam);
    printMatrix(matriz,tam);

    bool *visited = initVisited(tam);
    int v;
    callDFS(matriz,tam, visited);

    freeMemory(matriz,tam);
    freeVisited(visited);
    return 0;
}