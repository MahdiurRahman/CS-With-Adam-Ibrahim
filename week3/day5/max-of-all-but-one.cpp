void findNumbers(vector<int> &numbers, int &pos, int &neg, int &neg_count) {
    pos = 0;
    neg = 0;
    neg_count = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] < 0) {
            neg_count++;
            if (abs(numbers[i]) < abs(numbers[neg])) {
                neg = i;
            }
        }
        else {
            if (numbers[i] < numbers[pos]) {
                pos = i;
            }
        }
    }
}

int max_of_all_but_one(vector<int> numbers) {
    int pos, neg, neg_count, avoid;
    findNumbers(numbers, pos, neg, neg_count);
    if (neg_count == 0) {
        avoid = pos;
    }
    else {
        if (neg_count % 2 == 1) {
            avoid = neg;
        }
        else {
            avoid = pos;
        }
    }
    int sum = 1;
    for (int i = 0; i < numbers.size(); i++) {
        if (i != avoid) {
            sum *= numbers[i];
        }
    }
    return sum;
}