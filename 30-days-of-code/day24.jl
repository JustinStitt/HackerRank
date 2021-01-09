# link = https://www.hackerrank.com/challenges/30-linked-list-deletion

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

mutable struct SLL
    head::Union{ListNode, Nothing}
    SLL() = (me=new(); me.head=nothing; me)
end

function push!(sll::SLL, item::Int)::Int
    _node = ListNode(item)
    if sll.head == nothing
        sll.head = _node
        return item
    end
    tmp = sll.head
    while tmp.next != nothing
        tmp = tmp.next # find the tail
    end 
    tmp.next = _node
    return item
end

function Base.show(io::IO, sll::SLL)::Nothing
    if sll.head == nothing return end
    tmp = sll.head
    while tmp != nothing
        print(tmp.data, " -> ")
        tmp = tmp.next
    end
end

function Base.unique!(sll::SLL) # remove duplicates from sll
    if sll.head == nothing return end
    tmp = sll.head
    while tmp.next != nothing
        if tmp.data == tmp.next.data # found duplicate
            tmp.next = tmp.next.next
        else
            tmp = tmp.next
        end
    end
end

sll = SLL()
push!(sll, 1)
push!(sll, 1)
push!(sll, 2)
push!(sll, 2)
push!(sll, 3)
println(sll)
unique!(sll)
println(sll)
