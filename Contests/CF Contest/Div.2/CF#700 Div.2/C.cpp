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

signed main()
{IOS;

    int n; cin >> n;
    
    int L = 1, R = n;
    int x, y;
    while(R != L){
        int mid = (R + L) >> 1;
        cout << "? " << mid << endl;
        cin >> x;
        cout << endl;
        cout << "? " << mid + 1 << endl;
        cin >> y;
        cout << endl;

        if(x < y) R = mid;
        else L = mid + 1;
    }

    cout << "! " << L << endl;

}