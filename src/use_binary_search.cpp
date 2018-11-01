#include "binary_search.h"
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
//vector<int> binary_search(const vector<double>& targets, const vector<int>& sorted_numbers);
//vector<int> heap_binary_search(const vector<double>& targets, const vector<int>& sorted_numbers);
//argv[1] --> size of sorted_array to test on
//argv[2] --> number of queries
int main(int argc, char** argv)
{
    unsigned long long start_time = get_time();
    int size = 32;
    int queries_count = 10;
    int cache_height = 3;

    if (argc >= 3 && argc <= 4) {
        size = pow(2, stoi(argv[1]));
        queries_count = stoi(argv[2]);
        cache_height = (argc == 4) ? stoi(argv[3]) : 3;
    }

    cout<<"size = "<<size<<endl;
    cout<<"numQ = "<<queries_count<<endl;

    vector<int> numbers;
    vector<int> original;
    vector<double> queries;
    /**
      for (int i = 0 ; i < size; i++) {
      numbers.push_back(i);
      }

      for (int i = 0; i < queries_count; i++) {
      queries.push_back(i + 0.2);
      }*/
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int val = rand() % (size * 10);
        numbers.push_back(val);
        original.push_back(val);
    }
    sort (numbers.begin(), numbers.end());

    for (int i = 0; i < queries_count; i++) {
        int val = rand() % (size * 10 + 5);
        queries.push_back(val);
    }
    vector<int> heap_solutions = heap_binary_search(queries, numbers);
    vector<int> normal_solutions = binary_search(queries, numbers);
    vector<int> cache_heap_solutions = cache_heap_search(queries, numbers, cache_height);
    bool is_same = true;

    if (heap_solutions.size() != normal_solutions.size() || 
            heap_solutions.size() != cache_heap_solutions.size()) {
        cout<<"diffrent solution size..."<<endl;
        is_same = false;
    }

    for (int i = 0; i < queries.size(); i++) {
        double target = queries[i];
        int heap = heap_solutions[i];
        int normal = normal_solutions[i];
        int cache_heap = cache_heap_solutions[i];
        if (normal != heap || normal != cache_heap) { 
            is_same = false;
            cout<<"target = "<<target<<" , heap = "<<heap<<" , normal "<<normal
                <<" , cache_heap = "<<cache_heap<<endl;
        }
        //        cout<<"target = "<<target<<" , heap = "<<heap<<" , normal "<<normal
        //            <<" , cache_heap = "<<cache_heap<<endl;
    }
    cout<<"is_same = "<<is_same<<endl;
    unsigned long long end_time = get_time();
    unsigned long long time_taken = end_time - start_time;
    double seconds_taken = time_taken / 1000000.0;
    cout<<"total_time = "<<seconds_taken<<" seconds"<<endl;
}

unsigned long long get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long long time = tv.tv_usec + tv.tv_sec * 1000000;
    return time;
} 
