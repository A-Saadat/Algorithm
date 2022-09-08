#include <bits/stdc++.h>

using namespace std;

int main (void)
{
    int x;
    cin >> x;

    int a;
    a = x / 5;

    if (x % 5 == 0){

        cout << a << endl;

    } else if (x != 5)
    {
        cout << a + 1 << endl;
    }
}
