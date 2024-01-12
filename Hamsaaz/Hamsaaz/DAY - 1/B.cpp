#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
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
const int MOD = 30059; 

int a[MaxN]; 

main()
{IOS;

    int ans1 = 0;
    for(int x1 = 0; x1 <= 11; x1++){

        for(int x2 = 0; x2 <= 6; x2++){
            
            for(int x3 = 0; x3 <= 3; x3++){

                for(int x4 = 0; x4 <= 2; x4++){

                    for(int x5 = 0; x5 <= 1; x5++){

                        for(int x6 = 0; x6 <= 1; x6++){

                            int sum = (x1 + 1) * (x2 + 1) * (x3 + 1) * (x4 + 1) * (x5 + 1) * (x6 + 1);

                            if(sum == 2016) ans1++;
 
                        }

                    }

                }

            }

        }

    }

    int ans2 = 0;
    for(int x1 = 0; x1 <= 15; x1++){

        for(int x2 = 0; x2 <= 6; x2++){
            
            for(int x3 = 0; x3 <= 3; x3++){

                for(int x4 = 0; x4 <= 2; x4++){

                    for(int x5 = 0; x5 <= 1; x5++){

                        for(int x6 = 0; x6 <= 1; x6++){

                            int sum = (x1 + 1) * (x2 + 1) * (x3 + 1) * (x4 + 1) * (x5 + 1) * (x6 + 1);

                            if(sum == 2688) ans2++;
 
                        }

                    }

                }

            }

        }

    }

    int ans3 = 0;
    for(int x1 = 0; x1 <= 15; x1++){

        for(int x2 = 0; x2 <= 6; x2++){
            
            for(int x3 = 0; x3 <= 3; x3++){

                for(int x4 = 0; x4 <= 2; x4++){

                    for(int x5 = 0; x5 <= 1; x5++){

                        for(int x6 = 0; x6 <= 1; x6++){

                            for(int x7 = 0; x7 <= 1; x7++){
                                ll sum = (x1 + 1) * (x2 + 1) * (x3 + 1) * (x4 + 1) * (x5 + 1) * (x6 + 1) * (x7 + 1);

                                if(sum == 5376) ans3++;
                            }
 
                        }

                    }

                }

            }

        }

    }

    // ll g = (ans1 * ans1) * (ans2 * ans2);
    // g += ans3;
    
    // cout << (g * g) % MOD << endl;


    // for


    int r = 0;
    for(int x1 = 0; x1 <= 7; x1++){

        for(int x2 = 0; x2 <= 4; x2++){
            
            for(int x3 = 0; x3 <= 1; x3++){

                for(int x4 = 0; x4 <= 1; x4++){

                    ll sum = (x1 + 1) * (x2 + 1) * (x3 + 1) * (x4 + 1);
                    if(sum == 80) cout << x1 << ' ' << x2 << ' ' << x3 << ' ' << x4 << endl, r++;

                }

            }

        }

    }

    cout << r;

}
