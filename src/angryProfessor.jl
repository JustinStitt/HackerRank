# link = https://www.hackerrank.com/challenges/angry-professor

function angryProfessor(k, times)
    on_time = count(x->x<=0, times)
    if on_time >= k println("NO"); return; end
    println("YES")
end


t = parse(Int, readline()) # number of test cases

for _ in 1:t
    n, k = readline() |> split |> x->parse.(Int, x)
    times = readline() |> split |> x->parse.(Int, x)
    angryProfessor(k, times)
end