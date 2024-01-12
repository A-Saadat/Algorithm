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
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int mark[MAX]; 

vector<int> merge( vector<int> A, vector<int> B ){
    vector<int> ans;
    int a = A.size(), b = B.size();
    int i = 0, j = 0;

    int cnt = 0;
    while(cnt < 10 && i < a && j < b){
        if(A[i] > B[j]) ans.pb(B[j]), j++;
        else ans.pb(A[i]), i++;
        cnt++;
    }

    while(i < a && cnt < 10){
        ans.pb(A[i]);
        i++;
        cnt++;
    }

    while(j < b && cnt < 10){
        ans.pb(B[j]);
        j++;
        cnt++;
    }

    return ans;
}

vector<int> merge_Uniq( vector<int> A, vector<int> B, int id ){
    vector<int> ans;
    int a = A.size(), b = B.size();
    int i = 0, j = 0;

    int cnt = 0;
    while(cnt < 10 && i < a && j < b){
        if(mark[ A[i] ] == id){
            i++;
            continue;
        } 
        if(mark[ B[j] ] == id){
            j++;
            continue;
        } 

        if(A[i] > B[j]){
            mark[ B[j] ] = id;
            ans.pb(B[j]);
            j++;
        }
        else{
            mark[ A[i] ] = id;
            ans.pb(A[i]);
            i++;
        }
    }

    cnt++;

    while(cnt < 10 && i < a){
        if(mark[ A[i] ] == id){
            i++;
            continue;
        } 
        
        ans.pb(A[i]);
        i++;
        cnt++;
    }
    while(cnt < 10 && j < b){
        if(mark[ B[j] ] == id){
            j++;
            continue;
        } 
        
        ans.pb(B[j]);
        j++;
        cnt++;
    }

    return ans;
}

main()
{IOS;

    

}