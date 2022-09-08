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

intl n, tmp;
intl Table[def][def];
bool isOk = true;

intl solve(intl num, intl i, intl j);

int main (void)
{
    cin >> n;
    tmp = n;

    forn(i,n)
        forn(j,n){
            cin >> Table[i][j];
        }
    
    forn(i,n)
        forn(j,n){
            if(Table[i][j] == -1){
                solve(1, i, j);
            }
        }
}

intl solve(intl num, intl i, intl j){
    forn(idx,n){
        forn(x,n){ // for x
            if(Table[i][x] == idx){
                isOk = false;
                break;
            }
        } 
        forn(y,n){ // for x
            if(Table[y][j] == idx){
                isOk = false;
                break;
            }
        }
        
        intl x = i / n * n, y = j / n * n;
        pii block = mp(x, y);

        for(intl i2 = x; i2 < n / 3; i2++){
            for(intl j2 = y; i2 < n / 3; i2++){
                if(Table[i2][j2] == idx){
                    isOk = false;
                    break;
                }
            }
        }

        solve(num++, )

    }
}