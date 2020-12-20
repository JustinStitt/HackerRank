# 30-days-of-code: Day #2 - operators
# link = https://www.hackerrank.com/challenges/30-operators/problem?h_r=profile

function solve(meal_cost, tip_percent, tax_percent)
    tip = meal_cost * (tip_percent / 100)
    tax = meal_cost * (tax_percent / 100)
    meal_cost += tip + tax
    meal_cost = round(meal_cost) |> Int
    println(meal_cost)
end


mc = parse(Float64, readline())
tip_percent = parse(Int, readline())
tax_percent = parse(Int, readline())

solve(mc, tip_percent, tax_percent)
