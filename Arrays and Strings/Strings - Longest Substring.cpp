/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
	Given a string, find the length of the longest substring without repeating characters.

	Examples:
	Given "abcabcbb", the answer is "abc", which the length is 3.
	Given "bbbbb", the answer is "b", with the length of 1.
	Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, 
		"pwke" is a subsequence and not a substring.
*/

#include "Arrays_and_Strings.h"
class Solution {
public:
	/*
	Time complexity : O(n^​3).
		To verify if characters within index range [i, j)[i,j) are all unique, we need to scan all of them. 
		Thus, it costs O(j - i) time.

		For a given i, the sum of time costed by each j ∈ [ i + 1 , n ] is
			n
			∑	O(j - i)
​			i+1
​
		Thus, the sum of all the time consumption is:

			n−1	  n					n-1   (1 + n - i)(n - i)
		O(​	∑	( ∑  (j - i))) = O( ∑     ------------------   )  = O(n^3)
			i=0   j=i+1				i=0			   2

	Space complexity : O(min(n, m)). 
		We need O(k) space for checking a substring has no duplicate characters, where k is the size of the Set. 
		The size of the Set is upper bounded by the size of the string n and the size of the charset/alphabet m. 
	*/
	int lengthOfLongestSubstring_bruteForce(string s) {
		int n = s.length();
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				if (allUnique(s, i, j)) ans = max(ans, j - i);
		return ans;
	}

	bool allUnique(string s, int start, int end) {
		set<char> charset;
		for (int i = start; i < end; i++) {
			char ch = s[i];
			if (charset.find(ch) != charset.end()) 
				return false;
			charset.insert(ch);
		}
		return true;
	}

	/*
	Time complexity : O(2n) = O(n). 
		In the worst case each character will be visited twice by i and j.

	Space complexity : O(min(m, n)). 
		Same as the previous approach. We need O(k) space for the sliding window, where k is the size of the Set. 
		The size of the Set is upper bounded by the size of the string n and the size of the charset/alphabet m. 
	*/
	int lengthOfLongestSubstring_slidingWindow(string s) {
		int n = s.length();
		set<char> set;
		int ans = 0, i = 0, j = 0;
		while (i < n && j < n) {
			// try to extend the range [i, j]
			if (set.find(s[j]) == set.end()){
				set.insert(s[j++]);
				ans = max(ans, j - i);
			}
			else {
				set.erase(s[i++]);
			}
		}
		return ans;
	}

	/*
	Time complexity : O(n). 
		Index j will iterate n times.

	Space complexity (HashMap) : O(min(m, n)). 
		Same as the previous approach.
	Space complexity (Table): O(m). 
		m is the size of the charset.
	*/
	int lengthOfLongestSubstring_slidingOptimized(string s) {
		int n = s.length(), ans = 0;
		map<char, int> map; // current index of character
		// OR,
		int index[128] = {0}; // current index of character, init with zeros
		// try to extend the range [i, j]
		for (int j = 0, i = 0; j < n; j++) {
			// TABLE:
			i = max(index[s[j]], i);
			// HASH:
			if (map.find(s[j]) != map.end()) {
				i = max(map.find(s[j])->second, i);
			}
			ans = max(ans, j - i + 1);
			// TABLE:
			index[s[j]] = j + 1;
			// HASH:
			map.insert(make_pair(s[j], j + 1));
		}
		return ans;
	}

	int lengthOfLongestSubstring(string s) {
		int largestLength = 0;
		int currentLength = 0;
		int startIdx = 0;
		map<char, int> m;
		//cout << s << " (" << s.length() << ")" << endl;
		for (int i = 0; i < s.length(); i++) {
			//cout << "CHECKING " << s.substr(startIdx, i-startIdx+1) << " (" << startIdx << "," << i << "[" << s[i] << "])"<< endl;
			if (m.find(s[i]) == m.end() || (m.find(s[i])->second < startIdx)) {
				if (m.find(s[i]) == m.end()) {
					//cout << " NEW LETTER " << s[i] << endl;
					m.insert(make_pair(s[i], i));
				}
				else {
					//cout << " NOT NEW, " << m.find(s[i])->second << " IS < " << startIdx;
					m.find(s[i])->second = i;
				}
				currentLength++;
				if (currentLength > largestLength) {
					largestLength = currentLength;
				}
				//cout << "  adding/updating " << s[i] << "[" << m.find(s[i])->second << "], len:" << currentLength << endl;
			}
			else {
				int temp = m.find(s[i])->second;
				startIdx = temp + 1;
				currentLength = i + 1 - startIdx;
				//cout << "...DUP, updating start to " << startIdx << " i:" << i << "(len: " << currentLength << ")" << endl;
				m.find(s[i])->second = i;
			}
		}
		return largestLength > 0 ? largestLength : s.length();
	}
};
