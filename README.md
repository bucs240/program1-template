#### CS 240 - Spring 2018
# Program 1 - AntFarm
## Due Date: 11:59 p.m., February 21st, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * program1.cpp
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make checkmem
        * make clean
    * Sample Output (with our test case):
        ```shell
        ./program1
        TEST #1: Run AntFarm Simulation
        	=============== Turn #0 ==================
        The hill currently has:
        	Food:0
        	Ants: 3
        The hill has been attacked 0 times.
        	Successfully defended: 0
        	Failed to Defend: 0
        Ant #2 has run into a rival ant
        Ant #2 	 loses the fight and dies
        	=============== Turn #1 ==================
        The hill currently has:
        	Food:1
        	Ants: 2
        The hill has been attacked 0 times.
        	Successfully defended: 0
        	Failed to Defend: 0
        			...time passes
        	=============== Turn #71 ==================
        The hill currently has:
        	Food:3
        	Ants: 0
        The hill has been attacked 12 times.
        	Successfully defended: 7
        	Failed to Defend: 5
        =========================PASS========================
        	Don\'t forget to run with Valgrind and commit to Github!
        ```

### Grading Rubric
__Total: 60 points__
* __Program [5 points]__
    * Compiles [2 pts]
    * Runs with driver without error [3 pts]
* __Ant.h [11 points]__
    * All instance variables (except Node class) are private [2 pts]
    * fight() method returns if the ant has won [3 pts]
    * move() method must move 1 random unit [2 pts]
    * ants must stay in a defined grid [2 pt]
    * Has a copy constructor [2 pt]
* __LinkedList.h [23 points]__
    * Node Class contains an Ant object or a pointer to an Ant object [2 pts]
    * Node does not have a default constructor [3 pt]
    * LinkedList class has a pointer to the head of the list [1 pt]
    * LinkedList class contains default and copy constructor, as well as destructor [4 pts]
    * Linked List does not return a pointer to a node [5 pts]
    * The << operator is overloaded [3 pts]
    * All CRUD operations are supported [5 pts]
* __AntHill.h [21 points]__
    * Ants are stored in a linked list [5 pts]
    * Correctly keeps track of current food amount [2 pts]
    * Each turn the following should happen
        * adds ants to the hill, removing 1 food for each new ant [2 pts]
        * Has some percentage chance of being attacked. Attacks can result in success or failure [3 pts]
            * If failure, all food is removed as well as all ants within half the size of the grid
        * Each Ant has some percentage chance of getting into a fight [2 pts]
            * Ant is removed from the hill if it loses the fight.
        * Each Ant, if (and only if) it does not get into a fight, has some percentage chance of finding food [2 pts]
            * If food is found, it is added to the hill.
    * The state of the AntHill is written out to a log file, ‘anthill.log’, after the completion of each turn. [5 pts]__
* **Part C:**
    * If memory error, memory leak, no 'checkmem' target [-5 points]
    * Does not follow requested project structure, makefile, and submission format [-3 points]
    * Submission includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk) [-3 points]

### Guidelines

This is an individual lab assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

***

In Program 1, you will expand your anthill to create an ant farm where ants try to survive and build their anthill. You will begin with an anthill, and the ants will wander the Antfarm in search of food and rival ants. Program 1 will provide you experience with:
* a simple singly linked list container
* C++ heap memory management (strategic and extensive use of new and delete)
* deep copies of stored data, including in copy constructors and assignment operators
* operator implementation and overloading (including assignment operators, unary operators, binary operators)

:warning: __This program will be difficult for some of you so please begin early and work on it consistently. You can do it and we will help! When you finish successfully, you will really understand linked lists, operator overloading, deep vs. shallow copy, and more, guaranteed!__ :warning:



#### (Parts A must be completed in lab)

## Part A: Linked List

For part A you are going to write a singly linked list library for Ants. This means you will need a LinkedList.h and a LinkedList.cpp. The design of your linked list is largely up to you, but there are a few restrictions you must adhere to:
* All instance variables must be private and encapsulated
    * This means that everything must be accomplished through methods and you cannot return a pointer to anything inside the class (head, current, etc)
