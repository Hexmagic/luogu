/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (52.62%)
 * Likes:    729
 * Dislikes: 0
 * Total Accepted:    72.2K
 * Total Submissions: 137.3K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "aaabb", k = 3
 * 输出：3
 * 解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "ababbc", k = 2
 * 输出：5
 * 解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由小写英文字母组成
 * 1
 *
 *
 */
#include <algorithm>
#include <memory>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// @lc code=start

class Solution
{
public:
    int Tab[1000][1000];
    int cnt[26];
    int findLongestSub(string &s, int k, int start, int end)
    {
        if (Tab[start][end] != -1 || start == end)
        {
            Tab[start][end] = 1;
            return Tab[start][end];
        }
        else if (start > end)
        {
            Tab[start][end] = 0;
            return Tab[start][end];
        }

        memset(cnt, 0, sizeof(cnt));
        for (int i = start; i <= end; i++)
        {
            cnt[s[i] - 'a']++;
        }
        bool valid = true;
        char c;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i]>0&&cnt[i] < k)
            {
                c = 'a' + i;
                valid = false;
                break;
            }
        }
        if (valid)
        {
            Tab[start][end] =end-start+1;
        }
        else
        {
            int index;
            for (int i = start; i <= end; i++)
            {
                if (s[i] == c)
                {
                    index = i;
                    break;
                }
            }
            int L = findLongestSub(s, k, start, index - 1);
            int R = findLongestSub(s, k, index + 1, end);
            Tab[start][end] = max(L, R);             
        }
        return Tab[start][end];
    }
    int longestSubstring(string s, int k)
    {
        int n = s.length();
        memset(Tab, -1, sizeof(Tab));
        return findLongestSub(s, k, 0, n - 1);
    }
};
// @lc code=end

int main()
{
    Solution s;
    string c2 = "aaabb";
    string c1 = "ababbc";
    cout << s.longestSubstring(c2, 3) << endl;
    cout << s.longestSubstring(c1, 2) << endl;
}