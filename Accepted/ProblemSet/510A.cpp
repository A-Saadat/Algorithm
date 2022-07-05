#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{
    intl n, m;
    cin >> n >> m;


    bool right = true, left = false;
    for(intl i = 1; i <= n; i++){
        for(intl j = 1; j <= m; j++){
            if(i % 2 != 0)
                cout << '#';
            else{
                if(right){
                    if(j == m){
                        cout << '#';
                        right = false;
                        left = true;
                    }
                    else
                        cout << '.';
                }
                else{
                    if(j == 1)
                        cout << '#';
                    else{
                        cout << '.';
                        if(j == m){
                            right = true;
                            left = false;
                        }
                    }
                }
            }
        }

        cout << endl;
    }
}