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

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int sum = 0, ans = 0;
        for(int i = 1; i <= 2 * n; i++){
            cin >> a[i];
            sum += abs(a[i] - (-1));
            ans += abs(a[i]);
        }

        if(n == 1)
            ans = min(ans, abs(a[1] - a[2]));
        if(n == 2)
            ans = min(ans, abs(a[1] - 2) + abs(a[2] - 2) + abs(a[3] - 2) + abs(a[4] - 2));
        if(!(n % 2))
            for(int i = 1; i <= 2 * n; i++) 
                ans = min(ans, sum - abs(a[i] - (-1)) + abs(a[i] - n));

        cout << ans << endl;
    }

}