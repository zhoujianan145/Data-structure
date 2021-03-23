#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string s;
		int end1 = a.size() - 1;
		int end2 = b.size() - 1;
		int next = 0;
		while (end1 >= 0 || end2 >= 0)
		{
			int x1 = 0;
			int x2 = 0;
			if (end1 >= 0)
			{
				x1 = a[end1] - '0';
				end1--;
			}
			if (end2 >= 0)
			{
				x2 = a[end2] - '0';
				end2--;
			}
			int ret = x1 + x2 + next;
			if (ret >= 2)
			{
				ret -= 2;
				next = 1;
			}
			else
			{
				next = 0;
			}
			s += ret + '0';
		}
		if (next>0)
		{
			s += '1';
		}
		reverse(s.begin(), s.end());
		return s;

	}
};

int main()
{
	Solution().addBinary("1010","1011");
	return 0;
}