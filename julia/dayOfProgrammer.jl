# link = https://www.hackerrank.com/challenges/day-of-the-programmer

function isLeapYear(year)
    isJulian = false
    if year <= 1917 isJulian = true end
    if isJulian == true
        if year % 4 == 0 return true end
        return false
    end
    # not julian 
    if (year % 400 == 0) ||
       (year % 4 == 0 && year % 100 != 0)
        return true
    end
    return false
end

function dayOfProgrammer(year)
    # non-leap year on gregorian = 13.09.xxxx
    # non-leap year on julian = 13.09.xxxx
    # 1918 = 26.09.xxxx
    # leap year on gregorian = 12.09.xxxx
    # leap year on julian = 12.09.xxxx
    year == 1918 && return "26.09.1918"
    if isLeapYear(year) == true
        return "12.09.$year"
    end
    return "13.09.$year"
end

year = parse(Int, readline()) # year
dayOfProgrammer(year) |> println