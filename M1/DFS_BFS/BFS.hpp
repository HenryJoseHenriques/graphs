#include "queue.hpp"

void walkBFS(int **matriz, int tam, bool *&visited, int v);
void callBFS(int **matriz, int tam, bool *&visited);

void walkBFS(int **matriz, int tam, bool *&visited, int v, queue<int> &nextVisited, bool isDirected)
{
    insertQueue(nextVisited, v);
    visited[v] = true;
    bool first = true;
    while (nextVisited.inicio != NULL)
    {
        v = dequeue(&nextVisited);
        if (first)
        {
            cout << v + 1;
            first = false;
        }
        else
        {
            if (isDirected)
            {
                cout << "->";
            }
            else
            {
                cout << "--";
            }
            cout << v + 1;
        }
        for (int k = 0; k < tam; k++)
        {
            if (matriz[v][k] == 1 && !visited[k])
            {
                visited[k] = true;
                insertQueue(nextVisited, k);
            }
        }
    }
}

void callBFS(int **matriz, int tam, bool *&visited, int v, bool isDirected)
{
    queue<int> nextVisited;
    initQueue(nextVisited);
    if (v <= -1)
        return;
    if (v > 0)
        v--;
    cout << "Breadth-First-Search:";
    walkBFS(matriz, tam, visited, v, nextVisited, isDirected);
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
            {
                if (isDirected)
                {
                    cout << "->";
                }
                else
                {
                    cout << "--";
                }
                walkBFS(matriz, tam, visited, i, nextVisited, isDirected);
            }
        }
    }
}