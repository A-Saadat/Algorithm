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

vector<int> v;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        string s; cin >> s; v.clear();
        int cnt = 0;
        for(char c: s){
            if(c == 'A') cnt++;
            else v.pb(cnt), cnt = 0;
        }
        v.pb(cnt);

        cout << accumulate(all(v), 0) - *min_element(all(v)) << endl;
    }

}