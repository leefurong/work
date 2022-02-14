#include<iostream>
using namespace std;

string n;
string repeat(int n, string s){
    string ans="";
    while(n--) ans+=s;
    return ans;
}
int main(){
    cin >> n;
    string line2 = "*Welcome,ContestantNo."+n+"!*";
    int len = line2.size();
    cout << repeat(len, "*") << endl;
    cout << line2 << endl;
    cout << repeat(len, "*") << endl;
}