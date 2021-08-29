/*
 * @lc app=leetcode.cn id=1588 lang=c
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start


int sumOddLengthSubarrays(int* arr, int arrSize){
    int sum = 0;
    int lennow = 1;
    while(lennow <= arrSize){
        for(int i = 0; i <= arrSize - lennow; i++){
            for (int j = 0; j < lennow; j++){
                sum += arr[i+j];
            }
        }
        lennow += 2;
    }
    return sum;
}
// @lc code=end

