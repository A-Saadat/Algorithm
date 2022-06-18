#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{

    string a;
    cin >> a;
    bool isUnique = true;

    int ans = 0; // wjmzbmr
    for(int i = 0; i < a.size(); i++){
        for(int j = i + 1; j <= a.size(); j++){
            if(a[i] == a[j]){
                isUnique = false;
                break;
            } else
                isUnique = true;
        }
        if(isUnique == true){
            ans++;
        }
    }

    if(ans % 2 != 0)
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";


}