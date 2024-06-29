

## III. Evaluation of Efficiency

## Vector Time Complexity Analysis – Line by Line

The vector data structure offers a straightforward and efficient means of storing and accessing course data. The time complexity for reading and inserting courses into a vector is **O(n * m)**, where:
- **n**: Number of courses
- **m**: Average number of tokens per course line

**Memory Complexity:** **O(n)**

### Steps:

1. **Opening the File:**
   - OPEN file named `filename`
   - **Cost per line:** 1
   - **Total Cost:** 1

2. **Reading the File Line by Line:**
   ```
   WHILE not end of file DO
       Cost per line: 1
       Total Cost: O(n)
   ```
   ```
   line = READ line from file
       Cost per line: 1
       Total Cost: O(n)

3. **Parsing Each Line:**
   ```
   parts = SPLIT line by commas
       Cost per line: O(m)
       Total Cost: O(n * m)
   ```
   ```
   course = new Course(parts[0], parts[1], new List of Strings)
       Cost per line: 1
       Total Cost: O(n)
   ```
   ```plaintext
   FOR i FROM 2 TO size of parts
       Cost per line: 1
       Total Cost: O(n * m)
   ```
   ```
   course.prerequisites.add(parts[i])
       Cost per line: 1
       Total Cost: O(n * m)
   ```

4. **Adding Course to Vector:**
   ```
   courses.add(course)
       Cost per line: O(1) amortized (can be O(n) in worst-case due to resizing)
       Total Cost: O(n) amortized
   ```

**Overall Time Complexity:** **O(n * m)**

## Hash Table Time Complexity Analysis – Line by Line

Hash tables provide an efficient average-case time complexity for both insertion and search operations, making them an excellent choice for managing course data.

**Time Complexity:** **O(n * m)** on average

**Memory Complexity:** **O(n)**

### Steps:

1. **Opening the File:**
   - OPEN file named `filename`
   - **Cost per line:** 1
   - **Total Cost:** 1

2. **Reading the File Line by Line:**
   ```plaintext
   WHILE not end of file DO
       Cost per line: 1
       Total Cost: O(n)
   ```
   ```
   line = READ line from file
       Cost per line: 1
       Total Cost: O(n)
   ```

3. **Parsing Each Line:**
   ```plaintext
   parts = SPLIT line by commas
       Cost per line: O(m)
       Total Cost: O(n * m)
   ```
   ```plaintext
   course = new Course(parts[0], parts[1], new List of Strings)
       Cost per line: 1
       Total Cost: O(n)
   ```
   ```plaintext
   FOR i FROM 2 TO size of parts
       Cost per line: 1
       Total Cost: O(n * m)
   ```
   ```plaintext
   course.prerequisites.add(parts[i])
       Cost per line: 1
       Total Cost: O(n * m)
   ```

4. **Adding Course to Hash Table:**
   ```plaintext
   hashTable[course.courseNumber] = course
       Cost per line: O(1) on average (O(n) worst-case due to collisions)
       Total Cost: O(n) average
   ```

**Overall Time Complexity:** **O(n * m)**

## Binary Search Tree Time Complexity Analysis – Line by Line

Binary search trees (BST) can provide efficient search and insertion operations if they remain balanced.

**Time Complexity:** **O(n * m)** average, **O(n^2)** worst-case if unbalanced

**Memory Complexity:** **O(n)**

### Steps:

1. **Opening the File:**
   - OPEN file named `filename`
   - **Cost per line:** 1
   - **Total Cost:** 1

2. **Reading the File Line by Line:**
   ```plaintext
   WHILE not end of file DO
       Cost per line: 1
       Total Cost: O(n)
   ```
   ```plaintext
   line = READ line from file
       Cost per line: 1
       Total Cost: O(n)
   ```

3. **Parsing Each Line:**
   ```plaintext
   parts = SPLIT line by commas
       Cost per line: O(m)
       Total Cost: O(n * m)
   ```
   ```plaintext
   course = new Course(parts[0], parts[1], new List of Strings)
       Cost per line: 1
       Total Cost: O(n)
   ```
   ```plaintext
   FOR i FROM 2 TO size of parts
       Cost per line: 1
       Total Cost: O(n * m)
   ```
   ```plaintext
   course.prerequisites.add(parts[i])
       Cost per line: 1
       Total Cost: O(n * m)
   ```

4. **Inserting Course into BST:**
   ```plaintext
   tree.insert(course)
       Cost per line: O(log n) on average (O(n) worst-case if unbalanced)
       Total Cost: O(n log n) on average (O(n^2) worst-case)
   ```

**Overall Time Complexity:** **O(n * m)** average, **O(n^2)** worst-case if unbalanced

# IV. Advantages and Disadvantages of the Data Structures

## Vector

### Advantages:
- Straightforward implementation
- Direct access to elements through indexing
- Efficient memory management for appending

### Disadvantages:
- Linear search time (O(n))
- Performance overhead during resizing
- Inefficient for ordered insertions without sorting

## Hash Table

### Advantages:
- Constant time complexity (O(1)) for average-case operations
- Efficient handling of large datasets
- Ideal for quick lookups with direct key-based access

### Disadvantages:
- Potential performance degradation due to collisions (O(n) worst-case)
- Complexity in managing collisions
- Higher memory usage with low load factors

## Binary Search Tree (BST)

### Advantages:
- Maintains sorted order for efficient traversal
- Logarithmic time complexity (O(log n)) for balanced trees
- Dynamic size adjustment without resizing

### Disadvantages:
- Unbalanced trees lead to linear time complexity (O(n))
- Implementation complexity for balancing mechanisms
- Increased memory footprint with child node pointers

# V. Final Recommendation

After analyzing the vector, hash table, and binary search tree (BST) data structures, I recommend using the **Hash Table** for this implementation.

**Justification:**

- **Time Complexity:** Average-case constant time complexity (O(1)) for insertion, deletion, and search operations is significantly faster than alternatives.
- **Handling Large Datasets:** Efficient distribution and management of entries reduce performance bottlenecks.
- **Direct Access by Key:** Perfect for quick retrieval and display based on course numbers.

**Alternative Considerations:**
- **Vectors:** Linear search time and resizing overhead make them less suitable for large datasets.
- **Binary Search Trees:** While efficient when balanced, complexity and potential for unbalance make them less optimal compared to hash tables.

In conclusion, the hash table's efficiency, direct access capabilities, and average-case performance make it the most suitable data structure for managing course data in this application.
