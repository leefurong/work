#include <iostream>
using namespace std;
int n, m;
string a, b;
int main()
{
    cin >> n >> m >> a >> b;
    int r = 0, sum = 0, summ = 0;
    for (int i = 0; i < a.size(); i++)
    {
        // cout << r << " " << a[i] << " " << b[r] << endl;
        if (a[i] == b[r])
            r++;
        else
            r = 0;
        if (r == b.size())
        {
            sum++;
            summ += b.size();
            r = 0;
        }
    }
    cout << summ << " " << sum;
}