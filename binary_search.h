#pragma once

//not too sure how to use #ifndef
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>
std::vector<int> binary_search(const std::vector<double>& targets, const std::vector<int>& sorted_array);
std::vector<int> heap_binary_search(const std::vector<double>& targets, const std::vector<int>& sorted_array);
std::vector<int> build_heap(int size);
std::vector<int> cache_heap_search(const std::vector<double>& targets, const std::vector<int>& sorted, int cache_height);
#endif /*BINARY_SEARCH_H */
