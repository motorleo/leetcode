class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.empty()) return result;
		int column = matrix[0].size();
		int row = matrix.size();
		int center = (min(column,row) + 1) >> 1;
		for (int i = 0;i < center;++i)
		{
			for (int j = i;j < column - i;++j)
			{
				result.push_back(matrix[i][j]);
			}
			if (i != (row >> 1))
			{
				for (int j = i + 1;j < row - i;++j)
				{
					result.push_back(matrix[j][column - i - 1]);
				}
			}
			if (row - i - 1 != i)
			{
				for (int j = column - i - 2;j >= i;--j)
				{
					result.push_back(matrix[row - i - 1][j]);
				}
			}
			if (i != (column >> 1))
			{
				for (int j = row - i - 2;j > i;--j)
				{
					result.push_back(matrix[j][i]);
				}
			}
		}
		return result;
	}
};

