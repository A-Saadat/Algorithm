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
const int MOD = 1e9 + 7; 

int a[MaxN], b[MaxN]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        ll sumA = 0, sumB = 0;
        forn(i,1,n + 1) cin >> a[i], sumA += a[i];
        forn(i,1,m + 1) cin >> b[i], sumB += b[i];


        if(sumA == sumB) cout << "Draw\n";
        elif(sumA > sumB) cout << "Tsondu\n";
        else cout << "Tenzing\n";
        
    }

}