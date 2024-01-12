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

int a[MAX], ps[MAX]; 

main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i < n; i++)
        ps[i] = ps[i - 1] + (a[i] <= a[i - 1] && a[i + 1] <= a[i]);
        
    while(q--){
        int l, r; cin >> l >> r;
        if(l == r) cout << "1\n";
        else cout << r - l + 1 - (ps[r - 1] - ps[l]) << endl;
    }

}