# link = https://leetcode.com/problems/invert-binary-tree

mutable struct TreeNode
    data::Int
    left::Union{TreeNode, Nothing}
    right::Union{TreeNode, Nothing}
    TreeNode(d) = (x=new();x.data=d;x.left=nothing;x.right=nothing;x)
end

function inverttree!(root)::Nothing
    root == nothing && return
    # has both children
    if root.left != nothing && root.right != nothing
        # swap left and right
        hold = root.left # destroyed when exit scope
        root.left = root.right
        root.right = hold
        inverttree!(root.left); inverttree!(root.right)
    # has one child
    elseif root.left != nothing && root.right == nothing
        root.right = root.left
        root.left = nothing
        inverttree!(root.right)
    elseif root.left == nothing && root.right != nothing
        root.left = root.right
        root.right = nothing
        inverttree!(root.left)
    end
    nothing
end

function treeprint(root) # bfs print
    Q = []
    push!(Q, root)
    while(isempty(Q) == false)
        v = popfirst!(Q)
        print(v.data)
        if v.left != nothing push!(Q, v.left) end
        if v.right != nothing push!(Q, v.right) end
    end
end
# creating tree 
root = TreeNode(4)
n2 = TreeNode(2)
n3 = TreeNode(7)
n4 = TreeNode(1)
n5 = TreeNode(3)
n6 = TreeNode(6)
n7 = TreeNode(9)
root.left = n2; root.right = n3
n2.left = n4; n2.right = n5
n3.left = n6; n3.right = n7

treeprint(root)
inverttree!(root)
println()
treeprint(root)
