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

string bin(int x){
    string ans;
    if(x == 0) return "0000";
    while(x > 0){
        if(x % 2) ans += '1';
        else ans += '0';
        
        x >>= 1;
    }
    reverse(all(ans));
    return ans;
}

main()
{IOS;

    int mask; cin >> mask;
    for(int sm = mask; sm > 0; sm = (sm - 1) & mask){
        cout << bin(sm) << endl;
    }
}