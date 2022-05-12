#include<iostream>
using namespace std;

int n;
int defen[5]; // a[0],,  a[1]~a[4]

int dizhu, dang, winner;

int main(){
    cin >> n;
    while(n--){
        cin >> dizhu >> dang >> winner;
        for(int i=1; i<=4; i++){
            bool isDizhu = i==dizhu;
            bool isWinner = winner==(isDizhu?1:2);
            int diff = (isDizhu?3:1) * (isWinner?1:-1) * dang;
            defen[i] += diff;
        }
    }
    for(int i=1; i<=4; i++) cout << defen[i]<<" ";
}