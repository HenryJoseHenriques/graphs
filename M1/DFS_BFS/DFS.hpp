void walkDFS(int **matriz, int tam, bool *&visited, int v);
void callDFS(int **matriz, int tam, bool *&visited);

void walkDFS(int **matriz, int tam, bool *&visited, int v)
{

    visited[v] = true;
    cout << v + 1;
    for (int k = 0; k < tam; k++){
        if (matriz[v][k] == 1 && visited[k] == 0){
            cout << "->";
            walkDFS(matriz, tam, visited, k);
        }
    }
}

void callDFS(int **matriz, int tam, bool *&visited)
{
    int v;
    cout << "\nEscolha um vertice para dar inicio ao caminho:(-1 ou menor para sair)\n";
    cin >> v;
    if (v <= -1)
        return;
    if (v > 0)
        v--;
    
    cout << "Depth-First-Search:";
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
                walkDFS(matriz, tam, visited, i);
        }
    }
}