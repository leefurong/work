#include<iostream>
using namespace std;

int N,M,A,B; // 菜，机，洗，煮
int jiqi[2001]; // 某个机器的任务结束时间
int cai[2001]; // 某个青菜正在执行的任务的结束时间

int zhao_jiqi(){ // 哪一台机器先完事儿?
    int kmin=0;
    for(int i=1; i<M; i++){
        if (jiqi[i]<jiqi[kmin]){
            kmin = i;
        }
    }
    return kmin;
}

int main(){
    cin >> N>>M>>A>>B;

    // 分发洗菜任务
    int j = 0;
    for(int i=0;i<N; i++){
        jiqi[j] += A;
        cai[i] = jiqi[j];
        j = (j+1)%M;
    }


    int ans=0;
    // 分发煮菜任务
    for(int i=0;i<N; i++){
        j = zhao_jiqi();
        int beg = max(jiqi[j], cai[i]);
        jiqi[j] = beg + B;
        ans = max(ans, jiqi[j]);
    }

    cout << ans;


}