/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct CoffeeShop
{
    int numChairs = 54;
    int numStaff = 7;
    int numToilets = 2;
    float annualProfit = 45362.78f;
    float priceCoffee = 3.40f;
    CoffeeShop();

    struct Employee
    {
        std::string firstName = "Magnus";
        std::string lastName = "Magnusson";
        int employeeID = 12345;
        bool fullyTrained = false;
        float salary = 30000.00f;
        float deliveryDistTravelled;
        int deliveryNumCustomers;
        Employee();

        void makeDeliveries(float distTravelled, int numCustomers);
        void takeHoliday(int startDate, int endDate);
        bool deservesPromotion();
    };

    float hostLocalArtistOnWalls(float percenatgeCommissionAgreed, float totalArtSales, std::string name);
    float chargeCustomer(int numberOfCoffees, std::string customerName);
    bool trainStaff(Employee employee, std::string trainingRequired);
};

CoffeeShop::CoffeeShop()
{
    std::cout << "\nCoffeeShop being constructed!" << std::endl;
}

CoffeeShop::Employee::Employee()
{
    std::cout << "\nEmployee being constructed!" << std::endl;
}

void CoffeeShop::Employee::makeDeliveries(float distTravelled, int numCustomers)
{
    float aveDistancePerCustomer = distTravelled / numCustomers;
    std::cout << "Number of kilometers per customer: " << aveDistancePerCustomer << " km" << std::endl;
    deliveryDistTravelled = distTravelled;
    deliveryNumCustomers = numCustomers;
}

void CoffeeShop::Employee::takeHoliday(int startDate, int endDate)
{
    int numDaysHolidayTaken = endDate - startDate;
    std::cout << numDaysHolidayTaken << " days holiday taken by " << firstName << " " << lastName << std::endl;
}

bool CoffeeShop::Employee::deservesPromotion()
{
    if (fullyTrained)
    {
        std::cout << firstName << " " << lastName << " deserves a promotion!" << std::endl;
        salary += 1000;
        return true;
    }
    return false;
}

float CoffeeShop::hostLocalArtistOnWalls(float percenatgeCommissionAgreed, float totalArtSales, std::string name)
{
    float commissionTotal = percenatgeCommissionAgreed * totalArtSales;
    std::cout << name << " commission total: £" << commissionTotal << std::endl; 
    return commissionTotal;
}

float CoffeeShop::chargeCustomer(int numberOfCoffees, std::string customerName)
{
    float saleTotal = priceCoffee * numberOfCoffees;
    std::cout << customerName << " paid £" << saleTotal << std::endl;
    return saleTotal;
}

bool CoffeeShop::trainStaff(Employee employee, std::string trainingRequired)
{
    std::cout << employee.firstName << " " << employee.lastName << " has been trained on " << trainingRequired << std::endl;
    return true;
}

struct School
{
    int numClassrooms = 111;
    int leagueTablePosition = 13;
    int numTeachers = 54;
    int numPupils = 1111;
    float aveGrade = 3.45f;
    School();

    void trainTeachers(bool internalTraining, std::string trainingRequired);
    void produceStudentsChristmasPlay(int numberOfStudentsInCast, std::string nameOfPlay, int rehearsalDays);
    void closeForHolidays(int howManyDaysClosed, std::string nameOfHoliday);
};

School::School()
{
   std::cout << "\nSchool being constructed!" << std::endl;
}

void School::trainTeachers(bool internalTraining, std::string trainingRequired)
{
    if (internalTraining)
    {
        std::cout << "Teachers internally trained on " << trainingRequired << std::endl;
        --leagueTablePosition;
    }
    else
    {
                std::cout << "Teachers externally trained on " << trainingRequired << std::endl;
        --leagueTablePosition;
    }
    
}

void School::produceStudentsChristmasPlay(int numberOfStudentsInCast, std::string nameOfPlay, int rehearsalDays)
{
    std::cout << "This years school production of " << nameOfPlay << " was performed by " << numberOfStudentsInCast << ",pupils, it took " << rehearsalDays << " days rehearsal to perfect." << std::endl;
}

struct Farm
{
    int numSheep = 1234;
    int numCows = 321;
    int numFarmers = 6;
    float annualProfit = 679000.78f;
    float annualExpenses = 0;
    double cropYield = 76543.21;
    double farmLandAreaInHectare = 84.3;
    Farm();

    float sellSheep(float priceOfSheep);
    double harvestCrop(bool isCropMature, int numFarmHands, bool machinesFueled, double priceOfCrop);
    void constructNewBarn(bool needNewBarn, float newConstructionBudget);
};

Farm::Farm()
{
       std::cout << "\nFarm being constructed!" << std::endl;
}

float Farm::sellSheep(float priceOfSheep)
{
    float sheepSale = priceOfSheep * numSheep;
    std::cout << "The farm made £" << sheepSale << " from the sale of " << numSheep << " sheep!" << std::endl;
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
        annualExpenses = newConstructionBudget;
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
    CommercialAeroplane();

    struct Cockpit
    {
        float age = 1.35f;
        int numSeats = 5;
        int numWindows = 4;
        float proximityWarningThreshold = 1200.00f;
        bool hasBlackBox = true;
        bool ElectronicFlightInstrumentSystem = true;
        bool groundProximityalarmStateOn;
        bool autoPilotLightOn = true;
        Cockpit();

        float increaseAirSpeed(float deltaV, float currentAirSpeed);
        bool groundProximityWarningAlarm(bool nearGround, float proximityWarningThreshold);
        bool autopilotDisengagement(bool pilotAndCopilotChecklistComplete);
    };

    void accelerateForTakeOff(float groundSpeed, bool armDoorsAndCrossCheck, bool runWayClear, bool airspaceClear);
    void transportPeople(int totalPassengers, int totalCrew);
    void provideInflightEntertainment(int passengerSeatNumber, std::string mediaSelction);  
};

