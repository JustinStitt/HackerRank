# link = https://www.hackerrank.com/challenges/drawing-book

function pageCount(n, p)
    pages = div(n-2, 2) + 2
    p = div(p, 2)
    d = min(p, pages - p - 1)
    return d
end


n = parse(Int, readline()) # number of pageas
p = parse(Int, readline()) # page to turn to
pageCount(n, p) |> println