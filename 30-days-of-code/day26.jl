# link = https://www.hackerrank.com/challenges/30-nested-logic

struct date
    day
    month
    year
end

function libraryFine(r::date, e::date)
    day_fine = 15
    month_fine = 500
    year_fine = 10000
    
    if r.year > e.year return year_fine end
    if r.month > e.month && r.year == e.year
        return (month_fine * (r.month-e.month)) 
    end
    if r.day > e.day && r.month == e.month && r.year == e.year
        return (day_fine * (r.day-e.day)) 
    end
    return 0 # no fine
end

function main()
    inp1 = readline() |> split |> x->parse.(Int, x)
    inp2 = readline() |> split |> x->parse.(Int, x)
    returned = date(inp1...)
    expected = date(inp2...)
    libraryFine(returned, expected) |> println
end
main()
