Let's see the sample input:

arr = [1, 1, 2, 3], S = 1

so we have to assign every element a arithmetic symbol '+' or '-'
Such that value of that expressin is equal to S

## Observation
Let's form an expression

K = +1-1-2+3 = 1
value of K = S

So we have to find number of ways to assign symbols

In this case we can assign symbols in 3 ways:
(+1-1-2+3), (+1+1+2-3), (-1+1-2+3)

## Intuition
let's arrange an expression in such a way that positive terms and negative terms are seperately written
expression = +1-1-2+3
positive terms = (1, 3), sum = 4
negative terms = (1, 2), sum = 3

If we subtract positive terms and negative terms than we get 1 as result

## Conclusion

So we see that we have to "count number of subset with given difference" which is variation of "subset sum" problem

## Explaining number of subset with given difference

assume s1 and s2 as to subset
such that s1-s2 = S
also s1+s2 = sum(sum of array)

from above two equation:
s1 = (sum+S)/2

and we have to find only one subset with given sum s1.