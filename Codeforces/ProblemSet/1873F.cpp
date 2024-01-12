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

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int h[MAX], a[MAX], ps[MAX], len[MAX]; 
int n, k; 

inline bool check(int x){
    for(int i = 1; i <= n; i++){
        if(len[i] < x) continue;

        if(ps[i + x - 1] - ps[i - 1] <= k) return 1;
    }

    return 0;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n + 10; i++) ps[i] = 0, len[i] = 0;
        for(int i = 1; i <= n; i++) cin >> a[i], ps[i] = ps[i - 1] + a[i];
        for(int i = 1; i <= n; i++) cin >> h[i];

        len[n] = 1;
        for(int i = n - 1; i >= 1; i--){
            if(h[i] % h[i + 1] == 0) len[i] = len[i + 1] + 1;
            else len[i] = 1;
        }

        int L = 0, R = n + 1;
        while(R - L > 1){
            int mid = (R + L) / 2;

            if(check(mid)) L = mid;
            else R = mid;
        }

        cout << L << endl;
    }

}