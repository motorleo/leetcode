#define MAX_INT 0x7FFFFFFF
class Solution {
public:
    int divide(int dividend, int divisor) {
		if (divisor == 0) return MAX_INT;
		long long left = dividend;
		long long right = divisor;
		left = labs(left);
		right = labs(right);
		bool nagative = (dividend ^ divisor) >> 31;
		long result = 0;
		while (left >= right)
		{
			long temp = right;
			for (int i = 0;left >= temp;++i,temp <<= 1)
			{
				left -= temp;
				result += 1 << i;
			}
		}
		if (!nagative && result > MAX_INT) return MAX_INT;
		return nagative ? -result : result;
    }
};
