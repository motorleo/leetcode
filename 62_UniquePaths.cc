
int dfs(int m,int n)
{
	if (m == 1 || n == 1)
		return 1;
	int count = 0;
	for (int i = 0;i < m;++i)
	{
		count += dfs(m - i,n - 1);
	}
	return count;
}

class Solution {
public:
    int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0) return -1;
		return dfs(m,n);
    }
};//TLE

class Solution {
public:
    int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0) return -1;
		int vec[m][n];
		for (int i = 0;i < n;++i)
			vec[m - 1][i] = 1;
		for (int i = 0;i < m - 1;++i)
			vec[i][n - 1] = 1;
		for (int i = m - 2;i >= 0;--i)
		{
			for (int j = n - 2;j >= 0;--j)
			{
				vec[i][j] = vec[i + 1][j] + vec[i][j + 1];
			}
		}
		return vec[0][0];
    }
};
