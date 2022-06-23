#include <bits/stdc++.h> 
using namespace std;

#define intl long long int 

int main (void)
{
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 33 and s[i] <= 126){
            if(s[i] == 'Q' or s[i] == 'H' or s[i] == '9'){
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}