#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
#include<vector>
using namespace std;
//从后面开始排列,从最大的开始排
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int dst = m-1, src = n-1, end = m+n-1;

        while(dst>=0&&src>=0)
        {
            if (nums1[dst] > nums2[src])
            {
                nums1[end--] = nums1[dst--];
               
            }
            else
            {
                nums1[end--] = nums2[src--];
            }
        }

        //剩下的
        while (src >= 0)
        {
            nums1[end--] = nums2[src--];
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = { 2,0 };
    vector<int> nums2 = { 1 };
    s.merge(nums1, nums1.size()-nums2.size(), nums2, nums2.size());
    return 0;
}