#### CS 240 - Spring 2019
### PROGRAM 1 README FILE

## KNOWN BUGS AND INCOMPLETE PARTS:
- What parts of the program you were not able to complete

## REFERENCES:
- List any outside resources used

## MISCELLANEOUS COMMENTS:
- Anything you would like the grader to know

***
### Assignment Description
***
# Program 1 - Building Solar Systems
## Due Date: 11:59 p.m., February 27th, 2019

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Driver Code and Test Files

* program1.cpp
    * include the driver code with your submission, but do not alter it

### Grading Rubric

**_TOTAL: 45 points_**

* **Part A** (10 points): Vectors
    * [2 pts] Test 1 Passed: creates a vector with properly initialized values
    * [2 pts] Test 2-3 Passed: inserting into the vector passes all tests
    * [2 pts] Test 4-6 Passed: reading from vector passes all tests
    * [2 pts] Test 7 Passed: removing from vector passes tests
    * [2 pts] Test 8-9 Passed:  deleting vector frees memory
* **Part B** (10 points): Lists
    * [2 pts] Test 10 Passed: creates a list with properly initialized values
    * [2 pts] Test 11 Passed: inserting into list at index passes test
    * [2 pts] Test 12 Passed: reading from list at index passes test
    * [4 pts] Test 13 Passed: removing and deleting from list at index passes test
* **Part C** (20 points): Stars
    * [12 pts] Test 14 Passed: create, read, and remove from Starvector and Starlist without error
    * [8 pts] Test 15 Passed: delete Starvector and Starlist without error
* **Part D** (5 points): Profile
   * [5 pts] completes profiling without error
* **Style Guidelines and Memory Leaks**
    * You will lose significant points for the following:
        * Memory leak or error detected in valgrind  (-10 points)
        * Repository includes .o files or binary [-1 point]
        * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk)[-3 points]
        * Your submission will not be accepted if:
            * Does not follow requested project structure and submission format
            * Does not compile

### Guidelines

This is a pair programming assignment. You and a partner can divide up the work. Although both of you may not work on all parts of the program you should understand and be able to fully explain every portion of the code. Outside of your team, it is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically to solve the problem you have been given, and you may not have anyone else help you or your partner write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

If you or your partner are found to have plagiarized any part of the assignment, both will receive a 0 and be reported.

__In this program, you will learn to__:

* Work with sequential and secondary data structures

For the first program you and partner are going to build both a dynamic array (vector) and a linked list. Each data structure will be tested to ensure the validity of its operations. Once that is complete and you know your data structures are working, we are going to use them as internal data structures for our Star class. Both versions of the Star class will be evaluated to see which provides better performance.

You will reuse your Planet class from lab 3 with no changes.

:warning: *For all Data Structures, you may (and probably should) add additional functions, methods, and attributes, but what follows is the required minimum interface*

:no_entry_sign: You may __not__ use the STL library for this program.

***
You will need to make a small change to your planet class constructor.

#### Planet
* `Planet(int distance)`
    * You do not need to pass an ID. The ID will now be the address of the object.
* `long int getID()`
    * The return type of the getID() method will need to be changed to a long to hold the address (8 bytes)

:warning: You will need to update your `Star` class method `addPlanet` accordingly.
***    

## Part A: Vectors
You must break up your code into Vector.h and Vector.cpp according to the conventions we have discussed in class.

Create a dynamic array data class, Vector. You must create your internal array on the heap (using `new`). Your Vector class should have, at minimum, the following:
* `~Vector()`
    * A destructor to clean up memory
* `void insert(int index, Planet * p)`
    * inserts an element at index, increasing the Vector size by 1
    * if the insert index is out of bounds, you should increase the capacity to the size of the index + 1
* `Planet* read(int index)`
    * returns a pointer to the Planet object at `index`
    * if the index is out of bounds, return NULL
* `bool remove(int index)`
    * remove the Planet object at `index`, decreasing the size of the Vector by 1.
* `unsigned size()`
    * returns the current size of the Vector (this may not be the same as the number of elements)

## Part B: Linked Lists
You must break up your code into List.h and List.cpp according to the conventions we discussed in class. Create a doubly linked list using a List and Node classes. :bulb: Your List and Node classes can go in the same file. Your linked list should have the following operations:
* `List()`
    * A pointer to a head and tail node, both initialized to NULL
* `~List()`
    * A destructor to clean up memory
