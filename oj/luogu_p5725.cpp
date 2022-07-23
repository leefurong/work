#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n*n; i++){
        if (i<10) cout << 0;
        cout << i;
        if (i%n==0) cout << endl;
    }
    cout << endl;

    int k=1;
    int row=1;
    int col=1;
    for(int i=1; i<=n*n; i++){
        if (col<=n-row) cout << "  ";
        else {
            if (k<10) cout << 0;
            cout << k++;
        }
        col++;
        if (col>n){
            cout << endl;
            col=1;
            row++;
        }
    }

}