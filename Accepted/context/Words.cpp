#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 10000

int main (void)
{
    string a;
    intl count, ans1 = 0, ans2 = 0;

    cin >> a;

    for (int i = 0; i < a.size(); i++)
    {
        count = 0;

        if (a[i] >= 'a' and a[i] <= 'z')
        {
            count++;
            ans1 += count;
        }
        else if (a[i] >= 'A' and a[i] <= 'Z')
        {
            count++;
            ans2 += count;
        }
    }

    for(int i = 0; i < a.size(); i++)
    {
        if(ans1 >= ans2 and a[i] >= 'A' and a[i] <= 'Z')
        {
            a[i] = a[i] + 32;
        }
        else if (ans1 < ans2 and a[i] >= 'a' and a[i] <= 'z')
        {
            a[i] = a[i] - 32;
        }
    } 

    cout << a;

}
