Nycto and office 

Rash has been working in a furnishing business for the last couple of months. He recently has received a new order for covering a office with carpet. The office is divided into cubicles of unit size. Each unit can either accomodate the Boss, the employee, or simply be empty. Since the office doesn't believe in wastage of resources, only the cubicles with people working in them have to be covered with the carpet. Rest of the empty space will not be covered. A carpet can be extended from a cubicle to any other cubicle provided it is sharing a wall with it, and from that to other cubicles and so on. If it is not possible to extend to all the cubicles, new pieces of carpet will be required. For each new piece, an additional cost will be charged for it. 

Since the Head likes to live an extravagant lifestyle, the carpet used for him is better and different from the ones used by rest of the employees. But since he doesn't want to look self-centered, the carpet used by him is extended to other cubicles, provided only a single piece is being used. Given the rate of the carpet and the office plan, Rash has to calculate how much he has to charge for the contract. Since he is kind of busy in other tasks, help him do so.

Input Format
The first line will contain N and M, the dimensions of the office.
Next N lines follow with M characters in it, denoting the current office plan.
'#' stands for free space,
'C' stands for employee and
'B' stands for the head.
Then two lines follow each having two integers:

rate_emp new_emp
rate_head new_head

rate_emp is the carpet rate for normal employees and rate_head is the carpet rate for the head.
new_emp is the rate for any new piece for employees and new_head is the new piece cost for the head. 

Output Format
The output should be printed in the following format:
The total cost is TC.
where TC is the total calculated cost.

Constraints
1<=N,M<=100
0<=rate_emp,new_emp,rate_head,new_head<=10^6
Please Note: There is only one head in the office.
Sample Test Cases

#Input 1:

3 3
BC#
##C
C#C
5 2
8 3

#Output 1:

The total cost is 38.

#Input 2:

1 3
BCC
3 0
4 0

#Output 2:

The total cost is 12.

Explanation 1:
Three pieces of carpet is needed.
First one of 2 length, with the head in it.
Second and Third of 2 and 1 length, for normal employees.
Hence total cost=(8*2+3)+(5*2+2)+(5*1+2)=38 

Explanation 2:
Only one carpet piece is needed.
Of length 3, for the head.
Hence total cost=(4*3+0)=12

author:nyctophiliac