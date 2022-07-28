#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
#define forn(i,n) for(int i=0;i<n;i++) 
typedef long long int intl; 
typedef vector<int> vci;
typedef pair<int,int> pii; 

int main (void)
{
    intl n, l;
    cin >> n >> l;

    intl lanterns[def];
    forn(i,n) cin >> lanterns[i];
    sort(lanterns, lanterns + n);

    double maxLenght = lanterns[0];

    bool flag = true;
    forn(i,n){
        if((lanterns[i+1] - lanterns[i]) > maxLenght){
            maxLenght = lanterns[i+1] - lanterns[i];
        }
    }

    if((maxLenght / 2 < lanterns[0]) or (maxLenght / 2 < l - lanterns[n-1]))
        cout << max(lanterns[0], l - lanterns[n-1]);
    else
        cout << fixed << setprecision(12) << maxLenght / 2;
}