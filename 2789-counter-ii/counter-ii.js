/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
    return {
        currVal: init,
        initVal: init,
        increment: function () {
            this.currVal++;
            return this.currVal;
        },
        reset: function () {
            this.currVal = this.initVal;
            return this.currVal;
        },
        decrement: function () {
            this.currVal--;
            return this.currVal;
        }
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */