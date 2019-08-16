vector<int> sum_swap(vector<int> arr1, vector<int> arr2) {
    vector<int> answer;

    int arr1_sum{0}, arr2_sum{0}, halfway{0};
    for (int i = 0; i < arr1.size(); i++) {
        arr1_sum += arr1[i];
    }
    for (int i = 0; i < arr2.size(); i++) {
        arr2_sum += arr2[i];
    }

    halfway = abs(arr1_sum - arr2_sum);
    if (halfway % 2 == 1) {
        return answer;
    }
    halfway /= 2;
    
    if (arr1_sum > arr2_sum) {
        halfway *= -1;
    }

    unordered_set<int> complements;
    for (int i = 0; i < arr1.size(); i++) {
        complements.insert(arr1[i] + halfway);
    }

    for (int i = 0; i < arr2.size(); i++) {
        if (complements.count(arr2[i]) > 0) {
            answer.push_back(arr2[i] - halfway);
            answer.push_back(arr2[i]);
            return answer;
        }
    }

    return answer;
}