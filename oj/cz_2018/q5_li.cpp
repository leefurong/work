#include <iostream>
using namespace std;
int n, m;
string a, b;
bool color[1000000];
void red(int beg, int len){
    for(int i=beg; i<beg+len; i++){
        color[i]=true;
    }
}
int count(){
    int ans=0;
    for(int i=0; i<n; i++){
        if (color[i]) ans++;
    }
    return ans;
}
int main()
{
    cin >> n >> m >> a >> b;
    int r = 0, sum = 0;
    int len = b.size();
    int lock_pos=-1;
    for (int i = 0; i < a.size(); i++)
    {
        if(a.substr(i, len)==b){
            red(i, len);
            if (i>lock_pos){
                sum++;
                lock_pos = i+len-1;
            }
        }
    }

    cout << count() << " " << sum;
}