* `void insert(int index, Planet * p)`
    * inserts an element at index, increasing the List size by 1
    * if the insert index is out of bounds, you should append to the end of the list
* `Planet* read(int index)`
    * returns a pointer to the Planet object at `index`
    * if the index is out of bounds, return NULL
* `bool remove(int index)`
    * remove the Planet object at `index`, decreasing the size of the Vector by 1.
    * return `true` on successful deletion or `false` if the index is out of bounds
* `unsigned size()`
    * returns the current size of the List

## Part C: Full of Stars

Although you should have most of the code written from previous labs. You will need to make slight alterations to your Star class to work with the changes to the Planet class and to work with one of the Data Structures (Vector, List) you have created. You must break up your code into Star.h and Star.cpp according to the conventions we discussed in class.

You will have two Star classes, Starlist and Starvector. You will be using your List and Vector, respectively, as the internal data structure to hold Planets.

#### Starlist

Your Starlist must have the following:

* `Starlist()`
    * Initialize memory
* `~Starlist()`
    * deallocate all memory when the Star is deleted.
* `long addPlanet()`
    * return the ID of the newly created Planet
* `bool removePlanet(long)`
    * Takes a Planet’s ID as a parameter, and removes the Planet from the Star.
    * You must return `true` upon successful deletion and `false` on failure if the ID isn't found.
* `Planet * getPlanet(long)`
    * Takes a Planet’s ID and returns a pointer to the Planet. If the Planet is not found, it returns NULL.
* `void orbit()`
    * Iterate through your planets and alter their orbit position by +1
* `void printStarInfo()`
    * Prints the Star information.
* `unsigned int getCurrentNumPlanets()`
    * returns the current number of planets stored

#### Starvector

Your Starvector must have the following:
* `Starvector()`
    * Initialize memory
* `~Starvector()`
    * deallocate all memory when the Star is deleted.
* `long addPlanet()`
    * return the ID of the newly created Planet
* `bool removePlanet(long)`
    * Takes a Planet’s ID as a parameter, and removes the Planet from the Star.
    * You must return `true` upon successful deletion and `false` on failure if the ID isn't found.
* `Planet * getPlanet(long)`
    * Takes a Planet’s ID and returns a pointer to the Planet. If the Planet is not found, it returns NULL.
* `void orbit()`
    * Iterate through your planets and alter their orbit position by +1
* `void printStarInfo()`
    * Prints the Star information.
* `unsigned int getCurrentNumPlanets()`
    * returns the current number of planets stored (the size of the vector)

## Part D: Profiling

Welcome to the easy part. If you made it this far, you can sit back and relax. I have written some profiling that test the operations for both versions of your Star class.

Pay attention to the output.
* What implementation is better for insertion?
* Reading?
* Overall?

## Part E: Submission

### Required file naming and organization:
* program1.cpp //Driver Code
* List.cpp/.h
* Star.cpp/.h
* Planet.cpp/.h
* Vector.cpp/.h
* makefile
    * You must have the following labels in your makefile:
        * all - to compile all your code to an executable called ‘program4’ (no extension). Do not run.
        * run - to compile if necessary and run
        * memcheck - to compile only if necessary and run with valgrind
        * clean - to remove all executables and object files

:no_entry: Every program will have a required submission guidelines. Please read submission requirements carefully. Any deviations from specifications will result in point deductions or incomplete grades.

## README

* KNOWN BUGS AND INCOMPLETE PARTS
* REFERENCES
* MISCELLANEOUS COMMENTS

Before your final submission, edit the content for each of these sections in this README for your program. You do not have to use markdown, but you can find out more about markdown [here](https://guides.github.com/features/mastering-markdown/) if you would like to.

### Git

Below is a reminder of the commands you need to use to submit your program.

:warning: You have created several files and even a folder for this program. Be sure you add them to the repo. If you forget to add the files to the repo, your assignment will be considered late or not accepted at all.

```shell
git status
git add mylib.h
git commit -a -m "commit message"
git push
```

To find your most recent commit hash, use the following command:

```shell
git rev-parse HEAD
```    

To complete your submission, you must copy and paste this number into mycourses. Go to MyCourses, select cs240, then program1 under **Assignment Hash Submission**, and where it says text submission, paste your commit hash.

:warning: You __MUST__ submit the commit hash on mycourses before the deadline to be considered on time **even if your program is completely working before the deadline**. :warning:
