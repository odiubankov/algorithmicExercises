//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
#ifndef ALGORITHMICCHALLENGES_329_LONGESTINCREASINGPATHINMATRIX_H
#define ALGORITHMICCHALLENGES_329_LONGESTINCREASINGPATHINMATRIX_H

#include <vector>
#include <algorithm>
using namespace std;

using CacheT = vector<vector<int>>;

vector<pair<int, int>> getNextPositions(const vector<vector<int>>& matrix, int i, int j) {
    vector<pair<int, int>> nextPositions;
    if (j > 0)
        nextPositions.emplace_back(i, j - 1);
    if (j < (matrix[i].size() - 1))
        nextPositions.emplace_back(i, j + 1);
    if (i > 0)
        nextPositions.emplace_back(i - 1, j);
    if (i < (matrix.size() - 1))
        nextPositions.emplace_back(i + 1, j);
    return nextPositions;
}

int longestIncreasingPathImpl(const vector<vector<int>>& matrix, int i, int j, CacheT& cache) {
    if (cache[i][j] != -1)
        return cache[i][j];
    int path = 1;
    for (auto const& nextPos : getNextPositions(matrix, i, j)) {
        if (matrix[nextPos.first][nextPos.second] > matrix[i][j])
            path = max(path, 1 + longestIncreasingPathImpl(matrix, nextPos.first, nextPos.second, cache));
    }

    cache[i][j] = path;
    return path;
}

int longestIncreasingPath(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix.front().empty())
        return 0;
    int longestPath = 0;
    CacheT cache(matrix.size(), vector<int>(matrix.front().size(), -1));
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            int path = longestIncreasingPathImpl(matrix, i, j, cache);
            if (path > longestPath)
                longestPath = path;
        }
    }
    return longestPath;
}

#endif //ALGORITHMICCHALLENGES_329_LONGESTINCREASINGPATHINMATRIX_H
