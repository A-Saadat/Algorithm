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
int n; 

vector<int> A, B;
int maxi = 0;

void BT(int id){
    if(id == n + 1){
        vector<int> v1, v2;
        for(int i = 1; i <= n; i++){
            if(b[i] == 1) v1.pb(a[i]);
            else v2.pb(a[i]);
        }

        v1.erase(unique(all(v1)), v1.end());
        v2.erase(unique(all(v2)), v2.end());

        int res = v1.size() + v2.size();

        if(res > maxi){
            maxi = res;
            A = v1;
            B = v2;
        }

        return;
    }

    BT(id + 1);
    b[id] = 1;
    BT(id + 1);
    b[id] = 0;

}

signed main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    BT(1);

    for(int u: A) cout << u << ' ';
    cout << endl;
    for(int u: B) cout << u << " ";

    // int c1 = INF, c2 = INF;
    // int ans = 0;
    // for(int i = 1; i <= n; i++){
    //     if(c1 != a[i]) c1 = a[i], ans++;
    //     elif(c2 != a[i]) c2 = a[i], ans++;
    // }

    // cout << ans << endl;

}