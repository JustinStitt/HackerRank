# link = https://www.hackerrank.com/challenges/designer-pdf-viewer

function designerPdfViewer(heights, word)

    # area of rectangle = l * w
    # l = length(word)
    # w = height of tallest letter
    l = length(word)
    w = maximum(heights[x - 'a' + 1] for x in word)
    
    return l * w
end

heights = readline() |> split |> x -> parse.(Int, x)
word = readline()

designerPdfViewer(heights, word) |> println