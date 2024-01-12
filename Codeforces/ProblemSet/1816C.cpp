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

int a[MAX], b[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(i == 1) continue;

            b[i - 1] = a[i] - a[i - 1]; 
        }

        if(n % 2) puts("YES");
        else{
            int sum = 0;
            for(int i = 1; i < n; i += 2) sum += b[i];

            if(sum >= 0) puts("YES");
            else puts("NO");
        }
    }

}