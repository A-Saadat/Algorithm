#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{
    string s;
    cin >> s;

    bool cond1 = true, cond2 = true;
    for(intl i = 0; i < s.size(); i++){
        if(s[i] >= 'a' and s[i] <= 'z')
            cond1 = false;
        
        if(i != 0 and s[i] >= 'a' and s[i] <= 'z')
            cond2 = false;
    }

    for(intl i = 0; i < s.size(); i++){
        if(cond1 or cond2){
            if(s[i] >= 'a' and s[i] <= 'z')
                s[i] -= 32;
            else    
                s[i] += 32;
        } 
        else{
            continue;
        }
    }

    cout << s;
}