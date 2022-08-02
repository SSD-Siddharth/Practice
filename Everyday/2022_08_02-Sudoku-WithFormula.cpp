/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 
*/


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        //9*9
        for(int i=0;i<9;i++){
            //vector<char> l={"1","2","3","4","5","6","7","8","9"};
            int a=0,b=0,l[9],v[9];
            for(int j=0;j<9;j++){
                if (board[i][j]!='.')
                {
                    char ch=board[i][j];
                    for(int k=0;k<9;k++){
                        if(board[i][k]==ch && k!=j)  //row
                            return false;
                        if(board[k][j]==ch && k!=i)  //col
                            return false;
                        //sub boxes
                        if((((i/3)*3+ k/3)!=i && ((j/3)*3+k%3)!=j) && board[(i/3)*3+ k/3][(j/3)*3+k%3]==ch){
                            return false; 
                        }
                    }
                }    

            } 
            /*
            std::set<int> sa(l, l + a);
            if ((sa.size() == (sizeof(l)/sizeof(*l))))
                return false;
            std::set<int> sa1(v, v + b);
            if ((sa1.size() == (sizeof(v)/sizeof(*v))))
                return false;
            */
        }
    return true;
        
    }
};