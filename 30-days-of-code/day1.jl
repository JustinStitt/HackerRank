# link = https://www.hackerrank.com/challenges/30-data-types/problem?h_r=profile
i =  4
d = 4.0
s = "HackerRank"

# Declare second integer, double, and String variables.

# Read and save an integer, double, and String to your variables.
# Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.

i2 = parse(Int, readline())
d2 = parse(Float64, readline())
s2 = readline()

# Print the sum of both integer variables on a new line.
println(i + i2)

# Print the sum of the double variables on a new line.
println(d + d2)

# Concatenate and print the String variables on a new line
println(string(s," ", s2))
# The 's' variable above should be printed first.
