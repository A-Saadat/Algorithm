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

int a[MAX];int n;  
int mini = INF;
bool mark[MAX];

void BT(int id){
    if(id == n + 1){
        vector<int> b(n + 4);
        int res = 0;
        for(int i = 1; i <= n; i++)
            if(mark[i]) b[i] = __gcd(a[i], i), res += n - i + 1;
            else b[i] = a[i];

        int g = b[1];
        for(int i = 2; i <= n; i++) g = __gcd(g, b[i]);

        if(g == 1){
            mini = min(mini, res);
            // for(int i = 1; i <= n; i++) cout << b[i] << ' ';
            // cout << endl;
        }

        return;
    }

    BT(id + 1);
    mark[id] = 1;
    BT(id + 1);
    mark[id] = 0;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        mini = INF;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        BT(1);
        cout << mini << endl;
    }

}