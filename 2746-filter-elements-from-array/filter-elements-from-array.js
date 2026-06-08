/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function (arr, fn) {
    const newArr = [];
    const len = arr.length;
    for (let i = 0; i < len; i++) {
        if (fn(arr[i], i)) {
            newArr.push(arr[i]);
        }
    }
    return newArr;
};