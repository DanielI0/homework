#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
map<string, bool> used;
int count=-1, n;
bool result = false;
map<string, vector<string>> graph;
int dfs(string vertex, string prapor){
    used[vertex] = true;
    if(prapor==vertex)  count++;
    if(count==1) {
            result = true;
            return -1;
    }
    for(string i : graph[vertex]){
        if(i==prapor){
            result = true;
            return -1;

        }
        if(!used[i])dfs(i, prapor);
    }
    return 0;
}
int main()
{
    vector<string> vertexes, log;
    string line, v1, v2;
    int raz;
    cin >> n;
    vector<int> inp;
    for(int i = 0;i<n;i++) {
        cin >> v1;
        log.push_back(v1);
        used[v1] = false;
        cin >> raz;
        for(int i = 0; i<raz;i++)
        {
         cin>>v2;
         vertexes.push_back(v2);
        }
        graph.insert(make_pair(v1,vertexes));
        vertexes.clear();
        cin >> line;
    }


    for(string i : log){
        dfs(i, i);
        for(auto j = used.begin();j!=used.end();j++) (*j).second = false;
        cout <<((result==true) ? "YES":"NO")<<endl;
        result = false;
        count = -1;
    }

    return 0;
}
