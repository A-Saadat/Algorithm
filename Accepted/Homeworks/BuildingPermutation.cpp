#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000
#define forn(i,n) for(int i=1;i<=n;i++) 
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

intl a[def];

int main (void)
{
    intl n; cin >> n;
    forn(i,n) cin >> a[i];
    sort(a + 1, a + n + 1);

    intl ans = 0;
    forn(i,n){
        if(a[i] >= 0) {
            if(i <= a[i]) ans += a[i] - i;
            else ans += i - a[i];
        }
        else ans += (a[i] * -1) + i;

    } 

    cout << ans;

}