class ProductOfNumbers {
    vector<int> numbers;
    int n;

public:
    ProductOfNumbers() {
        numbers.push_back(1);
        n = 1;
    }

    void add(int num) {
        if (num == 0) {
            numbers.clear();
            numbers.push_back(1);
            n = 1;
        } else {
            numbers.push_back(numbers.back() * num);
            n++;
        }
    }

    int getProduct(int k) {
        if (k >= n)
            return 0;
        return numbers.back() / numbers[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */