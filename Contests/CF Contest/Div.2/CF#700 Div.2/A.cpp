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

char s[MAX]; 

inline void Solve(){
    // int n; cin >> n;
    // for(int i = 0; i < n; i++) cin >> s[i];
    string s; cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(!(i % 2)){
            if(s[i] != 'a') s[i] = 'a';
            else s[i] = 'b';
        }
        else{
            if(s[i] != 'z') s[i] = 'z';
            else s[i] = 'y';
        }
    }

    // for(int i = 0; i < n; i++) cout << s[i];
    // cout << endl;

    cout << s << endl;
}

signed main()
{IOS;

    int t; cin >> t;
    while(t--){

        Solve();

    }

}