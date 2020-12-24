# link = https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

lookup = Dict{String, String}() # name=>phonenumber

n = parse(Int, readline()) # number of name:phonenumber mappings

for _ in 1:n
    np = readline() |> split # "sam" "99912222"
    name = np[1]
    number = np[2]
    # add to lookup dictionary
    lookup[name] = number
end

# perform unknown number of queries
queries = readlines() # read all lines

for query in queries
    if haskey(lookup, query)
        println(query,"=",lookup[query])
    else
        println("Not found")
    end
end