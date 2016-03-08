#include <stdio.h>
#include <vector>
#include <stdexcept>
using std::vector;
void fillMatrix(vector<vector<int> >& result,int start,int end,int& count)
{
	for (int i = start;i <= end;++i)
	{
		printf("%d\n",count);
		printf("%d\n",result[start][i]);
		result[start][i] = ++count;
		printf("%d\n",result[start][i]);
		printf("%d\n",count);
	}
	for (int i = start + 1;i <= end;++i)
	{
		result[i][end] = ++count;
	}
	for (int i = end - 1;i >= start;--i)
	{
		result[end][i] = ++count;
	}
	for (int i = end - 1;i > start;--i)
	{
		result[i][start] = ++count;
	}
}

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
		if (n < 0) throw std::invalid_argument("");
        vector<vector<int> > result;
		if (n == 0) return result;
		for (int i = 0;i < n;++i)
		{
			result.push_back(vector<int>(n));
		}
		int center = n >> 1;
		int count = 0;
		for (int i = 0;i <= center;++i)
		{
			fillMatrix(result,i,n - i - 1,count);
		}
		return result;
    }
};


int main()
{
	Solution test;
	test.generateMatrix(1);
}
