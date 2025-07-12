# LFU Cache in C++

This is a simple command-line implementation of an **LFU (Least Frequently Used) Cache** using C++.  
It supports `get` and `put` operations, managing items based on their usage frequency.

---

## 👨‍💻 How It Works

- **get(key)**: Returns the value of the key if it exists in the cache, else returns `-1`.
- **put(key, value)**: Inserts or updates the value. If the cache reaches capacity, the least frequently used item is evicted.