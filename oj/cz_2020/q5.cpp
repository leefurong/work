#include<iostream>
#include<algorithm>
using namespace std;
long long atk, hp;
int n;
long long ati[100001];

bool canwin(int beg){
    long long total_atk=0;
    int k=1;
    for(int i=beg;i<=n;i++){
        total_atk += (ati[i]*k);
        k++;
    }
    return total_atk>=hp;
}

// 检查中间位置center， 这个位置及以后的勇士都被招募。
// 如果打不赢， 就把right移到center-1， 继续找。
// 如果能打赢， 就把left移到center， 继续找。
int binary_search(int left, int right){
    if(left==right){
        if (canwin(left)){
            return left;
        }else{
            return -1;
        }
    }

    int center = (left+right+1)/2;
    if (canwin(center)){
        return binary_search(center, right);
    } else {
        return binary_search(left, center-1);
    }
}
int main(){
    cin >> n;
    cin >> atk >> hp;
    for(int i=1; i<=n; i++){
        long long ai, hi;
        cin >> ai >> hi;
        ati[i] = (hi/atk+(hi%atk? 1: 0)) * ai;
    }
    sort(ati+1, ati+n+1);
    int ans = binary_search(1, n);
    if (ans==-1){
        cout << "Fail";
    }else{
        cout << n-(ans-1);
    }
}