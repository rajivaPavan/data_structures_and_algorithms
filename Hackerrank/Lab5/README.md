### <img src="https://cdn4.iconfinder.com/data/icons/logos-and-brands/512/160_Hackerrank_logo_logos-512.png" width="24" height="24" alt="Hackerrank" title="Hackerrank" />  [Lily's Homework Problem](https://www.hackerrank.com/challenges/lilys-homework/problem)

- Only 14/15 test cases passed 
  - [when using quick sort](https://github.com/rajivaPavan/data_structures_and_algorithms/blob/82023815bba12124a162efac5ab13af644393318/Hackerrank/Lab5/lilys_homework.cpp)
  - [when using quick sort with insertion sort for small inputs](https://github.com/rajivaPavan/data_structures_and_algorithms/blob/107375e39dbac6b287000769a89045955d62d78c/Hackerrank/Lab5/lilys_homework.cpp) 😐
- All 15 test cases passed [when using built in sort function](https://github.com/rajivaPavan/data_structures_and_algorithms/blob/e9a126652d3aa9025cc2125badf150530aad2d05/Hackerrank/Lab5/lilys_homework.cpp) 🍾

### 🙂 FYI
#### Note on minimum number of swaps taken by a sorting algorithm
- The sorting algorithm that uses the minimum number of swaps is Selection Sort.
- However, its time complexity is $\mathcal{O}{(n^2)}$. Therefore it is not the best sorting algorithm in terms of efficiency for large inputs.
  
#### Note on Quick Sort
- The worst case time complexity of Quick Sort is $\mathcal{O}{(n^2)}$.
> The efficiency of the Quicksort algorithm very much depends on the selection of the pivot element. Let’s assume **the input of the Quicksort is a sorted array and we choose the leftmost element as a pivot element**. In this case, we’ll have two extremely unbalanced arrays. One array will have one element and the other one will have (N - 1) elements.
> 
> Similarly, when the given **input array is sorted reversely and we choose the rightmost element as the pivot element**, the worst case occurs. Again, in this case, the pivot elements will split the input array into two unbalanced arrays.
> 
> Except for the above two cases, **there is a special case when all the elements in the given input array are the same**. In such a scenario, the pivot element can’t divide the input array into two and the time complexity of Quicksort increases significantly.

- Advantages and Disadvantages
> Quicksort is considered one of the best sorting algorithms in terms of efficiency. The average case time complexity of Quicksort is $\mathcal{O}(n\log{n})$ which is the same as Merge Sort.
> 
> The main disadvantage of quicksort is that a bad choice of pivot element can decrease the time complexity of the algorithm down to $\mathcal{O}(n^2)$. Also, it’s not a stable sorting algorithm.

Read more : https://www.baeldung.com/cs/quicksort-time-complexity-worst-case

**For small inputs, insertion sort is faster than quick sort**. By combining insertion sort and quicksort, the overhead of quicksort can be reduced and the overall performance of the algorithm can be improved. As done in this [code](https://github.com/rajivaPavan/data_structures_and_algorithms/blob/107375e39dbac6b287000769a89045955d62d78c/Hackerrank/Lab5/lilys_homework.cpp)

### 📚 Resources
- [Explanation & Solution 🌐](https://www.geeksforgeeks.org/minimum-number-of-swaps-required-to-sort-an-array-set-2/?ref=lbp)
  