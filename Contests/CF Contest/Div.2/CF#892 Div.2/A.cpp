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
vector<int> b, c; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        b.clear(); c.clear();
        int n; cin >> n;
        bool isOk = false;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] != a[i - 1] && i > 1) isOk = 1;
        }

        if(!isOk) { cout << "-1\n"; continue; }
        else{
            sort(a + 1, a + n + 1, greater<int>());

            int id = 0;
            for(int i = 1; i <= n; i++) {
                id = i;
                c.pb(a[i]);
                if(a[i] != a[i + 1]) break;
            }

            for(int i = id + 1; i <= n; i++)
                b.pb(a[i]);

            // cout << "ans: \n";
            cout << b.size() << ' ' << c.size() << endl;
            for(int u: b) cout << u << ' ';
            cout << endl;
            for(int u: c) cout << u << ' ';
        }
    }

}