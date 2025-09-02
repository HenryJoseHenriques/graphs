int **createMatrix(int tam);
void freeMemory(int **matriz, int tam);
void Directed(int **matriz, int tam);
void NoDirected(int **matriz, int tam);
void printMatrix(int **matriz, int tam);
bool verifyMatrixZero(int **matriz, int tam);
void fillMatrix(int **matriz, int tam);

void searchVertex(int **matriz, int tam, int i, int j);

void addVertex(int **matriz, int tam, int i, int j, bool isDirected);
void rmvVertex(int **matriz, int tam, int i, int j, bool isDirected);
void addEdge(int **matriz, int tam, int i, int j, bool isDirected);
void rmvEdge(int **matriz, int tam, int i, int j, bool isDirected);

int **createMatrix(int tam)
{
    int **matriz;
    matriz = new int *[tam];
    for (int i = 0; i < tam; i++)
    {
        matriz[i] = new int[tam];
    }
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

void free(int **matriz, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void Directed(int **matriz, int tam)
{
    int i, j;
    while (true)
    {
        cout << "\nIndique a conexao desejada da linha.(-1 para finalizar)\n";
        cin >> i;
        if (i <= -1)
            break;
        i = i - 1;

        cout << "\nIndique a conexao desejada da coluna.(-1 para finalizar)\n";
        cin >> j;
        if (j <= -1)
            break;
        j = j - 1;
        matriz[i][j] = 1;
        clearScreen();
    }
}

void NoDirected(int **matriz, int tam)
{
    int i, j;
    while (true)
    {
        do
        {
            cout << "\nIndique a conexao desejada da linha.(-1 para finalizar)\n";
            cin >> i;
            if (i <= -1)
                break;
            if (i == 0 || i > tam)
            {
                cout << "Tamanho invalido. Tente novamente.";
            }
        } while (i == 0 || i > tam);

        i = i - 1;

        do
        {
            cout << "\nIndique a conexao desejada da coluna.(-1 para finalizar)\n";
            cin >> j;
            if (j <= -1)
                break;
            if (j == 0 || j > tam)
            {
                cout << "Tamanho invalido. Tente novamente.";
            }
        } while (j == 0 || j > tam);

        j = j - 1;

        matriz[i][j] = 1;
        matriz[j][i] = 1;
        clearScreen();
    }
}

void printMatrix(int **matriz, int tam)
{
    cout << "\t";
    for (int j = 0; j < tam; j++)
        cout << j + 1 << "\t";
    cout << "\n";

    for (int i = 0; i < tam; i++)
    {
        cout << i + 1 << ":\t";
        for (int j = 0; j < tam; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << endl;
}

bool verifyMatrixZero(int **matriz, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (matriz[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

void fillMatrix(int **matriz, int tam, bool &isDirected)
{
    char respodrg;
    do
    {

        clearScreen();
        cout << "\nTrata-se de uma matriz dirigido?(S ou N)\n";
        cin >> respodrg;
        respodrg = toupper(respodrg);
        if (respodrg != 'S' && respodrg != 'N')
        {
            clearScreen();
            cout << "\nResposta invalida. Tente novamente.\n";
            pauseScreen();
        }
        else if (respodrg == 'S')
        {
            clearScreen();
            isDirected = true;
            Directed(matriz, tam);
        }
        else if (respodrg == 'N')
        {
            clearScreen();
            isDirected = false;
            NoDirected(matriz, tam);
        }
    } while (respodrg != 'S' && respodrg != 'N');
}

void addVertex(int **&matriz, int &tam, int newTam, bool isDirected)
{
    int **newMatriz = createMatrix(newTam);
    cout << "Matriz zerada: \n";
    printMatrix(newMatriz, newTam);
    cout << "\n";
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            newMatriz[i][j] = matriz[i][j];
        }
    }
    free(matriz, tam);
    matriz = newMatriz;
    tam = newTam;
    cout << "novo tamanho " << tam << "\n";
    cout << "Nova matriz: \n";
    printMatrix(newMatriz, newTam);
    cout << "\n";

    if (isDirected)
        Directed(matriz, tam);
    else
        NoDirected(matriz, tam);
}

void rmvVertex(int **&matriz, int &tam, int k, bool isDirected)
{
    int newTam = tam - 1;
    int **newMatriz = createMatrix(newTam);

    for (int i = 0, in = 0; i < tam; i++)
    {
        if (i == k)
            continue;

        for (int j = 0, jn = 0; j < tam; j++)
        {
            if (j == k)
                continue;
            newMatriz[in][jn] = matriz[i][j];
            jn++;
        }
        in++;
    }

    free(matriz, tam);
    matriz = newMatriz;
    tam = newTam;

    cout << "Matriz pos removacao do vertice: " << k + 1 << ": \n";
    printMatrix(matriz, tam);
    cout << "\n";
}

void addEdge(int **matriz, int tam, int i, int j, bool isDirected)
{
    matriz[i][j] = 1;
    if (!isDirected)
        matriz[j][i] = 1;
}

void rmvEdge(int **matriz, int tam, int i, int j, bool isDirected)
{
    matriz[i][j] = 0;
    if (!isDirected)
        matriz[j][i] = 0;
}

void walkVertex(int **matriz, int tam, bool *&visited, int v, queue<int> &nextVisited)
{
    insertQueue(nextVisited, v);
    visited[v] = true;

    while (nextVisited.inicio != NULL)
    {
        v = dequeue(&nextVisited);

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

void callVerterx(int **matriz, int tam, bool *&visited, int v)
{
    queue<int> nextVisited;
    initQueue(nextVisited);

    if (v <= -1)
        return;
    if (v > 0)
        v--;

    walkVertex(matriz, tam, visited, v, nextVisited);

    bool existe = false;
    for (int i = 0; i < tam; i++)
    {
        if (visited[i])
        {
            existe = true;
            break;
        }
    }

    if (existe)
        cout << "O vertice " << v + 1 << " existe no grafo\n";
    else
        cout << "O vertice " << v + 1 << " NAO existe no grafo\n";
}

void operation(int **&matriz, int &tam, bool isDirected)
{
    int escolha, i, j, vertice;
    bool *visited = initVisited(tam);
    do
    {
        clearScreen();
        cout << "1 - adicionar aresta\n";
        cout << "2 - remover aresta\n";
        cout << "3 - adicionar vertice\n";
        cout << "4 - remover vertice\n";
        cout << "5 - pesquisar\n";
        cout << "6 - retornar\n";
        cin >> escolha;
        if (escolha <= 0 && escolha > 5)
        {
            clearScreen();
            cout << "Opcao invalida\n";
            pauseScreen();
        }
        switch (escolha)
        {
        case 1:
            clearScreen();
            printMatrix(matriz, tam);
            do
            {
                cout << "Digite a linha que deseja adicionar:\n";
                cin >> i;
                if (i <= 0 || i > tam)
                    cout << "valor invalido";
                cout << "Digite a coluna que deseja adicionar:\n";
                cin >> j;
                if (j <= 0 || j > tam)
                    cout << "valor invalido";
            } while (i <= 0 || i > tam && j <= 0 || j > tam);
            i--;
            j--;
            addEdge(matriz, tam, i, j, isDirected);
            printMatrix(matriz, tam);
            pauseScreen();
            break;
        case 2:
            clearScreen();
            printMatrix(matriz, tam);
            do
            {
                cout << "Digite a linha que deseja remover:\n";
                cin >> i;
                if (i <= 0 || i > tam)
                    cout << "Valor inválido\n";
                cout << "Digite a coluna que deseja remover:\n";
                cin >> j;
                if (j <= 0 || j > tam)
                    cout << "Valor inválido\n";
            } while (i <= 0 || i > tam || j <= 0 || j > tam);
            i--;
            j--;
            rmvEdge(matriz, tam, i, j, isDirected);
            printMatrix(matriz, tam);
            pauseScreen();
            break;
        case 3:
            char resposta;
            clearScreen();
            printMatrix(matriz, tam);
            do
            {
                cout << "Escolha o novo vertice(nao pode ser menor que o limite atual da matriz): \n";
                cin >> vertice;
                if (vertice <= 0 || vertice <= tam)
                    cout << "valor invalido\n";
            } while (vertice <= 0 || vertice <= tam);
            addVertex(matriz, tam, vertice, isDirected);
            printMatrix(matriz, tam);
            pauseScreen();
            break;
        case 4:
            clearScreen();
            printMatrix(matriz, tam);
            do
            {
                cout << "Escolha o vertice que deseja remover(vai diminuir o tamanho da matriz):\n";
                cin >> vertice;
                if (vertice <= 0 && vertice > tam)
                    cout << "valor invalido\n";
            } while (vertice <= 0 && vertice > tam);
            vertice--;
            rmvVertex(matriz, tam, vertice, isDirected);
            pauseScreen();
            break;
        case 5:
            int pesquisa;
            do
            {
                cout << "Digite o vertice que deseja pesquisar(nao pode ser maior que o tamanho): \n";
                cin >> pesquisa;
                if (pesquisa <= 0 || pesquisa > tam)
                    cout << "valor invalido ou nao existente\n";
            } while (pesquisa <= 0 || pesquisa > tam);
            clearScreen();
            callVerterx(matriz, tam, visited, pesquisa);
            free(visited);
            pauseScreen();
            break;
        case 6:
            clearScreen();
            return;
            break;
        default:
            cout << "Valor invalido\n";
            break;
        }
    } while (escolha != 6);
}