#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i=k;i<n;i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define elif else if 
typedef long long int ll; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

ll n, k;

int main (void)
{
    cin >> n >> k;

    ll L = -1, R = n;
    while(R - L > 1){
        ll tmp = k;
        ll V = (R + L) / 2;
        
        ll sum = 0;
        while((V / tmp) > 0){
            sum += V / tmp; 
            tmp *= k;
        }

        sum += V;

        if(sum >= n) R = V;
        elif(sum < n) L = V;

    }

    cout << R;
}