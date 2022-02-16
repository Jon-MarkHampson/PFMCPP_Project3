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
*/

struct CoffeeShop
{

    //number of chairs (int)
    int numChairs = 54;
    //number of staff (int)
    int numStaff = 7;
    //number of toilets (int)
    int numToilets = 2;
    //annual profit (double)
    double annualProfit = 45362.78;
    //price of coffee (float)
    float priceCoffee = 3.40f;

    struct Employee
    {
        std::string firstName = "Magnus";
        std::string lastName = "Magnusson";
        int employeeID = 12345;
        bool fullyTrained = true;
        float salary = 30000.00f;

        void makeDeliveries();
        void takeHoliday();
        bool deservesPromotion(); // returns whether the employee is derving of a promotion



    };

    //host local artists work on walls
    float getArtExhibitCommision(float percenatgeCommisionAgreed, float totalArtSales, CoffeeShop coffeeshop); //returns the total value of commission earn from the sale of all the art at this instance of CoffeeShop 
    //charge customer
    float getCustomerSale(float priceCoffee, int numberOfCoffees, int customerNumber); //returns the total value of the sale of all good for this customer
    //train staff
    void staffTraining(Employee employee, std::string trainingRequired);
};

/*
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
*/

struct School
{
    //number of classrooms (int)
    int numClassrooms = 111;
    //position in leauge table (int)
    int leagueTablePosition = 13;
    ///number of teachers (int)
    int numTeachers = 54;
    //number of pupils (int)
    int numPupils = 1111;
    //student average grade (float)
    float aveGrade = 3.45f;

    //train teachers
    void teacherTraining(bool internalTraining, std::string trainingRequired);
    //students christmas play
    void christmasPlay(int numberOfStudentsInCast, std::string nameOfPlay, int rehearsalDays);
    //close for holidays
    void holidayClosure(int howManyDaysClosed, std::string nameOfHoliday);
};

/*
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
*/

struct Farm
{
    //number of sheep (int)
    int numSheep = 1234;
    //number of cows (int)
    int numCows = 321;
    //crop yeild (double)
    double cropYield = 76543.21;
    //number of farmers (int)
    int numFarmers = 6;
    //area in hectare (double)
    double farmLandAreaInHectare = 84.3;

    //sell sheep
    float getTurnoverSheepSale(float priceOfSheep, int numSheep); //returns the income from the sale of this farms sheep
    //harvest crop
    void harvestCrop(bool isCropMature, int numFarmHands, bool machinesFueled);
    //construct new barn
    void constructNewBarn(bool needNewBarn, float newConstructionBudget);
};

/*
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
*/

struct CommericalAeroplane
{
    //number of engines (int)
    int numEngines = 4;
    //top speed (double)
    double maxAirSpeedMPH = 576.43;
    //number of seats (int)
    int numSeats = 524;
    //fuel tank capacity (double)
    double fuelTankCapacityInLitres = 238840.04;
    //flight range (double)
    double flightRangeInKM = 14310.23;

    struct Cockpit
    {
        float age = 1.35f;
        int numSeats = 5;
        int numWindows = 4;
        bool hasBlackBox = true;
        bool ElectronicFlightInstrumentSystem = true;

        void increaseAirSpeed(float deltaV, float currentAirSpeed);
        void groundProximityWarningAlarm(bool nearGround, float proximityWarningThreshold);
        void autopilotDisengagement(bool pilotAndCopilotChecklistComplete);
    };


    //take off
    bool takeOffComplete(float groundSpeed, bool landingGear, bool armDoorsAndCrossCheck); //returns whether has this instance of Commercial Areoplane completed a successful take off
    //emergency landing
    void emergencyLanding(bool enginefailure, float urrentAirSpeed);
    //inflight entertainment
    void inflightEntertainment(int passengerSeatNumber, std::string movieSelction);
};

/*
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
*/

struct Player
{
    //body weight (float)
    float bodyMassKG = 101.34f;
    //sponsor (std:string)
    std::string sponsor = "Nike";
    //number of games played (int)
    int numGamesPlayed = 104;
    //scoring average (float)
    float scoringAverage = 1.78f;
    //name (std::string)
    std::string name = "Ronaldo";

