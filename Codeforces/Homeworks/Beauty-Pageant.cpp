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

int a[MAX]; 
set<int> s;

main()
{IOS;

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + n + 1, greater<int>());

    int cnt = 0;
    for(int i = 1; i <= n && cnt < k; i++) cout << 1 << " " << a[i] << endl, cnt++;

    for(int i = 1; i <= n; i++){
        s.insert(a[i]);

        for(int j = i + 1; j <= n; j++){
            if(cnt >= k) return 0;
            s.insert(a[j]);

            cout << s.size() << " ";
            fort(itr, s) cout << *itr << ' ';
            cout << endl;
            s.erase(a[j]);
            cnt++;

        }
    }
}