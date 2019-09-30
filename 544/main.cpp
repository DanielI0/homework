#include <iostream>
#include <vector>


using namespace std;
typedef vector<int> lnum;
const int base = 1;
int getCarry(lnum a, int stepen){
    int carry = 0;
        for (int i=(int)a.size()-1; i>=0; --i) {
            long long cur = a[i] + carry * 1ll * base;
            a[i] = int (cur / 2);
            carry = int (cur % 2);
        }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    if(stepen == 1) return carry;
    return getCarry(a, stepen - 1);
}
int main()
{
    lnum myVector;
    int nUM;
    cin >> nUM;
    for(int i = 1; i<=nUM;i++)
    {
        myVector.push_back(1);
        //myVector.insert(myVector.begin(),1);
        if(getCarry(myVector, i) != 0)
        {
            //myVector[0] = 2;
            myVector.pop_back();
            myVector.push_back(2);
        }


        printf ("%d", myVector.empty() ? 0 : myVector.back());
        for (int i=(int)myVector.size()-2; i>=0; --i)
            printf ("%i",myVector[i]);
        printf("\n");

    }

    return 0;
}
