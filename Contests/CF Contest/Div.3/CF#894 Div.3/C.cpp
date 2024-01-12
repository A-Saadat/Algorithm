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

vector<int> a, b; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        a.clear(), b.clear();
        int n; cin >> n;
        bool isOk = 1;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            a.pb(x);
            if(x > n) isOk = false;
        }

        if(!isOk){
            cout << "NO\n";
            continue;
        }

        int id = n - 1;
        for(int k = 1; k <= n; k++){
            while(id >= 0){
                if(a[id] >= k){
                    b.pb(id + 1);
                    break;
                } 
                else id--;
            }
        }

        if(a == b) cout << "YES\n";
        else cout << "NO\n";
    }

}