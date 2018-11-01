#include<vector> 
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
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

int main(int argc, char** argv) 
{
    int size = pow(2, stoi(argv[1]));
    int cache_height = stoi(argv[2]);
    vector<int> output = generate_index(size, cache_height);
    for (int i = 0; i < output.size(); i++) {
        cout<<i<<" = "<<output[i]<<endl;
    }
}
