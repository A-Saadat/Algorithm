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

vpii a;

int main (void)
{
    intl n; cin >> n;
    forn(i,n){
        intl x, y; cin >> x >> y;
        a.pb(mp(x,y));
    }

    sort(a.begin(), a.end());

    intl ans = 0;
    forn(i,n){
        if(min(a[i].F, a[i].S) >= ans) ans = min(a[i].F, a[i].S);
        else ans = max(a[i].F, a[i].S);
    };

    cout << ans;
    
}