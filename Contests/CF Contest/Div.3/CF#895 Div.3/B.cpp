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

const int MAX = 300 + 10; 
const int INF = 1e9 + 7; 

int a[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        fill(a, a + MAX + 1, INF);
        for(int i = 1; i <= n; i++){
            int d, s; cin >> d >> s;
            a[d] = min(a[d], s);
        }

        for(int i = 1; i <= MAX; i++)
            if(a[i] == INF) a[i] = 0;

        int lim = INF;
        for(int i = 1; i <= lim; i++){
            if(!a[i]) continue;

            int x = (a[i] % 2 ? a[i] / 2 : (a[i] / 2) - 1);
            lim = min(lim, i + x);
        } 

        cout << lim << endl;
        
    }

}