#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define pb push_back 
#define F first 
#define S second 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

int a[MaxN], cnt[5]; // ? cnt[0] is the counter of Postive subarrays, cnt[1] is the counter of Negetive subarrays 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll sum = 0;
        forn(i,0,n) cin >> a[i], sum += abs(a[i]);

        int isPos = -1;
        forn(i,0,n){
            if(a[i] == 0) continue;
            if(isPos == -1) isPos = (a[i] < 0 ? 1 : 0);


            if(isPos && a[i] < 0 || !isPos && a[i] > 0) cnt[isPos]++, isPos = 1 - isPos;

        }

        cout << sum << ' ' << min(cnt[0] + 1, cnt[1]) << endl;

        memset(cnt, 0, sizeof(cnt));
    }

}