# link = https://www.hackerrank.com/challenges/acm-icpc-team

function acmTeam(subjects::Array{String, 1})::Array{Int, 1}
    # maximize bitwise or (|)
    n = length(subjects)
    freq = Dict{Int, Int}()
    for i in 1:n - 1, j in (i+1):n
        numones = 0
        for d in 1:length(subjects[i])
            if subjects[i][d] == '1' || subjects[j][d] == '1'
                numones += 1
            end
        end
        freq[numones] = get(freq, numones, 0) + 1
    end
    
    subjectcount, teamcount = maximum(freq)
    
    return [subjectcount, teamcount]
end

n, m = readline() |> split |> x->parse.(Int, x)
subjects = String[]
for _ in 1:n
    bs = readline() # ex = 10101
    push!(subjects, bs)
end
for x in acmTeam(subjects) println(x) end