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

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++)
        if(i % 2 != a[i] % 2) cnt1++;

    for(int i = 1; i <= n; i++)
        if(i % 2 == a[i] % 2) cnt2++;

    cout << min(cnt1, cnt2) << endl;

}