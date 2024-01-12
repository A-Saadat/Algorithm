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

const int MaxN = 100; 
const int MOD = 30059; 

int mark[MaxN], d[MaxN]; 
int N, ans;

int Maximum_distance(){

    int DM = 0; // ? DM = maximum distance

    for(int i = 1; i <= N; i++){
        if(mark[i]) { d[i] = 0; continue; }

        int x = 0, y = 0;
        for(int j = i; j <= N; j++) 
            if(mark[j]){
                x = j - i; 
                break;
            }

        for(int j = i; j >= 1; j--)
            if(mark[j]){
                y = i - j;
                break;
            }

        d[i] = (x > 0 && y > 0 ? min(x, y) : (x > 0 ? x : y));

        DM = max(DM, d[i]);
    }

    return DM;
}

void BT(int n){

    cout << n << ": \n";
    cout << "MARKS: \n";
    for(int i = 1; i <= N; i++) cout << i << ": " << mark[i] << endl;
    Maximum_distance();
    cout << "\nDistances: \n"; 
    for(int i = 1; i <= N; i++) cout << i << ": " << d[i] << endl;


    cout << "\n--------------\n";

    if(n == 0) ans++; //cout << "\n*** END, ANS = " << ans << "\n***\n";}
    else{
        int DM = Maximum_distance();
        for(int i = 1; i <= N; i++){
            if(!mark[i] && d[i] >= DM){
                // cout << "INSIDE, FOR CHOSING THE NEXT SIT -> " << n << " -> " << i << ": " << d[i] << " * " << DM << endl;
                mark[i] = 1;
                BT(n - 1);
                mark[i] = 0;
            }
        }
    }
}

main()
{IOS;
    cin >> N;
    BT(N);

    int sum = 0;
    sum = (ans * ans * ans);
    cout << sum % (MOD * MOD);

}