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
struct Person
{ 
    int age; 
    int height; 
    float hairLenght; 
    float GPA; 
    unsigned int SATScore; 
    float distanceTraveled; 

    struct Foot 
    { 
        int numToes = 5; 
        int numSteps = 0;
        float footLengthInCM = 23.5f;
        float normalStepLengthInCM = 43.7f;

        void stepForward();
        float stepSize(); 
    }; 

    Foot leftFoot;
    Foot rightFoot; 

    void run(float howFast, bool startWithLeftFoot);
}; 

void Person::Foot::stepForward()
{
    ++numSteps;
}

float Person::Foot::stepSize()
{
    return footLengthInCM + footLengthInCM;
}

void Person::run(float howFast, bool startWithLeftFoot) 
{
    //float leftFootStepAdjust = howFast * 0.3f;
    //float rightFootStepAdjust = howFast * 0.33f;
    if (startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();

    std::cout << "Distance travelled: " << distanceTraveled << std::endl;
    std::cout << "Speed: " << howFast << std::endl;
}

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

struct CoffeeShop
{
    int numChairs = 54;
    int numStaff = 7;
    int numToilets = 2;
    double annualProfit = 45362.78;
    float priceCoffee = 3.40f;

    struct Employee
    {
        std::string firstName = "Magnus";
        std::string lastName = "Magnusson";
        int employeeID = 12345;
        bool fullyTrained = false;
        float salary = 30000.00f;

        void makeDeliveries(float distTravelled, int numCustomers);
        void takeHoliday(int startDate, int endDate);
        bool deservesPromotion();
    };

    float hostLocalArtistOnWalls(float percenatgeCommissionAgreed, float totalArtSales, std::string name);
    float chargeCustomer(int numberOfCoffees, std::string customerName);
    void trainStaff(Employee employee, std::string trainingRequired);
};
void CoffeeShop::Employee::makeDeliveries(float distTravelled, int numCustomers)
{
    float aveDistancePerCustomer = distTravelled / numCustomers;
    std::cout << aveDistancePerCustomer;
}

void CoffeeShop::Employee::takeHoliday(int startDate, int endDate)
{
    int numDaysHolidayTaken = endDate - startDate;
    std::cout << "Days holiday taken by " << firstName << " " << lastName << numDaysHolidayTaken << std::endl;
}
bool CoffeeShop::Employee::deservesPromotion()
{
    if (fullyTrained)
    {
        salary += 1000;
        fullyTrained = true;
        return true;
    }
    return false;
}

float CoffeeShop::hostLocalArtistOnWalls(float percenatgeCommissionAgreed, float totalArtSales, std::string name)
{
    float commissionTotal = percenatgeCommissionAgreed * totalArtSales;
    std::cout << name << "commission total: " << commissionTotal << std::endl; 
    return commissionTotal;
}

float CoffeeShop::chargeCustomer(int numberOfCoffees, std::string customerName)
{
    float saleTotal = priceCoffee * numberOfCoffees;
    std::cout << customerName << "paid" << saleTotal << std::endl;
    return saleTotal;
}

void CoffeeShop::trainStaff(Employee employee, std::string trainingRequired)
{
    std::cout << employee.firstName << " " << employee.lastName << "has been trained on " << trainingRequired << std::endl;
    employee.fullyTrained = true;
}

struct School
{
    int numClassrooms = 111;
    int leagueTablePosition = 13;
    int numTeachers = 54;
    int numPupils = 1111;
    float aveGrade = 3.45f;

    void trainTeachers(bool internalTraining, std::string trainingRequired);
    void produceStudentsChristmasPlay(int numberOfStudentsInCast, std::string nameOfPlay, int rehearsalDays);
    void closeForHolidays(int howManyDaysClosed, std::string nameOfHoliday);
};

void School::trainTeachers(bool internalTraining, std::string trainingRequired)
{
    if (internalTraining)
    {
        std::cout << "Teachers trained on " << trainingRequired << std::endl;
        --leagueTablePosition;
    }
    
}

void School::produceStudentsChristmasPlay(int numberOfStudentsInCast, std::string nameOfPlay, int rehearsalDays)
{
    std::cout << "This years production of " << nameOfPlay << " was performed by " << numberOfStudentsInCast << ", it took " << rehearsalDays << "to perfect." << std::endl;
}

struct Farm
{
    int numSheep = 1234;
    int numCows = 321;
    int numFarmers = 6;
    float annualProfit = 679000.78f;
    double cropYield = 76543.21;
    double farmLandAreaInHectare = 84.3;
    
    float sellSheep(float priceOfSheep);
    double harvestCrop(bool isCropMature, int numFarmHands, bool machinesFueled, double priceOfCrop);
    void constructNewBarn(bool needNewBarn, float newConstructionBudget);
};
float Farm::sellSheep(float priceOfSheep)
{
    float sheepSale = priceOfSheep * numSheep;
    return sheepSale;
}

double Farm::harvestCrop(bool isCropMature, int numFarmHands, bool machinesFueled, double priceOfCrop)
{
    if (isCropMature && machinesFueled)
    {
        cropYield = farmLandAreaInHectare * numFarmHands;
        return priceOfCrop * cropYield; 
    }
    return 0;
}
void Farm::constructNewBarn(bool needNewBarn, float newConstructionBudget)
{
    if (needNewBarn)
    {
        annualProfit -= newConstructionBudget;
    }
    
}

struct CommercialAeroplane
{
    bool landingGearDown;
    int numEngines = 4;
    int numSeats = 524;
    float maxAirSpeedMPH = 576.43f;
    float speedRequiredForTakeOff = 213.56f;
    double fuelTankCapacityInLitres = 238840.04;
    double flightRangeInKM = 14310.23;

    struct Cockpit
    {
        float age = 1.35f;
        int numSeats = 5;
        int numWindows = 4;
        bool hasBlackBox = true;
        bool ElectronicFlightInstrumentSystem = true;
        bool groundProximityalarmStateOn;
        bool autoPilotLightOn = true;

        float increaseAirSpeed(float deltaV, float currentAirSpeed);
        bool groundProximityWarningAlarm(bool nearGround, float proximityWarningThreshold);
        bool autopilotDisengagement(bool pilotAndCopilotChecklistComplete);
    };

    void accelerateForTakeOff(float groundSpeed, bool armDoorsAndCrossCheck, bool runWayClear, bool airspaceClear);
    void transportPeople(int totalPassengers, int totalCrew);
    void provideInflightEntertainment(int passengerSeatNumber, std::string mediaSelction);  
};

float CommercialAeroplane::Cockpit::increaseAirSpeed(float deltaV, float currentAirSpeed)
{
return deltaV + currentAirSpeed;
}

bool CommercialAeroplane::Cockpit::groundProximityWarningAlarm(bool nearGround, float proximityWarningThreshold)
{
    if(nearGround == true && proximityWarningThreshold < 800)
    {
        groundProximityalarmStateOn = true;
    }
    else
    {
        groundProximityalarmStateOn = false;
    }
    return groundProximityalarmStateOn;
}
bool CommercialAeroplane::Cockpit::autopilotDisengagement(bool pilotAndCopilotChecklistComplete)
{
    if (pilotAndCopilotChecklistComplete)
    {
        autoPilotLightOn = false;
    }
    else
    {
        autoPilotLightOn = true;
    }
    return autoPilotLightOn;
}

void CommercialAeroplane::accelerateForTakeOff(float groundSpeed, bool armDoorsAndCrossCheck, bool runWayClear, bool airspaceClear)
{
    if (runWayClear && armDoorsAndCrossCheck && airspaceClear)
    {
        std::cout << "Clear for take off" << std::endl;

        if (groundSpeed > speedRequiredForTakeOff)
        {
            landingGearDown = false;
        }
    }
}

void CommercialAeroplane::transportPeople(int totalPassengers, int totalCrew)
{
    std::cout << "Total number on board: " << totalPassengers + totalCrew << std::endl;
}
void CommercialAeroplane::provideInflightEntertainment(int passengerSeatNumber, std::string mediaSelction)
{
    std::cout << "Passenger " << passengerSeatNumber << " selected " << mediaSelction << std::endl;
}

struct Player
{
    float bodyMassKG = 101.34f;
    std::string sponsor = "Nike";
    int numGamesPlayed = 104;
    float scoringAverage = 1.78f;
    std::string name = "Ronaldo";

    float run(int howFast, float howFar, bool startWithLeftFoot);
    void score(bool hasBall, bool inScoringPosition);
    void train(std::string trainingRequired, float fitnessScore);
};
float Player::run(int howFast, float howFar, bool startWithLeftFoot)
{
    float speed = 0;
    float energyUsed = 0;

    if (startWithLeftFoot)
    {
        speed = howFar / howFast;
        energyUsed = speed * bodyMassKG;
    }
    return energyUsed;
}

void Player::score(bool hasBall, bool inScoringPosition)
{
    if (hasBall && inScoringPosition)
    {
        std::cout << "Goal scored" << std::endl;
    }
}

void Player::train(std::string trainingRequired, float fitnessScore)
{
    std::cout << name << " completed " << trainingRequired << std::endl;
    fitnessScore += 1;
}

struct Coach
{
    std::string name;
    int yearsExperience = 4;
    int numTrophiesWon = 2;
    double salary = 8078900.99;
    bool inspiringn = false;

    void deliverMotivationalSpeech(bool winningStreak);
    void loseJob(int numberOfGamesInLosingStreak);
    void givePressConference(bool wonGame);
};

void deliverMotivationalSpeech(bool winningStreak)
{
    if (winningStreak == false)
    {
        std::cout << "No one will deny me, no one will define me. And no one will tell me who and what I am and can be. Belief will change my world.";
    } 
}

void Coach::loseJob(int numberOfGamesInLosingStreak)
{
    if (numberOfGamesInLosingStreak > 6)
    {
        std::cout << "You're Fired" << std::endl;
    }

}
void givePressConference(bool wonGame)
{
    if (wonGame)
    {
        std::cout << "It's a game of two halves, and we were the better team in both of them" << std::endl;
    }

}

struct Fan
{
    std::string name = "John Johnson";
    int age;
    bool hasSeasonTicket = true;
    double distanceFromStadiumInKM = 345.78;
    bool fanclubMember = true;

    void buyTicketToGame(float ticketPrice, std::string opponentTeam);
    void cheer(bool teamScoredGoal);
    void wearTeamColours(bool teamWinningStreak);
};

void Fan::buyTicketToGame(float ticketPrice, std::string opponentTeam)
{
    std::cout << name << "purchased ticket to " << opponentTeam << ". Price: £" << ticketPrice << std::endl;
}

void Fan::cheer(bool teamScoredGoal)
{
    if (teamScoredGoal)
    {
        std::cout << "Wooohooo, goal!";
    }
}

void Fan::wearTeamColours(bool teamWinningStreak)
{
    if (teamWinningStreak)
    {
        fanclubMember = true;
        hasSeasonTicket = true;
        std::cout << name << "purchased a team shirt" << std::endl;
    }
}

struct Medic
{
    std::string qualifications;
    std::string name = "The FA Level 4 Emergency Medical Management in Football";
    double salary = 178909.99;
    bool isExPlayer = true;
    bool hasITSkills = true;

    void giveSteriodInjection(std::string player, std::string bodyPart, bool servePain);
    void giveMassageTreatment(std::string player, std::string therapyTargetArea);
    float provideFitnessAssessmentScore(int restingBPM, int maxBPM, int bloodPressure);
};
void Medic::giveSteriodInjection(std::string player, std::string bodyPart, bool severePain)
{
    if (severePain)
    {
        std::cout << player << "received steriod injection to " << bodyPart << std::endl;
    }

}

void Medic::giveMassageTreatment(std::string player, std::string therapyTargetArea)
{
    std::cout << player << " received massage treatment to " << therapyTargetArea << std::endl;
}

float Medic::provideFitnessAssessmentScore(int restingBPM, int maxBPM, int bloodPressure)
{
    int scoreRestingBPM = 0;
    int scoreMaxBPM = 0;
    int scoreBloodPressure = 0;

    if (50 < restingBPM && restingBPM < 100)
    {
        scoreRestingBPM = 1;
    }
    else if (100 <= restingBPM && restingBPM < 120)
    {
        scoreRestingBPM = 2;
    }
    else
    {
        scoreRestingBPM = 3;
    }

    if (150 < maxBPM && maxBPM < 190)
    {
        scoreMaxBPM = 1;
    }
    else if (190 <= maxBPM && maxBPM < 210)
    {
        scoreMaxBPM = 2;
    }
    else
    {
        scoreMaxBPM = 3;
    }

    if (90 < bloodPressure && bloodPressure < 120)
    {
        scoreBloodPressure = 1;
    }
    else if (120 <= bloodPressure && bloodPressure < 160)
    {
        scoreBloodPressure = 2;
    }
    else
    {
        scoreBloodPressure = 3;
    }

    return scoreRestingBPM + scoreMaxBPM + scoreBloodPressure;
}

struct Stadium
{
    int numSeats = 62850;
    float pitchAreaInSqMetres = 7123.89f;
    int numToilets = 66;
    bool trainingPitch = true;
    double constructionCost = 1200500700.99;

    void hostHomeGame(std::string nameVisitingTeam);
    bool provideCovidVaccinationCentre(int numberOfUnvaccinated, float RNumber);
    void maintance(bool brokenToilet);
};

void Stadium::hostHomeGame(std::string nameVisitingTeam)
{
    std::cout << "Welcome " << nameVisitingTeam << std::endl;
}

bool Stadium::provideCovidVaccinationCentre(int numberOfUnvaccinated, float RNumber)
{
    if (numberOfUnvaccinated > 10000 && RNumber > 1.5f)
    {
        return true; 
    }
    return false;
}

void Stadium::maintance(bool brokenToilet)
{
    if (brokenToilet)
    {
        std::cout << "Call maintainance to toilet" << std::endl;
    }
}

struct SportsTeam
{
    Player TeamCaptain;
    Coach coach;
    Fan numberOneFan;
    Medic bestMedic;
    Stadium stadium;

    bool winHomeGame(int goalsScoredFor, int goalsScoredAgainst);
    bool winAwayGame(int goalsScoredFor, int goalsScoredAgainst);
    bool winChampionship(int gamesPlayed, int gamesWon, int gamesLost, int gamesDrawn, int totalGoalsScoredFor, int totalGoalsScoredAgainst);
};

bool SportsTeam::winHomeGame(int goalsScoredFor, int goalsScoredAgainst)
{
    if (goalsScoredFor > goalsScoredAgainst)
    {
    std::cout << "We win home game" << std::endl;
    return true;
    }
    return false;
}

bool SportsTeam::winAwayGame(int goalsScoredFor, int goalsScoredAgainst)
{
    if (goalsScoredFor > goalsScoredAgainst)
    {
    std::cout << "We win away game" << std::endl;
    return true;
    }
    return false;
}

bool SportsTeam::winChampionship(int gamesPlayed, int gamesWon, int gamesLost, int gamesDrawn, int totalGoalsScoredFor, int totalGoalsScoredAgainst)
{
    if (gamesPlayed >= 38)
    {
        if (gamesWon > gamesLost && gamesDrawn < 19 && totalGoalsScoredFor > totalGoalsScoredAgainst)
            {
                std::cout << "We won the championship" << std::endl;
                return true;
            }
    }    
    return false;
}

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
