//#include <iostream>
//using namespace std;

int **createMatrix(int tam);
void freeMemory(int **matriz, int tam);
void Directed(int **matriz, int tam);
void NoDirected(int **matriz, int tam);
void printMatrix(int **matriz, int tam);
void fillMatrix(int **matriz, int tam);

int **createMatrix(int tam){
    int **matriz;
    matriz = new int*[tam];
    for(int i = 0; i < tam;i++){
        matriz[i] = new int[tam];
    }
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

void freeMemory(int **matriz, int tam){
    for(int i = 0; i < tam;i++){
        delete [] matriz[i];
    }
    delete[] matriz;
}

void Directed(int **matriz, int tam){
    //bool trava = true;
    int i,j;
    //while(trava){
    while(true){
        cout << "\nIndique a conexao desejada da linha.(-1 para finalizar)\n";
        cin >> i;
        if(i <= -1) break;
        i = i-1;
        
        cout << "\nIndique a conexao desejada da coluna.(-1 para finalizar)\n";
        cin >> j;
        if(j <= -1) break;
        j = j-1;
        
        matriz[i][j] = 1;
        matriz[j][i] = 1;
    }
}

void NoDirected(int **matriz, int tam){
    //bool trava = true;
    int i,j;
    //while(trava){
    while(true){
        cout << "\nIndique a conexao desejada da linha.(-1 para finalizar)\n";
        cin >> i;
        if(i <= -1) break;
        i = i-1;
        
        cout << "\nIndique a conexao desejada da coluna.(-1 para finalizar)\n";
        cin >> j;
        if(j <= -1) break;
        j = j-1;
        
        matriz[i][j] = 1;
    }
}

void printMatrix(int **matriz, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

void fillMatrix(int **matriz, int tam){
    char respodrg;
    cout << "\nTrata-se de uma matriz dirigido?(S ou N)\n";
    cin >> respodrg;
    respodrg = toupper(respodrg);
    if(respodrg != 'S' && respodrg != 'N'){
        cout << "\nResposta invalida.\n";
    }else if(respodrg == 'S'){
        Directed(matriz, tam);
    }else if(respodrg == 'N'){
        NoDirected(matriz, tam);
    }
}