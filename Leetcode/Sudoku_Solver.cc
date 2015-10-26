#include <vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
		//check if valid
		if(board.size()!=9||board[0].size()!=9)return;
		bool row[9][9] = {false};
		bool col[9][9] = {false};
		bool sub[9][3][3] = {false};
		for(int i = 0;i<9;i++)
		{
			for(int j = 0;j<9;j++)
			{
				if(board[i][j]!='.')
				{
					int num = board[i][j] - '1';
					row[num][i] = col[num][j] = sub[num][i/3][j/3] = true;
				}
			}
		}
		solveSudoku_DFS(board,0,row,col,sub);
    }
	bool solveSudoku_DFS(vector<vector<char> > &board,int pos,bool rowhash[9][9],bool colhash[9][9],bool blockhash[9][3][3])
	{
    if ( pos >= 81)
    {
        return true;
    }
    int i = pos / 9, j = pos % 9;

    if (board[i][j] != '.')
    {
        return solveSudoku_DFS(board, pos+1, rowhash, colhash, blockhash);
    } 
    else
    {
        for ( int num = 0; num < 9; num++)
        {
            if (rowhash[num][i] != true && colhash[num][j] != true && blockhash[num][i/3][j/3] != true)
            {
                board[i][j] = '1' + num;
                rowhash[num][i] = true;
                colhash[num][j] = true;
                blockhash[num][i/3][j/3] = true;
                if (solveSudoku_DFS(board, pos+1, rowhash, colhash, blockhash))
                {
                    return true;
                } 
                else
                {
                    board[i][j] = '.';
                    rowhash[num][i] = false;
                    colhash[num][j] = false;
                    blockhash[num][i/3][j/3] = false;
                }
            }
        }

        return false;
    }
	}
};
