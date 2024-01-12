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
#define err_mat(i, j) cout << "mat[" << i + 1 << "][" << j + 1 << "] = " << mat[i][j] << endl;
#define err_Bmat(i, j) cout << "B.mat[" << i + 1 << "][" << j + 1 << "] = " << B.mat[i][j] << endl;
#define int long long 

const int MAX = 1e6; 
const int MOD = 1e9 + 7; 

int adj[3][3] = {
    1, 1, 1,
    1, 1, 1,
    1, 1, 0,
};

struct Matrix{
    int mat[5][5];

    Matrix operator* (const Matrix& B) const{
        Matrix res;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){ 
                int sum = 0;
                for(int k = 0; k < 3; k++){
                    sum = sum + 1LL * mat[i][k] * B.mat[k][j];
                    sum = sum % MOD;
                    // err_mat(i, k);
                    // err_Bmat(k, j);
                    // cout << "\n---------------\n";
                    // cout << "{" << i << ", " << j << "}, k = " << k << "-> " << mat[i][k] * B.mat[k][j] << endl;
                } 
                res.mat[i][j] = sum % MOD;
            }
        }
        return res;
    }

    Matrix Copy(){
        Matrix ret;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) ret.mat[i][j] = mat[i][j];
        return ret;
    }

    Matrix operator ^(int y){
        Matrix ans; 
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) ans.mat[i][j] = (i == j);

        // Matrix t = Copy();
        // t = t * ans;
        // t = t * t;
        // t = t * t;
        
        // cout << "*\n";
        // for(int i = 0; i < 3; i++){
        //     for(int j = 0; j < 3; j++) cout << t.mat[i][j] << " "; //= (i == j);
        //     cout << endl;
        // }

        Matrix tmp = Copy();
        while(y > 0){
            if(y & 1) ans = ans * tmp;
            tmp = tmp * tmp;
            y >>= 1;
        }
        return ans;
    }

};


signed main()
{IOS;


    Matrix m;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) m.mat[i][j] = adj[i][j];

    Matrix ans = m ^ 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) cout << ans.mat[i][j] << ' ';
        cout << endl;
    }

    // int n; cin >> n;
    // Matrix ans = m ^ n;
    // cout << ans.mat[0][0];

}