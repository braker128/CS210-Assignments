Answer underneath, two to four sentences each, in your own words, referring to your own
code where a question asks you to.

1. Why does concat only need to work between two lists of the same representation? What would
   you have to do differently, or what would go wrong, if you tried to make it work between a
   LinkedList and an ArrayList?



2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.



3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?



4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?



5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.



6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing.


