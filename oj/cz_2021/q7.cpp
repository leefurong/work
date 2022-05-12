#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
bool between(int a, int b, int c){
    int mn = min(a, c);
    int mx=max(a,c);
    return b>=mn&&b<=mx;
}
int main(){
    int H,M, K;
    int x[301], h1[301], h2[301];
    scanf("%d%d%d", &H, &M, &K);
    for(int i=1; i<=K; i++){
        scanf("%d%d%d", &x[i], &h1[i], &h2[i]);
    }

    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        int sx, sy, tx, ty;
        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
        if (K==0)
        { // 没有楼梯
            if (sy!=ty) printf("%d\n", -1);
            else printf("%d\n", abs(sx-tx));
        }
        else if (K == 1)
        {
            if (between(h1[1], sy, h2[1]) && between(h1[1], ty, h2[1])){
                printf("%d\n", abs(x[1]-sx)+abs(x[1]-tx)+abs(sy-ty));
            }else{
                printf("%d\n", -1);
            }
        }
    }

}