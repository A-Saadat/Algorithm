#include <bits/stdc++.h>

using namespace std; 

#define intl long long int
     
int main (void)
{

    intl x = 0;

    for (int i = 1; i <= 5; i++)
    {

        for (int j = 1; j <= 5; j++)
        {
            cin >> x;

            if (x == 1)
                cout << abs(i - 3) + abs(j - 3) << endl;
        }

    }

    return 0;

}