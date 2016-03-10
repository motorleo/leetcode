class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() || b.empty()) throw std::invalid_argument("");
		if (a.size() < b.size()) return addBinary(b,a);
		int length = a.size();
		string bAdd(length - b.size(),'0');
		bAdd += b;
		string result(length,'0');
		int currentNum = 0;
		int nextNum = 0;
		for (int i = length - 1;i >= 0;--i)
		{
			currentNum = (a[i] - '0') + (bAdd[i] - '0') + nextNum;
			nextNum = currentNum >> 1;
			currentNum = currentNum % 2;
			result[i] += + currentNum;
		}
		if (nextNum)
			return "1" + result;
		else
			return result;
    }
};
