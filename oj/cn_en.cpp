#include <iostream>
using namespace std;
string sheng[23] = {"b", "p", "m", "f", "d", "t", "n", "l", "g", "k", "h", "j", "q", "x", "y", "w", "z", "c", "s", "zh", "ch", "sh", "r"};
string yun[25] = {"a", "o", "e", "i", "u", "v", "ai", "ei", "ui", "ao", "ou", "iu", "ie", "ve", "er", "an", "en", "in", "un", "vn", "ang", "eng", "ing", "ong", "uo"};
string dan[13] = {"a", "o", "e", "ai", "ei", "ao", "ou", "er", "an", "en", "ang", "eng", "ong"};
bool is_pinyin(string word){
    for(int i=0; i<23; i++){
        for(int j=0; j<25; j++){
            string pinyin = sheng[i]+yun[j];
            if (word==pinyin){
                return true;
            }
        }
    }
    for(int i=0; i<13; i++){
        if (word==dan[i]){
            return true;
        }
    }
    return false;
}
bool is_en(string s){
    s = s+' ';
    string word="";
    int total_words=0, cn_words=0;
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if (c==' '){
            if (is_pinyin(word)){
                cn_words++;
            }
            total_words++;
            word="";
        } else {
            word = word + c;
        }
    }
    return cn_words*2<total_words;
}

int solve(){
    string s;
    getline(cin, s);
    if (is_en(s)){
        cout << "English"<<endl;
    } else {
        cout << "Pinyin"<<endl;
    }
}
int main(){
    int n;
    cin >> n;
    string x;
    getline(cin, x);
    for(int i=0; i<n; i++) solve();
}