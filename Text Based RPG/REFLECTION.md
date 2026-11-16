1. For every function you wrote (`TODO 1 to 19`), explain in your own words what it does and
   give its time complexity in terms of n, the number of scenes. One short paragraph each.

`TODO 1`: The scene constructor. If a scene has no choices (an ending), 
returns nothing and leaves choices_ as its default value of nullptr. Otherwise,
it creates a new array the size of numChoices_. It runs O(1) because it can only allocate
up to 3 indexes, independent of how large the story gets / number of scenes.

`TODO 2`: The scene destructor. Frees everything a scene owns. It deletes data_ first, then
the pointers stored in choices_[], then deletes choices_[]. Deleting one
scene is O(1), but deleting the root recurses down and frees all of its subtrees too, 
so that is O(n).

`TODO 3`: Checks if a scene is ending by comparing whether there are 0 choices or not.
0 choices being an ending and returning true. O(1).

`TODO 4`: Returns the child pointer at index or a nullptr if index is out of range. O(1).

`TODO 5`: Stores next into the specified index of choices_. O(1).

`TODO 6`: Recursively counts the number of scenes. Base case `if (scene == nullptr)` with 
recursive case `sceneCount += countScenes(scene->getChoice(i));`. It visits and counts every
scene. O(n).

`TODO 7`: Recursively counts the number of endings. Base cases are `if (scene == nullptr)`
and `if (scene->isEnding())` with recursive case 
`endingCount += countEndings(scene->getChoice(i));`. It visits every scene. O(n).

`TODO 8`: Recursively finds the most choices a player can make before reaching an ending.
It visits every scene. O(n).

`TODO 9`: Deletes the root, which recursively frees every scene through the scene 
destructor. O(n).

`TODO 10`: Opens the story file with error handling, sets starting hp, and builds the story
with readScene. O(n) because readScene reads every scene.

`TODO 11`: Reads a scene's fields with error handling, builds the Moment and Scene, 
reads the label of each choice and recurses to build that branch. The scene is listed
before its children. Failures delete that build and return nullptr so nothing leaks.
Every scene is read once. O(n).

`TODO 12`: Prompts the player to pick a choice with error handling. O(1) per attempt.

`TODO 13`: Core game function / the ability to play through a story. Applies hp and
loot changes, prints the scene, does item handling, prints current stats, stops on
deaths or endings, lists choices, and moves to the choice made. After the game ends, 
it prints final stats and items. Each new item does a linear search on bag. Up to O(n^2)
where an item is given each scene and each scene has one choice until the ending (0).

`TODO 14`: Prints number of scenes, number of endings, and longest possible playthrough (max
height). countScenes(), countEndings(), and height() are each O(n) traversals, so O(n).

`TODO 15`: Calls printEndings at the root with an empty path. O(n)

`TODO 16`: Recursively traverses to each ending and keeps track of the path taken, printing
the path and ending scene. It visits each scene once. O(n).

`TODO 17`: Plays the story only considering the path with the most immediate loot. At each
scene, it picks the choice with the highest amount of loot even if that is not the most
loot able to be acquired. Checks at most 3 children (MAX_CHOICES). Up to O(n) where each 
scene has one choice until the ending (0).

`TODO 18`: Recursively finds the most loot you can possibly collect without dying. If
it reaches an ending or dies, it saves that path as the best result and recurses the remaining
scenes. It visits every scene. O(n).

`TODO 19`: Calls bestLoot and displays the optimal path, loot, and survival result. O(n).


2. Why does each scene allocate exactly `numChoices` slots instead of declaring `Scene<T>*
   choices[3]`? What does an ending hold in `choices_`, and why?

Each scene allocates numChoices slots so that it doesn't waste memory and each loop through
children only runs the number of times it has choices available. An ending in choices_
holds a nullptr because it doesn't have any choices and therefore does not need an array.

3. Walk through your `Scene` destructor. What gets deleted, and in what order? What would
   go wrong if `choices_` were deleted first?

My scene destructor deletes data_, pointers stored in choices_ (child pointers), and 
choices_ in that order. If choices_ were deleted first, the child pointers would be lost
and leaked to memory.

4. Show the path greedy took and the path optimal took on your story, with the loot for each.
   Explain why greedy lost. If greedy did not lose, change your story until it does, and explain
   what you changed.

Greedy advisor
Path: 2-1-1-1-1
Loot: 5
Result: died

Optimal advisor
Path: 2-1-1-2-2-1-1
Loot: 10
Result: reached an ending

The greedy path lost because it chose to go to the forest instead of the village because 
there was more loot there to grab, which led to them dying to the wolf. 

5. `bestLoot` tries every path, yet it runs in `O(n)` time. Explain why it is not exponential, using
   what you know about paths and leaves in a tree.

Each scene has one parent and the number of endings are the number of leaves, which cannot be
greater than n. A path is from the root to a leaf, but shared paths are not tried separately,
they branch, making it visit each node only once. It could become exponential if it were a 
graph rather than a tree.

6. Which `List` methods does your game use, and why? What does one `search` cost as the bag
   grows?

My game uses: search to check if an item is already in the bag before adding it, addFront
to add an item to the bag, size to display the number of items in the bag, and print to
list each item in the bag. Search's cost is linear / O(n), but it is called each time you
enter a scene with an item, up to O(n^2) over the entire game.