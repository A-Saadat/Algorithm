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
vector<int> v;
int n;
int sum;
int maxi = 0;

void BT(int id, int val){
    if(id == n + 1){
        sum = 0;
        for(int i = 1; i <= n; i++){
            sum += (a[i] * v[i - 1]);
        }
        maxi = max(maxi, sum);
        for(int u: v) cout << u << ' ';
        cout << " | sum = " << sum << endl;
        return;
    }

    v.pb(val);
    BT(id + 1, val);
    v.pop_back();
    v.pb(val + 1);
    BT(id + 1, val + 1);
    v.pop_back();
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    v.pb(1);
    BT(2, 1);

    cout << maxi << endl;
}