#include <bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

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
const int INF = 1e18 + 7; 

int a[MAX]; 
set<int> s;
// vector<int> v;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        int c1 = 0, c2 = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] % 2) c1++;
            else c2++; 
        } 

        for(int i = 2; i <= 2e18; i *= 2){
            s.clear();
            for(int j = 1; j <= n; j++) s.insert(a[j] % i);
            if(s.size() == 2){
                cout << i << endl;
                break;
            }
        }



    }
} 