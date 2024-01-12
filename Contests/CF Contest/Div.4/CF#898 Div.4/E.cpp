#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
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

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        for(int i = 1; i <= n; i++) cin >> a[i];

        int L = 1, R = 1e13 + 10;
        while(R - L > 1){
            int mid = (R + L) / 2, sum = 0;

            bool isOk = 0;
            for(int i = 1; i <= n; i++){
                if(a[i] > mid) continue;

                sum += (mid - a[i]);
                if(sum > x){
                    isOk = 0;
                    break;
                }
            }

            isOk = (sum <= x);

            if(isOk) L = mid;
            else R = mid;
        }

        cout << L << endl;
    }

}