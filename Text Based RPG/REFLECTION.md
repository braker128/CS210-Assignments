1. For every function you wrote (`TODO 1 to 19`), explain in your own words what it does and
   give its time complexity in terms of n, the number of scenes. One short paragraph each.



2. Why does each scene allocate exactly `numChoices` slots instead of declaring `Scene<T>*
   choices[3]`? What does an ending hold in `choices_`, and why?



3. Walk through your `Scene` destructor. What gets deleted, and in what order? What would
   go wrong if `choices_` were deleted first?



4. Show the path greedy took and the path optimal took on your story, with the loot for each.
   Explain why greedy lost. If greedy did not lose, change your story until it does, and explain
   what you changed.



5. `bestLoot` tries every path, yet it runs in `O(n)` time. Explain why it is not exponential, using
   what you know about paths and leaves in a tree.



6. Which `List` methods does your game use, and why? What does one `search` cost as the bag
   grows?

