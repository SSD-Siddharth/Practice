/*
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int> > res(r, vector<int> (c, 0));
        //When the size in not the same
        if(r*c!=m*n) 
            return mat;
        vector<int> tmp;
        //Adding the whole matrix, into a 1d array, 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                tmp.push_back(mat[i][j]);
            }
        }
        //Adding that 1d array into the final matrix
        int ind1=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[i][j]=tmp[ind1++];
            }
        }
        //ut<<m;
        return res;
    }
};