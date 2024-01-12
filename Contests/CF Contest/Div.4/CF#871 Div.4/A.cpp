#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 



main()
{IOS;

    string m = "codeforces";
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int cnt = 0;
        for(int i = 0; i < 10; i++) {
            if(s[i] != m[i]) cnt++;
        }

        cout << cnt << endl;
    }
}