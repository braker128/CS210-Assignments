Answer underneath, two to four sentences each, in your own words, referring to your own
code where a question asks you to.

1. Why does concat only need to work between two lists of the same representation? What would
   you have to do differently, or what would go wrong, if you tried to make it work between a
   LinkedList and an ArrayList?

Concat only needs to work between two lists of the same representation because they store and connect
their elements differently. To make that work, you would need to convert the storage structures, 
allocate nodes to hold the array's pointers, transfer data pointers to open array indexes, and do 
this while cleaning up memory/pointers without deleting stored objects.

2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.

The three pointers I need alive at once are previous, current, and temp. Previous tracks the 
reversed part, current tracks the node that I'm changing the pointer of, and temp stores the
original next node before I overwrite current->next. Losing track of previous would lose access to the 
reversed part, losing track of current would process an incorrect node, and losing track of temp 
would lose access to the remaining list.

3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?

The valid range for position in addAnywhere is between 0 and n, and the range in deleteAnywhere 
is between 0 and n - 1. If a caller passes a position outside of those ranges, my
implementation prints an error message and leaves the list unchanged.

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?

I needed to walk to the end of the list first because to append nodes onto the list, I have 
to be at the end or else I would overwrite other nodes; addFront and deleteFront only managed
the front, which are O(1) in a LinkedList. concat's performance would become O(1) if it tracked
a tail pointer, but would have to update the pointer throughout nearly all of the methods.

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.

In addAnywhere, every pointer from position to size_ - 1 moves one index to the right. Shifting 
in the wrong direction would overwrite two pointers of data because you move one to the left, then
replace the position pointer too.


6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing.

table->reverse() on line 47 of main.cpp. If that call were missing, the order would stay
the same instead of reversing play and would also remove Chloe instead of Steve later on. 