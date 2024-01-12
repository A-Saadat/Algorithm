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

int ans;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        ans = 0;
        int n; cin >> n;
        vector<int> p(n);
        for(int i = 2; i <= n; i++){
            int x; cin >> x;
            p[x - 1]++;
        }
        p.pb(1);
        sort(p.rbegin(), p.rend());

        while(p.back() <= 0 && !p.empty()) p.pop_back();
        n = p.size();
        for(int i = 0; i < n; i++){
            p[i] = p[i] - n + i;
            ans++;
        }

        sort(p.rbegin(), p.rend());
        while(p.back() <= 0 && !p.empty()) p.pop_back();

        while(p.size() > 0){
            n = p.size(); int id = 0;
            for(int i = 0; i < p.size(); i++)
                if(p[i] == p[0]) id = i; // ? we want to keep the array sorted, so we pick the last maximum item

            p[id]--;
            for(int i = 0; i < n; i++) p[i]--;

            ans++;
            while(p.back() <= 0 && !p.empty()) p.pop_back();
        }
        cout << ans << endl;
    }

}