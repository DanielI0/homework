#include <iostream>
#include <string>
using namespace std;
int main(){
    string s, r = "";
    int iter;
    getline(cin, s);
    iter = s.find_last_not_of(" ");
    for (int i = iter; i>=0;i--)
    {
        if(s[i]==' ') break;
        r+= s[i];
    }
    //cout<<r<<endl;
    for(auto i = r.end() - 1; i >= r.begin();i--)
        cout << (*i);


}
