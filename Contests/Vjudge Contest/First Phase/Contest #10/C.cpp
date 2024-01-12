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

const int MAX = 200000 + 20; 
const int MOD = 2019; 

int suf[MAX]; 
int p[MAX];
int cnt[2023];

signed main()
{IOS;

    string s; cin >> s; int n = (int)(s.size());
    p[0] = 1;
    for(int i = 1; i <= n + 10; i++) p[i] = 1LL * (p[i - 1] * 10), p[i] = p[i] % MOD;

    suf[n - 1] = (int)(s[n - 1] - '0');
    for(int i = n - 2; i >= 0; i--){
        int a = (int)(s[i] - '0');
        int x = 1LL * (p[n - i - 1] * a); //x = x % MOD;
        suf[i] = (suf[i + 1] + x) % MOD;
        cnt[suf[i]]++;
    }

    int ans = cnt[0];
    for(int i = 1; i <= 2019; i++){
        int res = 1LL * (cnt[i] * (cnt[i] - 1) / 2);
        ans += res;
    }

    cout << ans << endl;
}