# link = https://www.hackerrank.com/challenges/queens-attack-2

function moveCount(r_start, c_start, r_step, c_step, n, lookup)
    # base case
    if r_start > n || c_start > n return 0 end
    if r_start < 1 || c_start < 1 return 0 end
    if in((r_start, c_start), lookup) == true return 0 end
    return 1 + moveCount(r_start + r_step,
                        c_start + c_step, r_step, c_step, n, lookup)
end

function queensAttack(n, k, rq, cq, obs)
    moves = 0
    # start moveCount calls for each of the 8 directions
    lookup = Set{Tuple}([x for x in obs]) # generator comprehension
    for i in -1:1, j in -1:1
        if i == j == 0 continue end
        moves += moveCount(rq + i, cq + j, i, j, n, lookup)
    end
    return moves
end

function main()
    n, k = readline() |> split |> x->parse.(Int, x) # length of sides, # of obstacles
    r, c = readline() |> split |> x->parse.(Int, x) # queens (r, c) position
    obstacles = []
    for _ in 1:k
        or, oc = readline() |> split |> x->parse.(Int, x) # obstacle r, c pos
        push!(obstacles, (or, oc))
    end
    queensAttack(n, k, r, c, obstacles) |> println
end
main()

