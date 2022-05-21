#include<iostream>
#include<math.h>
using namespace std;
int s, v;
int main(){
    cin >> s >> v;

    int t = 8*60+24*60;// 昨天0:00开始的分钟数
    t -= 10; // 减去垃圾分类时间

    t -= ceil((float)s/v);// 减去路途时间

    int h = t/60 % 24;
    int m = t%60;

    cout << (h<10?"0": "") << h << ":" <<(m<10?"0": "") << m;
}