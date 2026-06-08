/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function (functions) {
    const n = functions.length;
    return function (x) {
        let val = x;
        for (let i = n - 1; i >= 0; i--) {
            val = functions[i](val);
        }
        return val;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */