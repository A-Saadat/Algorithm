// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 

int a[MaxN], b[MaxN], c[MaxN];
vector<int> v; 
int n;
map<int, int> mp;

int lb(int tar){

    int L = 0, R = v.size() + 1;
    while(R - L > 1){
        int mid = (R + L) / 2;

        if(v[mid] >= tar) L = mid;
        else R = mid;
    }

    return L + 1;

}

int Find_LDS(){
    v.pb(-INF);
    forn(i,1,n + 1){
        int idx = lb(b[i]);

        if(idx >= v.size()) v.pb(b[i]);
        else v[idx] = b[i];
    }

    return v.size() - 1;
}

main()
{IOS;

    cin >> n;
    forn(i,1,n + 1) cin >> a[i];
    forn(i,1,n + 1){
        int x; cin >> x;
        mp[x] = i;
    } 

    forn(i,1,n + 1){
        b[i] = mp[ a[i] ];
    }
    cout << Find_LDS();

}