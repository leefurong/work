#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a[5]={10,6,4,2,1};

    cout << *lower_bound(a, a, 3);
}