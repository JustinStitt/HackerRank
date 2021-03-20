# link = https://www.hackerrank.com/challenges/the-grid-search/

function gridsearch(grid, pattern)
    yes, no = "YES", "NO" # ret vals
    gr, gc = length(grid), length(grid[1])
    pr, pc = length(pattern), length(pattern[1])
    
    if pr > gr || pc > gc return no end # bounds check
    
    # brute-force
    
    for gi in 1:(gr-pr+1)
        for gj in 1:(gc-pc+1)   
            for pi in 1:pr
                for pj in 1:pc
                    ni = gi+pi-1
                    nj = gj+pj-1
                    if grid[ni][nj:nj] != pattern[pi][pj:pj]
                        pi = pr + 1
                        break
                    end
                end
                if pi > pr break end
                pi == pr && return yes
            end # end pi
        end
    end
    return no
end


function main()
    t = parse(Int, readline()) # number of test cases
    for _ in 1:t
        grid    = []
        pattern = []
        gr, gc = readline() |> split |> x->parse.(Int, x)
        for i in 1:gr
            row = readline()
            push!(grid, row)
        end
        pr, pc = readline() |> split |> x->parse.(Int, x)
        for i in 1:pr
            row = readline()
            push!(pattern, row)
        end
        gridsearch(grid, pattern) |> println
    end
end
main()
