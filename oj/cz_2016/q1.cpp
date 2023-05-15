#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = 0;

    // move the x1 y1 chess CW until reach x2 y2,
    // count how many steps it takes.
    while (x1 != x2 && y1 != y2)
    {
        if (y1 == 1)
        { // at left side of board
            if (x1 != 19)
            {
                x1++;
                ans++;
            }
        }
        else if (y1 == 19)
        { // at right side of board
            if (x1 != 1)
            {
                x1--;
                ans++;
            }
        }
        else if (x1 == 1) // at bottom side of board
        {
            if (y1 != 1)
            {
                y1--;
                ans++;
            }
        }
        else if (x1 == 19) // at top side of board
        {
            if (y1 != 19)
            {
                y1++;
                ans++;
            }
        }
    }

    cout << min(ans, 18 * 4 - ans);
}