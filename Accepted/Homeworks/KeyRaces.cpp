#include <bits/stdc++.h>

using namespace std;

int main (void)
{
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;

    int a = (s * v1) + (t1 * 2);
    int b = (s * v2) + (t2 * 2);


    if (a < b)
    {   
        cout << "First" << endl;
    }
    else if(a > b)
    {
        cout << "Second" << endl;
    }
    else
    {
        cout << "Friendship" << endl;
    }


    return 0;
}