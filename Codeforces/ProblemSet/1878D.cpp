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

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int l[MAX], r[MAX];
int n, k; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        string s; cin >> s;
        for(int i = 1; i <= k; i++) cin >> l[i], l[i]--;
        for(int i = 1; i <= k; i++) cin >> r[i], r[i]--;

        vector<int> cnt(n + 1, 0);

        int q; cin >> q;
        while(q--){
            int x; cin >> x;
            cnt[x - 1]++;
        }

        string ans = "";
        for(int i = 1; i <= k; i++){
            int L = l[i], R = r[i];
            string ss = s.substr(L, R - L + 1); // ? [,)
            int sum = 0;
            for(int j = L; j <= (R + L) / 2; j++){
                sum += cnt[j] + cnt[R + L - j];
                if(sum % 2) swap(ss[j - L], ss[R - j]);
            }
            ans += ss;
        }
        cout << ans << endl;
    }

}