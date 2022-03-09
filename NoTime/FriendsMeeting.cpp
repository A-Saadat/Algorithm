#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
 
int main (void)
{

    intl a , b, maxnum, minnum, res;
    cin >> a >> b;

    if (a > b)
    {
        maxnum = a;
        minnum = b;
    } 
    else {
        maxnum = b;
        minnum = a;
    }

    res = (maxnum - minnum) / 2;

    if ( (maxnum - minnum) % 2 != 0 )
        res++;

    int sum = 0;

    for (int i = 1; i < res; i++)
    {
        sum = (sum + i) + 1;
    }

    if (maxnum - minnum == 1)
        sum = sum / 2;

    cout << sum << endl;

    

}

    //int a , b, x;
    // cin >> a >> b;
    // x = 10000000;

    // for (int i = a; i <= b; i++)
    // {
    //     int t1 = ((i - a) * (i - a + 1)) / 2;
    //     int t2 = ((b - i) * (b - i + 1)) / 2;

    //     int sum = t1 + t2;

    //     if (sum < x)
    //     {
    //         x = sum;
    //     }


    // }

    // cout << x << endl;