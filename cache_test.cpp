#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include "binary_search.h"

using namespace std;

unsigned long long get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long long time = tv.tv_usec + tv.tv_sec * 1000000;
    return time;
}

int test(int array_size, int small_size, int large_size, int repeat
        , bool use_small) {
    vector<int> something (array_size, 0);
    string type = use_small? "small" : "large"; 
    unsigned long long start_time = get_time();
    for (int i = 0; i < repeat; i++) {
        int v1 = rand() % small_size;
        int v2 = rand() % small_size;
        int v3 = rand() % large_size;
        int v4 = rand() % large_size;
        if (use_small) {
            int x = something[v1];
            int y = something[v2];
        } else {
            int x = something[v3];
            int y = something[v4];
        }
    }
    unsigned long long end_time = get_time();

    unsigned long long random_start = get_time();
    for (int i = 0; i < repeat; i++) {
        int v1 = rand() % small_size;
        int v2 = rand() % small_size;
        int v3 = rand() % large_size;
        int v4 = rand() % large_size;
    }
    unsigned long long random_end = get_time();
    unsigned long long time_taken = end_time - start_time;
    unsigned long long random_time_taken = random_end - random_start;
    cout<<type<<" time taken = "<<time_taken<<endl;
    cout<<type<<" random_time_taken = "<<random_time_taken<<endl;
    return time_taken - random_time_taken;
}

int random_time(int small_size, int large_size, int repeat) {

    unsigned long long start_time = get_time();
    for (int i = 0; i < repeat; i++) {
        int v1 = rand() % small_size;
        int v2 = rand() % small_size;
        int v3 = rand() % large_size;
        int v4 = rand() % large_size;
    }
    unsigned long long end_time = get_time();
    return end_time - start_time;
}
int test_diff(int array_size, int small_size, int large_size, int repeat) {
    int short_time = test(array_size, small_size, large_size, repeat, 1);
    int long_time = test(array_size, small_size, large_size, repeat, 0);
    return long_time - short_time;
}

int main()
{
    int size = 1000000;
    int num = 1000000;
    test(size, 10, 1000000, num, 1);
    test(size, 10, 1000000, num, 1);
    test(size, 10, 1000000, num, 1);
    test(size, 10, 1000000, num, 0);
    test(size, 10, 1000000, num, 0);
    int long_time = test(size, 10, 1000000, num, 0);
    int short_time = test(size, 10, 1000000, num, 1);
    test(size, 10, 1000000, num, 1);
    test(size, 10, 1000000, num, 1);
    cout<<"long_time - short_time = "<<long_time - short_time<<endl;
    int cut_off = (long_time - short_time) /4;
    cut_off = 100;

    int left = 10;
    int right = size - 1;
    while(left != right) {
        int mid = left + (right - left)/2;
        int time_diff = test_diff(size, 10, mid, num);
        cout<<"mid = "<<mid<<", left = "<<left<<", right = "<<right
            <<", time_diff = "<<time_diff<<endl;
        left = (time_diff < cut_off) ? mid + 1: left;
        right = (time_diff < cut_off) ? right : mid;
    }
    cout<<"left = "<<left<<endl;
    cout<<"large - small diff = "<<long_time - short_time <<endl;
    cout<<"cut_off = "<<cut_off<<endl;

    for (int i = 10; i < 1000000; i += 10000) {
        int time_diff = test_diff(size, 10, i, num);
        cout<<"i = "<<i<<", time_diff = "<<time_diff<<endl;
        cout<<"*****************************************************"<<endl;
    } 
}

