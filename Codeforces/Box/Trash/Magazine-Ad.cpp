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
typedef long long int ll; 
typedef vector<int> vi;

const int MaxN = 1e6; 
const int INF = 1e9 + 7; 

vector<int> a, v; // ? the index of Breaking Point
string str;
int k; 

bool check(int mid){
    int sum = 0, cnt = 0, sz = a.size();

    if(mid > str.size()) return 1;

    int lst = 0; // ? lst = the last index of sum
    for(int i = 1; (cnt < k) && (i < a.size()); i++){

        cout << "I = " << i << " a[" << i << "] = " << a[i] << " sum = " << sum << endl;

        if(a[i] - sum > mid){
            v.pb(a[i - 1] - sum);
            sum = a[i - 1]; 
            cnt++; 
            lst = i; //cout << "WTF DUDE, I UPDATE THIS SHIT TO " << i - 1 << " LONG TIME AGO :/\n";
        } 
        if(a[i] - sum > mid) {cout << "YEAH, BABY C'MON\n"; return 0;}
    }

    if(cnt < k - 1)
}

main()
{IOS;

    cin >> k;
    cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); 
    getline(cin, str);
    
    for(int i = 0; i < str.size(); i++)
        if(str[i] == ' ' || str[i] == '-') a.pb(i + 1);

    for(int u: a) cout << u << " ";
    cout << "\n-------------------\n";

    // int L = 0, R = INF;
    // while(R - L > 1){
    //     int mid = (R + L) / 2;

    //     if(check(mid)) R = mid;
    //     else L = mid;
    // }

    check(6); 
}