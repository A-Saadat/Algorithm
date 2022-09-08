#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define elif else if 
typedef long long int intl; 
typedef vector<intl> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

int main (void)
{
    char ref[3][10] = {
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 
        'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 
        'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    };

    char type;
    cin >> type;

    intl move = type == 'R' ? -1 : +1;

    string s;
    cin >> s;


    forn(idx,s.size()){
        forn(i,3){
            forn(j,10){
                if(ref[i][j] == s[idx])
                    cout << ref[i][j + move];
            }
        }
    }
}