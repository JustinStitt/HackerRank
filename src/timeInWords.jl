# link = https://www.hackerrank.com/challenges/the-time-in-words

function timeInWords(h, m)
    htos = Dict{Int, String}([ 0=>"",
        1=>"one", 2=>"two", 3=>"three", 4=>"four",
        5=>"five", 6=>"six", 7=>"seven", 8=>"eight",
        9=>"nine", 10=>"ten", 11=>"eleven", 12=>"twelve",
        13=>"thirteen",14=>"fourteen", 15=>"quarter", 16=>"sixteen",
        17=>"seventeen", 18=>"eighteen", 19=>"nineteen", 20=>"twenty",
    ])
    if m == 0 return join([htos[h], " o' clock"]) end
    suffix = (m<=30 ? "past" : "to")
    if m == 30
        return join(["half past ", htos[h]])
    end
    nh = htos[h+1]
    if m == 15 || m == 45
        return join(["quarter ", suffix, " ", 
                        (suffix == "to" ? nh : htos[h])])
    end
    minutes = ""
    plural = "minutes"
    singular = "minute"
    if m > 30
        m = 60 - m
    end
    if m > 20
        minutes = join([htos[20], " ", htos[m-20]])
    else
        minutes = htos[m]
    end
    minutes = join([minutes, " minutes ", suffix, " ", 
                        (suffix == "to" ? nh : htos[h])])
    if m == 1 # remove plural
        minutes = deleteat!(collect(minutes), 
                    findfirst(x->x=='s', minutes)) |> join
    end
    return minutes
end

function main()
    h  = parse(Int, readline()) # hours
    m = parse(Int, readline()) # minutes
    timeInWords(h, m) |> println
end
main()
