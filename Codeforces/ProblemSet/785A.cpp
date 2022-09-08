#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define pb push_back 
#define F first 
#define S second 
#define elif else if 
typedef long long int intl; 
typedef vector<int> vci;
typedef pair<int,int> pii; 
typedef pair<string,int> psi; 

int main (void)
{
    intl n;
    cin >> n;

    string a;
    intl ans = 0;
    forn(i,n){
        cin >> a;
        if(a == "Tetrahedron") ans += 4;
        elif(a == "Cube") ans += 6;
        elif(a == "Octahedron") ans += 8;
        elif(a == "Dodecahedron") ans += 12;
        elif(a == "Icosahedron") ans += 20;
    }

    cout << ans;
}