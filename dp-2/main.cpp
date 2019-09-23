#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int* dp = new int[n+1];
    dp[1] = k-1;
    dp[2] = (k-1)*k;
    for(int i = 3; i<=n;i++)
        dp[i] = (k-1)*(dp[i-2]+dp[i-1]);
    cout << dp[n];
    return 0;
}
