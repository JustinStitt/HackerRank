# link = https://www.hackerrank.com/challenges/cavity-map/

function cavityMap(grid)
    n = size(grid, 1)
    cgrid = copy(grid)
    for i in 2:n-1, j in 2:n-1
        v = grid[i][j]
        if grid[i-1][j] < v && 
           grid[i+1][j] < v &&
           grid[i][j-1] < v &&
           grid[i][j+1] < v
            cgrid[i][j] = "X"
        end
    end
    return cgrid
end

function main()
    n = parse(Int, readline()) # nxn grid
    grid = []
    for _ in 1:n
        row = readline() |> x->split(x, "")
        push!(grid, row)
    end
    
    a = cavityMap(grid)
    for r in a
        join(r) |> println
    end
end

main()
