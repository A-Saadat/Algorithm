#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int

int main (void)
{

    string n;
    cin >> n;

    intl cnt = 0;
    for(intl i = 0; i < n.size(); i++)
    {
        if (n[i] == '4' or n[i] == '7')
            cnt++;
    }

    if(cnt == 4 or cnt == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


}
