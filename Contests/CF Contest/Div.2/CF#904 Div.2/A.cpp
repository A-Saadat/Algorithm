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

inline int decom(int tmp){
    int sum = 0;
    while(tmp > 0){
        sum += tmp % 10;
        tmp /= 10;
    }
    return sum;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int x, k; cin >> x >> k;
        int cnt = 0;
        while(decom(x) % k) x++;
        cout << x << endl;
    }

}