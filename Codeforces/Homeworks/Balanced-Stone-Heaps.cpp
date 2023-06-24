#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++)  
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define elif else if 

const int MaxN = 1e6; 
const int INF = 1e9 + 7; 

int a[MaxN], b[MaxN]; 
int n; 

bool check(int mid){
    for(int i = n; i >= 3; i--){
        if(b[i] < mid) return 0;
        int d = min( (b[i] - mid) , a[i] ) / 3;

        b[i - 1] += d;
        b[i - 2] += 2 * d;
        b[i] -= 3 * d;
    }

    bool isOk = true;
    forn(i,1, n + 1) 
        if(b[i] < mid) isOk = false;

    return isOk;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n;
        forn(i,1,n + 1) cin >> a[i], b[i] = a[i];

        int L = 0, R = INF;
        while(R - L > 1){
            int mid = (R + L) / 2;
            if(check(mid)) L = mid;
            else R = mid;
            
            forn(i,1,n + 1) b[i] = a[i];
        }

        cout << L << endl;
    }

}