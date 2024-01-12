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

const int MAX = 1e2 + 10; 
const int INF = 1e9 + 7; 

int a[MAX], b[MAX]; 
map<int, vector<int>> mp; 
vector<int> v[MAX];

main()
{IOS;

    int t; cin >> t;
    while(t--){
        mp.clear(); for(int i = 1; i <= 100; i++) v[i].clear(); 
        int n; cin >> n;
        for(int i = 1; i <= n; i++) b[i] = 1;
        for(int i = 1; i <= n; i++) cin >> a[i], mp[a[i]].pb(i);
        fort(itr, mp) {
            int tmp = itr->S.size(); if(tmp == 1) continue;
            for(int u: itr->S) v[itr->F].pb(u);
        }
        int cnt = 0;
        for(int i = 1; i <= 100; i++){
            if(v[i].size() >= 2) cnt++;
        }

        if(cnt < 2) {cout << "-1\n"; continue;}

        int pri = 0;
        for(int i = 1; i <= 110; i++){
            if(v[i].size() > 1) pri = 1 - pri;
            for(int j = 1; j < v[i].size(); j++) b[v[i][j]] = pri + 2; 
        }
        for(int i = 1; i <= n; i++) cout << b[i] << ' ';
        cout << endl;
    }

}