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
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

vector<int> a[12] = { {0}, {1}, {2}, {3}, {2, 2}, {5}, {2, 3}, {7}, {2, 2, 2}, {3, 3}, {2, 5} }; 
vector< vector<int> > b;
vector<int> v;
int ans = 0;


main()
{IOS;

    int n = 10;
    for(int mask = 1; mask < (1 << n); mask++){
        b.clear();

        int mini = MaxN; v.clear();
        for(int j = 0; j < 32; j++)
            if( ((mask >> j) & 1) ){
                if( a[j + 1].size() < mini ) mini = a[j + 1].size(), v = a[j + 1];

                b.pb( a[j + 1] );
            } 

        int s = b.size();
        int id = 0;
        while(id < mini){

            bool isOk = true;
            for(auto u: b){
                isOk = true;

                if(v[id] != u[id]) isOk = false;
            }

            ++id;

            if(isOk) ans++;
        }
    }
    cout << ans;

}