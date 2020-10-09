#include <iostream>
#include <vector>
using namespace std;

bool WordSearchUtil(int row, int col, int wdIdx, vector<vector<char>> board, vector<char> word)
{
	if (wdIdx == word.size())
	{
		return true;
	}
	if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[wdIdx])
	{
		return false;
	}
	
	bool stat = WordSearchUtil(row + 1, col, wdIdx+1,board, word) ||
	WordSearchUtil(row - 1, col, wdIdx+1, board, word) || 
	WordSearchUtil(row, col+1, wdIdx+1, board, word) || 
	WordSearchUtil(row, col-1, wdIdx+1, board, word);

	return stat;
}


bool WordExisit(vector<vector<char>> board, vector<char> word)
{
	bool bret = false;
	int wdIdx = 0;
	for (int i = 0; i < board.size() && !bret; i++)
	{
		for (int j = 0; j < board[0].size() && !bret; j++)
		{
			if (board[i][j] == word[wdIdx])
			{
				bret = WordSearchUtil(i, j, wdIdx, board, word);
			}
		}
	}
	return bret;
}

int main(int argc, char** argv)
{
	vector<vector<char>> board{ {'A', 'B', 'C', 'E'},
								{'S', 'F', 'C', 'S'},
								{'A', 'D', 'E', 'E'} };
	vector<char>word = {'A','B','C', 'D'};

	bool bStat = WordExisit(board, word);
	cout << "The status of the search is: " << bStat;
	return 0;
}