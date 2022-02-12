/*
Project 3 - Part 1a-d / 5
Video:  Chapter 2 Part 5
User-Defined Types

Create a branch named Part1

Purpose: The entire purpose of this 5-part project is to get you 
writing C++ code that compiles and to reinforce the syntax habits 
that C++ requires.  
What you create in this project will be used as the basis of 
Project 5 in C++ Language Fundamentals.

************************
Part1 purpose:  Learn to write User-Defined Types (UDTs)

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps, all on the same branch.
    Part 1a: you will learn to think about an object in terms of 
    its sub-objects.
    
    Part 1b: you will write 4 un-related UDTs in plain english.
    
    Part 1c: you will write 1 UDT in plain english that will be 
    made of 5 related sub-objects.
    
    Part 1d: you will write plain-english UDTs for the 5 
    sub-objects that form the UDT defined in Part 1c.
    
    Part 1e: you will convert those 10 plain-english UDTs into code 
    that runs.
************************
*/

/*
Part 1a
1) Look at the picture of the car interior (Part1a pic.jpg).  
    It's in the list of files on the left in Replit.
    Fill in the blanks below which break this car interior down 
    into sub-objects.

Several sub-objects are listed below that make up this car's interior.
    you're going to name several things that you'll find on each 
    subobject.
    you're going to name several things that each subobject can do.
    If you've seen "Family Feud", we are going to do what they do 
    in that show.

    A few blanks are filled in for you already.

Main Object: Car Interior
Sub Object 1: Steering Wheel
    Name 4 things you'll find on the:    Steering Wheel
        1) paddle shifters
        2) 'cruise control' controls
        3) car horn
        4) phone system controls
    Name 2 things you can do with the:   Steering Wheel
        1) adjust cruise control settings.
        2) sound the car horn
        
Sub Object 2: Instrument Cluster
    Name 4 things you'll find on the:   Instrument Cluster
        1) odometer
        2) speedometer
        3) temperature gauge
        4) indicator status lights
    Name 3 things you can do with the:   Instrument Cluster
        1) read the speed the car is travelling
        2) check whether the indictator lights are blinking and which side
        3) read the external environment temperature
    
Sub Object 3: Environment Controls
    Name 3 things you'll find on the:    Environment Controls
        1) internal envirnoment temperature controls 
        2) heater/ac fan speed control
        3) ac on/off toggle button
    Name 3 things you can do with the:   Environment Controls
        1) adjust the internal envirnoment temperature
        2) adjust the speed of the fans
        3) toggle the ac on/off

Sub Object 4: Infotainment System
    Name 3 things you'll find on the:    Infotainment System
        1) Infotainment System on/off toggle button
        2) Volume knob
        3) CD edject button
    Name 3 things you can do with the:   Infotainment System
        1) Play a audio CD
        2) Place a phone call
        3) Listen to the radio

Sub Object 5: Seat 
    Name 3 things you'll find on the:    Seat
        1) seat belt buckle
        2) seat mounted airbag
        3) seat postion controls
    Name 2 things you can do with the:   Seat
        1) recline the seat
        2) heat your butt
*/

/*
Part 1b
Now you have some basic understanding of how to think of an object 
in terms of its sub-objects.

Next, write 4 un-related UDTs in plain english:
*/
/*
 example:  
 
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - the amount of water used per week.
        - amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior

    Notice that I did not use "has a vacuum cleaner" or "Has 
    eco-friendly cleaning supplies" as one of the properties.
    
    Writing 'has a ___" checks whether or not your object **has the 
    ability to do something**.
    Instead, I wrote "number of vacuum cleaners" and "number of 
    eco-friendly cleaning supplies".  
    
    These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' 
    (has a) as a member variable type.
    Instead, prefer the other primitive types.

    In addition to the usual primitives (covered in Project 2), you 
    can use 'std::string' to represent strings in this project.
 */

/*
Part 1b Assignment:
1)  Fill in the 4 UDTs below with a random UDT in plain english.
    These 4 UDTs do not need to be related.
        a) For each plain-english UDT, write out 5 traits or 
        properties and 3 things it can do.
        b) remember: these properties will eventually become
        primitives.
        c) pick properties that can eventually be represented with 
        'int float double bool char std::string'.
*/

/*
Thing 1) Coffee Shop
5 properties:
    1) number of chairs
    2) number of staff
    3) number of toilets
    4) annual profit
    5) price of coffee
3 things it can do:
    1) host local artists work on walls
    2) charge customer
    3) train staff
 */

/*
Thing 2) School
5 properties:
    1) number of classrooms
    2) position in leauge table
    3) number of teachers
    4) number of pupils
    5) student average grade
3 things it can do:
    1) train teachers
    2) students christmas play
    3) close for holidays
 */

/*
Thing 3) farm
5 properties:
    1) number of sheep
    2) number of cows
    3) crop yeild
    4) number of farmers
    5) area in hectare
3 things it can do:
    1) sell sheep
    2) harvest crop
    3) construct new barn
 */

