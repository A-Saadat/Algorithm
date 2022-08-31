#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define elif else if 
typedef long long int intl; 
typedef vector<intl> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

int main (void)
{
    intl t; cin >> t;

    while(t--){
        char LETTERS[] = {'T', 'i', 'm', 'u', 'r'};
        intl n; cin >> n;
        string s; cin >> s;
        
        intl cnt = 0;
        if(n != 5){
            cout << "NO" << endl;
            continue;
        }
        else{
            forn(i,5){
                forn(j,5){
                    if(s[i] == LETTERS[j]) {
                        cnt++;
                        LETTERS[j] = '1';
                    } 
                }
            }
        }

        if(cnt == 5) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}