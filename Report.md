# Report For Task 1
Fibonacci turned out to work as Fibonacci is expected to, exponential growth. With k=16 being the point it surpasses 1000 additions. In fact the number of basic operations matches
near exactly with the function provided to us being ϕ^n/sqrt(5). Though it seems to be a bit off instead calculating the prior n value instead. This is likely because way the two base
cases, 0 and 1 are being treated. But the values do match. On a similar note, Θ(ϕ^n) for this recursive algorithm of the Fibonacci sequence. Since we are doing it recursively,
there is no way to pre-emptively calculate repeating equations meaning we are stuck doing operation after operation. 
On the other hand, GCD, even in the worst case, seems to be Θ(n). It was calculated using the Fibonacci sequence values sequentially so at Fib(k), GCD(Fib(k+1), Fib(k)) with n=k, but it
never seemed to go higher than n-1 divisions. Leaving behind a seemingly linear growth. Don't have much knowledge about GCD but it is interesting that it's worst case is not as bad as I
imaged it could be.

# Report For Task 2

# Report For Task 3