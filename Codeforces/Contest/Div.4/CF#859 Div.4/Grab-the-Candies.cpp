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

int a[MaxN], mi, bi;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        mi = 0, bi = 0;
        int n; cin >> n;
        forn(i,0,n){
            int x; cin >> x;
            if(x % 2) bi += x;
            else mi += x;
        } 

        if(mi > bi) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}