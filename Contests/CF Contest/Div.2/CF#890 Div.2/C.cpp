#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX]; 
int n, k; 

bool check(int mid){
    for(int i = 1; i <= n - 1; i++){
        int id = 0;
        ll sum = 0;
        bool isOk = 0;

        for(int j = i; j <= n - 1; j++){
            if(a[j] >= mid - id) { isOk = 1; break; }
            // cout << "a[" << j << "] = " << a[j] << " -> x = " << mid - id - a[j] << endl;
            sum += mid - id - a[j];
            ++id;
        }
        
        // if(!isOk) cout << "** " << mid - n + i << endl;
        if(a[n] < (mid - id) && !isOk) continue; 

        if(sum <= k) return 1;
        
    }

    return 0;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];

        int L = 0, R = INF;
        while(R - L > 1){
            int mid = (R + L) / 2;
            if(check(mid) || a[n] >= mid) L = mid;
            else R = mid;
        }

        cout << L << endl;
    
        // check(7);
    }

}