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

int cnt[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        cnt[a] = 0, cnt[b] = 0, cnt[c] = 0;
        cnt[a]++;
        cnt[b]++;
        cnt[c]++;
        if(cnt[a] == 1) cout << a << endl;
        elif(cnt[b] == 1) cout << b << endl;
        else cout << c << endl;
    }

}