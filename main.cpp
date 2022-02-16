 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */


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
    float hostLocalArtistOnWalls(float percenatgeCommisionAgreed, float totalArtSales, CoffeeShop coffeeshop); //returns the total value of commission earn from the sale of all the art at this instance of CoffeeShop 
    //charge customer
    float chargeCustomer(float priceCoffee, int numberOfCoffees, int customerNumber); //returns the total value of the sale of all good for this customer
    //train staff
    void trainStaff(Employee employee, std::string trainingRequired);
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
    2) produce students christmas play
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
    void trainTeachers(bool internalTraining, std::string trainingRequired);
    //produce students christmas play
    void produceStudentsChristmasPlay(int numberOfStudentsInCast, std::string nameOfPlay, int rehearsalDays);
    //close for holidays
    void closeForHolidays(int howManyDaysClosed, std::string nameOfHoliday);
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
    float sellSheep(float priceOfSheep, int numSheep); //returns the income from the sale of this farms sheep
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

    //accelerate for take off
    bool accelerateForTakeOff(float groundSpeed, bool landingGear, bool armDoorsAndCrossCheck, bool runWayClear, bool airspaceClear); //returns whether has this instance of Commercial Areoplane can go for takeoff
    //transportPeople
    void transportPeople(int totalPassengers, int totalCrew);
    //provide inflight entertainment
    void provideInflightEntertainment(int passengerSeatNumber, std::string mediaSelction);  
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
    float run(int howFast, float howFar, bool startWithLeftFoot);
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
    void loseJob(int numberOfGamesInLosingStreak);
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
    void butTicketToGame(float ticketPrice, std::string opponentTeam);
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
    //provide fitness assessment
    float provideFitnessAssessmentScore(int restingBPM, int maxBPM, float bloodPressure); //returns value of a players fitness assessment
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
    void hostHomeGame(std::string nameVistingTeam);
    //provide covid vaccination centre
    bool provideCovidVaccinationCentre(int numberOfUnvaccinated, float RNumber); //returns wheteher stadium is required to be vaccination centre
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

struct SportsTeam
{
    //player
    Player TeamCaptain;
    //coach
    Coach coach;
    //fan
    Fan numberOneFan;
    //medic
    Medic bestMedic;
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
