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
        string s; cin >> s;
        vector<int> lower, upper;
        vector<bool> mark(s.size() + 1, 0);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'B'){
                mark[i] = 1;
                if(upper.empty()) continue;
                mark[upper.back()] = 1;
                upper.pop_back();
            }
            elif(s[i] == 'b'){
                mark[i] = 1;
                if(lower.empty()) continue;
                mark[lower.back()] = 1;
                lower.pop_back();
            }
            else{
                if((int)(s[i] - 'a') < 0) upper.pb(i);
                else lower.pb(i); 
            }
        }

        for(int i = 0; i < s.size(); i++){
            if(mark[i]) continue;
            cout << s[i];
        }
        cout << endl;
    }

}