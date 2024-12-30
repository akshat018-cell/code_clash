# code_clash
#Question 1->
This program counts the number of subarrays in an array whose sums are divisible by a given integer kk.
Approach

    Prefix Sum & Remainders:
        Use a prefix sum to efficiently compute subarray sums.
        Track the remainders of prefix sums modulo kk in a hash map.

    Counting Magical Subarrays:
        A subarray is magical if the difference between two prefix sums has a remainder of 0 modulo kk.
        For each remainder, count its occurrences to determine how many subarrays can end at the current position.

    Optimized Using a Hash Map:
        Store counts of remainders in a hash map to reduce complexity to O(n).

Complexity

    Time Complexity: O(n)
    Space Complexity: O(k)

Question 2->
This program finds the shortest sequence of word transformations from a beginWord to an endWord using a given dictionary (wordList). Each transformation must satisfy the following:

    Transformation Rules:
        Two consecutive words differ by exactly one letter.
        The transformation word must exist in the dictionary.
        Only words with even indices in the sorted dictionary are valid.

    Algorithm:
        Sorting and Filtering: Sort the dictionary and select words with even indices.
        BFS Search: Perform a breadth-first search to find the shortest path, checking transformations using the "differ by one letter" rule.

    Output:
        The length of the shortest sequence if a transformation is possible.
        0 if no valid transformation exists.

Complexity

    Time Complexity: O(n⋅m+nlog⁡n), where n is the dictionary size and mm is the word length.
    Space Complexity: O(n).

Question 3->
This program sorts a list of integers based on the lexicographical order of their binary representations.
Key Features

    Binary Conversion:
        Each integer is converted to its binary representation as a string.

    Stable Sorting:
        The program uses a stable sort to maintain the original order of integers with identical binary representations.

    Sorting Criteria:
        Integers are sorted in ascending lexicographical order of their binary strings.

Example

Input:

3
5 1 3

Binary representations:

101, 1, 11

Sorted lexicographically:

1 -> 11 -> 101

Output:

1 3 5

Complexity

    Time Complexity: O(nlog⁡n+m), where nn is the number of integers and m is the total length of all binary strings.
    Space Complexity: O(n+m) for storing binary representations and the sorted output.

Question 4->
This C++ program schedules team meetings with the goal of minimizing isolation between employees. It ensures that all pairs of employees from different teams meet within a given number of weeks while minimizing the maximum gap between their meetings.
Key Steps:

    Input: Takes the number of teams n and weeks w.
    Feasibility Check: If w < n - 1, it outputs "infinity" because it's impossible to schedule all pair meetings.
    Isolation Calculation: The minimum isolation is calculated as (w - 1) / (n - 1).
    Scheduling: Uses a round-robin approach to schedule team members’ office visits so that all pairs meet.
    Output: Prints the minimum isolation followed by the schedule.

Time Complexity: O(n * w)
Space Complexity: O(n * w)

Question 5->
This program determines the minimum number of transformations required to convert a starting word into a target word, where each transformation changes exactly one letter, and every intermediate word must exist in a given dictionary. If the transformation is not possible, the program outputs -1.
Approach

    Input Parsing: Reads the dictionary, starting word, and target word.
    Validation: Ensures the starting and target words are present in the dictionary.
    Breadth-First Search (BFS):
        Explores all possible transformations by modifying one character at a time.
        Tracks visited words to prevent cycles.
        Stops when the target word is reached, returning the step count.
    Output: If the target word is unreachable, outputs -1.


