class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) throw std::invalid_argument("");
		int i = digits.size() - 1;
		for (;i >= 0 && digits[i] == 9;--i) {}
		if (i != -1)
		{
			++digits[i];
			for (int j = i + 1;j < digits.size();++j)
				digits[j] = 0;
		}
		else
		{
			digits[0] = 1;
			for (int j = 1;j < digits.size();++j)
				digits[j] = 0;
			digits.push_back(0);
		}
		return digits;
    }
};
