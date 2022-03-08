/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; // in-class initialization
    UDT() : a(0) { } // 'constructor-initializer-list' member variable initialization
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()



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
    float speed = 0.0f;
    float energyUsed = 0.0f;
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
    std::cout << name << " completed " << trainingRequired << " training"<< std::endl;
    fitnessScore += 1;
}

struct Coach
{
    std::string name;
    int yearsExperience = 4;
    int numTrophiesWon = 2;
    double salary = 8078900.99;
    bool inspiring = false;
    Coach();

    void deliverMotivationalSpeech(bool winningStreak);
    void loseJob(int numberOfGamesInLosingStreak);
    void givePressConference(bool wonGame);
};

Coach::Coach()
{
    std::cout << "\nCoach being constructed!" << std::endl;
}

void Coach::deliverMotivationalSpeech(bool winningStreak)
{
    if (winningStreak == false)
    {
        std::cout << "No one will deny me, no one will define me. And no one will tell me who and what I am and can be. Belief will change my world." << std::endl;
    } 
}

void Coach::loseJob(int numberOfGamesInLosingStreak)
{
    if (numberOfGamesInLosingStreak > 6)
    {
        std::cout << "You're Fired" << std::endl;
    }

}

void Coach::givePressConference(bool wonGame)
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
    std::cout << name << " purchased ticket to " << opponentTeam << ". Price: £" << ticketPrice << std::endl;
}

void Fan::cheer(bool teamScoredGoal)
{
    if (teamScoredGoal)
    {
        std::cout << "Wooohooo, goal!"<< std::endl;
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
        std::cout << player << " received steriod injection to " << bodyPart << std::endl;
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
        std::cout << "Stadium is require to be vaccination centre" << std::endl;
        return true;    
    }
    std::cout << "Stadium is not require to be vaccination centre" << std::endl;
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
    std::cout << "We lose home game" << std::endl;
    return false;
}

bool SportsTeam::winAwayGame(int goalsScoredFor, int goalsScoredAgainst)
{
    if (goalsScoredFor > goalsScoredAgainst)
    {
        std::cout << "We win away game" << std::endl;
        return true;
    }
    std::cout << "We lose away game" << std::endl;
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
    std::cout << "New airspeed is " << cockpit.increaseAirSpeed(122.1f, 345.f) << " mph" << std::endl;

    Player player;
    player.run(10, 100, true);
    std::cout << "The player ran at " << player.speed << " m/s" << std::endl;
    player.score(true, true);
    player.train("strength", 3.2f);

    Coach coach;
    coach.deliverMotivationalSpeech(false);
    coach.loseJob(8);
    coach.givePressConference(true);

    Fan fan;
    fan.buyTicketToGame(32.45f, "Chelsea");
    fan.cheer(true);
    fan.wearTeamColours(true);

    Medic medic;
    medic.giveSteriodInjection("David Davidson", "knee", true);
    medic.giveMassageTreatment("David Davidson", "shoulder");
    std::cout << "Fitness assement score: " << medic.provideFitnessAssessmentScore(70, 180, 90) << std::endl;

    Stadium stadium;
    stadium.hostHomeGame("Chelsea");
    stadium.provideCovidVaccinationCentre(20000, 1.7f);
    stadium.maintance(true); 

    SportsTeam sportsTeam;
    sportsTeam.winHomeGame(3, 5);
    sportsTeam.winAwayGame(5,3);
    sportsTeam.winChampionship(38, 28, 10, 0, 56, 22);
    
}
