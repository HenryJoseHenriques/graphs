void transitiveClosureDirected(int **matriz, int tam, int start, bool *visited);
void transitiveClosureInverse(int **matriz, int tam, int start, bool *visited);
void callTCDeI(int **matriz, int tam, bool *visited);

void transitiveClosureDirected(int **matriz, int tam, int start)
{

    if (start < 0 || start >= tam)
    {
        cout << "Vertice inicial fora dos limites.\n";
        return;
    }

    bool *visited = new bool[tam];
    for (int i = 0; i < tam; ++i)
        visited[i] = false;

    cout << "Matriz original:\n";
    printMatrix(matriz, tam);
    cout << "\n";

    int **transtive = createMatrix(tam);
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            transtive[i][j] = matriz[i][j];

    bool first = true;
    queue<int> nextVisited;
    initQueue(nextVisited);
    insertQueue(nextVisited, start);
    visited[start] = true;
    cout << "fecho transitivo direto de " << start+1 << ":{";
    while (nextVisited.inicio != NULL)
    {
        int v = dequeue(&nextVisited);
        for (int k = 0; k < tam; k++)
        {
            if (matriz[v][k] == 1 && !visited[k])
            {
                visited[k] = true;
                insertQueue(nextVisited, k);
                transtive[start][k] = 1;
                if (first)
                {
                    cout << (k + 1);
                    first = false;
                }
                else
                {
                    cout << "," << (k + 1);
                }
            }
        }
    }
    cout << "}";

    cout << "\nPelo fecho transitivo direto do vertice " << start + 1 << ": \n";
    printMatrix(transtive, tam);
    free(transtive, tam);
    delete[] visited;
}

void transitiveClosureInverse(int **matriz, int tam, int start)
{
    if (start < 0 || start >= tam)
    {
        cout << "Vertice inicial fora dos limites.\n";
        return;
    }

    bool *visited = new bool[tam];
    for (int i = 0; i < tam; ++i)
        visited[i] = false;

    cout << "Matriz original:\n";
    printMatrix(matriz, tam);
    cout << "\n";

    int **transtive = createMatrix(tam);
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            transtive[i][j] = matriz[i][j];

    bool first = true;
    queue<int> nextVisited;
    initQueue(nextVisited);

    insertQueue(nextVisited, start);
    visited[start] = true;

    cout << "Fecho transitivo inverso de " << start + 1 << ":{";

    while (nextVisited.inicio != NULL)
    {
        int v = dequeue(&nextVisited);
        for (int k = 0; k < tam; k++)
        {
            // se existe aresta k -> v
            if (matriz[k][v] == 1 && !visited[k])
            {
                visited[k] = true;
                insertQueue(nextVisited, k);
                transtive[k][start] = 1;
                if (first)
                {
                    cout << (k + 1);
                    first = false;
                }
                else
                {
                    cout << "," << (k + 1);
                }
            }
        }
    }
    cout << "}\n";

    cout << "\nPelo fecho transitivo inverso do vertice " << start + 1 << ": \n";
    printMatrix(transtive, tam);

    free(transtive, tam);
    delete[] visited;
}

void callTCDeI(int **matriz, int tam)
{
    int start;
    char resposta;

    cout << "Digite o vertice que deseja visualizar o fecho transtivo:\n ";
    cin >> start;
    if (start <= -1)
        return;
    if (start > 0)
        start--;
    cout << "A matriz e direta por padrao, mas trata-se de uma transitiva inversa? (S ou N):\n";
    cin >> resposta;
    resposta = toupper(resposta);
    if (resposta != 'S' && resposta != 'N')
    {
        clearScreen();
        cout << "\nResposta invalida. Tente novamente.\n";
        pauseScreen();
    }
    else if (resposta == 'S')
    {
        transitiveClosureDirected(matriz, tam, start);
    }
    else if (resposta == 'N')
    {
        transitiveClosureInverse(matriz, tam, start);
    }
}