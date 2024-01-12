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
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX]; 
vi v;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        v.clear();
        int n, k; cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int c1 = a[1], c2 = a[n];
        
        for(int i = 1; i <= n; i++)
            if(a[i] == c1 || a[i] == c2) v.pb(a[i]);

            // cout << k;
        int cn1 = 0, cn2 = 0;
        for(int u: v) {
            if(cn1 >= k && u == c2) cn2++;
            elif(u == c1) cn1++;
        }

        if(c1 == c2){
            if(cn1 + cn2 >= k) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            if(cn1 >= k && cn2 >= k) cout << "YES\n";
            else cout << "NO\n";
        }

    }

}