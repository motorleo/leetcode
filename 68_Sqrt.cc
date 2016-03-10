class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) return -1;
		if (x == 0) return 0;
		int base = 1;
		while (true)
		{
			int temp = base*base;
			if (temp > x || temp/base != base)
			{
				break;
			}
			base <<= 1;
		}
		base >>= 1;
		while (true)
		{
			int temp = base*base;
			if (temp > x || temp/base != base)
			{
				break;
			}
			++base;
		}
		--base;
		return base;
    }
};

class Solution {
public:
    int mySqrt(int x) {
		if (x < 0) return -1;
		if (x == 0) return 0;
		int begin = 0;
		int end = 70000;
		while (begin <= end)
		{
			int middle = (begin + end) >> 1;
			int temp = middle * middle;
			if (temp > x || temp / middle != middle)
				end = middle - 1;
			else if (temp < x)
				begin = middle + 1;
			else
				return middle;
		}
		return begin;
    }
};

int main()
{
	Solution test;
	test.mySqrt(2);
}
