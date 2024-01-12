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

const int MAX = 1e2 + 100; 
const int INF = 1e9 + 7; 

int a[MAX]; 
int mark[MAX];

main()
{IOS;

    int t; cin >> t;
    while(t--){
        memset(mark, 0, sizeof(mark));
        int n, k; cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i], mark[a[i]] = 1;
        if(mark[k]) puts("YES");
        else puts("NO");
    }    

}