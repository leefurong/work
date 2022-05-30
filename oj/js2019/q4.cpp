#include<bits/stdc++.h>
using namespace std;
bool first=true;
void f(int n){
    if (n>=2){
        f(n >> 1);
        cout << "dup\nadd\n";
    }
    if (n%2==1) {
      cout << "1\n";
      if (first){
        first=false;
      }else{
        cout << "add\n";
      }
    }
}
int main(){
    int n;
    cin >> n;
    f(n);
}