#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 10000


int main (void)
{
    string s;
    char ans[def];
    intl num[def];
    cin >> s;

    int cnt = 0;
    int j = 0;
    for(int i = 0; i < s.size(); i++){
        if(i % 2 == 0 or i == s.size()){
            ans[j] = s[i];
            cnt++;
            j++;
        }
    }


    for (int i = 0; i < cnt; i++){
        num[i] = ans[i] - '0';
    }
    
    sort(num, num + cnt);

    for(int i = 0; i < cnt; i++){
        if(i < cnt -1)
            cout << num[i] << '+';
        else if(i == cnt -1)
            cout << num[i];
    }
}
