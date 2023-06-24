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

const int MaxN = 1e6; 
const int INF = 1e9 + 7; 

int a[MaxN], mark[MaxN]; 
int n, k, x; // ? x is the number of boxes with 2 cowbell

bool check(ll mid){
    int cnt = 0;
    int l = 1, r = n;
    while(r - l > 0 && !mark[r]){
        mark[l] = 1;

        if(a[l] + a[r] <= mid) l++, r--, cnt++;
        else r--;
    }

    if(cnt >= x) return 1;
    else return 0;
}

main()
{IOS

    cin >> n >> k;
    forn(i,1,n + 1) cin >> a[i];

    x = n - k;  

    ll L = a[n] - 1, R = 10 * INF;
    while(R - L > 1){
        ll mid = (L + R) / 2;

        forn(i,0,n + 1) mark[i] = 0;

        if(check(mid)) R = mid;
        else L = mid; 

    }

    cout << R << endl;
}