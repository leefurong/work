#include<map>
#include<iostream>
using namespace std;
map<string, int> wc;
string compress(string s){
    string ans;
    for(char c:s){
        if (c!=ans[ans.size()-1]){
            ans+=c;
        }
    }
    return ans;
}
int main(){
    int n;
    string w;
    cin >> n;
    while(n--){
        cin >> w;
        wc[compress(w)]++;
    }
    string maxs;
    int mx=0;
    for(map<string, int>::iterator it=wc.begin(); it!=wc.end(); it++){
        string word =  it->first;
        int count = it->second;
        if (count>mx){
            mx=count;
            maxs=word;
        }
    }
    cout<<maxs;
}