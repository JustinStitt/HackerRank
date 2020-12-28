# link = https://www.hackerrank.com/challenges/bon-appetitt

function bonApetit(bill, k, b)::Nothing
    k += 1 # 1-based indexing
    l = length(bill)
    s = sum(bill[1:k - 1]) + sum(bill[k+1:l])
    anna_pay = div(s, 2)
    if anna_pay == b
        println("Bon Appetit")
        return
    end
    println(b - anna_pay)
end

n, k = readline() |> split |> x->parse.(Int, x)
bill = readline() |> split |> x->parse.(Int, x)
b = parse(Int, readline()) # the amount of money that Brian charged Anna for her share of the bill

bonApetit(bill, k, b)