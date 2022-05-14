#include<iostream>
using namespace std;

int main(){
    cout << "以下4项，有一项是假的，猜猜是哪一项？"<<endl;
    cout << "1. 最近我每天7点前起床。" << endl;
    cout << "2. 我从来不玩游戏。" << endl;
    cout << "3. 我从楼上跳下来。" << endl;
    cout << "4. 我切断了手指。" << endl;
    int x;
    cin >> x;
    if (x==2){
        cout << "对了， 这是假的！ 我会玩动物森友会。";
    } else if (x==1) {
        cout << "不对， 这是真的! 我最近真的起得很早。";
    } else if (x==3){
        cout << "不对，这是真的！我小时候从楼上跳下来!";
    }else {
        cout << "不对， 这是真的！ 我小时候切断过自己的手指。";
    }
}