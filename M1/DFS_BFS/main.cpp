#include <iostream>
using namespace std;
#include "screen.hpp"
#include "vertex.hpp"
#include "DFS.hpp"
#include "BFS.hpp"
#include "graphs_base.hpp"
#include "FTDeI.hpp"
#include "connection.hpp"

int main()
{
    int **matriz;
    bool *visited, isDirected;
    int v, escolha, tam = 0;
    do
    {
        clearScreen();
        cout << "\t\tMENU:\n";
        cout << "1 - Preecher matriz\n";
        cout << "2 - Visualizar matriz\n";
        cout << "3 - Operacoes\n";
        cout << "4 - Verificar Transitividade\n";
        cout << "5 - Conecoes\n";
        cout << "6 - Creditos\n";
        cout << "7 - Sair\n";
        cout << "Escolha: ";
        cin >> escolha;
        switch (escolha)
        {
        case 1:
            do
            {
                clearScreen();
                cout << "\nEscreva o tamanho da matriz:\n";
                cin >> tam;
                if (tam <= 0)
                {
                    cout << "Tamanho nao aceito. Tente novamente.\n";
                    pauseScreen();
                }
            } while (tam <= 0);
            matriz = createMatrix(tam);
            fillMatrix(matriz, tam, isDirected);

            if (verifyMatrixZero(matriz, tam))
            {
                clearScreen();
                cout << "Matriz nula. Volte e preecha a matriz.\n";
                pauseScreen();
            }
            else
            {
                bool *visited = initVisited(tam);
                printMatrix(matriz, tam);
                pauseScreen();
                do
                {
                    clearScreen();
                    cout << "\nEscolha um vertice para dar inicio ao caminho:(-1 ou menor para sair)\n";
                    cin >> v;
                    if (v <= 0 || v > tam)
                    {
                        cout << "O vertice escolhido esta fora dos limites da matriz. Tente novamente.\n";
                        pauseScreen();
                    }
                } while (v <= 0 || v > tam);

                cout << "\t\tMatriz:\n";
                printMatrix(matriz, tam);

                visited = initVisited(tam);
                callDFS(matriz, tam, visited, v, isDirected);
                (visited);

                cout << endl;

                visited = initVisited(tam);
                callBFS(matriz, tam, visited, v, isDirected);
                free(visited);

                cout << endl;
                pauseScreen();
            }
            break;
        case 2:
            if (tam <= 0)
            {
                clearScreen();
                cout << "Tamanho da matriz nao definido. Retorne, defina o tamaho da matriz e a preencha primeiro.\n";
                pauseScreen();
            }
            else
            {
                clearScreen();
                printMatrix(matriz, tam);
                pauseScreen();
            }
            break;
        case 3:
            if (tam <= 0)
            {
                clearScreen();
                cout << "Tamanho da matriz nao definido. Retorne, defina o tamaho da matriz e a preencha primeiro.\n";
                pauseScreen();
            }
            else
            {
                clearScreen();
                operation(matriz, tam, isDirected);
                pauseScreen();
            }
            break;
        case 4:
            clearScreen();
            if (tam <= 0)
            {
                clearScreen();
                cout << "Tamanho da matriz nao definido. Retorne, defina o tamaho da matriz e a preencha primeiro.\n";
                pauseScreen();
            }
            else
            {
                callTCDeI(matriz, tam);
                pauseScreen();
            }
            break;
        case 5:
            clearScreen();
            if (tam <= 0)
            {
                clearScreen();
                cout << "Tamanho da matriz nao definido. Retorne, defina o tamaho da matriz e a preencha primeiro.\n";
                pauseScreen();
            }
            else
            {
                do
                {
                    clearScreen();
                    cout << "\nEscolha um vertice para dar inicio ao caminho:(-1 ou menor para sair)\n";
                    cin >> v;
                    if (v <= 0 || v > tam)
                    {
                        cout << "O vertice escolhido esta fora dos limites da matriz. Tente novamente.\n";
                        pauseScreen();
                    }
                } while (v <= 0 || v > tam);
                visited = initVisited(tam);
                checkConexidade(matriz,tam);
                free(visited);
                pauseScreen();
            }
            break;
        case 6:
            clearScreen();
            cout << "Universidade do Vale do Itajai - UNIVALI\n";
            cout << "Engenharia de Computacao\n";
            cout << "Academicos: Henry Jose, Ian Marcos e Vinicius Tridapalli\n";
            cout << "Disciplina: Grafos\n";
            cout << "Professor: Rudimar Luis\n";
            pauseScreen();
            break;
        default:
        case 7:
            clearScreen();
            cout << "Saindo...Tenha um otimo dia.\n";
            break;
        }
    } while (escolha != 7);
    free(matriz, tam);
    return 0;
}