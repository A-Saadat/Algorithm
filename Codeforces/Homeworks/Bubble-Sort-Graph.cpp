#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
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
const int INF = 1e9 + 7; 

int a[MaxN], n; 
vector<int> v;

int lb(int tar){
    int L = 0, R = v.size() + 1;
    while(R - L > 1){
        int mid = (R + L) / 2;

        if(v[mid] <= tar) L = mid;
        else R = mid;
    }

    return R;
}

int Find_LIS(){
    v.pb(INF); v.pb(a[0]);
    forn(i,1,n){
        int x = lb(a[i]);

        if(x > v.size() - 1) v.pb(a[i]);
        else v[x] = a[i];
    }

    return v.size() - 1;
}

main()
{IOS;

    cin >> n;
    forn(i,0,n) cin >> a[i];

    cout << Find_LIS();
}