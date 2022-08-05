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
    intl k;
    cin >> k;

    intl a[def];
    forn(i, 12) cin >> a[i];
    sort(a, a + 12, greater<int>());

    intl ans = 0, cnt = 0;
    if(k == 0){
        cout << 0;
        return 0;
    }
    else{
        forn(i, 12){
            ans += a[i];
            cnt++;
            
            if(ans >= k){
                cout << cnt;
                return 0;
            }
        }
    }

    cout << -1;
}