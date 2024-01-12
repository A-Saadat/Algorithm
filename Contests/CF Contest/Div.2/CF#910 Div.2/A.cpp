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
        int n, k; cin >> n >> k;
        string s; cin >> s; 
        int cnt = 0;
        for(char u: s) if(u == 'B') cnt++;

        if(cnt == k) {cout << 0 << endl; continue;}
        int ans = 0;
        if(cnt < k){
            for(int i = 0; i < n && cnt < k; i++){
                if(s[i] == 'A') cnt++;
                ans++;
            }
            cout << 1 << endl << ans << " B\n"; 
        }
        else{
            for(int i = 0; i < n && cnt > k; i++){
                if(s[i] == 'B') cnt--;
                ans++;
            }
            cout << 1 << endl << ans << " A\n";
        }
        
    }

}