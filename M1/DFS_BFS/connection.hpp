
bool *copy(bool *original, int tam)
{
    bool *copia = new bool[tam];
    for (int i = 0; i < tam; i++)
    {
        copia[i] = original[i];
    }
    return copia;
}

void connections(int **matriz, int tam, bool *&visited, bool isDirected)
{
    queue<int> nextVisited;
    initQueue(nextVisited);
    for (int i = 0; i < tam; i++)
    {
        if (visited[i])
        {
            walkBFS(matriz, tam, visited, i, nextVisited, isDirected, false);
        }
    }
}