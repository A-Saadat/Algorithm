#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define int long long 

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

// int a[MAX]; 
vector< pair<int, int> > a, b, c;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        a.clear();
        b.clear();
        c.clear();
        a.resize(n + 5);
        b.resize(n + 5);
        c.resize(n + 5);

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            a.pb({x, i});
        } 

        
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            b.pb({x, i});
        } 

        
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            c.pb({x, i});
        } 

        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        sort(c.rbegin(), c.rend());

        int ans = 0;
        // vector<int> mark(10, 0);
        for(int i = 0; i < 3; i++){
            int d1 = a[i].S;
            for(int j = 0; j < 3; j++){
                int d2 = b[j].S;
                if(d1 == d2) continue;

                for(int k = 0; k < 3; k++){
                    int d3 = c[k].S;
                    if(d1 == d3 || d2 == d3) continue;

                    // cout << "{" << a[i].F << ", " << b[i]

                    ans = max(ans, a[i].F + b[j].F + c[k].F);
                }
            }
        }

        cout <<  ans << endl;

    }    

}