# link = https://www.hackerrank.com/challenges/30-queues-stacks
using DataStructures
# verify a string is a palindrome using stack and queue

function isPalindrome(s)
    S = Stack{Char}()
    Q = Queue{Char}()
    for c in s
        push!(S, c)
        enqueue!(Q, c)
    end

    for _ in 1:length(s)
        st = pop!(S)
        qt = dequeue!(Q)
        if st != qt return false end
    end
    return true
end

s = readline()
isPalindrome(s) |> println