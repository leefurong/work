#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long atk, hp;
int n;
long long ati[100001];
const int sz=30;
int total_atk[sz];
int temp[sz];

void to_big_temp(long long x){
    memset(temp, 0, sizeof(temp));
    string sx = to_string(x);
    for(int i=0; i<sx.size(); i++){
        temp[i] = sx[i]-'0';
    }
    reverse(temp, temp+sx.size());
}

void big_add(long long a){
    to_big_temp(a);
    for(int i=0; i<sz; i++){
        total_atk[i] += temp[i];
    }
    for(int i=0; i<sz-1; i++){
        total_atk[i+1] += total_atk[i]/10;
        total_atk[i]%=10;
    }
}
/**
 *  Is total_atk greater or equal than x?
 **/
bool big_ge(long long x){
    to_big_temp(x);
    int res=0;
    for(int i=20; i>=0; i--){
        if (temp[i]!=total_atk[i]){
            return total_atk[i]>temp[i]; // greater than
        }
    }
    return true; // equals.
}

bool canwin(int beg){
    memset(total_atk, 0, sizeof(total_atk));
    int k=1;
    for(int i=beg;i<=n;i++){
        big_add(ati[i]*k);
        k++;
    }
    // 既然total_atk有可能大于hp， 而hp是一个long long， 也就是说，
    // 万一数据中hp竟然是最大的long long， 那么totak_atk用long long就可能溢出。
    // 所以用高精来表达total_atk
    return big_ge(hp);
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