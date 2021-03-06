
/* 
data-time 2020-03-11 14:14:53


题目描述:

1013. 将数组分成和相等的三个部分

给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

 

示例 1：

输出：[0,2,1,-6,6,-7,9,1,2,0,1]
输出：true
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
示例 2：

输入：[0,2,1,-6,6,7,9,-1,2,0,1]
输出：false
示例 3：

输入：[3,3,6,5,-2,2,5,1,-9,4]
输出：true
解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 

提示：

3 <= A.length <= 50000
-10^4 <= A[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/**
主要思路:
    本质上还是双指针问题
    先遍历求和，查看和能否被3整除;
    然后前后遍历查找目标左右指针。如果两个指针相遇就表示错误
 */

#include <cmath>
#include <cctype>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <cstdint>

using namespace std;


class Solution{
public:
      bool canThreePartsEqualSum(vector<int>& A) {   
        if(A.size()<3) return false;
        int a_sum=accumulate(A.begin(),A.end(),0);
        if(a_sum%3!=0) return false;
        int target=a_sum/3;
        int left=0,right=A.size()-1;
        int left_sum=0,right_sum=0;
        int templ_sum=A[left];
        int tempr_sum=A[right];
        /* 查找前半段 */
        while(left<A.size()-1&&templ_sum!=target){
            ++left;
            templ_sum+=A[left];
        }
        while(right>0&&tempr_sum!=target){
            --right;
            tempr_sum+=A[right];
        }
        return left+1<right;
    }
}

//关闭流输出
static auto static_lambda = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();

int main(int argc,char* argv[]){
    Solution a;
    vector<int> temp={0,2,1,-6,6,-7,9,1,2,0,1};
    a.canThreePartsEqualSum(temp);
    return 0;
}
/*
优质解析1:向前循环调用；减少了调用次数

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0, currSum = 0, k = 0;
        for(auto it : A)
            sum += it;
        if(sum % 3 != 0)
            return false;
        for(auto it : A)
        {
            currSum += it;
            if(currSum == sum / 3){
                currSum = 0;
                k++;
            }
        }
        if(currSum == sum / 3)
            k++;
        return k==3;           
    }
};
//官方题解：
https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/solution/1013-jiang-shu-zu-fen-cheng-he-xiang-deng-de-san-2/
//优质解析1:
//https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/solution/jiang-shu-zu-fen-cheng-he-xiang-deng-de-san-ge-b-6/
*/