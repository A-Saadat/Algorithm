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
// #define int long long 

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX]; 
vector<int> v;

inline bool check(){
    int n = v.size();
    set<int> s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            s.insert(v[i] + v[j]);
        }
    }

    int ss = n * (n - 1) / 2;
    int sz = s.size();
    if(ss == sz) return 1;
    else return 0;
}

main()
{IOS;

    int mx = 0;
    for(int mask = 0; mask < (1 << 13); mask++){
        v.clear();
        for(int j = 0; j < 32; j++){
            if((mask >> j) & 1) v.pb(j + 1);
        }

        int n = v.size();
        if(check()) mx = max(mx, n);
    }

    cout << mx << endl;
}