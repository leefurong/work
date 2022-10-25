#include<bits/stdc++.h>
using namespace std;

set<int> a;
int main(){
    int n;
    cin >> n;
    while(n--){
        int command, len;
        cin >> command >> len;
        if (command==1){
            if (a.find(len)!=a.end())
                cout << "Already Exist" << endl;
            else
                a.insert(len);
        }else{
            auto it = a.lower_bound(len);
            if (a.empty()) cout << "Empty"<<endl;
            else if (len == *it){
                a.erase(it);
                cout << len << endl;
            }else{
                auto tar = it;
                if (it!=a.begin()){
                    it--;
                    if (tar==a.end() || abs(len-*it)<=abs(len-*tar)){ // a better one.
                        tar = it;
                    }
                }
                int v = *tar;
                a.erase(tar);
                cout << v << endl;
            }
        }
    }
}