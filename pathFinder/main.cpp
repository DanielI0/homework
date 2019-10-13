#include <fstream>

using namespace std;
int v1, v2, n;
int** graph;
bool k = false;
bool* used;
int dfs(int v){
    used[v] = true;
    if(v==v2){
        k = true;
        return 1;
    }
    for(int i = 0; i<n; i++)
    {

        if(!used[i] && graph[v][i] != 0 && graph[v][i] != -1)
            dfs(i);
    }
    return 0;
}
int main()
{
    ifstream fin("data2.in");
    ofstream fout("file.out");



    fin >> n >> v1 >> v2;
    v1--;
    v2--;
    used = new bool[n];
    for(int i = 0; i<n;i++)
        used[i] = false;

    graph = new int*[n];

    for(int i = 0; i < n; i++){
            graph[i] = new int[n];
            for(int j = 0; j < n ;j++)
                fin >> graph[i][j];
    }
    dfs(v1);
    fout <<(k ? "true":"false");
    return 0;
}
