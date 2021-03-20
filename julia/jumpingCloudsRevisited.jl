# link = https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited

function jumpingOnClouds(c::Array{Int, 1}, k::Int)::Int
    energy = 100
    player = 0
    n = length(c)
    while(true) # emulate do-while
        energy -= 1 # always spend at least 1 energy to make jump of len k
        player = (player + k) % n
        if c[player + 1] == 1 energy -= 2 end
        player == 0 && break
    end
    return energy
end

n, k = readline() |> split |> x->parse.(Int, x)
c = readline() |> split |> x->parse.(Int, x)
jumpingOnClouds(c, k) |> println