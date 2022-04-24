#include<iostream>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int djiao = c - b*2;
    int dtui = d - a*2 - b*4;

    // 鸡的变异
    int new_jijiao = 0 + djiao;
    int new_jitui = 2 + dtui;
    if (a>0 && new_jijiao>=0 && new_jitui>=0){
        cout << new_jijiao << " "<<new_jitui << endl;
    }else{
        cout << -1 << endl;
    }

    // 羊的变异
    int new_yangjiao = 2+djiao;
    int new_yangtui = 4+dtui;
    if (b>0){
        cout << new_yangjiao << " " << new_yangtui;
    } else {
        cout << -1;
    }
}