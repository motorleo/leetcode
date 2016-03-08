class Solution {
public:
    string getPermutation(int n, int k) {
        if (n <= 0 || k <= 0) throw std::invalid_argument("");
		int sequenceCount = 1;
		int count = 1;
		for (;count <= n;++count)
		{
			sequenceCount *= count;
			if (sequenceCount >= k)
			{
				break;
			}
		}
		string result = "1";
		for (int i = 2;i <= n;++i)
		{
			char ch = '0' + i;
			result += ch;
		}
		if (count == n + 1)	--count;
		int times = k % sequenceCount;
		int start = n - count;
		for (int i = 2;i <= times;++i)
		{
			next_permutation(result.begin() + start,result.end());
		}
		return result;
    }
};//TLE


void KthPermutation(string& result,int n,int k)
{
	if (k == 0) return;
	int base = 1;
	int i = 1;
	for (;i <= n;++i)
	{
		int temp = base * i;
		if (temp > k)
			break;
		base = temp;
	}
	if (i > n)
	{
		KthPermutation(result,n,k % base);
		return;
	}
	int index = n - i;
	int nextIndex = index + k / base;
	swap(result[index],result[nextIndex]);
	sort(result.begin() + index + 1,result.end());
	KthPermutation(result,n,k % base);
}

class Solution {
public:
	string getPermutation(int n, int k) {
		if (n <= 0 || k <= 0) throw std::invalid_argument("");
		string result = "1";
		for (int i = 2;i <= n;++i)
		{
			char ch = '0' + i;
			result += ch;
		}
		KthPermutation(result,n,k - 1);
		return result;
	}
};
