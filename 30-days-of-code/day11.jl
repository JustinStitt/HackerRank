# link = https://www.hackerrank.com/challenges/30-2d-arrays

function hourglassSum(A)
    # idea : create 3x3 view kernel, convolve over A
    maxsum = typemin(Int)
    k = [1 1 1; 0 1 0; 1 1 1] # 3x3 view
    m, n = size(k)
    for r in 1:(m + 1)# move kernel down
        for c in 1:(n + 1)# move kernel right
            csum = 0
            v = view(A, r:(r+m-1), c:(c+n-1))
            for vr in 1:size(v, 1)
                for vc in 1:size(v, 2)
                    if k[vr, vc] == 1
                        csum += v[vr, vc]
                    end
                end
            end
            maxsum = max(maxsum, csum)
        end
    end
    return maxsum
end

A = zeros(Int, 6, 6)
for r in 1:6
    row = readline() |> split |> x -> parse.(Int, x)
    for c in 1:length(row)
        A[r, c] = row[c]
    end
end

hourglassSum(A) |> println

#   1 1 1 0 0 0
#   0 1 0 0 0 0   hourglass sum of 7
#   1 1 1 0 0 0   1 1 1
#   0 0 0 0 0 0   0 1 0
#   0 0 0 0 0 0   1 1 1
#   0 0 0 0 0 0