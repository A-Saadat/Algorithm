#include <bits/stdc++.h> 
#include <limits>
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
#define int long long int 
typedef vector<int> vi;

const int MaxN = 1e6; 
const int INF = 1e9 + 7; 

string str;
int k; 

bool check(int mid){
    int BP = 0, lnCnt = 1, wdl = 0;
    for(int i = 0; i < str.size(); i++){
        wdl++;

        if(wdl > mid){
            if(BP == 0) return 0;
            
            wdl = i - BP;
            BP = 0;
            lnCnt++;
        }

        if(str[i] == ' ' || str[i] == '-') BP = i;
        
    }

    if(lnCnt <= k) return 1;
    else return 0;
}

main()
{IOS;

    cin >> k;
    cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); 
    getline(cin, str);

    int L = 0, R = INF;
    while(R - L > 1){
        int mid = (R + L) / 2;

        if(check(mid)) R = mid;
        else L = mid;
    }

    cout << R;
}