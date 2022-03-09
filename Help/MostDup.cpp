#include <bits/stdc++.h>

using namespace std;

#define def 100

int main ()
{
    // int n, ans;
    // cin >> n;

    // int  copy[n], a[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     a[i] = copy[i];
    // }
    

    // for (int i = 0; i < n; i++)
    // {

    //     int count = 0;
        
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (a[i] == copy[j])
    //             count++;

    //         if (count > ans)
    //             ans = count;
    //     }

        


    // }

    // cout << count << endl; 



    // sul -2

    int b[10000000], n, a[def], ans;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 10000001; i++)
    {
        b[i] = 0;
    }

    for (int i = 0; i < n; i++) // finding most dup item
    {
        int x = a[i];
        b[x]++;
    }
    
    int x = 0;

    for (int i = 0; i < 101; i++) // finding the largest value
    {
        if (b[i] > ans)
            x = b[i];
    }

    cout << x << endl;
}