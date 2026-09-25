1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
   Name exactly what each one frees, and name the two new calls back in the program responsible
   for putting them on the heap in the first place.

In `main.cpp`, the method call uses `new int(value)`, which creates a new integer object. This then is 
passed to `LinkedList::addFront()` and inside of that method, a new node object is created 
(`new Node<T>(value)`). Now there are two objects in memory that both need to be freed. 
`delete doomed->data` frees the integer object inside the node and `delete doomed` frees the Node object.

2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?

Switching from `T data[CAPACITY]` to `T* data [CAPACITY]` makes a destructor necessary because
when you create an arraylist out of pointers, the objects sit somewhere in memory and 
pointers do not have their own destructors. By not writing a destructor in a pointer arraylist, 
you would fill your memory with inaccessible objects. In a standard arraylist,
the compiler automatically creates and calls destructors for the objects because the objects in it
are members of that arraylist, not pointers to other bits of memory. You would not get 
a compiler error because pointers are memory addresses and the compiler doesn't track if a pointer 
and object in memory should be connected or not, it's a logic error and memory leak.

3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?

The difference in terms of ownership between them is that `addFront` has ownership over the pointer 
because the value that it's passed gets stored into a list or node that persists after the method call. 
`search()` never has ownership because it doesn't store any values outside of the call and only 
compares values against the search value.

4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?

The two mechanisms that made that possible are abstraction and polymorphism. Abstraction allows 
`main.cpp` to use the interface `List<T>` which abstracts which class is used (`ArrayList` vs 
`LinkedList`) rather than requiring you to make or know that choice in `main.cpp`. Polymorphism
allows `list->addFront(value)` to call the correct method at runtime because `List<T>`'s methods 
are `virtual', rather than the compiler deciding on which to call.

5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.

