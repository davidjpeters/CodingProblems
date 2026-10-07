#include <iostream>
#include <queue>
#include <functional>

void balance(std::priority_queue<int>&, std::priority_queue<int, std::vector<int>, std::greater<int>>&);

int main() {

    
    int num_of_cases = 0;
    std::cin >> num_of_cases;
    
    for (int i = 0; i < num_of_cases; ++i) {
        // initialize min and max heap, add the first element to 
        // the max heap to start, that element is also the current median
        std::priority_queue<int> maxHeap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        int num_of_elements = 0;
        std::cin >> num_of_elements;
        int new_element = 0;
        std::cin >> new_element;
        maxHeap.push(new_element);
        // at most 10^5 integers of size 10^9 (max sum is 10^14, 2^64 = 10^19)
        uint64_t running_median = new_element; 
        
        for (int j = 1; j < num_of_elements; ++j) {

            std::cin >> new_element;

            // push to max heap, and then pop the top (largest int)
            // from max heap and push it min heap to keep lower
            // half <= upper half of elements
            maxHeap.push(new_element);
            minHeap.push(maxHeap.top());
            maxHeap.pop();

            // if the min heap is larger, move the top (smallest int)
            // to the max heap
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            // if sizes are equal, take average of middle two elements
            if (maxHeap.size() == minHeap.size()) 
                running_median += (maxHeap.top() + minHeap.top())/2; // no negatives and c++ floors by default
            else  // else add the "middle" element to the sum
                running_median += maxHeap.top();
        }
        std::cout << running_median << std::endl;
    }

    return 0;
}
