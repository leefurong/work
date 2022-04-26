#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<math.h>
#define ce(a,b) ((a-1+b)/b)
using namespace std;
int iH, iA, H, dA, M;
int C[200000];
// 会死亡的回合
int die[200000];

int main(){
    cin >> iH >> iA >> H >> dA>>M;
    for(int i=0; i<M; i++){
        scanf("%d", &C[i]);
    }
    // 计算死亡的回合
    int newH=iH;
    int ming=0;
    die[0]=M-1;// 先假设战士在M回合都死不了
    for(int i=0; i<M; i++){
        newH -= C[i];
        if (newH<=0) {
            newH=iH;
            die[ming++]=i;
        }else if (i==M-1){
            die[ming++]=M-1;
        }
    }

    int i=0;
    ming=0;
    int enemyH=H;
    while(1){
        // 这条命到哪个回合？
        int die_at = die[ming++];
        // 还能活几关?(包括这一关)
        int life_remain = die_at-i+1;

        // 对于这一条命， 磨几次刀最划算？
        long long max_attack=0;
        int first_ko=M;
        for(int mo=0; mo<life_remain-1; mo++){
            // 每个战斗回合攻击力
            long long each_attack = iA+mo*dA;
            int fight_times = life_remain-mo;
            long long total_attack = each_attack*fight_times;
            max_attack=max(max_attack, total_attack);
            if(total_attack>=enemyH){ // 第几关敌人死亡
                int ko =  ce(enemyH,each_attack)+mo;
                first_ko = min(ko, first_ko);
            }
        }

        

        

        if (first_ko!=M){
            cout << first_ko+i;
            return 0;
        }else{
            i+=life_remain;
            enemyH -= max_attack;
        }
        if (i>=M){
            break;
        }
    }


    cout << -1;
}