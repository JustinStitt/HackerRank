# link = https://www.hackerrank.com/challenges/extra-long-factorials

n = parse(Int, readline()) 
#calculate n! and store in BigInt
output = factorial(BigInt(n))
println(output)