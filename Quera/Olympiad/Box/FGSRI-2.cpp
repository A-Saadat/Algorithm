///** فوق سری
#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define all(v) v.begin(), v.end() 
#define pb push_back 
#define elif else if 
#define S second 
#define F first 
#define int long long 

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int par[MAX], c[MAX], t[MAX], ans[MAX]; 

signed main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> par[i] >> c[i] >> t[i];

    for(int i = 1; i <= n; i++){
        int curr = i, cost = t[i], val = c[i];
        while(curr != -1){
            int p = par[curr];
            if(c[p] > val) ans[p] += cost;
            curr = p;
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << endl;


}