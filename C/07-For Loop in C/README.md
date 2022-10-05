# For Loop in C
## Easy 

### Objective

In this challenge, you will learn the usage of the for loop, which is a programming language statement which allows code to be executed until a terminal condition is met. They can even repeat forever if the terminal condition is never met.

The syntax for the for loop is:
```
for ( <expression_1> ; <expression_2> ; <expression_3> )
    <statement>
```
- expression_1 is used for intializing variables which are generally used for controlling the terminating flag for the loop.
- expression_2 is used to check for the terminating condition. If this evaluates to false, then the loop is terminated.
- expression_3 is generally used to update the flags/variables.
The following loop initializes *i* to 0, tests that *i* is less than 10, and increments *i* at every iteration. It will execute 10 times.
```
for(int i = 0; i < 10; i++) {
    ...
}
```

### Task

For each integer *n* in the interval *[a,b] (given as input) :

- If 1 <= n <= 9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
- Else if n > 9 and it is an even number, then print "even".
- Else if n > 9and it is an odd number, then print "odd".

### Input Format

The first line contains an integer, *a*.
The seond line contains an integer, *b*.

### Output Format

Print the appropriate English representation,even, or odd, based on the conditions described in the 'task' section.

### Sample Input
```
8
11
```
### Sample Output
```
eight
nine
even
odd
```
