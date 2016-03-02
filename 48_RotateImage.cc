
void RotateCircle(vector<vector<int>>& matrix,int begin,int end)
{
	int times = end - begin;
	for (int i = 0;i < times;++i)
	{
		int temp = matrix[begin][begin + i];
		matrix[begin][begin + i] = matrix[end - i][begin];
		matrix[end - i][begin] = matrix[end][end - i];
		matrix[end][end - i] = matrix[begin + i][end];
		matrix[begin + i][end] = temp;
	}
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int length = matrix.size();
		int center = length >> 1;
        for (int i = 0;i < center;++i)
		{
			RotateCircle(matrix,i,length - i - 1);
		}
    }
};
