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

vector<int> v1, v2, v3; 

main()
{IOS;

    for(int i = 1; i <= 497; i++) v1.pb(i);
    for(int i = 0; i < v1.size(); i++)
        if(!(i % 2)) v2.pb( v1[i] );
    for(int i = 0; i < v2.size(); i++)
        if(!(i % 2)) v3.pb( v2[i] );

    ll cnt = 1, h = 0, ans = 0; // ? h = هوشنگ
    for(int x1 = 0, x2 = 0, x3 = 0; h < 1e12; x1++, x2--, x3++){
        if(x2 < 0) x2 += v2.size();
        if(x1 == v1.size()) x1 = 0;
        if(x3 == v3.size()) x3 = 0;

        if(!(v2[x2] % v3[x3]) && !(v1[x1] % v2[x2])) h++, ans += cnt, ans %= 93283;

        cnt++;
    }

    cout << ans << endl;

}