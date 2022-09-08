#include <bits/stdc++.h> 
using namespace std;

#define intl long long int 
#define def 1000


string reference, test;
intl psb, smpSpace, voidSpace, testRes, mainRes, ans;
bool useState[def];

int factorial(int n);
void backTrack(int x);

int main (void)
{
    cin >> reference >> test;
    intl n = reference.size();

    for(intl i = 0; i < n; i++){ // ? save value
        if(reference[i] == '+')
            mainRes++;
        else
            mainRes--;

        if(test[i] == '+')
            testRes++;
        else if(test[i] == '-')
            testRes--;
        else
            voidSpace++;
    }

    smpSpace = pow(2, voidSpace);

    backTrack(0);
    double psb2 = psb / 2;
    double ans = psb2 / smpSpace;
    
    cout << fixed << setprecision(9) << ans;
}

void backTrack(int x){
    int tmp = testRes;

    if(x == voidSpace + 1){
        for(intl i = 0; i < voidSpace; i++){
            if(useState[i] == 0)
                tmp--;
            else if(useState[i] == 1)
                tmp++;
        }

        if(tmp == mainRes){
            psb++;
        }

        tmp = testRes;
        return;
    }

    useState[x] = 0;
    backTrack((x + 1));
    
    useState[x] = 1; 
    backTrack((x + 1));

    return;
}