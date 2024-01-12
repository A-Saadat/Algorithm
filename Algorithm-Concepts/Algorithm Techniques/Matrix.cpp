#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define int long long 

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

struct Matrix{
    int mat[MAX][MAX];

    Matrix Copy(){
        Matrix tmp;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++) tmp.mat[i][j] = mat[i][j];
        return tmp;
    }
    
    Matrix operator *(const Matrix& B) const{
        Matrix ret;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                int sum = 0;
                for(int k = 1; k <= m; k++) sum += 1LL * mat[i][k] * B.mat[k][j], sum = sum % MOD;
                ret.mat[i][j] = sum;
            }
        }
        return ret;
    }


    Matrix operator ^(int y) {
        Matrix ans;
        for(int i = 1; i <= m; i++) ans.mat[i][i] = 1;

        Matrix tmp = Copy();
        while(y > 0){
            if(y & 1) ans = ans * tmp;
            tmp = tmp * tmp;
            y >>= 1;
        }
        return ans;
    }
};

main()
{IOS;

    

}