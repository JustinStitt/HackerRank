mutable struct TreeNode 
    data::Int
    left::Union{TreeNode, Nothing}
    right::Union{TreeNode, Nothing}
    TreeNode(d) = (
        x= new();
        x.data = d;
        x.left = nothing;
        x.right = nothing;
        x;
    )
end

function assignchildren!(some_node::TreeNode, c1, c2)
    some_node.left = c1;
    some_node.right = c2;
end

function make_tree_01()
    tn = [TreeNode(x) for x in 1:13]
    assignchildren!(tn[1], tn[2], tn[3])
    assignchildren!(tn[2], tn[4], tn[5])
    assignchildren!(tn[3], nothing,tn[6])
    assignchildren!(tn[4], tn[7],nothing)
    assignchildren!(tn[6], tn[8], tn[9])
    assignchildren!(tn[8], tn[11], nothing)
    assignchildren!(tn[7], nothing,tn[10])
    assignchildren!(tn[10], nothing, tn[12])
    assignchildren!(tn[12], tn[13], nothing)
    return tn[1]
end

root = make_tree_01()

function dfs(root::Union{TreeNode, Nothing},
                level_count, 
                    curr_level, visible)
    if root === nothing return visible end
    get!(level_count, curr_level, 0)
    level_count[curr_level] += 1
    # is first of level
    if get(level_count, curr_level, 0) == 1
        push!(visible, root)
    end

    # go right
    dfs(root.right, level_count, curr_level+1, visible)
    # go left
    dfs(root.left, level_count, curr_level+1, visible)
end

function printtree(root)
    for x in root
        println(x.data)
    end
end

function povtree(root::TreeNode)
    start_level = 1
    level_count = Dict{Any, Any}()
    visible = []
    return dfs(root, level_count, 0, visible)
end

ret = povtree(root)

printtree(ret)