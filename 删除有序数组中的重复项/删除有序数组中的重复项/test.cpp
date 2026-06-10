#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
#include<vector>
using namespace std;

//¿ìÂýÖ¸Õë
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dst = 0, src = 0;
        while (src < nums.size())
        {
            if (nums[src] != nums[dst])
            {
                dst++;
                nums[dst] = nums[src];
            }
            src++;
        }
        return dst + 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,1,2 };
    s.removeDuplicates(nums);
    return 0;
}