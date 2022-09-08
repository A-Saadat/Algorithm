#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
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
    intl t;
    cin >> t;

    vci ans;
    intl n;
    forn(i,t) {
        cin >> n;

        if(n == 1 or n == 2) ans.pb(0);
        else{
            intl min = (n / 2) + 1;
            intl max = n - 1;

            ans.pb((max - min) + 1);
        }

    }

    forn(i,t) cout << ans[i] << endl;
    
}