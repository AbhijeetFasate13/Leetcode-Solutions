/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    const len = nums.length;
    if(len===0)return init;
    let val = init;
    for(let i=0;i<len;i++){
        val = fn(val,nums[i]);
    }
    return val;
};