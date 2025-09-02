void walkConnections(int **matriz, int tam, bool *&visited, int v)
{
    queue<int> nextVisited;
    initQueue(nextVisited);

    insertQueue(nextVisited, v);
    visited[v] = true;

    cout << "{ "; // abre um subgrafo
    while (nextVisited.inicio != NULL)
    {
        v = dequeue(&nextVisited);
        cout << v + 1 << " "; // mostra vértice do componente

        for (int k = 0; k < tam; k++)
        {
            if (matriz[v][k] == 1 && !visited[k])
            {
                visited[k] = true;
                insertQueue(nextVisited, k);
            }
        }
    }
    cout << "}\n"; // fecha o subgrafo
}

void checkConexidade(int **matriz, int tam)
{
    bool *visited = new bool[tam];
    for (int i = 0; i < tam; i++) visited[i] = false;

    int componentes = 0;

    for (int i = 0; i < tam; i++)
    {
        if (!visited[i])
        {
            componentes++;
            walkConnections(matriz, tam, visited, i);
        }
    }

    if (componentes == 1)
        cout << "O grafo eh conexo\n";
    else
        cout << "O grafo NAO eh conexo. Existem " << componentes << " componentes conexos.\n";
}
