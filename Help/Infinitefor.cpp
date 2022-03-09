#include <bits/stdc++.h>

using namespace std;

#define def 100

int main (void)
{
    int x, sum = 0;

    for(int i = 1; i > 0; i++)
    {
        if(x == 0)
        {
            cout << sum << endl;
            break;
        }
        else
        {
            sum += x;
        }
    }
} 

// break : break the exact loop
// continue : skip all loop




// ---------------------------------------- 