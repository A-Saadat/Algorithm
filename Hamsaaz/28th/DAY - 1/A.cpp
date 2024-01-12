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

const int MaxN = 1e4; 
const int MOD = 17837; 

vector<ll> a, b;
vector<ll> inp;
ll g[MaxN][MaxN];

void ArrayMaker(){
    int x = a.size() + 1, tmpX = x + 2;
    for(int u: a){
        tmpX = x + 2;
        b.pb(u);
        for(int i = x; i <= tmpX; i++) b.pb(i), ++x;     
    }    

    a = b;
    b.clear();
}

main()
{IOS;

    a = {1, 2, 3};
    
    for(int i = 1; i < 4; i++) ArrayMaker();

    int n = a.size();
    for(int i = 0; i < a.size() - 1; i++){
        for(int j = i + 1; j < a.size(); j++){
            g[ a[i] ][ a[j] ] = min(j - i, n - j + i);
            g[ a[j] ][ a[i] ] = min(j - i, n - j + i);
        }
    }

    inp = {1, 3, 8, 13, 34, 89};

    ll ans = 0;
    for(int i = 0; i < inp.size(); i++)
        for(int j = i + 1; j < inp.size(); j++)
            ans += (inp[i] * inp[j] * g[ inp[i] ][ inp[j] ]);

    cout << ans;

    
}