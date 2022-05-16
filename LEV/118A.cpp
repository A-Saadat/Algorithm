#include <bits/stdc++.h>

using namespace std; 

#define intl long long int
#define def 10000
     
int main (void)
{
    string a, ans;
    cin >> a;

    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] >= 'A' and a[i] <= 'Z')
            a[i] += 32;
    }

    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == 'a' or a[i] == 'A' or a[i] == 'o' or a[i] == 'O' or a[i] == 'Y' or a[i] == 'y' or a[i] == 'e' or a[i] == 'E' or a[i] == 'u' or a[i] == 'i' or a[i] == 'I')
        {
            continue;
        }else{
            ans += '.';
            ans += a[i];
        }
    }

    cout << ans;


}   