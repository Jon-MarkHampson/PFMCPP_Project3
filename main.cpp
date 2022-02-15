/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};

/*
Thing 1) Coffee Shop
5 properties:
    1) number of chairs (int)
    2) number of staff (int)
    3) number of toilets (int)
    4) annual profit (double)
    5) price of coffee (float)
3 things it can do:
    1) host local artists work on walls
    2) charge customer
    3) train staff

Thing 2) School
5 properties:
    1) number of classrooms (int)
    2) position in leauge table (int)
    3) number of teachers (int)
    4) number of pupils (int)
    5) student average grade (float)
3 things it can do:
    1) train teachers
    2) students christmas play
    3) close for holidays

Thing 3) Farm
5 properties:
    1) number of sheep (int)
    2) number of cows (int)
    3) crop yeild (double)
    4) number of farmers (int)
    5) area in hectare (double)
3 things it can do:
    1) sell sheep
    2) harvest crop
    3) construct new barn

Thing 4) Commerical Aeroplane
5 properties:
    1) number of engines (int)
    2) top speed (double)
    3) number of seats (int)
    4) fuel tank capacity (double)
    5) flight range (double)
3 things it can do:
    1) take off
    2) emergency landing
    3) inflight entertainment

Thing 5 ) Player
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

Thing 10) Sports Team
5 properties:
    1) player
    2) coach
    3) fan
    4) medic
    5) stadium
3 things it can do:
    1) play home game
    2) play away game
    3) win championship
*/

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
