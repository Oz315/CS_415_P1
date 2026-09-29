# Report For Task 1
Fibonacci turned out to work as Fibonacci is expected to, exponential growth. With k=16 being the point it surpasses 1000 additions. In fact the number of basic operations matches
near exactly with the function provided to us being ϕ^n/sqrt(5). Though it seems to be a bit off instead calculating the prior n value instead. This is likely because way the two base
cases, 0 and 1 are being treated. But the values do match. On a similar note, Θ(ϕ^n) for this recursive algorithm of the Fibonacci sequence. Since we are doing it recursively,
there is no way to pre-emptively calculate repeating equations meaning we are stuck doing operation after operation. 
On the other hand, GCD, even in the worst case, seems to be Θ(n). It was calculated using the Fibonacci sequence values sequentially so at Fib(k), GCD(Fib(k+1), Fib(k)) with n=k, but it
never seemed to go higher than n-1 divisions. Leaving behind a seemingly linear growth. Don't have much knowledge about GCD but it is interesting that it's worst case is not as bad as I
imaged it could be.

# Report For Task 2
Task 2 – Exponentiation
For Task 2, I compared decrease-by-one, decrease-by-constant-factor, and divide-and-conquer exponentiation. The x-axis represents the exponent n, and the y-axis represents the number of multiplications M(n). The legend shows all three algorithms.
Before testing, I expected decrease-by-one to be Θ(n), decrease-by-constant-factor to be Θ(log n), and divide-and-conquer to be Θ(n). The scatterplot matched these expectations. Decrease-by-constant-factor grew much slower because it reduces the exponent by about half each recursive call. Divide-and-conquer also divides the exponent, but it makes two recursive calls, so its growth was still linear.
For the scatterplot, I tested powers of two from 1 to 1024. I used a constant base of 1 because the base does not affect the number of multiplications, and this also helped avoid overflow for large values of n.
The results were:
Algorithm	                   Complexity
Decrease-by-One               	Θ(n)
Decrease-by-Constant-Factor    	Θ(log n)
Divide-and-Conquer	            Θ(n)

# Report For Task 3
Task 3 – Selection Sort and Insertion Sort
For Task 3, I compared Selection Sort and Insertion Sort using sorted, random, and reverse-sorted data. The x-axis represents the input size n, and the y-axis represents the number of comparisons C(n). Each graph has a legend showing Selection Sort and Insertion Sort.
For the best case, I used the sorted files. I expected Selection Sort to be Θ(n²) and Insertion Sort to be Θ(n). The graph matched this because Insertion Sort stayed much lower while Selection Sort grew much faster.
For the average case, I used the random files. I expected both algorithms to be Θ(n²). The graph matched this, but Insertion Sort used fewer comparisons than Selection Sort.
For the worst case, I used the reverse-sorted files. I expected both algorithms to be Θ(n²). The graph also matched this. The two lines almost overlapped because their comparison counts were very close in the reverse-sorted case.
The results were:
| Algorithm      | Best Case | Average Case | Worst Case |
| Selection Sort | Θ(n²)     | Θ(n²)        | Θ(n²) |
| Insertion Sort | Θ(n)      | Θ(n²)        | Θ(n²) |

These results matched what I expected before running the program. Selection Sort stayed Θ(n²) for all three input types, while Insertion Sort worked much better when the data was already sorted. I tested input sizes from 100 to 10,000, and the program was able to process all of them and create the CSV files used for the graphs.
