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

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        int mini = min(a, min(b, c));
        if(a % mini || b % mini || c % mini){
            cout << "NO\n";
            continue;
        } 
        int a1 = a / mini - 1;
        int b1 = b / mini - 1;
        int c1 = c / mini - 1;

        if(a1 + b1 + c1 <= 3) cout << "YES\n";
        else cout << "NO\n";
        // cout << a1 << " " << b1 << " " << c1 << endl;
    }

}