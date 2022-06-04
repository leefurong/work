#include<bits/stdc++.h>
using namespace std;
double m, h;

int main(){
    cin >> m >> h;
    double hh=h*h;
    if (m/hh <18.5){
        cout << "Underweight";
    } else if (m/hh>=18.5 && m/hh<24){
        cout << "Normal";
    } else {
        cout << m/hh << endl;
        cout << "Overweight";
    }
    cout <<fixed << setprecision(5) <<  m / hh << endl;
}