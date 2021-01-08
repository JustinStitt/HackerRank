# link = https://www.hackerrank.com/challenges/30-binary-search-trees
mutable struct Node
    data::Int
    left::Union{Node, Nothing}
    right::Union{Node, Nothing}
    Node(d) = (
        x = new();
        x.data = d;
        x.left = nothing;
        x.right = nothing;
        return x
    )
end

mutable struct BST
    head::Union{Node, Nothing}
    BST() = (
        me = new();
        me.head = nothing;
        return me;
    )
end

function addnode!(tree::BST, data::Int)::Nothing
    _node = Node(data) # construct a new node 
    if tree.head == nothing # tree is empty
        tree.head = _node
        return
    end
    # find where the new node should go
    _tmp = tree.head
    while(true)
        if _tmp.data > data
            if _tmp.left == nothing
                _tmp.left = _node
                break
            else
                _tmp = _tmp.left        
            end
        else
            if _tmp.right == nothing
                _tmp.right = _node
                break
            else
                _tmp = _tmp.right
            end                
        end
    end # end while
end

# day23.jl
function showtree(bst::BST)::Nothing
    if bst.head == nothing
        return
    end
    Q = [bst.head]
    while(!isempty(Q))
        v = popfirst!(Q)
        print(v.data)
        if v.left != nothing
            push!(Q, v.left)
        end
        if v.right != nothing
            push!(Q, v.right)
        end
    end
end
# end day23

function getheight(root::Node)
    if root.left == nothing && root.right == nothing
        return 0 # height of leaf
    end
    lh = -1; rh = -1 # height of empty trees
    if root.left != nothing
        lh = 1 + getheight(root.left)
    end
    if root.right != nothing
        rh = 1 + getheight(root.right)
    end
    return max(lh, rh)
end

bst = BST()
addnode!(bst, 7)
addnode!(bst, 3)
addnode!(bst, 5)
addnode!(bst, 2)
addnode!(bst, 1)
addnode!(bst, 4)
addnode!(bst, 6)

showtree(bst)
println("height: ", getheight(bst.head))