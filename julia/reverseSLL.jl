mutable struct ListNode
    data::Int
    next::Union{ListNode, Nothing}
    ListNode(d) = (
        me = new();
        me.data = d;
        me.next = nothing;
        return me;
    )
end

mutable struct SinglyLinkedList 
    head::Union{ListNode, Nothing}
    SinglyLinkedList() = (me=new(); me.head=nothing; me)
end

function Base.push!(sll::SinglyLinkedList, item::Int)::Int
    _node = ListNode(item)
    if sll.head == nothing
        sll.head = _node
        return item
    end
    tmp = sll.head
    while tmp.next != nothing
        tmp = tmp.next
    end
    tmp.next = _node
    return item
end

function Base.show(io::IO, sll::SinglyLinkedList)::Nothing
    sll.head == nothing && return
    tmp = sll.head
    while tmp != nothing
        print(tmp.data, " -> ")
        tmp = tmp.next
    end
end

function reverse!(sll::SinglyLinkedList)
    sll.head == nothing && return
    p = nothing
    n = sll.head.next
    while n != nothing
        sll.head.next = p
        p = sll.head
        sll.head = n
        n = n.next
    end
    sll.head.next = p
end

#= pointer swap with 'c'
function reverse!(sll::SinglyLinkedList)
    sll.head == nothing && return
    p = nothing
    c = sll.head
    n = sll.head.next
    while n != nothing
        c.next = p
        p = c
        c = n
        n = n.next
    end
    c.next = p
    sll.head = c
end
=#
sll = SinglyLinkedList()
push!(sll, 5)
push!(sll, 7)
push!(sll, 8)
push!(sll, 1)
push!(sll, 3)
push!(sll, 2)
println(sll)
reverse!(sll)
println(sll)