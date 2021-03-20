mutable struct ListNode
    data::Int
    prev::Union{ListNode, Nothing}
    next::Union{ListNode, Nothing}
    ListNode(d::Int) = (
        me = new();
        me.data = d;
        me.prev = nothing;
        me.next = nothing;
        return me;
    )
end

mutable struct DLL
    head::Union{ListNode, Nothing}
    tail::Union{ListNode, Nothing}
    DLL() = (me=new(); me.head=nothing; me.tail=nothing; me)
end

function push!(dll::DLL, item::Int)::Int
    toadd = ListNode(item)
    if dll.head == nothing
        dll.head = toadd
        dll.tail = toadd
        return item
    end
    dll.tail.next = toadd
    toadd.prev = dll.tail
    dll.tail = dll.tail.next
    return item
end

function Base.show(io::IO, dll::DLL)
    tmp = dll.head
    while tmp != nothing
        print(tmp.data, " -> ")
        tmp = tmp.next
    end
end

function reverse!(dll::DLL)
    newhead = dll.head
    while true
        tmp = newhead.prev
        newhead.prev = newhead.next
        newhead.next = tmp
        if newhead.prev == nothing break end
        newhead = newhead.prev
    end
    dll.head = newhead
end

lst = DLL()
push!(lst, 3)
push!(lst, 5)
push!(lst, 6)
push!(lst, 2)
println(lst)
reverse!(lst)
println(lst)
