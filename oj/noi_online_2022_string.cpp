// https://www.luogu.com.cn/problem/P8256
#include<iostream>
using namespace std;
int n;
int lens, lent;
string s, t;

int count(string s, char c){
    int ans=0;
    for(char sc: s) if (c==sc)ans++;
    return ans;
}
char end(string s){
    return s[s.size()-1];
}
string dropTail(string s){
    return s.substr(0, s.size()-1);
}
string dropTail(string s, int n){
    return s.substr(0, s.size()-n);
}
int m(int n){
    return n%1000000071;
}
int dfs(string s, string t, int pending_drop_head, int pending_drop_tail){
    // 既然长度确定是对的， 我们就只需要从尾巴向前检查。


    // 基线条件
    // t比完了。 如果s还有纯字符的话， 那也是之前该去的头。 所以，这是可行方案。
    // 具体算不算呢？ 看看s的“真实长度”是否为0吧。 所谓s的“真实长度”， 是指根据'-'删去字符后的长度, 再删去还欠的长度（pending_drop_head）
    // 只要长度为0， 具体s里是怎样个顺序， 已经无关紧要了。 因为我们其实是从后面倒着推过来的。
    // 如果长度匹配， 再看s里有几个-， 每一个-， 都代表两种可能。
    if (t==""){
        bool len_match = s.size()-pending_drop_head-count(s, '-')*2==0;
        return len_match?m(1<<count(s, '-')):0; 
    }


    // 递归条件
    if (end(s)!='-'){
        if (pending_drop_tail){
            return dfs(dropTail(s), t, pending_drop_head, pending_drop_tail-1);
        }
        if (end(s)==end(t)){
            return dfs(dropTail(s), dropTail(t), pending_drop_head, pending_drop_tail);
        } else {
            return 0;
        }
    } else {
        int ans1 = dfs(dropTail(s, 1), t, pending_drop_head, pending_drop_tail+1); // 把s的-和尾巴都去掉， 继续和t倒着比

        // 把s的-去掉（见基线条件：将来反正不管头了，相当于去掉了头）, 继续和t倒着比
        // TODO: 但是， 如果有连续的--， 就不灵了！怎么办？？？？！！！
        int ans2 = dfs(dropTail(s, 1), t, pending_drop_head+1, pending_drop_tail);
        return m(ans1+ans2);
    }

}
int main(){
    cin >> n;
    while(n--){
        cin >> lens>>lent;
        cin >> s >> t;
        int ans;
        // 长度不对， 返回0
        if (s.size()-2*count(s, '-')!=t.size()) ans=0;
        else ans = dfs(s, t, 0, 0);
        cout << ans<<endl;
    }
}