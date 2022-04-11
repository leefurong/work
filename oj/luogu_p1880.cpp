#include<iostream>
using namespace std;
int n;
int w[201];
int qz[201];
int dpmn[201][201];
int dpmx[201][201];
const int INF = 999999999;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> w[i];
        qz[i] = qz[i-1]+w[i];
    }
    for(int i=n+1; i<=2*n; i++){
        w[i]=w[i-n];
        qz[i]=qz[i-1]+w[i];
    }
    int mn=INF, mx=0;

    for(int len=2; len<=n; len++){
        for(int i=1; i+len-1<=2*n; i++){
            int j=i+len-1;
            dpmn[i][j] = INF;
            for(int k=i; k<j; k++){
                dpmn[i][j] = min(dpmn[i][j], dpmn[i][k]+dpmn[k+1][j]+qz[j]-qz[i]+w[i]);
                dpmx[i][j] = max(dpmx[i][j], dpmx[i][k]+dpmx[k+1][j]+qz[j]-qz[i]+w[i]);
            }
            if(len==n){
                mn = min(mn, dpmn[i][j]);
                mx = max(mx, dpmx[i][j]);
            }
        }
    }
    cout << mn << endl << mx;
}