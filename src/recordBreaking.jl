# link = https://www.hackerrank.com/challenges/breaking-best-and-worst-records

function recordBreaking(scores)
    big = small = scores[1] # first game is the min and max
    bi = si = 0
    for score in scores[2:length(scores)]
        if score > big
            bi += 1
            big = score
        elseif score < small
            si += 1
            small = score
        end
    end
    println(bi, " ", si)
end

n = parse(Int, readline()) # number of games
scores = readline() |> split |> x -> parse.(Int, x)
recordBreaking(scores)