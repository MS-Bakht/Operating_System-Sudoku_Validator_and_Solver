# Operating System: Sudoku Validator and Solver

## Introduction
This project consists of designing a multithreaded application that determines whether the solution to a Sudoku puzzle is valid. There are several different ways of multithreading this application. One suggested strategy is to create threads that check the following criteria:
1. A thread to check that each column contains the digits 1 through 9
2. A thread to check that each row contains the digits 1 through 9
3. Nine threads to check that each of the 3 × 3 sub grids contains the digits 1 through 9 columns

![image](https://github.com/MS-Bakht/Operating_System-Sudoku_Validator_and_Solver/assets/70213048/36016b39-3b27-46bb-8e08-6a7782045e64)


## Phase I: Validation
**Passing Parameters to Each Thread:** The parent thread will create the worker threads, passing each worker the location that it must check in the Sudoku grid.

**Returning Results to the Parent Thread:** 
Each worker thread is assigned the task of determining the validity of a particular region of the Sudoku puzzle. Once a worker has performed this check, it must pass its results back to the parent. The ith index in this array corresponds to the ith worker thread. If a worker sets its corresponding value to 1, it is indicating that its region of the Sudoku puzzle is valid. A value of 0 would indicate otherwise. When all worker threads have completed, the parent thread checks each entry in the result array to determine if the Sudoku puzzle is valid.

## Phase II: Soultion
In phase 2, you must initialize a matrix with at least 2 invalid entries and provide its solution. You can store the matrix in a file. Each thread is assigned to each row and column and change the corresponding values if found erroneous. (Same as followed in phase 1). Solution of the sudoku puzzle, threads attributes must be initialized in start. So that Thread cancelation can be achieved. (As in solution thread has to swap the values with other threads, you need to keep track of changes. If a thread changes another threads value, thread don’t allow to change its value it will cancel the other thread.) When a thread wants to swap the position of digits, it sends the signal to corresponding thread (Optional). Each thread must have a criterion to allow a thread to swap its position with other threads. Limited threads will be running using semaphores to balance the overhead and security issues, e.g., while updating the  matrix no other thread will read the data. Threads should be created efficiently. After resolving the invalid entries, you must have to validate the solution and display the result.

![image](https://github.com/MS-Bakht/Operating_System-Sudoku_Validator_and_Solver/assets/70213048/fdc5f048-7b82-40ab-b0ca-aee067729645)
