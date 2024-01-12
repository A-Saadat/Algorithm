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

string x, s;

inline bool check(int st){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == x[st]) st++;
        else return 0;
    }

    return 1;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        cin >> x;
        cin >> s;
        bool isOk = 0; int ans = 0;
        while(!isOk && x.size() < 1000){
            for(int i = 0; i < x.size(); i++)
                if(x[i] == s[0] && check(i)){
                    isOk = 1;
                    break;
                }
            x += x;
            ans++;
        }

        if(isOk) cout << ans - 1 << endl;
        else cout << -1 << endl;
    }

}