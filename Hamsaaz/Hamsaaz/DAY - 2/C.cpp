#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

vi a; 
int ans;

void TB(int n){
    if(n == 0){
        bool isOk = false;
        for(int u: a){
            if(u >= 202) isOk = true;
        }

        if(isOk) ans++;
    }
    else{
        for(int i = 1; i <= min(1000, n); i++){
            a.pb(i);
            TB(n - i);
            a.pop_back();
        }
    }

}

main()
{IOS;

    TB(10);
    cout << ans;

}