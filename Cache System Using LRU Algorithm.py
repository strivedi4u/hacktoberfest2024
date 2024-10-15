from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        """
        Initialize the cache with a given capacity.
        - `cache`: OrderedDict to store key-value pairs.
        """
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        """
        Fetch the value associated with the key if it exists in the cache.
        If key is found, update its position as the most recently used key.
        If key is not found, return -1.
        """
        if key in self.cache:
            # Move the accessed key to the end (most recently used)
            self.cache.move_to_end(key)
            return self.cache[key]
        return -1  # Key not found in cache

    def put(self, key: int, value: int) -> None:
        """
        Insert a new key-value pair into the cache.
        If the key already exists, update its value and move it to the most recently used position.
        If the cache reaches its capacity, remove the least recently used (LRU) item.
        """
        if key in self.cache:
            # Update the key's value and move it to the end
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.capacity:
            # Remove the least recently used item (first item)
            self.cache.popitem(last=False)

# Test Cases
lru_cache = LRUCache(2)

# Test Case 1: Fetching a non-existent key
print(lru_cache.get(1))  # Output: -1 (key 1 not found)

# Test Case 2: Adding two entries and fetching them
lru_cache.put(1, 1)  # Add key 1 with value 1
lru_cache.put(2, 2)  # Add key 2 with value 2
print(lru_cache.get(1))  # Output: 1 (key 1 is found)

# Test Case 3: Adding a third entry which will evict the least recently used item (key 2)
lru_cache.put(3, 3)  # Add key 3, evicts key 2
print(lru_cache.get(2))  # Output: -1 (key 2 is evicted)

# Test Case 4: Fetching the existing key and adding a new one
print(lru_cache.get(3))  # Output: 3 (key 3 is found)
lru_cache.put(4, 4)  # Add key 4, evicts key 1
print(lru_cache.get(1))  # Output: -1 (key 1 is evicted)
print(lru_cache.get(3))  # Output: 3 (key 3 is still present)
print(lru_cache.get(4))  # Output: 4 (key 4 is found)
