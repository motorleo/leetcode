class Solution {
public:
    vector<string> result;
    vector<string> dtoletter={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(int index,string s,string& digits,int len){
         if (index==len) {
            result.push_back(s);
            return;
        }
	    int k = 3,num=digits[index]-'0';
        if (1<num&&num<10)
        {
        if (num==7||num==9) k=4;
        for (int i=0;i!=k;++i)
            solve(index+1,s+dtoletter[num][i],digits,len);
    }
}
    vector<string> letterCombinations(string digits) {
        int len=digits.size();
        if (!len) return result;
        solve(0,"",digits,len);
        return result;
    }
};