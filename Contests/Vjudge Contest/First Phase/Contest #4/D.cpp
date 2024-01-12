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
typedef vector<int> vi;

const int MAX = 50 + 10; 
const int Mx = 500 * 1000 * 100;
int MOD = 1e7; 

int a[MAX];
long long int sum;
int n, k, cnt;

void defineee(int MOD){
    int dp[MOD];
    set<int> s[MOD];  

    for(int i = 1; i <= sum; i++) dp[i] = 0;

    sort(a + 1, a + n + 1);

    dp[0] = 1;
    for(int x = 1; x <= sum; x++){
        for(int i = 1; i <= n; i++){
            if(x - a[i] < 0) continue;

            if(dp[(x - a[i]) % MOD] && !s[(x - a[i]) % MOD].count(a[i])){
                dp[x % MOD] = 1;
                s[x % MOD] = s[(x - a[i]) % MOD];
                s[x % MOD].insert(a[i]);

                cout << s[x % MOD].size() << " ";
                fort(itr, s[x % MOD]) cout << *itr << " ";
                cout << endl;
                cnt++;

                if(cnt == k) exit(0);

                break;
            }

        }
    }
}


main()
{IOS;

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];

    int mx = 1000 * 1000 * 100;
    int MOD = min(1LL * mx, sum);

    defineee(MOD);

    
    // cout << "}\n";

}
    // cout << "\n------------------------\n";
    // int cnt = 0;
    // for(int x = 1; x <= sum && cnt < k; x++){
    //     if(dp[x]) {
    //         cout << s[x].size() << " ";
    //         fort(itr, s[x]) cout << *itr << " ";
    //         cout << endl;
    //         cnt++;
    //     }
    // 