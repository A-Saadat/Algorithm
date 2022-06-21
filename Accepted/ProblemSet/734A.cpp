#include <bits/stdc++.h> 

using namespace std; 

#define intl long long int 

int main (void)
{   
    intl n;
    string s;
    cin >> n >> s;

    intl antCnt = 0, danCnt = 0;
    for(intl i = 0; i < n; i++){
        if(s[i] == 'A')
            antCnt++;
        else
            danCnt++;
    }

    if(antCnt > danCnt)
        cout << "Anton" << endl;
    else if(antCnt < danCnt)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
}
