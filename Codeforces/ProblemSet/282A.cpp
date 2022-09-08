#include <bits/stdc++.h>

using namespace std; 

#define intl long long int
     
int main (void)
{

    int n, total = 0;
    string x;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;

        if(x == "X++" || x == "++X")
            total++;
        else
            total--;
    }

    cout << total;


}