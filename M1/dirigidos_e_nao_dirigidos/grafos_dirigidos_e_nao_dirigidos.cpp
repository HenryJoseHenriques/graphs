#include <iostream>
using namespace std;

int **criarMatriz(int tam){
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

void liberarMemoria(int **matriz, int tam){
    for(int i = 0; i < tam;i++){
        delete [] matriz[i];
    }
    delete[] matriz;
}

void preecherDirigida(int **matriz, int tam){
    //bool trava = true;
    int i,j;
    //while(trava){
    while(true){
        cout << "\nIndique a conexão desejada da linha.(-1 para finalizar)\n";
        cin >> i;
        if(i <= -1) break;
        i = i-1;
        
        cout << "\nIndique a conexão desejada da coluna.(-1 para finalizar)\n";
        cin >> j;
        if(j <= -1) break;
        j = j-1;
        
        matriz[i][j] = 1;
        matriz[j][i] = 1;
    }
}

void preecherNaoDirigida(int **matriz, int tam){
    //bool trava = true;
    int i,j;
    //while(trava){
    while(true){
        cout << "\nIndique a conexão desejada da linha.(-1 para finalizar)\n";
        cin >> i;
        if(i <= -1) break;
        i = i-1;
        
        cout << "\nIndique a conexão desejada da coluna.(-1 para finalizar)\n";
        cin >> j;
        if(j <= -1) break;
        j = j-1;
        
        matriz[i][j] = 1;
    }
}

void exibirMatriz(int **matriz, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

void preencherMatriz(int **matriz, int tam){
    char respodrg;
    cout << "\nÉ dirigido?(S ou N)\n";
    cin >> respodrg;
    respodrg = toupper(respodrg);
    if(respodrg != 'S' && respodrg != 'N'){
        cout << "\nResposta não aceita.\n";
    }else if(respodrg == 'S'){
        preecherDirigida(matriz, tam);
    }else if(respodrg == 'N'){
        preecherNaoDirigida(matriz, tam);
    }
}

int main()
{
    int **matriz;
    int tam;
    cout << "\nEscreva o tamanho da matriz:\n";
    cin >> tam;
    matriz = criarMatriz(tam);
    preencherMatriz(matriz,tam);
    exibirMatriz(matriz,tam);
    liberarMemoria(matriz,tam);
    return 0;
}