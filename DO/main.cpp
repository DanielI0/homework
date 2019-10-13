#include <iostream>
using namespace std;
//derevo otrezkov

int* t;
int littleThing(int a, int b)
{
   if (b == 0)
		return a;
	else
		return littleThing (b, a % b);
}
void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		//t[v] = t[v*2] + t[v*2+1];
		t[v] = littleThing(t[v*2],t[v*2+1]);
	}
}
int sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm))
		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}
int gcd(int v, int tl, int tr, int l, int r)
{
    if (l > r){

        return 0;

    }

	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return littleThing(gcd (v*2, tl, tm, l, min(r,tm)), gcd (v*2+1, tm+1, tr, max(l,tm+1), r));
}
int main()
{

    int n;
    cin >> n;
    t = new int[4*n];
    int* data = new int[n];
    for(int i = 0; i < n;i++)
        cin >> data[i];
    build(data, 1, 0, n-1);
    int k, l, r;
    cin >> k;
    for(int i = 0;i<k;i++)
    {
        cin >> l>>r;
        cout << gcd(1, 0, n-1, l-1,r-1)<<" ";
    }
    return 0;
}
