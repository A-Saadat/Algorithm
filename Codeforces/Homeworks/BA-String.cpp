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

int a[MAX], ans[MAX]; 
string str;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, k;
        ll x; 
        cin >> n >> k >> x;
        --x;
        cin >> str;
        int id = 1, cnt = 0;
        for(auto u: str){
            if(u == '*') cnt++;
            else{
                a[id] = (cnt * k) + 1;
                cnt = 0;
                id++;
            }
        }

        a[id] = (cnt * k) + 1;
        int ii = id;

        while(id--){
            ans[id + 1] = x % a[id + 1];
            x /= a[id + 1];
        }

        id = 1; bool isOnce = 0;
        for(auto u: str){
            if(u == '*' && !isOnce){
                int sz = ans[id];
                while(sz--) cout << 'b';
                isOnce = 1;
            }
            elif(u == 'a'){
                cout << 'a';
                isOnce = 0;
                ++id;
            }
        }

        cout << endl;
    }

}