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
        cout << "3 - sair\n";
        cout << "Escolha: ";
        cin >> escolha;
        switch (escolha)
        {
        case 1:
            clearScreen();
            cout << "\nEscreva o tamanho da matriz:\n";
            cin >> tam;
            matriz = createMatrix(tam);

            fillMatrix(matriz, tam);
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

            // clearScreen();
            cout << "\t\tMatriz:\n";
            printMatrix(matriz, tam);

            visited = initVisited(tam);
            callDFS(matriz, tam, visited, v);
            free(visited);

            cout << endl;

            visited = initVisited(tam);
            callBFS(matriz, tam, visited, v);
            free(visited);

            pauseScreen();

            free(matriz, tam);
            break;
        case 2:
            if (tam <= 0)
            {
                clearScreen();
                cout << "Tamanho da matriz nao definido. Retorno e preenchar primeiro.\n";
                pauseScreen();
            }
            else
            {
                int pesquisa;

                cout << "Digite o vertice que deseje pesquisar: \n";
                cin >> pesquisa;
                if (pesquisa <= 0 || pesquisa >= tam)
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
            cout << "Saindo...Tenha um otimo dia.\n";
            break;
        default:
            clearScreen();
            cout << "Escolha nao aceita. Tente novamente.\n";
            pauseScreen();
            break;
        }
    } while (escolha != 3);
    return 0;
}