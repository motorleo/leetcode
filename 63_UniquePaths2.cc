class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
		int row = obstacleGrid.size();
		int culumn = obstacleGrid[0].size();
		int vec[row][culumn];
		memset(vec,0,row * culumn * sizeof(int));
		for (int i = culumn - 1;
				i >= 0 && obstacleGrid[row - 1][i] == 0;
				--i)
			vec[row - 1][i] = 1;
		for (int i = row - 1;
				i >= 0 && obstacleGrid[i][culumn - 1] == 0;
				--i)
			vec[i][culumn - 1] = 1;
		
		for (int i = row - 2;i >= 0;--i)
		{
			for (int j = culumn - 2;j >= 0;--j)
			{
				if (obstacleGrid[i][j] == 0)
				{
					vec[i][j] = vec[i + 1][j] + vec[i][j + 1];
				}
			}
		}
		return vec[0][0];
    }
};
