#include <vector>
#include <iostream>

// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    // numRows = 5
    // 1
    // 1 1
    // 1 2 1
    // 1 3 3 1
    // 1 4 6 4 1

    // i starts from 0
    // The row i has i + 1 elements
    // The first and last element of each row are always 1
    // Get row i from row i - 1 if i >= 2
    // row[i][0] = 1
    // row[i][i] = 1
    // row[i][j] = row[i - 1][j - 1] + row[i - 1][j], 1 <= j <= i - 1
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> result;

        for (int i = 0; i < numRows; i++)
        {
            std::vector<int> row;
            row.push_back(1);

            // if (i == 0)
            // {
            //     result.push_back(row);
            //     continue;
            // }

            // if (i == 1)
            // {
            //     row.push_back(1);
            //     result.push_back(row);
            //     continue;
            // }

            for (int j = 1; j <= i - 1; j++)
            {
                int element = result[i - 1][j - 1] + result[i - 1][j];
                row.push_back(element);
            }

            if (i >= 1)
                row.push_back(1);

            result.push_back(row);
        }

        return result;
    }
};

void printResult(std::vector<std::vector<int>> &result)
{
    std::cout << "[";
    for (auto &row: result)
    {
        std::cout << "[";

        for (auto &element: row)
        {
            std::cout << element << " ";
        }

        std::cout << "]";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    Solution solution;
    int numRows;
    std::vector<std::vector<int>> result;

    // Example 1
    numRows = 5;
    result = solution.generate(numRows);
    std::cout << "Answer: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]" << std::endl;
    std::cout << "Output: ";
    printResult(result);

    // Example 2
    numRows = 1;
    result = solution.generate(numRows);
    std::cout << "Answer: [[1]]" << std::endl;
    std::cout << "Output: ";
    printResult(result);

    return 0;
}