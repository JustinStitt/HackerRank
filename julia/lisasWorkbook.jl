# link = https://www.hackerrank.com/challenges/lisa-workbook/problem?isFullScreen=true

function workbook(n, k, chapters)
    num_special = 0
    page = 1
    for c in eachindex(chapters)
        for p in 1:chapters[c]
            if (p-1) % k == 0 && p > 1 page += 1 end
            if p == page num_special += 1 end
        end
        page += 1
    end
    return num_special
end

n, k = readline() |> split |> x->parse.(Int, x)# num chap, max prob per page
chapters = readline() |> split |> x->parse.(Int, x) # num prob per chapter
workbook(n, k, chapters) |> println