/*
Thing 4) commerical aeroplane
5 properties:
    1) number of engines
    2) top speed
    3) number of seats
    4) fuel tank capacity
    5) flight range
3 things it can do:
    1) take off
    2) emergency landing
    3) inflight entertainment
 */

 /*
Part 1c
You have just finished practicing writing out a UDT that is has 
5 properties and can perform 3 actions.  

Now you will write 1 UDT in plain english. 

This UDT will be different than the previous 4 you wrote: It will 
use UDTs to describe its 5 properties, as opposed to using C++ 
primitives to describe the 5 properties.

You will define these 5 'property' UDTs in Part 1d.
 */

 /*
Part 1c example:
    Cell Phone

    A Cell Phone is built using the following 5 UDTs:
        Display
        Memory
        CPU
        Radio
        Applications

    A Cell Phone has 3 things it can do:
        make a call
        send a text
        run an application.

    Notice that I did not use "has a display" or "Has memory" or 
    "has a cpu" as one of the properties of the CellPhone.
    
    Writing 'has a ___" checks whether or not your object **has 
    the ability to do something**.
    Instead, I wrote "Display" or "CPU".  These are specific 
    objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' 
    (has a) as a member variable type.
    Instead, prefer the other primitive types.

    When you choose your 5 smaller parts, remember that each of 
    these 5 Sub Objects will need to be defined with 5 primitive 
    properties and 3 actions EACH.
*/
/*
Part 1c assignment:
1) Fill in the 10th UDT below.
    Define an object that is made of 5 sub-objects.
    These parts will not be defined using Primitives, but instead 
    will be their own UDTs you'll define in Part 1d.

2) write the name of the primitive type you'll be using after each 
    property in UDTs 1-4:
    pick properties that can be represented with 
    'int float double bool char std::string'.
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            area in cm2 (int)
            brand (std::string)
*/

/*
    Thing 10) Sports Team
5 properties:
    1) Player
    2) Coach
    3) Fan
    4) Medic
    5) Stadium
3 things it can do:
    1) play home game
    2) play away game
    3) win championship
 */

/*
Part 1d
You now know how to define a UDT that is composed of other UDT.
Now you will learn how to break down those sub-object UDTs into 
their 5 properties and 3 actions.

The goal of Part 1d is to get you to think about breaking down an 
object into smaller and smaller objects, until the smallest object 
is made of up only C++ primitives and std::string. 

Revisiting the previous example:  
Cell Phone

A Cell Phone is made up of the following 5 properties/sub-objects 
and 3 actions:
    Display
    Memory
    CPU
    Radio
    Applications
3 actions:
    make a call
    send a text
    run an application.

These 5 properties can be broken down into their own sub-objects 
and properties. 

If we break down the first property 'Display' into its 5 properties 
we get:
    brightness
    amount of power consumed.
    pixels
    width in cm
    height in cm

the Display's brightness can be represented with a Primitive, 
such as a double. 

The amount of power consumed can also be represented with a 
Primitive, such as a float or integer (i.e. 250mWa)

The 'pixels' property must be represented with an array of Pixel 
instances, as the screen has more than 1 row of pixels.
    Arrays have not been discussed and can't be used in this 
    project.
    Instead, we can use an Integer primitive to store the 
    Number of Pixels:

Display:
    Number of Pixels
    Amount of Power consumed (milliwatt-hours)
    Brightness
    width in cm
    height in cm

As you can see, the 'Display' UDT has been broken down to the 
point of being able to describe it with C++ primitives. 
*/

/*
Part 1d assignment:
1) Fill in #5 - #9 below with plain-english UDTs for the 5 
properties you created for UDT #10. 
    example: 
        If #10's first property was 'Engine', then `Thing 5)` 
        will be `Engine`. 
        You will need to provide 5 properties and 3 member 
        functions of that Engine object in plain English.
        Remember to pick properties that can be represented 
        with 'int float double bool char std::string'.

2) write the name of the primitive type you'll be using after 
each property for UDTs 5 - 9.
    You already did this for UDTs 1-4 in Part 1c.
    Pick properties that can be represented with 
    'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)
*/

/*
Thing 5) Player
5 properties:
    1) body weight (float)
    2) sponsor (std:string)
    3) number of games played (int)
    4) scoring average (float)
    5) name (std::string)
3 things it can do:
    1) run
    2) score
    3) train
 */

/*
Thing 6) Coach
5 properties:
    1) name (std::string)
    2) years experience (int)
    3) trophies won (int)
    4) salary (double)
    5) inspiring (bool)
3 things it can do:
    1) give motivational speech
    2) lose job
    3) give press conference
 */

/*
Thing 7) Fan
5 properties:
    1) name (std::string)
    2) age (int)
    3) season ticket holder (bool)
    4) distance from stadium (double)
    5) fan club member (bool)
3 things it can do:
    1) buy ticket to game
    2) cheer
    3) wear team colours
 */

/*
Thing 8) Medic
5 properties:
    1) qualifications (std::string)
    2) name (std::string)
    3) salary (double)
    4) explayer (bool)
    5) IT skills (bool)
3 things it can do:
    1) give steriod injection
    2) massage treatment
    3) make fitness assessment
 */

/*
Thing 9) Stadium
5 properties:
    1) number of seats (int)
    2) pitch area (float)
    3) toilets (int)
    4) training pitch (bool)
    5) construction cost (double)
3 things it can do:
    1) host home game
    2) covid vaccination centre
    3) require maintance
 */

/*
You've just defined 10 UDTs!
4 of them are unrelated (UDTs 1-4).
5 of them form the sub-objects that make up the 10th UDT. 

Move them below this block comment and put them in numerical order 
(1 - 10).

The next thing that will happen is that I will review the 
pseudo-code that you have written.
Send me a DM to review your pull request when the project is ready for review.
*/

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