CommercialAeroplane::CommercialAeroplane()
{
    std::cout << "\nCommercialAeroplane being constructed!" << std::endl;
}

CommercialAeroplane::Cockpit::Cockpit()
{
    std::cout << "\nCockpit being constructed!" << std::endl;
}

float CommercialAeroplane::Cockpit::increaseAirSpeed(float deltaV, float currentAirSpeed)
{
    return deltaV + currentAirSpeed;
}

bool CommercialAeroplane::Cockpit::groundProximityWarningAlarm(bool nearGround, float distFromGround)
{
    if(nearGround == true && distFromGround < proximityWarningThreshold)
    {
        groundProximityalarmStateOn = true;
        std::cout << "Warning! Pull Up! Warning! Pull Up!" << std::endl;
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
        std::cout << "Autopilot disengaged" << std::endl;
    }
    else
    {
        autoPilotLightOn = true;
        std::cout << "Autopilot engaged" << std::endl;
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
    Player();

    float run(int howFast, float howFar, bool startWithLeftFoot);
    void score(bool hasBall, bool inScoringPosition);
    void train(std::string trainingRequired, float fitnessScore);
};

Player::Player()
{
    std::cout << "\nPlayer being constructed!" << std::endl;
}

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
    Coach();

    void deliverMotivationalSpeech(bool winningStreak);
    void loseJob(int numberOfGamesInLosingStreak);
    void givePressConference(bool wonGame);
};

Coach::Coach()
{
    std::cout << "\nCoach being constructed!" << std::endl;
}

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
    Fan();

    void buyTicketToGame(float ticketPrice, std::string opponentTeam);
    void cheer(bool teamScoredGoal);
    void wearTeamColours(bool teamWinningStreak);
};

Fan::Fan()
{
    std::cout << "\nFan being constructed!" << std::endl;
}

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
    Medic();

    void giveSteriodInjection(std::string player, std::string bodyPart, bool servePain);
    void giveMassageTreatment(std::string player, std::string therapyTargetArea);
    float provideFitnessAssessmentScore(int restingBPM, int maxBPM, int bloodPressure);
};

Medic::Medic()
{
    std::cout << "\nMedic being constructed!" << std::endl;
}

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
    Stadium();

    void hostHomeGame(std::string nameVisitingTeam);
    bool provideCovidVaccinationCentre(int numberOfUnvaccinated, float RNumber);
    void maintance(bool brokenToilet);
};

Stadium::Stadium()
{
    std::cout << "\nStadium being constructed!" << std::endl;
}

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
    SportsTeam();

    bool winHomeGame(int goalsScoredFor, int goalsScoredAgainst);
    bool winAwayGame(int goalsScoredFor, int goalsScoredAgainst);
    bool winChampionship(int gamesPlayed, int gamesWon, int gamesLost, int gamesDrawn, int totalGoalsScoredFor, int totalGoalsScoredAgainst);
};

SportsTeam::SportsTeam()
{
    std::cout << "\nSportsTeam being constructed!" << std::endl;
}

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
    Example::main();
    
    std::cout << "good to go!" << std::endl;

    CoffeeShop coffeeShop;
    coffeeShop.chargeCustomer(3, "Jennifer Aniston");
    std::cout << "Each coffee cost £" << coffeeShop.priceCoffee << std::endl;

    coffeeShop.annualProfit += coffeeShop.hostLocalArtistOnWalls(0.1f, 3214.51f, "Banksy");
    std::cout << "This has added funds to the total annual profit, which is now £" << coffeeShop.annualProfit  << std::endl;

    CoffeeShop::Employee employee;
    employee.fullyTrained = coffeeShop.trainStaff(employee, "Milk frothing");
    std::cout << "Is employee number: " << employee.employeeID << " " << employee.firstName << " " << employee.lastName << " fully trained? " << (employee.fullyTrained == 0 ? "No" : "Yes") << std::endl;

    employee.deservesPromotion();

    employee.takeHoliday(156, 167);

    employee.makeDeliveries(13, 12);
    std::cout << employee.firstName << " " << employee.lastName << " made deliveries to " << employee.deliveryNumCustomers << " customers over " << employee.deliveryDistTravelled << " km" << std::endl;

    School school;
    school.trainTeachers(false, "SEN");

    school.produceStudentsChristmasPlay(44, "Peter Pan", 20);

    Farm farm;
    farm.sellSheep(12.11f);

    std::cout << "The farm made income of £" << farm.harvestCrop(true, 4, true, 1.30) << " from this years harvest." << std::endl;
   
    farm.constructNewBarn(true, 12345.45f);
    std::cout << "The farm has spent £" << farm.annualExpenses << " this year. It's remaining profit is £" << farm.annualProfit <<  "." << std::endl;

    CommercialAeroplane commercialAeroplane;
    commercialAeroplane.accelerateForTakeOff(278, true, true, true);
    commercialAeroplane.provideInflightEntertainment(234, "Love Actually");
    commercialAeroplane.transportPeople(156, 7);

    CommercialAeroplane::Cockpit cockpit;
    cockpit.autopilotDisengagement(true);
    cockpit.groundProximityWarningAlarm(true, 200);
    std::cout << "You are within " << cockpit.proximityWarningThreshold << " metres of the ground!" << std::endl;
}
