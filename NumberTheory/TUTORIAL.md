# Number Theory
1. Modulo Arithmetic
    * Basics
    * Modulo Inverse
2. Euclid
    * GCD
    * Extended Euclid
    * Diophantine Equations
3. Binary Exponentiation
4. Sieve 
5. Chinese Remainder Theorem
6. Euler Totient Function
7. Matrix Exponentiation
8. Misc - Goldbach's Conjecture, number of divisors on N, NCR

## Euclid's theorem
[Intuition/Proof](https://cp-algorithms.com/algebra/euclid-algorithm.html)
```
gcd(a,b) = g (say) and a<b
a = a'g
b = b'g
then if b is changed to 
b = b-a = b'g-a'g = (b'-a')g
gcd will not change
=> gcd(a,b) = gcd(a,b-a)
```
[Time Complexity](https://youtu.be/HNOypQFpW3s) = O(log min(a,b))

Recurence relation - 
```
gcd(a,b) = gcd(b%a,a)
```
Base Case
```
gcd(0,b) = b
```
Invalid Case
```
gcd(0,0) = infinity(not defined)
```
GCD is always positive : so if a or b is negative take absolute value of it
```
gcd(a,b) = gcd(|a|,b) = gcd(a,|b|) = gcd(|a|,|b|)
```
Iterative GCD
```
while(a){
    ll t=a;
    a=b%a;
    b=t;
}
return b;
```
```
lcm(a,b) = a/gcd(a,b) * b
```
## Extended Euclid
Proof
```
ax + by = gcd(a,b) = g  -------------1
(b%a)x1 + (a)y1 = gcd(b%a,a) = g

we know, b%a = b - floor(b/a)*a

(b-floor(b/a)*a)x1 + ay1
a(y1-floor(b/a)x1) + b(x1) = g--------2

using 1 & 2
x = y1-floor(b/a)x1
y = x1
```
See the code file