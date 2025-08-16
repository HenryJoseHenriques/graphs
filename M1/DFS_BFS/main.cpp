#include <iostream>
using namespace std;
#include "screen.hpp"
#include "graphs_base.hpp"
#include "vertex.hpp"
#include "DFS.hpp"
#include "BFS.hpp"

int main()
{
    int **matriz;
    bool *visited;
    int v, escolha, tam = 0;
    do
    {
        clearScreen();
        cout << "\t\tMENU:\n";
        cout << "1 - Preecher matriz\n";
        cout << "2 - Pesquisar vertice\n";
        cout << "3 - Creditos\n";
        cout << "4 - Sair\n";
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
                if(tam <= 0){
                    cout << "Tamanho nao aceito. Tente novamente.\n";
                    pauseScreen();
                }
            } while (tam <= 0);
            matriz = createMatrix(tam);

            fillMatrix(matriz, tam);
            if (verifyMatrixZero(matriz, tam))
            {
                clearScreen();
                cout << "Matriz nula. Volte e preecha a matriz.\n";
                pauseScreen();
            }
            else
            {
                printMatrix(matriz, tam);
                pauseScreen();
                do
                {
                    clearScreen();
                    cout << "\nEscolha um vertice para dar inicio ao caminho:(-1 ou menor para sair)\n";
                    cin >> v;
                    if (v <= 0 || v >= tam)
                    {
                        cout << "O vertice escolhido esta fora dos limites da matriz. Tente novamente.\n";
                        pauseScreen();
                    }
                } while (v <= 0 || v >= tam);

                cout << "\t\tMatriz:\n";
                printMatrix(matriz, tam);

                visited = initVisited(tam);
                callDFS(matriz, tam, visited, v);
                free(visited);

                cout << endl;

                visited = initVisited(tam);
                callBFS(matriz, tam, visited, v);
                free(visited);

                cout << endl;
                pauseScreen();

                free(matriz, tam);
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
                int pesquisa;
                cout << "Digite o vertice que deseja pesquisar: \n";
                cin >> pesquisa;
                if (pesquisa <= 0 || pesquisa > tam)
                {
                    clearScreen();
                    cout << "O vertice " << pesquisa << " NAO foi localizado no grafo.\n";
                    pauseScreen();
                }
                else
                {
                    clearScreen();
                    cout << "O vertice " << pesquisa << " existe no grafo.\n";
                    pauseScreen();
                }
            }
            break;
        case 3:
            clearScreen();
            cout << "Universidade do Vale do Itajai - UNIVALI\n";
            cout << "Engenharia de Computacao\n";
            cout << "Academicos: Henry Jose, Ian Marcos e Vinicius Tridapalli\n";
            cout << "Disciplina: Grafos\n";
            cout << "Professor: Rudimar Luis\n";
            pauseScreen();
            break;
        case 4:
            clearScreen();
            cout << "Saindo...Tenha um otimo dia.\n";
            break;
        default:
            clearScreen();
            cout << "Escolha nao aceita. Tente novamente ou reinicie o programa.\n";
            pauseScreen();
            break;
        }
    } while (escolha != 4);
    return 0;
}