// Given an 8x8 chessboard, the task is to place 8 queens on the board such that no 2 queens threaten each other.
// Return a matrix of size 8x8, where 1 represents queen and 0 represents an empty position.

#include <iostream>
#include <vector>

// Check if the queen is safe when it's placed in matrix[row][col]
bool isSafe(std::vector<std::vector<int>> &matrix, int row, int col)
{
    return false;
}

bool placeQueen(std::vector<std::vector<int>> &matrix, int row)
{

}

std::vector<std::vector<int>> nQueen(int n)
{
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    placeQueen(matrix, 0);

    return matrix;
}

int main()
{
    // std::vector<std::vector<int>>
    return 0;
}