# Contents

During my time taking a course titled "Science of Programming" I had the chance to learn about the differences of verification and testing and what all goes into defining specs.I spent time getting to know about termination of programs, loop bounds, loop invarients, pratial and total correctness, Hoare triples, Domain predicates, Proof Outlines, Parellel Programs, Sequential non-determinism and much more.

Dafny was a tool we used to check if the loop bounds were true thorugh out the program. Here are a few programs I worked on:

### Find the greatest number in Array:
In this assignment, I was given a list of random numbers and had to return the greast number on that array. Although, it seems like a simple it was diffuicult to figure out what the appropriate loop bound should be. 

#### The bounds:
1) Array should be completely traversed
2) The size of i shouldn't exceed the size of array. 

### Calculate the square of a number:
This program calculate the square of the number.

#### The bounds:
The number of loops should be greater than 0.

#### The invariant:
The square of the number is always maintained.

### Check if number of positive numbers is equal to the number of negetive numbers:
This was a perticularly tricky one to do. Here, I was given two arrays, one comtaining all positive numbers and one containing all negetive numbers. The objective was that the number of elements in the two array should always be equal. 

#### The bounds:
Both the arrays should always be in their respective ranges.

#### The invariant:
Bot the array have the upper bound i for the same element in each array. Waht this does is, it maintains equality throughout the program instead of just checking for it at the end of the loop.

### Work out the sum of all the elements of an array:
This problem works on a similiar principle, but the only tricky thing is to get over the loop that comes with calculating the sum of a number is a list or well in this case, an Array

#### The bounds:
Sum of the number of elements is not greater than the size of the array.

#### The invariant: 
Sum of an intermediate is maintained. That is we store the number of which loop we are on and make sure that it is always the sum of all the numbers before it.

### Conclusion
Dafny is a great tool to understnad what happens on a much more deeper level. While its easy to code and have it run, its much more difficult to come up with cases that have to be true on every step of the program.
