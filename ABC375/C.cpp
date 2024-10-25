#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<string> A(N);
    
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    
    vector<string> B = A;
    
    int k = N /2;
    
    for(int l=1;l<=k;l++){
        int r = l %4;
        
        if(r ==0) continue;
        
        int s = N +1 -l;
        int s_idx = s -1;
        int l_idx = l -1;
        
        for(int t=0;t <= s_idx - l_idx -1;t++){
            int x1 = l_idx + t;
            int y1 = l_idx;
            int x2 = s_idx;
            int y2 = l_idx + t;
            int x3 = s_idx - t;
            int y3 = s_idx;
            int x4 = l_idx;
            int y4 = s_idx - t;
            
            switch(r){
                case 1:
                    B[y1][N -1 -x1] = A[x1][y1];
                    B[y2][N -1 -x2] = A[x2][y2];
                    B[y3][N -1 -x3] = A[x3][y3];
                    B[y4][N -1 -x4] = A[x4][y4];
                    break;
                case 2:
                    B[N -1 -x1][N -1 -y1] = A[x1][y1];
                    B[N -1 -x2][N -1 -y2] = A[x2][y2];
                    B[N -1 -x3][N -1 -y3] = A[x3][y3];
                    B[N -1 -x4][N -1 -y4] = A[x4][y4];
                    break;
                case 3:
                    B[N -1 -y1][x1] = A[x1][y1];
                    B[N -1 -y2][x2] = A[x2][y2];
                    B[N -1 -y3][x3] = A[x3][y3];
                    B[N -1 -y4][x4] = A[x4][y4];
                    break;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        cout << B[i] << "\n";
    }
}