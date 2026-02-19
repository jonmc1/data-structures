# Fundamental Data Structures
The idea of this project is to practice the fundamental data structures in Computer Science. I googled 'fundamental data structures' and below is what the AI overview generated. My goal is to implement all of them.

## Linear Data Structures
Elements in linear data structures are arranged in a sequential order

- Arrays: A collection of elements of the same type stored in contiguous memory locations, allowing for fast, direct access to any element using its index (constant time O(1)). The primary limitation is their fixed size in many programming languages.
- Linked Lists: A sequence of nodes where each node contains data and a pointer (link) to the next node in the sequence. This dynamic structure is efficient for frequent insertions and deletions because elements do not need to be shifted, but accessing a specific element requires traversing the list from the beginning (linear time O(n)).
- Stacks: A structure that follows the Last-In, First-Out (LIFO) principle; the last element added is the first one to be removed. Operations are typically push (add) and pop (remove) and occur at only one end, called the "top". Use cases include managing function calls in a program's memory (call stack) and implementing undo features.
- Queues: A structure that follows the First-In, First-Out (FIFO) principle, similar to a waiting line. Elements are added at the rear (enqueue) and removed from the front (dequeue). They are used in scenarios where order needs to be preserved, such as CPU scheduling and handling printer requests.

## Non-Linear Data Structures
Elements in non-linear data structures are organized in hierarchical or interconnected networks, rather than a single sequence.

- Trees: A hierarchical structure composed of nodes, starting from a single root node, with child subnodes branching out. Each node has at most one parent. They are useful for representing hierarchical data like file systems, organizational charts, and database indexing. Binary trees, a specific type where each node has at most two children, are fundamental for efficient searching.
- Graphs: A versatile structure consisting of a set of vertices (nodes) connected by edges (links). Graphs are used to model complex networks such as social networks, transportation systems, and communication networks. Algorithms like Dijkstra's are used with graphs to find the shortest path between two points.
- Hash Tables (Hash Maps): A structure that uses a hash function to map keys to values for very fast lookups, insertions, and deletions. They store data as key-value pairs and are widely used in databases, symbol tables in compilers, and caching.
