#include "queue.hpp"

void walkBFS(int **matriz, int tam, bool *&visited, int v);
void callBFS(int **matriz, int tam, bool *&visited);

void walkBFS(int **matriz, int tam, bool *&visited, int v, queue<int> &nextVisited){
    //visited[v] = true;
    insertQueue(nextVisited,v);
    //cout << v+1;
    bool first = true;
    while(nextVisited.inicio != NULL){
        v = dequeue(&nextVisited);
        if(first){
            cout << v+1;
            first = false;
        }else{
            cout << "->" << v+1;
        }
        for(int k = 0; k < tam; k++){
            if(matriz[v][k] == 1 && !visited[k]){
                visited[k] = true;
                insertQueue(nextVisited,k);
                cout << "->" << k+1;
            }
        }
    }
}

void callBFS(int **matriz, int tam, bool *&visited){
    queue<int> nextVisited;
    initQueue(nextVisited);
    int v;
    cout << "\nEscolha um vertice para dar inicio ao caminho:(-1 ou menor para sair)\n";
    cin >> v;
    if (v <= -1)
        return;
    if (v > 0 )
        v--;
    cout << "Breadth-First-Search:";
    walkBFS(matriz,tam,visited,v,nextVisited);
        walkDFS(matriz, tam, visited, v);
    for (int i = 0; i < tam; i++)
    {
        if (!visited[i])
        {
            bool temAresta = false;
            for (int j = 0; j < tam; j++)
            {
                if (matriz[i][j] == 1)
                {
                    temAresta = true;
                    break;
                }
            }
            if (temAresta)
                walkBFS(matriz,tam,visited,i,nextVisited);
        }
    }
}