#include <bits/stdc++.h>

using namespace std;

const int MAX_WEIGHT = 40000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int j=0; j<n-1; j++){
        cout<<arr[j]*arr[j+1]<<" ";
    }

    return 0;
}