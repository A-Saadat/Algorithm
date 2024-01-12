// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 2e5 + 100; 
const ll INF = 1e9 + 7; 

int a[MaxN], sum[MaxN]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){

        memset(sum, 0, sizeof(sum));

        int n; cin >> n;
        forn(i,1,n + 1) cin >> a[i], sum[i] = sum[i - 1] + a[i];

        int L = 0, R = n;
        while(R - L > 1){

            int mid = (R + L) / 2;

            cout << "? " << mid - L + (L == 0 ? 0 : 1) << ' ';
            forn(i,L,mid + 1) 
                if(i) cout << i << ' ';

            cout << endl;

            int res1; cin >> res1;
            int s = 0;

            s = sum[mid] - sum[L - 1];
            
            if(s != res1) R = mid;
            else L = mid;

        }

        cout << "! " << L + 1 << endl;

    }

}