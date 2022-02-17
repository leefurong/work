#include<iostream>
using namespace std;
int n, m;
int a[1000001];

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];

    while(m--){ // m个提问
        int target;
        cin >> target; // 搜索这个target
        // 最终答案（如果有）必定在[left, right]这个区间中。
        int left = 1;
        int right = n;
        while(left<right){ // 区间不止一个元素， 继续找
            // 2: 因为调整边界时，
            // 会这样调整：right=mid(line 24)
            // 故， 当left和right相差1时，mid如果取右边，
            // 则搜索会止步不前。 即陷入死循环。
            // 故，mid必须取左边， 即left+(right-left)/2， 而非left+(right-left+1)/2
            int mid = left + (right-left)/2; 
            // 1: 当他们相等时， 不能直接把mid排除在外。而是把mid右边排除在外。
            if (a[mid]>=target){
                right = mid;
            } else if (a[mid]<target){
                left = mid+1;
            }
        }
        // 还剩一个元素了。 要么就是答案，要么没答案。
        if (a[left]==target) cout << left<<" ";
        else cout << -1 <<" ";

    }
}