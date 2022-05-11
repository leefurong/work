#include<iostream>
using namespace std;
int n;
int scores[5];

int main(){
    cin >> n;
    while(n--){
        int dizhu, dang, winner;
        cin >> dizhu >> dang>>winner;
        int dfen; // 农民分数变化
        if (winner==1){ // 地主赢
            dfen = -dang;
        } else { // 地主输
            dfen = dang;
        }
        for(int i=1; i<=4; i++){
            if (dizhu==i){
                scores[i] -= 3*dfen;
            }
            else{
                scores[i] += dfen;
            }
        }
    }
    for(int i=1; i<=4; i++){
        cout << scores[i]<<" ";
    }
}