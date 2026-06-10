#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        int right = nums.size() - 1;
//        int left = 0;
//        if (nums.size() == 0)
//        {
//            return 0;
//        }
//
//        while (left <= right)
//        {
//            while (left <= right && nums[left] != val)
//            {
//                left++;
//            }
//            while (left <= right && nums[right] == val)
//            {
//                right--;
//            }
//            if (left <= right && (nums[left] == val && nums[right] != val))
//            {
//                std::swap(nums[right], nums[left]);
//                left++;
//                right--;
//            }
//        }
//        return left;
//    }
//};

//¿ìÂýÖ¸Õë--ÍÆ¼ö
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int dst = 0, src = 0;
        while (src < nums.size())
        {
            if (nums[src] != val)
            {
                nums[dst] = nums[src];
                dst++;
            }
            src++;
        }
        return dst;
    }
};
int main()
{

    Solution s;
    vector<int> nums = { 0,1,2,2,3,0,4,2 };
    int val = 2;
    s.removeElement(nums, val);
    return 0;
}