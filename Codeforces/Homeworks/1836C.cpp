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

int cu_pow(int a, int b){
    if(b == 0) return 1;
    return a * cu_pow(a, b - 1); 
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int A, B, C, k; cin >> A >> B >> C >> k;

        bool isOk = 0;
        for(int a = cu_pow(10, A - 1); a < cu_pow(10, A); a++){
            int l = max( cu_pow(10, B - 1), cu_pow(10, C - 1) - a );
            int r = min( cu_pow(10, B), cu_pow(10, C) - a );
            
            if(l >= r) continue;

            int ways = r - l;

            if(k <= ways){
                cout << a << " + " << l + k - 1 << " = " << a + l + k - 1 << endl;
                isOk = 1;
                break;
            }

            k -= ways;
        }

        if(!isOk) cout << "-1\n";
    }

}