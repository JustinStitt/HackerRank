# link = https://www.hackerrank.com/challenges/library-fine

function libraryFine(d1, d2, m1, m2, y1, y2)::Int
    day_fee = 15 # per day
    month_fee = 500 # per month
    if y1 > y2 
        return 10000 
    elseif y1 < y2
        return 0 
    end
    if m1 > m2 
        return (month_fee) * (m1 - m2) 
    elseif m1 < m2
        return 0
    end
    if d1 > d2 return (day_fee) * (d1 - d2) end
    return 0
end

#=
    2 7 1014 # return
    1 1 1015 # due
=#
d1, m1, y1 = readline() |> split |> x->parse.(Int, x) # return date
d2, m2, y2 = readline() |> split |> x->parse.(Int, x) # due date
libraryFine(d1, d2, m1, m2, y1, y2) |> println
