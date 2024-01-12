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

int a[MAX], last[MAX], fr_max[MAX], sc_max[MAX]; 
int n, k; 

inline void clear_Arr(){
    for(int i = 1; i <= k; i++) last[i] = 0;
    for(int i = 1; i <= k; i++) fr_max[i] = 0;
    for(int i = 1; i <= k; i++) sc_max[i] = 0;
}   

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        clear_Arr();

        for(int i = 1; i <= n; i++){
            cin >> a[i];

            int step = i - last[ a[i] ] - 1;
            last[ a[i] ] = i;
            
            if(step > fr_max[ a[i] ]) {
                sc_max[ a[i] ] = fr_max[ a[i] ];
                fr_max[ a[i] ] = step;
            }
            elif(step > sc_max[ a[i] ])
                sc_max[ a[i] ] = step;
        } 

        for(int i = 1; i <= k; i++){
            int step = n - last[i];
            if(step > fr_max[i]) {
                sc_max[i] = fr_max[i];
                fr_max[i] = step;
            }
            elif(step > sc_max[i])
                sc_max[i] = step;
        }

        int ans = INF;
        for(int i = 1; i <= k; i++){
            int fr = fr_max[i];
            int sc = sc_max[i];

            ans = min(ans, max(fr / 2, sc));
        }

        cout << ans << endl;
    }

}