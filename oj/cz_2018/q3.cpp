#include<iostream>
#include<math.h>
using namespace std;
double height, weight;
int main(){
    cin >> height >> weight;
    height=height/100;
    double bmi = (double)weight/(height*height);
    if (bmi<18){
        cout << "Too thin!"<<endl;
        cout << ceil(abs(18*(height*height)-weight));
    }else if (bmi>24){
        cout << "Too fat!" << endl;
        cout << ceil(abs(24 * (height * height) - weight));
    }else{
        cout << "Good!";
    }
}