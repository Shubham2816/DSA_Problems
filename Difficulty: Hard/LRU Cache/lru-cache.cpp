//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
private:
    int capacity; // Maximum capacity of the cache
    std::list<std::pair<int, int>> cache; // Doubly linked list to store key-value pairs
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hash_map; // Hashmap to store references to list nodes

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) : capacity(cap) {}

    // Function to return value corresponding to the key.
    int get(int key) {
        if (hash_map.find(key) == hash_map.end()) {
            return -1; // Key does not exist
        }
        // Move the accessed key-value pair to the front of the cache (most recently used)
        auto it = hash_map[key];
        cache.splice(cache.begin(), cache, it);
        return it->second;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (hash_map.find(key) != hash_map.end()) {
            // If the key exists, update its value and move it to the front
            auto it = hash_map[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
        } else {
            // If the cache is full, remove the least recently used element
            if (cache.size() == capacity) {
                auto lru = cache.back();
                hash_map.erase(lru.first);
                cache.pop_back();
            }
            // Insert the new key-value pair at the front
            cache.push_front({key, value});
            hash_map[key] = cache.begin();
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends