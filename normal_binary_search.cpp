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
    int right = arr.size();

    while(left != right) {
        int mid = left + (right - left)/2;
        //cout<<"target = "<<target<<", left = "<<left<<", right = "<<right<<", mid ="<<mid<<endl;
        //cout<<"arr[mid] = "<<arr[mid]<<endl;
        if (target > arr[mid]) {
            left = mid + 1;
            //cout<<"target > arr[mid], left = "<<left<<", right = "<<right<<endl;
        } else { //target <= arr[mid]
            right = mid;
            //cout<<"else: target <= arr[mid], left = "<<left<<", right = "<<right<<endl;
        }
    }
    return arr[left]; //left and right has the same value;
}
/**
int main()
{
    //cout<<"value = "<< (10.1 > 10) << endl;
    vector<int> test_array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    
    bool match = true;
    for(int i = 0; i < 11; i++) {
        //cout<<"**************************************************************************"<<endl;
        double target = i + 0.2;
        //cout<<"target = "<<target<<", i = "<<i<<endl;
        int sol = binary_search(target, test_array);
        int expected_sol = ceil(target);
        if (expected_sol != sol) {
            cout<<"wrong ans for i = "<<i<<", expected_sol = "<<expected_sol<<", actual sol = "<<sol<<", target = "<<target<<endl;
            match = false;
        }
    }
    cout<<"match = "<<match<<endl;
}*/
