# Solution

## Method 1

Find Digital root of 65785412

### Steps:

1. Find out all the digits of a number
2. Add all the number one by one
3. If the final sum is double digit, add again to make it single digit
4. The result obtained in single digit is the Digital root of number

### Example:
```
Input: 65785412
Find Digital root: (6 + 5 + 7 + 8 + 5 + 4 + 1 + 2) = 38 => 11 => (1 + 1) = 2
Output: 6
```

## Method 2
The idea is based on the fact that for a non-zero number num, digital root is 9 if number is divisible by 9, else digital root is num % 9. (Please see http://www.sjsu.edu/faculty/watkins/Digitsum0.htm for details)

Find the digital root of 65785412

### Steps:
1. Sum of digits = 6 + 5 + 7 + 8 + 5 + 4 + 1 + 2 = 38
2. Since 38 is not multiple of 9, digital root is 38 % 9 = 2.