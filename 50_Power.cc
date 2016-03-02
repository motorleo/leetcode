
bool equalZero(double x)
{
	return x > -0.0000001 && x < 0.0000001;
}

class Solution {
public:
    double myPow(double x, int n) {
		if (n == 0)
			return 1.0;
		if (equalZero(x))
		{
			if (n > 0)
			{
				return x;
			}
			else
			{
				throw invalid_argument("invalid.");
			}
		}
		if (n == 0x80000000)
		{
			return 1.0 / (x * myPow(x,0x7FFFFFFF));
		}
		if (n < 0)
		{
			return 1.0 / myPow(x,-n);
		}
		if (n == 1)
			return x;
		double half = myPow(x,n >> 1);
		if (n & 1)
			return half*half*x;
		else 
			return half*half;
    }
};
