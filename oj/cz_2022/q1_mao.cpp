#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    double sum=0;
    for(int i=x+1;i<=y;i++){
        if(i<=2760)sum+=0.52;
        else if(i>4800)sum+=0.82;
        else sum+=0.57;
    }
    cout<<fixed<<setprecision(2)<<sum;
}