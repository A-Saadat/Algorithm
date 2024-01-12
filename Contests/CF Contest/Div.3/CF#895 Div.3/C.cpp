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
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX]; 

inline int Solve(int l){
    return -1;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        if(l == r) cout << "ans: " << Solve(l) << endl;
        else{
            int x = (l % 2 ? l - 1 : l - 2);
            cout << "ans: " << 2 << ' ' << x << endl;
        }
    }

}