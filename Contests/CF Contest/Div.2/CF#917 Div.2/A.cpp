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

    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        bool isOk = 0;int cnt = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] == 0) isOk = 1;
            // if(a[i] < 0) 
            if(a[i] < 0) cnt++;
        } 

        if(isOk) cout << 0 << endl;
        elif(cnt % 2) cout << 0 << endl;
        else cout << 1 << endl << 1 << ' ' << 0 << endl;
        
    }

}