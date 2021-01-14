# link = https://www.hackerrank.com/challenges/30-regex-patterns

function alphabeticalEmails(emails; tag = "gmail.com")
    n = length(emails)
    re = Regex(".+@$tag")
    gmails = []
    # find all matches
    for i in emails
        s = split(i)
        name, email = s[1], s[2]
        m = match(re, email)
        m == nothing && continue
        push!(gmails, name)
    end
    return sort(gmails)
end

function main()
    n = parse(Int, readline()) # number of emails to read
    emails = []
    for _ in 1:n
        push!(emails, readline())
    end
    alphabeticalEmails(emails, tag = "gmail.com") |> x->println.(x)
end
main()
