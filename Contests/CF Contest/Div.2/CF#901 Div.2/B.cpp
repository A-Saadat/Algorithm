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

int a[MAX], b[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= m; i++) cin >> b[i];

        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);

        if(a[1] < b[m]) swap(a[1], b[m]);
        if(!(k % 2)){
            if(a[1] < b[m]) swap(a[1], b[m]); // ? Jellyfish 
            
            sort(a + 1, a + n + 1);
            sort(b + 1, b + m + 1);

            if(b[1] < a[n]) swap(b[1], a[n]);
        }

        int sum = 0;
        for(int i = 1; i <= n; i++) sum += a[i];
        cout << sum << endl;
    }

}