#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define p path
#define def 1000000

int main (void)
{
    intl n, a, b;
    cin >> n >> a >> b;
    char p[def];
    for(intl i = 0; i < n; i++){
        cin >> p[i];
    }
    intl maxi, mini;
    char maxl, minl;
    for(intl i = 0; i < n; i++){
        if(a > b){
            maxi = a;
            maxl = 'a';
            mini = b;
            minl = 'b';
        }
        else if (a <= b){
            maxi = b;
            maxl = 'b';
            mini = a;
            minl = 'a';
        }
        
        if(p[i] == '*')
            continue;
        else if(i == 0){
            p[i] = maxl;
            if(maxl == 'a')
                a--;
            else
                b--;
            continue;
        }
        else{
            if(p[i - 1] == '*' or p[i - 1] == '.'){
                if(maxi != 0){
                    p[i] = maxl;
                    if(maxl == 'a')
                        a--;
                    else if(maxl == 'b')
                        b--;
                }
                else
                    continue;
            }
            else if(p[i - 1] == 'a'){
                if(b != 0){
                    p[i] = 'b';
                    b--;
                }
                else
                    continue;
            }
            else if(p[i - 1] == 'b'){
                if(a != 0){
                    p[i] = 'a';
                    a--;
                }
                else
                    continue;
            }
            else
                continue;
        }

        if(a == 0 and b == 0)
            break;
    }
    intl cnt = 0;
    for(intl i = 0; i < n; i++){
        if(p[i] == 'a' or p[i] == 'b')
            cnt++;
    }
    cout << cnt;

}