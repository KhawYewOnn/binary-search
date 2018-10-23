#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> build_heap(int size);
vector<int> build_heap_without_queue(int size);
vector<int> build_real_heap(const vector<int>& sorted_list);
int heap_binary_search(double target, const vector<int>& heap);
vector<int> heap_binary_search(const vector<double>& targets, const vector<int>& sorted_array);


/**
 * Build the heap structure using a queue
 * size == pow(2, n), where n is a positive integer
 */
vector<int> build_heap(int size)
{
    //what if the size of my array isn't (2^n)?
    vector<int> heap_index {1};

    queue<pair<int, int> > build_queue;
    build_queue.push(make_pair(1, size));

    while(!build_queue.empty()) {
        int left = build_queue.front().first;
        int right = build_queue.front().second;
        build_queue.pop();
        int mid = left + (right - left)/2;
        heap_index.push_back(mid);
        if (left == right) {
            continue;
        }
        //if target <= arr[mid], right = mid, do not throw mid away.
        build_queue.push(make_pair(left, mid));
        //if target > arr[mid], left = mid + 1, throw mid away.
        build_queue.push(make_pair(mid + 1, right));
    }
    //to match array generated by build_heap_without_queue(int size)
    return heap_index;
}

/**
 * build the heap structure without using queue
 */
vector<int> build_heap_without_queue(int size) {
    vector<int> heap {0};
    int interval = size + 1;
    while(interval > 0) {
        int position = interval / 2;
        position += (position == 0);
        while(position <= size) {
            heap.push_back(position);
            position += interval;
        }
        interval /= 2;
    }
    return heap;
}

/**
 * Build the heap structure using actual value
 * The input array has to be sorted and 
 * sorted_list.size() == 2^n - 1 where n is a positive integer
 */
vector<int> build_real_heap(const vector<int>& sorted_list) {
    vector<int> heap_indexes = build_heap(sorted_list.size());
    vector<int> heap(heap_indexes.size(), 0);
    for (int i = 1; i < heap.size(); i++) {
        heap[i] = sorted_list[heap_indexes[i] - 1];
    }
    return heap;
}

/**
 * The actual searching is done here
 * input heap has to be a heap structure
 */
int heap_binary_search(double target, const vector<int>& heap) {
    int end_search = heap.size() / 2;
    int index = 1;
    while(index < end_search) {
        int result = (target > heap[index]);
        index = index * 2 + result;
    }
    return heap[index];
}

vector<int> heap_binary_search(const vector<double>& targets, const vector<int>& sorted_array) {
    vector<int> heap = build_real_heap(sorted_array);
    vector<int> solutions;

    for (int i = 0; i < targets.size(); i++) {
        solutions.push_back(heap_binary_search(targets[i], heap));
    }
    return solutions;
}
