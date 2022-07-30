#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    if (x!=2 && x!=3 && x%6!=1 && x%6!=5) return false;

    for (int j = 2; j*j <= x; j++)
    {
        if (x % j == 0)
        {
            return false;
        }
    }
    return true;
    
}

int main()
{
    int a;
    cin >> a;
    int c[a];
    int ls = 0;
    int s = 0;

    int ddd=0;
    for (int i = 2; ddd <= a; i++)
    {
        if (isPrime(i))
        {
            c[ls] = i;
            ls++;
            s++;
            ddd += i;
        }
    }



    for (int i = 0; i < ls - 1; i++)
    {
        cout << c[i] << endl;
    }
    
    cout << s - 1;
    
}