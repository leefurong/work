#include <iostream>
using namespace std;
const int FRIEND = 0;
const int ENEMY = 1;
int n;
int x[100001], y[100001], who[100001];
bool pan[10001][10001];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// how many chesses between pao and chess i?
int count_between(int i)
{

    // 12, 8
    // 最大公因数4,
    // 12/4: 3
    // 8/4:  2
    // 每次移动3, 2， 看看有没有字。 统计一共几个子。 如果子数为1.
    int d = gcd(x[i], y[i]);
    int step_x = x[i] / d;
    int step_y = y[i] / d;
    int ans = 0;
    for (int j = 1; j < d; j++)
    {
        int mid_x = j * step_x;
        int mid_y = j * step_y;
        if (pan[mid_x][mid_y])
            ans++;
    }
    return ans;
}
bool can_eat(int i)
{
    // 1. 是敌方？
    // 2. 有合适的炮架？
    bool is_enemy = who[i] == ENEMY;
    if (!is_enemy)
        return false;

    return count_between(i) == 1 ? true : false;
}
int read()
{
    char ch = getchar();
    while (ch < '0' || '9' < ch)
        ch = getchar();
    int sum = ch - '0';
    ch = getchar();
    while ('0' <= ch && ch <= '9')
    {
        sum = sum * 10 + ch - '0';
        ch = getchar();
    }
    return sum;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        x[i] = read();
        y[i] = read();
        who[i] = read(); // 0友， 1敌
        pan[x[i]][y[i]] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (can_eat(i))
            ans++;
    }
    cout << ans;
}