#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        //a is available and n is not available
        vector<vector<char>> rows(9,vector<char>(9,'a'));
        vector<vector<char>> cols(9,vector<char>(9,'a'));
        vector<vector<char>> sub_boxs(9,vector<char>(9,'a'));

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]>'0'&& board[i][j]<='9')
                {
                    int ii=(i/3);
                    int jj=(j/3);
                    int sub_no=3*ii+jj;
                    int n=(board[i][j])-'1';

                    // mathematical operations on character results in an int 
                    char row=rows[i][n];
                    char col=cols[j][n];
                    char sub_box=sub_boxs[sub_no][n];

                    
                    if(row=='n')
                        return false;
                    rows[i][n]='n';
                    if(col=='n')
                        return false;
                    cols[j][n]='n';
                    if(sub_box=='n')
                        return false;
                    sub_boxs[sub_no][n]='n';
                }
                
            }
        }
        return true;
    }
};