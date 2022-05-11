#include<iostream>
using namespace std;

long long n;
int main(){
    cin >> n;
    long long ans = 1900*(n/33);
    int remain = n%33;
    if (remain==0){ // 正好
        ;
    }else if (remain>=1&&remain<=16 && n/33>0){
        // 33车下一车人， 和剩下的人拼到49车上
        ans += 3300-1900;
    } else {
        ans += 1900;
    }
    cout << ans;
}