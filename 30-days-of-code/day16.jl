# link = https://www.hackerrank.com/challenges/30-exceptions-string-to-integer

function stoi(str)
    try
        return parse(Int, str)
    catch e
        println("Bad String")
    end
end


S = readline()
stoi(S) |> println