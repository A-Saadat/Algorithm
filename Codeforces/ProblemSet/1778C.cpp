#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define int long long 
typedef vector<int> vi;

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

string a, b;
int n, k; 
set<char> uni;
vector<int> ch;
int mark[MAX];
int ans;

inline int Find_Matching(){
    int cnt = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i] || mark[ a[i] - 'a' ]) cnt++;
        else{
            sum += (cnt + 1) * cnt / 2;
            cnt = 0;
        }
    }

    sum += (cnt + 1) * cnt / 2;

    return sum;
}

void BT(int pos, int cnt){ // ? cnt will count the number of '1'
    if(cnt > k) return;
    if(pos == ch.size()){
        if(cnt == k) ans = max(ans, Find_Matching());
        return;
    }

    BT(pos + 1, cnt);
    mark[ ch[pos] - 'a' ] = 1;
    BT(pos + 1, cnt + 1);
    mark[ ch[pos] - 'a' ] = 0;
}

inline void clear_arr(){
    memset(mark, 0, sizeof(mark));
    ch.clear();
    uni.clear();
    ans = 0;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        clear_arr();
        cin >> n >> k;
        cin >> a >> b;

        for(int i = 0; i < n; i++){
            if(a[i] == b[i]) continue;

            uni.insert(a[i]);
        }

        fort(itr, uni) ch.pb(*itr);
        k = min(k, 1LL * (uni.size()));

        BT(0, 0);
        cout << ans << endl;

    }

}