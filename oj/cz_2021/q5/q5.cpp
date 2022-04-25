#include<iostream>
#include<algorithm>
using namespace std;

string cases[] = {"00", "22", "55", "69", "88", "96"};

string fun[559870]={"0", "2", "5", "8"};
long long funl[559870];

long long beg[15]={0, 0};
long long endd[15]={0, 4};

string wrap(string s, string wr){
    return wr[0]+s+wr[1];
}


// 把read_beg~read_end之间的内容， 每个以六种情况， 添加到write_beg开始的位置上。
// 00 22 55 69 88 96
void write(int read_beg, int read_end, int write_beg)
{
    if (read_end==read_beg){
        for(string cs: cases){
            fun[write_beg++] = wrap("", cs);
        }
    }else{
        for(string cs:cases){
            for(int i=read_beg; i<read_end; i++){
                fun[write_beg++] = wrap(fun[i], cs);
            }
        }
    }

}

int shrink(int end){
    int i=0, j=0;
    for(;i<end; i++){
        if (i==0 || fun[i][0]!='0'){ // keep this.
            funl[j++]=stoll(fun[i]);
        }
    }
    return j+1;
}
int prepare(){
    for(int len=2; len<=14; len++){
        beg[len] = endd[len-1];
        write(beg[len-2], endd[len-2], beg[len]);
        if (len==2){
            endd[len] = beg[len] + 6;
        }else{
            endd[len] = beg[len]+6*(endd[len-2]-beg[len-2]);
        }
    }

    return shrink(endd[14]);
}

int main(){
    long long Q, L, R;
    cin >> Q;
    int n = prepare();

    while(Q--){
        cin >> L >> R;
        cout << upper_bound(funl, funl+n, R)-lower_bound(funl, funl+n, L)<<endl;
    }
}