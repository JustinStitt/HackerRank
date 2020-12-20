#link = https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dictionaries-hashmaps&isFullScreen=true&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
function sherlockAndAnagrams(w)
    d = Dict{String,Int}()
    for i in 1:length(w)# size of substring
        for j in 1:(length(w) - i + 1) # starting index
            key = w[j:(j + i - 1)] |> collect |> sort |> join
            d[key] = get(d, key, 0) + 1;
        end
    end
    # d now holds all contiguous substrings and their frequency
    count = 0
    for (k, v) in d
        seq_sum = ((v - 1) / 2) * v |> Int
        # sum of arithmetic sequence
        count += seq_sum
    end
    println(count)
end

n = parse(Int, readline())
for i in 1:n
    word = readline()
    sherlockAndAnagrams(word)
end
