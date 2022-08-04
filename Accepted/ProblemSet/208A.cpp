#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define pb push_back 
typedef long long int intl; 
typedef vector<int> vci;
typedef pair<int,int> pii; 

int main (void)
{

    string s;
    cin >> s;

    intl n = s.size();
    bool isWub = true;

    forn(i,n){
        if(s[i] == 'W' and s[i + 1] == 'U' and s[i + 2] == 'B'){
            i += 2;
            
            if(!isWub)
                cout << " ";

            isWub = true;
            continue;


        } else{
            isWub = false;
            cout << s[i];
        }
    }

}