    //run
    float getDistanceRun(int howFast, float howFar, bool startWithLeftFoot);
    //score
    void score(bool hasBall, bool inScoringPosition);
    //train
    void train(std::string trainingRequired, float fitnessScore);
};

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

struct Coach
{
    //name (std::string)
    std::string name;
    //years experience (int)
    int yearsExperience = 4;
    //trophies won (int)
    int numTrophiesWon = 2;
    //salary (double)
    double salary = 8078900.99;
    //inspiring (bool)
    bool inspiringn = false;

    //give motivational speech
    void deliverMotivationalSpeech(bool winningStreak);
    //lose job
    void getSacked(int numberOfGamesInLosingStreak);
    //give press conference
    void givePressConference(bool wonGame);
};

/*
Thing 7) Fan
5 properties:
    1) name (std::string)
    2) age (int)
    3) season ticket holder (bool)
    4) distance from stadium (double)
    5) fanclub member (bool)
3 things it can do:
    1) buy ticket to game
    2) cheer
    3) wear team colours
*/

struct Fan
{
    //name (std::string)
    std::string name = "John Johnson";
    //age (int)
    int age;
    //season ticket holder (bool)
    bool hasSeasonTicket = true;
    //distance from stadium (double)
    double distanceFromStadiumInKM = 345.78;
    //fanclub member (bool)
    bool fanclubMember = true;

    //buy ticket to game
    void purchseTicket(float ticketPrice, std::string opponentTeam);
    //cheer
    void cheer(bool teamScoredGoal);
    //wear team colours
    void wearTeamColours(bool teamWinningStreak);
};

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

struct Medic
{
    //qualifications (std::string)
    std::string qualifications;
    //name (std::string)
    std::string name = "The FA Level 4 Emergency Medical Management in Football";
    //salary (double)
    double salary = 178909.99;
    //explayer (bool)
    bool isExPlayer = true;
    //IT skills (bool)
    bool hasITSkills = true;

    //give steriod injection
    void giveSteriodInjection(Player player, std::string bodyPart, bool servePain);
    //massage treatment
    void giveMassageTreatment(Player player, std::string therapyTargetArea);
    //make fitness assessment
    float getFitnessAssessmentScore(int restingBPM, int maxBPM, float bloodPressure); //returns value of a players fitness assessment
};

/*
Thing 9) Stadium
5 properties:
    1) number of seats (int)
    2) pitch area (float)
    3) number of toilets (int)
    4) training pitch (bool)
    5) construction cost (double)
3 things it can do:
    1) host home game
    2) covid vaccination centre
    3) require maintance
*/

struct Stadium
{
    //number of seats (int)
    int numSeats = 62850;
    //pitch area (float)
    float pitchAreaInSqMetres = 7123.89f;
    //number of toilets (int)
    int numToilets = 66;
    //training pitch (bool)
    bool trainingPitch = true;
    //construction cost (double)
    double constructionCost = 1200500700.99;

    //host home game
    void homeGame(std::string nameVistingTeam);
    //covid vaccination centre
    bool covidVaccinationCentre(int numberOfUnvaccinated, float RNumber); //returns wheteher stadium is required to be vaccination centre
    //require maintance
    void maintance(bool brokenToilet);
};

/*
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
struct TeamCaptain //to prevent compile errors
{
    std::string name = "David Davison";
};
struct NumberOneFan //to prevent compile errors
{
    std::string name = "William Williamson";
};


struct SportsTeam
{
    //player
    Player player;
    //coach
    Coach coach;
    //fan
    NumberOneFan numberOneFan;
    //medic
    TeamCaptain TeamCaptain;
    //stadium
    Stadium stadium;

    //play home game
    bool winHomeGame(int goalsScoredFor, int goalsScoredAgainst); //returns whether the team have won the home game
    //play away game
    bool winAwayGame(int goalsScoredFor, int goalsScoredAgainst); //returns whether the team have won the away game
    //win championship
    bool winChampionship(int gamesPlayed, int gamesWon, int gamesLost, int gamesDrawn, int totalGoalsScoredFor, int totalGoalsScoredAgainst); //returns whether the team have won the championship
};


#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
