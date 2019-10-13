#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* dp = new int[n+1];
    int* a = new int[n+1];
    for(int i = 0;i<n;i++)
        cin >> a[i];
    dp[0] = 0;
    dp[1] = abs(a[1] - a[0]);
    for(int i = 2; i < n; i++)
        dp[i] = min(dp[i-2] + 3*abs(a[i]-a[i-2]),dp[i-1] + abs(a[i]-a[i-1]));
    if(n!=1) cout << dp[n-1];
    else cout << 0;
    return 0;
}
