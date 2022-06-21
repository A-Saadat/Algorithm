#include <bits/stdc++.h> 

using namespace std; 

#define intl long long int 

int main (void)
{
    string org, trs;
    cin >> org >> trs;

    intl n = org.size();

    for(intl i = 0; i < n; i++){
        if(org[i] != trs[n - (i + 1)]){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}