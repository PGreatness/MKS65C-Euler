#include <stdio.h>
//Problem 1
/*
*Find the sum of all numbers that are multiples of 2 numbers below the given limit
* @param number1 - first number to check for multiples
* @param number2 - second number to check for multiples
* @param limit - the limit to stop looking for multiples
* @return int that is a sum of all the multiples of number1 or number2
*/
int multiples(int number1, int number2, int limit) {
    int runningSum = 0;
    int currNum = 0;
    while (currNum < limit) {
        if (currNum % number1 == 0 || currNum % number2 == 0) {
            runningSum += currNum;
        }
        currNum++;
    }
    return runningSum;
}

//Problem 2

/*
*Helper for the even_fibonacci method
* @param a1 - the starting number from the fibonacci sequence
* @param a2 - the next number from the fibonacci sequence
* @param limit - the limit to not exceed
* @param sum - sum of the even numbers
* @return int that is the sum of all the even numbers in the fibonacci sequence betweeen a1 
* and a2 below the limit
*/
int fibonacci_helper(int a1, int a2, int limit, int sum) {
    if (a2 >= limit) {
        return sum;
    }
    if (a2 % 2 == 0) {
        sum += a2;
    }
    return fibonacci_helper(a2, a1 + a2, limit, sum);
}

/*
* Find the sum of all the even numbers in the fibonacci sequence below the given limit
* @param limit - the limit to stop continuing the the fibonacci sequence
* @return int that is the sum of all the even numbers in the fibonacci sequence below limit
*/
int even_Fibonacci(int limit) {
    return fibonacci_helper(1, 2, limit, 0);
}

//Problem 5

/*
* Helper for smallest_multiple(int)
* @param number - count that the function is on
* @param upper_limit - the limit that needs to be reached
* @return int that is either 0, meaning number is the smallest multiple, or 1, meaning 
* number is not the smallest multiple
*/
int smallest_multiple_helper(int number, int upper_limit) {
    int i = 1;
    for (; i < upper_limit; i++) {
        if (number % i != 0) {
            return 1;
        }
    }
    return 0;
}

/*
* Finds the smallest multiple of the all the numbers starting from 1 to endingNum
* @param - endingNum - the last of the numbers that need a multiple
* @return int that is the number that can be evenly divided by all the numbers up to and including
* endingNum
*/
int smallest_multiple(int endingNum) {
    int i = 1;
    for (; ; i++) {
        if (smallest_multiple_helper(i, endingNum) == 0) {
            return i;
        }
    }
}

int main() {
    printf("\nHello!\n");
    printf("The sum of all the multiples of 3 or 5 is: %i\n", multiples(3, 5, 1000));
    printf("\nThe sum of all the even numbers in the fibonacci sequence is: %i\n", even_Fibonacci(4000000));
    printf("\nThe smallest multitple evenly divisible by the first 20 numbers is: %i\n", smallest_multiple(20));
    return 0;
}