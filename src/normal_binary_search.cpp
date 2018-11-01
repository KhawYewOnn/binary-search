#include <iostream>
#include <vector>
#include <cmath>
#include "binary_search.h"
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
    unsigned long long start_time = get_time();
    for (int i = 0; i < targets.size(); i++) {
        results.push_back(binary_search(targets[i], sorted_array));
    }
    unsigned long long end_time = get_time();
    unsigned long long time_taken = end_time - start_time;
    cout<<"binary_search = "<<time_taken<<endl;
    return results;
}
