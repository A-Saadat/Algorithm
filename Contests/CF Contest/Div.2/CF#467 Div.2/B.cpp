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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX]; 

main()
{IOS;

    int p, yy; cin >> p >> yy;
    for(int y = yy; y > p; y--){
        int fr = y;
        for(int i = 2; i * i <= y; i++) if(!(y % i)) {fr = i; break;}

        if(fr > p) {cout << y << endl; return 0;}
    }

    cout << -1 << endl;

}