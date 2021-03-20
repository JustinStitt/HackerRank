# link = https://www.hackerrank.com/challenges/climbing-the-leaderboard
function climbingLeaderboard(ranked, player)::Array{Int, 1}
    unique!(ranked) |> sort!
    lb = Int[]
    for score in player
        idx = findfirst(x->x>=score, ranked)
        if idx == nothing
            push!(lb, 1)
            push!(ranked, score)
            continue
        end
        rank = length(ranked) - idx + 1
        if ranked[idx] != score
            rank += 1
            insert!(ranked, idx, score)
        end
        push!(lb, rank)
    end
    return lb
end

function main()
    n = parse(Int, readline()) # number of players on leaderboard
    r = readline() |> split |> x->parse.(Int, x)
    m = parse(Int, readline()) # number of games player played
    p = readline() |> split |>x->parse.(Int, x) # player scores 
    climbingLeaderboard(r, p) |> println
end

main()

