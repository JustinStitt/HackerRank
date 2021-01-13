# link = https://www.hackerrank.com/challenges/30-testing

function minIndex(arr)
    if isempty(arr)
        error("Array cannot be empty.")
    end
    return sortperm(arr)[1]
end

# write unit tests

# test unqiue

function uniqueTest(f)
    # test f to ensure it works with unique input
    t = Int[4,3,1,7,6]
    expected = 3
    if f(t) != expected
        error( String(Symbol(f))," failed unique unit-test")
    end
    println("pass")
end

# test empty 

function emptyTest(f)
    t = Int[]
    try
        f(t)
    catch
        println("pass")
        return
    end
    error(String(Symbol(f)), " failed empty unit-test")
end

# test duplicate

function duplicateTest(f)
    t = Int[6,4,3,1,7,8,1,9]
    expected = 4
    if f(t) != expected
        error(String(Symbol(f)), " failed duplicate unit-test")    
    end
    println("pass")
end
println("running unit-tests...")
uniqueTest(minIndex)
emptyTest(minIndex)
duplicateTest(minIndex)
