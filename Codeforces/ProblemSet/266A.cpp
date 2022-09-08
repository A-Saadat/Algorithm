#include <bits/stdc++.h> 

using namespace std; 

#define intl long long int 

int main (void)
{
    intl stonsNum;
    string stons;
    cin >> stonsNum >> stons;

    intl cnt = 0;
    for(intl i = 0; i < stonsNum - 1; i++){
        if(stons[i] == stons[i + 1])
            cnt++;
    }

    cout << cnt;

}