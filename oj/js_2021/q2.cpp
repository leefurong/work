#include<bits/stdc++.h>
using namespace std;
string table[]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

char morse(string code){
    for(int i=0; i<26; i++){
        if (code==table[i]){
            return 'A'+i;
        }
    }
    return 'X';
}
int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        cout << morse(s);
    }
}