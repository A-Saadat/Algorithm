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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX], b[MAX], c[MAX]; 
vi v;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        v.clear();
        memset(b, -1, sizeof(b));
        memset(a, 0, sizeof(a));

        int n, k; cin >> n >> k;
        forn(i,1,n + 1) cin >> c[i];
        forn(i,1, n + 1){
            if(b[ c[i] ] == -1) b[ c[i] ] = max(b[ c[i] ], i - 1);
            else b[ c[i] ] = max( b[ c[i] ], i - a[ c[i] ] - 1);

            a[ c[i] ] = i;
        }

        for(int i = 1; i <= k; i++){
            b[i] = max(b[i], n - a[i]);
        }

        int mini = MAX, col = 0;
        for(int i = 1; i <= k; i++){
            if(b[i] < mini) mini = b[i], col = i;
        }


        int ls = 0;
        for(int i = 1; i <= n; i++){
            if(c[i] == col) v.pb(i - ls -1), ls = i;
        }

        v.pb(n - ls);
        sort( all(v) );
        // int f = v.back();
        // v.pop_back();
        // v.pb(f / 2);
        // if(!(f % 2)) v.pb( (f / 2) - 1);
        // else v.pb(f / 2);


        cout << col << ' ';
        sort( all(v), greater<int>() );
        for(int u: v) cout << u << ' ';
        // cout << "ans: " << v[0] << endl;
    }

}