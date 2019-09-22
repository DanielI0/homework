#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
//*****************************500**************************************\\
int main()
{

    int n, age, rep;
    cin >> n;
    map<int,int> agents;
    for(int i = 0; i< n;i++){
        cin >> age >> rep;
        agents.insert(make_pair(age, rep));
    }

    int* dp = new int[n+1];
    auto iter = agents.begin();
    iter++;
    dp[2] = (*iter).second;
    iter++;
    dp[3] = dp[2]+(*iter).second;
    iter++;
    for(int  i = 4; i<=n;i++){
        dp[i] = min(dp[i-1], dp[i-2]) + (*iter).second;
       // cout << dp[i]<<endl;
        iter++;
    }
    cout << dp[n];
    return 0;
}
