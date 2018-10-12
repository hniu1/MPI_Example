Parallel Prefix Alogrithm
====

The following is a polynomial in a single unknown variable x with degree n−1 
where
<a href="https://www.codecogs.com/eqnedit.php?latex=a_{0}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?a_{0}" title="a_{0}" /></a>,
<a href="https://www.codecogs.com/eqnedit.php?latex=a_{1}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?a_{1}" title="a_{1}" /></a>,
...,
<a href="https://www.codecogs.com/eqnedit.php?latex=a_{n-1}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?a_{n-1}" title="a_{n-1}" /></a>
are known constants.

<a href="https://www.codecogs.com/eqnedit.php?latex=p(x)&space;=&space;a_{0}&plus;a_{1}x&plus;a_{2}x^{2}&plus;a_{3}x^{3}&plus;...&plus;a_{n-1}x^{n-1}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?p(x)&space;=&space;a_{0}&plus;a_{1}x&plus;a_{2}x^{2}&plus;a_{3}x^{3}&plus;...&plus;a_{n-1}x^{n-1}" title="p(x) = a_{0}+a_{1}x+a_{2}x^{2}+a_{3}x^{3}+...+a_{n-1}x^{n-1}" /></a>

The goal here is to compute the value of the polynomial at a given value of x, say, 
<a href="https://www.codecogs.com/eqnedit.php?latex=x_{0}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x_{0}" title="x_{0}" /></a>, 
that is, 
evaluate <a href="https://www.codecogs.com/eqnedit.php?latex=p(x_{0})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?p(x_{0})" title="p(x_{0})" /></a>. 
Your programming assignment is to implement a parallel prefix alogrithm
and evaluate this polynomial with degree 63 at a given value of x = 0.5 using processor counts P = 1, 2, 4, 8 and 16.

Compile and Run
--------
```
mpicc 1.c -lm -o 1
mpirun -n 8 ./1
```
