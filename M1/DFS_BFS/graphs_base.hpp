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
        // clearScreen();
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

void addVertex(int **matriz, int &tam, int k, bool isDirected)
{
    int newTam = tam+1;
    int **newMatriz = createMatrix(newTam);
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            newMatriz[i][j] = matriz[i][j];
        }
    }
    free(matriz,tam);
    matriz = newMatriz;
    tam = newTam;
    if(isDirected)
        Directed(matriz,tam);
    else
        NoDirected(matriz,tam);
}       

void rmvVertex(int **matriz, int tam, int k, bool isDirected)
{
    int newTam = tam-1;
    int **newMatriz = createMatrix(newTam);
    for (int i = 0; i < newTam; i++)
    {
        for (int j = 0; j < newTam; j++)
        {
            if(i != k){
                newMatriz[i][j] = matriz[i][j];
                if(!isDirected)
                    newMatriz[j][i] = matriz[j][i];
            }
        }
    }
    free(matriz,tam);
    matriz = newMatriz;
    tam = newTam;
}

void addEdge(int **matriz, int tam, int i, int j, bool isDirected){
    matriz[i][j] = 1;
    if(!isDirected)
        matriz[j][i] = 1;
}

void rmvEdge(int **matriz, int tam, int i, int j, bool isDirected){
    matriz[i][j] = 0;
    if(!isDirected)
        matriz[j][i] = 0;
}