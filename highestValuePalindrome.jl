function highestValuePalindrome(s, n, k)::String
    ns = s |> collect
    mp = (n ÷ 2) + 1 # integer division with \div
    inc, dec = 1, n
    while(inc < mp)
        if(ns[inc] != ns[dec])
            ns[inc] = max(ns[inc], ns[dec])
            ns[dec] = max(ns[inc], ns[dec])
            k -= 1 # made a swap
            if k < 0 return "-1" end # cannot make palindrome
        end
        inc += 1
        dec -= 1
    end
    if k <= 0 return ns |> String end # no swaps remaining, return ns
    #can we swap pairs to '9's?

    for (inc, dec) in zip(1:mp, n:-1:mp)
        if ns[inc] == '9' continue end # already a '9'
        cost = (ns[inc] == s[inc] && ns[dec] == s[dec] ? 2 : 1)
        if k - cost >= 0
            ns[inc] = '9'
            ns[dec] = '9'
            k -= cost
        end
    end

    # should we change the middle to a '9'?
    if n & 1 == 1 # swaps remaining and is odd
        ns[mp] = '9'
        k -= 1
    end
    return ns |> String
end


nk = readline() |> split |> x->parse.(Int, x)
n = nk[1]
k = nk[2]
s = readline()
println("answer: ")
println(highestValuePalindrome(s, n, k))
