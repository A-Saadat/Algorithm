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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX]; 

main()
{IOS;
cout.precision(10); cout.setf(ios::fixed);

    int t; cin >> t;
    while(t--){
        int n, d, h; cin >> n >> d >> h;
        
        for(int i = 1; i <= n; i++) cin >> a[i];
        
        double ans =(d * h / 2.0);

        sort(a + 1, a + n + 1);
        for(int i = 1; i < n; i++){

            if(a[i + 1] - a[i] >= h)
                ans += (d * h / 2.0);
            else {
                double hh = a[i + 1] - a[i];
                double k = (h - hh) / h;
                double dt = (d * k);
                
                double area = (dt + d) * hh / 2;
                ans += area;
            }
        }

        cout << ans << endl;
    }

}