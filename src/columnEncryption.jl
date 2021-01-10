# link = https://www.hackerrank.com/challenges/encryption
"""
    print encrpyted string
"""
function encryption(str::String)::Nothing
    n = length(str)
    c = ceil(sqrt(n)) |> Int
    for i in 1:c
        print(str[i:c:n], " ")
    end
end

s = readline() |> collect |> x->filter!(i->i!=' ', x) |> String
encryption(s)