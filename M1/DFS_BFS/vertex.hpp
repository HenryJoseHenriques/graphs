//#include <iostream>
//using namespace std;

bool *initVisited(int tam)
{
    bool *visited = new bool[tam];
    for (int i = 0; i < tam; i++)
        visited[i] = 0;
    return visited;
}

void free(bool *&visited)
{
    delete[] visited;
}

int findUnvisitedVertex(int tam, bool *visited)
{
    int v, k = 0;
    while (k < tam)
    {
        if (visited[k] == 0)
        {
            v = k;
            return v;
        }
        k++;
    }
    return -1;
}
