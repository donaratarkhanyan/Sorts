# Sorting-Algorithms
Includes counting sort O(n+k), Radix LSD sort O(nk), Merge Sort O(n log n), Quick Sort O(n Log n), Bubble sort O(n^2), selection sort O(n^2)

About counting sort: No negative values allowed, must know highest and lowest values.
Counting sort (sometimes referred to as ultra sort or math sort) is a sorting algorithm which (like bucket sort) takes advantage of knowing the range of the numbers in the array to be sorted (array A).
Counting sort is a stable sort and has a running time of Θ(n+k), where n and k are the lengths of the arrays A (the input array) and C (the counting array), respectively. In order for this algorithm to be efficient, k must not be much larger than n.

![Alt text](http://i.imgur.com/yZXLIb4.jpg "Counting Sort")

About Radix LSD sort: Current implementation does not allow negative numbers. A least significant digit radix sort operates in O(nk) time, where n is the number of keys, and k is the average key length.

![Alt text](http://i.imgur.com/g2Snlvp.jpg "Radix LSD Sort")

About Merge sort:  is an O(n log n) comparison-based sorting algorithm. Divide and conquer algorithm. Conceptually, a merge sort works as follows: Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted). Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.

![Alt text](http://i.imgur.com/vX2fqKS.png "Merge Sort")

About Quick sort: On the average, it has O(n log n) complexity, worst case O(n^2). The divide-and-conquer strategy is used in quicksort. Below the recursion step is described: 1) Choose a pivot value. We take the value of the middle element as pivot value, but it can be any value, which is in range of sorted values, even if it doesn't present in the array. 2) Partition. Rearrange elements in such a way, that all elements which are lesser than the pivot go to the left part of the array and all elements greater than the pivot, go to the right part of the array. Values equal to the pivot can stay in any part of the array. Notice, that array may be divided in non-equal parts. 3) Sort both parts. Apply quicksort algorithm recursively to the left and the right parts.

![Alt text](http://i.imgur.com/9m20krB.jpg "Quick Sort")

About Bubble sort: O(n^2). Comparison based sorting algorithm that repeatedly steps through the list to be sorted, compares each pair of adjacent items and swaps them if they are in the wrong order.

![Alt text](http://i.imgur.com/K0R4ROL.jpg "Bubble Sort")

About Selection sort: Selection sort is an in-place comparison sort. It has O(n^2) complexity, making it inefficient on large lists, and generally performs worse than the similar insertion sort. Selection sort is noted for its simplicity, and also has performance advantages over more complicated algorithms in certain situations. The algorithm finds the minimum value, swaps it with the value in the first position, and repeats these steps for the remainder of the list. It does no more than n swaps, and thus is useful where swapping is very expensive.

![Alt text](http://i.imgur.com/rnRfumw.jpg "Selection Sort")
