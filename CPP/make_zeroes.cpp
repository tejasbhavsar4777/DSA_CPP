#include <iostream>

void makeZeros(vector<vector<int> >& matrix) {

    int n = matrix<size();
    int m = matrix[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                if(i+1<n){
                    matrix[i][j] += matrix[i+1][j];
                    matrix[i+1][j]=0;

                }
                if(i-1 >= 0){
                    matrix[i][j] += matrix[i-1][j];
                    matrix[i-1][j]=0;

                }
                if(j+1<m){
                    matrix[i][j] += matrix[i][j+1];
                    matrix[i][j+1]=0;

                }
                if(j-1 >= 0){
                    matrix[i][j] += matrix[i][j]-1;
                    matrix[i][j-1]=0;

                }

            }
        }
    }


}
