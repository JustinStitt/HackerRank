# link = https://www.hackerrank.com/challenges/30-linked-list

mutable struct Node
    data::Int
    next::Union{Node, Nothing}
    Node(d) = (x = new(); x.data=d; x.next=nothing;x)
end

function insert(head, add)
    to_add = Node(add) # construct node to add 
    if(head == nothing)
        head = to_add
        return head
    end
    tmp = head
    while(tmp.next != nothing)
        tmp = tmp.next
    end
    tmp.next = to_add
    return head
end

function display(head)::Nothing
    while(head != nothing)
        print(head.data, "->")
        head = head.next
    end
end

function main()
    head = nothing
    t = parse(Int, readline()) # number of elements to add to sll
    for _ in 1:t
        n = parse(Int, readline()) # element to add
        head = insert(head, n)
    end
    display(head)
end
main()
