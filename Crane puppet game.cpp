#include<iostream>
#include<iterator>
#include<vector>

using std::cout; using std::endl;
using std::vector;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> temp;
    int movement,size,result = 0;
    size = board[0].size() - 1;
    for (unsigned int i = 0; i < moves.size(); ++i) {
        movement = moves[i] - 1;
        for (int a = size; a >= 0; --a) {
            if (board[size - a][movement] != 0) {
                cout << "input:" <<board[size - a][movement] << endl;
                if (temp.empty() == false && temp[temp.size() - 1] == board[size - a][movement]) {
                    temp.pop_back();
                    result += 2;
                }
                else
                    temp.push_back(board[size - a][movement]);
                board[size - a][movement] = 0;
                cout << "after: " << board[size - a][movement] << endl;
                break;
            }
        }
    }
    return result;
}
