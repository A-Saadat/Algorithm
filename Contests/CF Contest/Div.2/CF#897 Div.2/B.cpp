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

int a[MAX], b[MAX];

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int md = (n % 2 ? n / 2 + 1 : n / 2);
       
        int mini = 0;
        for(int i = 0; i < n / 2; i++){
            if(s[i] != s[i + md]) mini++;
        }
        string ans(n + 1, '0');
        for(int i = mini; i <= n - mini; i += (n % 2 ? 1 : 2)) ans[i] = '1';
        cout << ans << endl;
    }

}