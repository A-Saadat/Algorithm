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

vci a;

int main (void)
{
    intl t;
    cin >> t;

    intl copy = t;

    while(copy--){

        intl n;
        cin >> n;
        intl last = 0;

        for(intl i = 0; i < 30; i++)
            if(((n >> i) & 1) == 1) last = i;

        a.pb(((1 << last) - 1));

    }

    forn(i,t) cout << a[i] << endl;
}