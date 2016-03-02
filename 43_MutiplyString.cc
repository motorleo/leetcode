#include <stdio.h>
#include <string>

using std::string;

class Solution {
public:
    string multiply(string num1, string num2) {
        int currentNum = 0;
		int nextNum = 0;
		string result(num1.size() + num2.size(),'0');
		for (int i = num1.size() - 1;i >= 0;--i)
		{
			for (int j = num2.size() - 1;j >= 0;--j)
			{
				int resultIndex = i + j + 1;
				currentNum = nextNum + (result[resultIndex] - '0');
				currentNum += (num1[i] - '0') * (num2[j] - '0');
				nextNum = currentNum / 10;
				currentNum %= 10;
				result[resultIndex] = currentNum + '0';
			}
			if (nextNum)
			{
				result[i] = nextNum + '0';
				nextNum = 0;
			}
		}
		string::iterator iter = result.begin();
		for (;iter < result.end() && *iter == '0';++iter) ;
		if (iter == result.end()) return "0";
		return string(iter,result.end());
    }
};

int main()
{
	Solution test;
	printf("%s\n",test.multiply("0","0"));
}
