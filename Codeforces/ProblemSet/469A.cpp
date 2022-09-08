#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 10000

int main (void)
{
    intl n;
    cin >> n;

    intl p[def], q[def], pn, qn;

    cin >> pn;
    for(intl i = 1; i <= pn; i++)
        cin >> p[i];
    
    cin >> qn;
    for(intl i = 1; i <= qn; i++)
        cin >> q[i];

    bool isAvail[def];

    intl cnt = 0;
    for(intl i = 1; i <= n; i++){
        for(intl j = 1; j <= n; j++){
            if(q[j] == i or p[j] == i){
                isAvail[i] = true;
                break;
            }
        }
    }
    
    for(intl i = 1; i <= n; i++){
        if(!(isAvail[i])){
            cout << "Oh, my keyboard!";
            return 0;
        }
    }

    cout << "I become the guy.";
}