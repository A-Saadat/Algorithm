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

int a[MAX]; 

inline void Solve(){

    int n; cin >> n;
    vector<char> v;
    for(int i = 1; i <= n; i++) {char c; cin >> c; v.pb(c);}

    v.erase(unique(all(v)), v.end());
    // for(auto u: v) cout << u << ' ';
    // if(*v.rbegin() == '1') v.pop_back();

    int idx = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == 1) {idx = i; break;}
        // cout << v[i] << ' ';
    }

    
    cout << "ans: " << (int)(v.size()) - idx - (*v.rbegin() == '0' && n % 2) - 1 << endl;


}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        Solve();
    }

}