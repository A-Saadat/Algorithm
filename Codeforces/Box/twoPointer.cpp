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
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

typedef vector<char> vcc; 

const ll LIMIT = 1e8; 

const int maxn = 1e5 + 100;
int a[maxn];
int par[maxn];

int main (void)
{
    int n, t;
    cin >> n >> t;

    for(int i = 1; i <= n;  i++)
    {
        cin >> a[i];
        par[i] = par[i - 1] + a[i];
    }

    par[n + 1] = par[n];
    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > t)
            continue;
        
        int L = i;
        int R = n + 1;

        while(R - L > 1)
        {
            int mid = (L + R) / 2; 
            if(par[mid] - par[i - 1] <= t)
                L = mid;
            else    
                R = mid;
        }

        mx = max(mx, L - i + 1);
    }
    cout << mx;

    int L = 0;
    int R = n + 1;
    while(R - L > 1)
    {
        int mid = (L + R) / 2;

        bool is = false; // i -> i + mid - 1
        for(int i = 1; i <= n - mid + 1; i++)
        {
            if(par[i + mid - 1] - par[i - 1] <= t)
                is = true;
        }

        if(is == true)
            L = mid;
        else
            R = mid;
    }
    cout << L;

    
    int E = 1;
    int sum = 0;
    int ans = 0;
    for(int S = 1; S <= n; S++)
    {
        if(E < S)
            E++;

        while(E < n + 1)
        {
            if(sum + a[E] <= t)
            {
                sum += a[E];
                E++;
            }
            else
            {
                break;
            }
        }

        ans = max(ans, E - S);
        sum -= a[S];
    }
    
    cout << ans;


}