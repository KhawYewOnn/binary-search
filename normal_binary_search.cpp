#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/**
 * Return the smallest value from arr that is larger or equal to targets
 * arr has to be sorted
 */
int binary_search(double target, const vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while(left != right) {
        int mid = left + (right - left)/2;
        if (target > arr[mid]) {
            left = mid + 1;
        } else { //target <= arr[mid]
            right = mid;
        }
    }
    return arr[left]; //left and right has the same value;
}

vector<int> binary_search(const vector<double>& targets, const vector<int>& sorted_array) {
    vector<int> results;
    for (int i = 0; i < targets.size(); i++) {
        results.push_back(binary_search(targets[i], sorted_array));
    }
    return results;
}
