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

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int a[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n; multiset<int> s;
        for(int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]);
        int mini = *s.begin();
    
        vector<int> mark(MAX, 0); int cnt = 0;
        for(int i = 1; i <= n; i++){
            int x = *s.begin();
            if(a[i] > x) mark[i] = 1, cnt++;
            s.erase(s.find(a[i]));
        }

        int id = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == mini){
                id = i;
                break;
            }
        }

        bool isOk = 1;
        for(int i = id; i <= n; i++){
            if(mark[i]) {isOk = 0; break;}
        }

        if(isOk) cout << cnt << endl;
        else cout << "-1\n";
        
    }

}