* It must be a __singly__ linked list
    * No pointer to the tail of the list or pointers to previous nodes
* The Node class must be in LinkedList.h, not a separate file
* The Node class cannot have a default constructor
* Your list class must contain the following:
   * A default constructor
   * A copy constructor
   * A destructor
   * All CRUD operations
      * How you implement these CRUD operations is up to you, but again, you must not expose the internals of the list. This means you never return a pointer to any Node from any of your public methods.
         * _You may return a pointer or reference to the data in a Node._
      * You also cannot ‘index’ into the list with the method. No indexInsert(), indexRead(), etc.
      * However, you will need to implement a find and delete that finds or deletes, respectively, a specific Ant. How you do that is up to you.
   * The following overloaded operators
      * `a << b`
         * Should take data `b` and add it to the linked list `a`
__I strongly suggest you test your Linked List rigorously before moving on to the next part. Write a short main that runs several tests to ensure all methods are working.__


_The TA will look over your code in next week’s lab. You must have your LinkedList implemented by then to get credit for that lab._


## Part B: Create Your AntFarm Program

Your AntFarm will consist of a single AntHill. Your ants will wander the (metaphorical) AntFarm encountering food or rival Ants.
Functional Requirements:
* Your program should write out a summary of the AntFarm after every turn to a log file call ‘anthill.log’.
    * A full turn is defined as
        * The Anthill produces all of the ants it can
        * The Anthill may be attacked
        * Every Ant has moved

### Anthill requirements

* AntHills start with 3 Ants (no food requirement)
* Anthills can spawn any number of ants depending on food. Each time an Ant is spawned it is appended to an internal linked list that keeps track of the Ants.
    * You cannot spawn more ants unless you have enough food
        * 1 piece of food allows you to create 1 ant
            * The food is consumed when the ant is created
* When an ant is created, it will leave the anthill and randomly wander the Ant Farm in search of food or battle.  
    * Each ant moves 1 unit in the Ant Farm per turn
    * Movement should be random and should stay within a grid.
        * In other words, the X and Y value should never exceed the grid.
    * As the Ants wander the AntFarm, there are 3 possible events:
        * For each full turn, there is a slight chance (maybe ⅕) that your AntHill will be attacked.
            * If you are attacked you should generate a random value between 1-and your total number of ants to determine how many Ants are attacking you.
            * Any Ants less than half the size of the grid in any direction help ‘defend’.
                * If you have more Ants defending than attacking, you successfully fend off the attack.
                * Otherwise, all defending Ants are removed and all food is lost.
    * An individual ant has a chance (again, around ⅕) during their move of encountering a single rival Ant. If they do, they must fight.
        * Design a fight method that randomly determines if they have won or lost. If they lose, they are killed and removed from the AntHill.
    * If the Ant does not encounter a rival Ant, the Ant has a chance (⅕ worked well for me again) to find food. If the attempt to find food is successful, it is immediately added to the Ant’s AntHill.

### Ant Requirements
* You must implement a copy constructor for the Ant class.
* You must have a fight method that returns if the Ant has won the random encounter with a rival Ant
* The simulation ends when you have reach 0 or 100 ants in the AntHill.
* You should play around with the various literal values, such as grid size, odds for being attacked, the fight, or finding food to see what odds produce the best results. This means you should write your code so these values are easy to change.


## Part C : Code Organization and Submission
* Required code organization:
   * program1.cpp
   * Ant.h/.cpp
   * AntHill.h/.cpp
   * LinkedList.h/.cpp
   * anthill.log
   * makefile

Below is just a reminder of the commands you should use to submit your code. If you cannot remember the exact process, please review lab 1.

*These commands all presume that your current working directory is within the directory tracked by `git`.*

```git
git add Anthill.h
git add Anthill.cpp
git commit -a -m "first commit"
git push
```
Lastly we are going to make our final commit. You will need to do this when your submission is ready for grading.

```shell
git commit --allow-empty -m "final commit"
git push
```

:warning: Remember, you __MUST__ make a submission with the comment "final commit" before the deadline to be considered on time.
