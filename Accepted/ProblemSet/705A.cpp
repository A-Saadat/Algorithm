#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 10000

int main (void)
{
    string text[] = {"I hate that", "I love that", "I hate it", "I love it"};

    intl n; 
    cin >> n;

    string ans[def];
    for(int i = 1; i <= n; i++){
        if(i == 1 and i == n)
            ans[i] = text[2];
        else if(i % 2 != 0 and i != n)
            ans[i] = text[0];
        else if(i != n and i % 2 == 0)
            ans[i] = text[1];
        else if(i == n and n % 2 == 0)
            ans[i] = text[3];
        else if(i == n and n % 2 != 0)
            ans[i] = text[2];
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}