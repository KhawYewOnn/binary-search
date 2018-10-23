#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include "binary_search.h"

using namespace std;
//definitely need to learn make_file soon...
/*
 * only works for cache_height = 3, size = 63
 */
bool check_correctness(const vector<int>& other) {
    vector<int> base {0, 1, 2, 3, 4, 5, 6, 7, 8, 16, 17, 32, 33, 34, 35, 9, 18, 19, 36, 37, 38, 39, 
        10, 20, 21, 40, 41, 42, 43, 11, 22, 23, 44, 45, 46, 47, 12, 24, 25, 48, 49, 50, 51, 13, 26, 27, 52, 53, 54, 55, 
        14, 28, 29, 56, 57, 58, 59, 15, 30, 31, 60, 61, 62, 63};
    bool is_correct = true;

    for (int i = 0; i < base.size(); i++) {
        if (other[i] != base[i]) is_correct = false;
    }

    cout<<"is_correct = "<<is_correct<<endl;
    return is_correct;
}

/**
 * For now assume default of size = 63
 * cache_height = 3;
 */
vector<int> generate_index(int size, int cache_height) {
    vector<int> cache_heap {0};
    queue<int> next_element;
    next_element.push(1);
    while(!next_element.empty()) {
        int top = next_element.front();
        next_element.pop();

        if (top >= size) break;

        for (int i = 0; i < cache_height; i++) {
            int base = top * pow(2, i);
            int num_elements = pow(2, i);

            for (int j = 0; j < num_elements; j++) {
                cache_heap.push_back(base + j);
            }
        }

        for (int i = 0; i < pow(2, cache_height); i++) {
            next_element.push(top * pow(2, cache_height) + i);
        }
    }

    return cache_heap;
}

/**
 * The actual heap for traversal purposes
 */
vector<int> generate_actual_heap(const vector<int>& sorted, int cache_height) {
    vector<int> heap_structure = build_heap(sorted.size());
    vector<int> cache_heap_structure = generate_index(heap_structure.size(), cache_height);
    vector<int> cache_heap (heap_structure.size(), 0);
    for (int i = 1; i < cache_heap.size(); i++) {
        cache_heap[i] = sorted[heap_structure[cache_heap_structure[i]] - 1];
    }
    return cache_heap;
}

/**
 * the actual querying is done here
 */
int cache_heap_search(double target,const vector<int>& cache_heap, int cache_height) {
    int member_count = 0;//zero base
    int curr_index = 1;
    int level = 0;
    int original_index = 1;
    int size = cache_heap.size(); //for sample, size = 64
    int next_member = 0;
    while(curr_index < size) {
        level++;
        int base_index = curr_index;
        int cache_index = 1; //actual index is base_index + cache_index
        //logic for within cache traversal
        for (int i = 0; i < cache_height; i++) {
            //note that -1 is not needed if cache_size = pow(2, cache_height)
            //instead of cache_size = pow(2, cache_height) - 1
            //meaning add a blank element at the start of each cache
            original_index = base_index + cache_index - 1;
            cache_index = cache_index * 2 + (target > cache_heap[original_index]);
        }
        //logic for choosing next jump, need to update curr_index

        //next_member is zero-index base
        next_member = cache_index + (next_member - 1) * pow(2, cache_height);

        int next_family_base = pow(2, level*cache_height);
        curr_index = next_member*(pow(2, cache_height) - 1) 
            + next_family_base;
        /*        cout<<"*************************************"<<endl;
                  cout<<"next_member = "<<next_member<<endl;
                  cout<<"next_familily_base = "<<next_family_base<<endl;
                  cout<<"curr_index = "<<curr_index<<endl;
                  cout<<"_____________________________________"<<endl;
                  */
    }
    return cache_heap[original_index];
}

vector<int> cache_heap_search(const vector<double>& targets,const vector<int>& sorted, int cache_height) {
    vector<int> cache_heap = generate_actual_heap(sorted, cache_height);
    vector<int> solutions;
    for (int i = 0; i < targets.size(); i++) {
        double target = targets[i];
        int solution = cache_heap_search(target, cache_heap, cache_height);
        solutions.push_back(solution);
    }
    return solutions;
}

vector<int> cache_heap_search(const vector<double>& targets, const vector<int>& sorted) {
    int default_cache_height = 3; //3 the magic number
    return cache_heap_search(targets, sorted, default_cache_height);
}
/**
//for debugging purposes
int main()
{
    vector<int> sorted;
    for (int i = 0; i < 256; i++) {
        sorted.push_back(i);
    }
    vector<int> cache_heap = generate_actual_heap(sorted);
    double target = 40;
    int solution = cache_heap_search(target, cache_heap);
    cout<<"target = "<<target<<", solution = "<<solution<<endl;
}
*/
