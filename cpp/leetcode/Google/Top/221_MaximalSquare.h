//https://leetcode.com/problems/maximal-square/
#ifndef ALGORITHMICCHALLENGES_221_MAXIMALSQUARE_H
#define ALGORITHMICCHALLENGES_221_MAXIMALSQUARE_H

#include <vector>
#include <algorithm>

using namespace std;

int getSquareSize(std::vector<std::vector<char>>& matrix, std::size_t i, std::size_t j) {
    std::size_t k = 1;
    for (;;++k) {
        if (matrix.size() == (i + k) || matrix[i].size() == (j + k))
            break;
        bool square = true;
        for (std::size_t l = 0; l <= k; ++l) {
            if (matrix[i + k][j +l] == '0' || matrix[i + l][j + k] == '0') {
                square = false;
                break;
            }
        }
        if (!square)
            break;
    }
    for (std::size_t l = i; l < (i + k); ++l)
        for (std::size_t m = j; m < (j + k); ++m)
            matrix[l][m] = '2';
    return k;
}

int maximalSquare(std::vector<std::vector<char>>& matrix) {
    int maxSquare = 0;
    for (int i = 0; i < (static_cast<int>(matrix.size()) - maxSquare); ++i)
        for (int j = 0; j < (static_cast<int>(matrix[i].size()) - maxSquare); ++j)
            if (matrix[i][j] == '1' || matrix[i][j] == '2') {
                int square = getSquareSize(matrix, i, j);
                if (square > maxSquare)
                    maxSquare = square;
            }
    return maxSquare * maxSquare;
}

int maximalSquareDP(const vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix.front().empty())
        return 0;
    vector<vector<int>> maxSquareDP(matrix.size(), vector<int>(matrix.front().size(), 0));
    for (int i = 0; i < matrix[0].size(); ++i)
        maxSquareDP[0][i] = matrix[0][i] == '1' ? 1 : 0;
    for (int i = 0; i < matrix.size(); ++i)
        maxSquareDP[i][0] = matrix[i][0] == '1' ? 1 : 0;
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix.front().size(); ++j) {
            if (matrix[i][j] == '1') {
                int minNeigbourSquare = min(maxSquareDP[i][j - 1], maxSquareDP[i - 1][j]);
                minNeigbourSquare = min(minNeigbourSquare, maxSquareDP[i - 1][j - 1]);
                maxSquareDP[i][j] = minNeigbourSquare + 1;
            }
        }
    }
    int maxSquare = 0;
    for (const auto& row : maxSquareDP) {
        for (auto cell : row)
            maxSquare = max(maxSquare, cell);
    }
    return maxSquare * maxSquare;
}

#endif //ALGORITHMICCHALLENGES_221_MAXIMALSQUARE_H
