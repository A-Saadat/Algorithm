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

const int MAX = 1e3 + 100; 
const int INF = 1e9 + 7; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int m = (n * (n - 1)) / 2;
        int b[m];

        for(int i = 1; i <= m; i++) cin >> b[i];
        sort(b + 1, b + m + 1);
        for(int i = 1; i <= m; i += (--n)) // ? because the number of occurrences of a[i] in b is n - i 
            cout << b[i] << ' ';

        cout << 1000 * 1000 * 1000 << endl;
    }

}