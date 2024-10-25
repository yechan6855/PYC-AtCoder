#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M;
    cin >> M;

    vector<int> A;

    for(int exp=10; exp>=0 && M>0 && A.size()<20; exp--){
        int power=1;
        for(int i=0;i<exp;i++){
            power *=3;
        }
        while(M >= power && A.size()<20){
            A.push_back(exp);
            M -= power;
        }
    }
    if(M >0){
        while(M >0 && A.size()<20){
            A.push_back(0);
            M -=1;
        }
    }

    cout << A.size() << endl;

    for(auto it:A){
        cout << it << " ";
    }
    cout << endl;
}