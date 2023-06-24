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

int a[MaxN]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){

        memset(a, 0, sizeof(a));

        int n; cin >> n;
        string s; cin >> s;
        
        forn(i,0,n){
            int bit = i % 2;
            
            forn(j,0,n)
                if(s[j] == s[i]) a[j] = bit;

        }
        
        bool isOk = true;
        forn(i,0,n - 1)
            if(a[i] == a[i + 1]) isOk = false;

        if(isOk) cout << "YES\n";
        else cout << "NO\n";

    }

}