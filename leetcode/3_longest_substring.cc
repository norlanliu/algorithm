#include <string>
using namespace std;
/*
 * 动态规划算法的简单应用
 * 保存中间过程的状态
 */
int lengthOfLongestSubstring(string s) {
	if(s.size() <= 1)
		return s.size();
	const unsigned int MAX_SIZE_STRING = 0xff;
	int i, j, start, end, max_length, tmp;
	int marks[MAX_SIZE_STRING] = {0};
	start = 0;
	end = 0;
	max_length = 1;
	for(j = 0; (i = (int)s[j]); ++j)
	{
		if(marks[i] > start)
		{
			tmp = end - start;
			if(tmp > max_length)
				max_length = tmp;
			start = marks[i];
		}
		marks[i] = ++end;
	}
	tmp = end - start;
	if(tmp > max_length)
		max_length = tmp;
	return max_length;
}

int main()
{
	string str = "aa";
	int length = lengthOfLongestSubstring(str);
	fprintf(stdout, "Length: %d\n", length);
	return 0;
}
