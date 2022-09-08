#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
 
int main (void)
{

    int who = 1;
    int n;

    cin >> n;

    for (int i = 1; i <= n - 1; i++)
    {
        who = who + i;

        if (who > n)
        {
            who = who - n;
        }
        
        cout << who << endl;
    }

}