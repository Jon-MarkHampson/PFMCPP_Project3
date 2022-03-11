/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





struct CoffeeShop
{
    int numChairs;
    int numStaff;
    int numToilets;
    float annualProfit {45362.78f};
    float annualSales {345678.9f};
    float priceCoffee {3.40f};
    CoffeeShop();

    struct Employee
    {
        std::string firstName {"Magnus"};
        std::string lastName {"Magnusson"};
        int employeeID = 12345;
        bool fullyTrained = false;
        float salary = 30000.00f;
        float deliveryDistTravelled;
        int deliveryNumCustomers;
        Employee();

        void makeDeliveries(float distTravelled, int numCustomers);
        void takeHoliday(int startDate, int endDate);
        bool deservesPromotion();
        void takeOutTrash(int bagsOfTrash, int numBagsEmployeeCanCarry);
    };

    float hostLocalArtistOnWalls(float percenatgeCommissionAgreed, float totalArtSales, std::string name);
    float chargeCustomer(int numberOfCoffees, std::string customerName);
    bool trainStaff(Employee employee, std::string trainingRequired);
    float addDailyTakingsToAnnualProfit(int numCoffeesSold, float totalFromAdditionalSales);

};

CoffeeShop::CoffeeShop() : numChairs(54), numStaff(7), numToilets(2)
{
    std::cout << "\nCoffeeShop being constructed!" << std::endl;
}

CoffeeShop::Employee::Employee() : employeeID(12345), fullyTrained(false), salary(30000.00f), deliveryDistTravelled(0.f), deliveryNumCustomers(0)
{
    std::cout << "\nEmployee being constructed!" << std::endl;
}

void CoffeeShop::Employee::makeDeliveries(float distTravelled, int numCustomers)
{
    float aveDistancePerCustomer = distTravelled / numCustomers;
    std::cout << "Employee number: " << employeeID << " made some deliveries. Number of kilometers per customer: " << aveDistancePerCustomer << " km" << std::endl;
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

void CoffeeShop::Employee::takeOutTrash(int bagsOfTrash, int numBagsEmployeeCanCarry)
{
    int numOfTripsToDumpster = 0;
    for (int i = 0; i < bagsOfTrash/numBagsEmployeeCanCarry; ++i)
        {
            std::cout << firstName << " " << lastName << " took " << numBagsEmployeeCanCarry << " bags to the dumpster" << std::endl;
            ++numOfTripsToDumpster;
        }
    if (bagsOfTrash%numBagsEmployeeCanCarry != 0)
    {
        std::cout << firstName << " " << lastName << " took " << bagsOfTrash%numBagsEmployeeCanCarry << " bags to the dumpster" << std::endl;
        ++numOfTripsToDumpster;
    }
    std::cout << firstName << " " << lastName << " made a total of " << numOfTripsToDumpster << " trips to the dumpster" << std::endl;

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

float CoffeeShop::addDailyTakingsToAnnualProfit(int numCoffeesSold, float totalFromAdditionalSales)
{
    float dailySalesTotal {0};
    for (int i = 0; i < numCoffeesSold; ++i)
        {
            dailySalesTotal += priceCoffee;
        }
    dailySalesTotal += totalFromAdditionalSales;
    annualSales += dailySalesTotal;
    std::cout << "Daily sales total is £" << dailySalesTotal << std::endl;
    std::cout << "New annual sales total is £" << annualSales << std::endl;
    return dailySalesTotal;
}
struct School
{
    int numClassrooms;
    int leagueTablePosition;
    int numTeachers;
    int numPupils;
    float aveGrade {3.45f};
    School();

    void trainTeachers(bool internalTraining, std::string trainingRequired);
    void produceStudentsChristmasPlay(int numberOfStudentsInCast, std::string nameOfPlay, int rehearsalDays);
    void closeForHolidays(int howManyDaysClosed, std::string nameOfHoliday);
    void cleanClassrooms(int numClassroomsNeedCleaning);
};

School::School() : numClassrooms(111), leagueTablePosition(13), numTeachers(54), numPupils(1111)
{
    std::cout << "\nSchool being constructed!" << std::endl;
}

void School::trainTeachers(bool internalTraining, std::string trainingRequired)
{
    std::cout << "Current league table positaion: " << leagueTablePosition << std::endl;
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
       std::cout << "New league table positaion: " << leagueTablePosition << std::endl;
}

void School::produceStudentsChristmasPlay(int numberOfStudentsInCast, std::string nameOfPlay, int rehearsalDays)
{
    std::cout << "This years school production of " << nameOfPlay << " was performed by " << numberOfStudentsInCast << ",pupils, it took " << rehearsalDays << " days rehearsal to perfect." << std::endl;
}

void School::cleanClassrooms(int numClassroomsNeedCleaning)
{
    for (int i = 1; i < (numClassroomsNeedCleaning + 1); ++i)
        {
            std::cout << "Classroom " << i << " chairs are stacked on tables and the floor has been cleaned" << std::endl;
        }
}

struct Farm
{
    int numSheep {1234};
    int numCows {321};
    int numFarmers {6};
    float annualProfit;
    float annualExpenses;
    double cropYield;
    double farmLandAreaInHectare;
    Farm();

    float sellSheep(float priceOfSheep);
    double harvestCrop(bool isCropMature, int numFarmHands, bool machinesFueled, double priceOfCrop);
    void constructNewBarn(bool needNewBarn, float newConstructionBudget);
    void milkCows(int totalVolumeOfMilkNeeded, float volumeOfMilkAlreadyInTanks, float priceOfMilk);
};

Farm::Farm() : annualProfit(679000.78f), annualExpenses(0), cropYield (76543.21), farmLandAreaInHectare (84.3)
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
    std::cout << "The farm has " << numSheep << " sheep, " << numCows << " cows, " << "and a crop yield of " << cropYield << "." << std::endl;
    if (needNewBarn)
    {
        annualExpenses = newConstructionBudget;
        annualProfit -= newConstructionBudget;
    }
    
}
void Farm::milkCows(int totalVolumeOfMilkNeeded, float volumeOfMilkAlreadyInTanks, float priceOfMilk)
{
    while (volumeOfMilkAlreadyInTanks < totalVolumeOfMilkNeeded)
        {
            std::cout <<  "Milking in progress" << std::endl;
            volumeOfMilkAlreadyInTanks += 10;
        }
    std::cout << "Achieved total volume of milk needed: " << totalVolumeOfMilkNeeded << std::endl;
    std::cout << "Value of milk: £" << totalVolumeOfMilkNeeded * priceOfMilk << std::endl;
}
struct CommercialAeroplane
{
    bool landingGearDown {false};
    int numEngines {4};
    int numSeats {524};
    float maxAirSpeedMPH {576.43f};
    float speedRequiredForTakeOff {213.56f};
    double fuelTankCapacityInLitres {238840.04};
    double flightRangeInKM {14310.23};
    CommercialAeroplane();

    struct Cockpit
    {
        float age;
        int numSeats;
        int numWindows;
        float proximityWarningThreshold;
        float altitude;
        bool hasBlackBox;
        bool ElectronicFlightInstrumentSystem;
        bool groundProximityalarmStateOn;
        bool autoPilotLightOn;
        Cockpit();

        float increaseAirSpeed(float deltaV, float currentAirSpeed);
        bool groundProximityWarningAlarm(bool nearGround, float proximityWarningThreshold);
        bool autopilotDisengagement(bool pilotAndCopilotChecklistComplete);
        void increaseAltitude(float requireAltitude);
    };

    void accelerateForTakeOff(float groundSpeed, bool armDoorsAndCrossCheck, bool runWayClear, bool airspaceClear);
    void increaseGroundSpeed(float windSpeed);
    void transportPeople(int totalPassengers, int totalCrew);
    void provideInflightEntertainment(int passengerSeatNumber, std::string mediaSelction);  
};

CommercialAeroplane::CommercialAeroplane()
{
    std::cout << "\nCommercialAeroplane being constructed!" << std::endl;
}

CommercialAeroplane::Cockpit::Cockpit() : age(1.35f), numSeats(5), numWindows(4), proximityWarningThreshold(1200.00f), altitude(10000.00f), hasBlackBox(true), ElectronicFlightInstrumentSystem(true), groundProximityalarmStateOn(false), autoPilotLightOn(true)
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
    std::cout << "Autopilot currently engaged?: " << autoPilotLightOn << std::endl;
    if (pilotAndCopilotChecklistComplete)
    {
        autoPilotLightOn = false;
        std::cout << "Pilot and copilot checklist complete" << std::endl;
        std::cout << "Autopilot disengaged" << std::endl;
    }
    else
    {
        autoPilotLightOn = true;
        std::cout << "Autopilot engaged" << std::endl;
    }
    return autoPilotLightOn;
}

void CommercialAeroplane::Cockpit::increaseAltitude(float requireAltitude)
{
    while (altitude < requireAltitude)
        {
            altitude += 100;
        }
    std::cout << "New altitude of " << altitude << "ft achieved" << std::endl;
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

void CommercialAeroplane::increaseGroundSpeed(float windSpeed)
{
    float currentGroundSpeed {0.0f};
    while (currentGroundSpeed < speedRequiredForTakeOff - windSpeed)
        {
            currentGroundSpeed += 15;
        }
    std::cout << "Speed for take off achieved... Take Off" << std::endl;
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
    float bodyMassKG {101.34f};
    float speed {0.0f};
    float energyUsed {0.0f};
    std::string sponsor;
    int numGamesPlayed;
    float scoringAverage;
    std::string name;
    Player();

    float run(int howFast, float howFar, bool startWithLeftFoot);
    void score(bool hasBall, bool inScoringPosition);
    void train(std::string trainingRequired, float fitnessScore);
    void loseWeight(float requiredNewBodyMassKg);
};

Player::Player() : sponsor("Nike"), numGamesPlayed(104), scoringAverage(1.78f), name("Ronaldo")
{
    std::cout << "\nPlayer being constructed!" << std::endl;
}

float Player::run(int howFast, float howFar, bool startWithLeftFoot)
{
    std::cout << "This run was sponsored by " << sponsor << std::endl;
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
        std::cout << name << " scored!" << std::endl;
    }
}

void Player::train(std::string trainingRequired, float fitnessScore)
{
    std::cout << name << " completed " << trainingRequired << " training"<< std::endl;
    fitnessScore += 1;
}

void Player::loseWeight(float requiredNewBodyMassKg)
{
    float oldBodyMassKG = bodyMassKG;
    while (bodyMassKG > requiredNewBodyMassKg)
        {
            bodyMassKG -= 0.5f;
        }
    std::cout << name << " lost " << oldBodyMassKG - bodyMassKG << "kg" << std::endl;
    std::cout << "New body mass: " << bodyMassKG << "kg" << std::endl;
}

struct Coach
{
    std::string name {"Roman Abramovich"};
    int yearsExperience {4};
    int numTrophiesWon;
    double salary;
    bool inspiring;
    Coach();

    void deliverMotivationalSpeech(bool winningStreak);
    void loseJob(int numberOfGamesInLosingStreak);
    void givePressConference(bool wonGame);
    void buyPlayers(int playerBudget, int costOfPlayer);
};

Coach::Coach() : numTrophiesWon(2), salary(8078900.99), inspiring(false)
{
    std::cout << "\nCoach being constructed!" << std::endl;
}

void Coach::deliverMotivationalSpeech(bool winningStreak)
{
    std::cout << name << " winner of " << numTrophiesWon << " trophies, is about to give a speech:" <<std::endl;
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

void Coach::buyPlayers(int playerBudget, int costOfPlayer)
{
    int moneySpentOnPlayers {0};
    int numPlayersPurchased = playerBudget/costOfPlayer;
    for ( int i = 0; i < numPlayersPurchased; ++i)
        {
            moneySpentOnPlayers += costOfPlayer;
        }
    std::cout << "Money spent on players £" << moneySpentOnPlayers << std::endl;
    std::cout << "Number of players purchased :" << numPlayersPurchased << std::endl;
}
    
struct Fan
{
    std::string name;
    int age;
    bool hasSeasonTicket;
    double distanceFromStadiumInKM {345.78};
    bool fanclubMember {true};
    Fan();

    void buyTicketToGame(float ticketPrice, std::string opponentTeam);
    void cheer(bool teamScoredGoal);
    void wearTeamColours(bool teamWinningStreak);
    void getPlayersSignatures(int numCurrentSignatures, int numSignaturesRequired);
};

Fan::Fan() : name("John Johnson"), age(34), hasSeasonTicket(true)
{
    std::cout << "\nFan being constructed!" << std::endl;
}

void Fan::buyTicketToGame(float ticketPrice, std::string opponentTeam)
{
    std::cout << name << " age " << age << " purchased ticket to " << opponentTeam << ". Price: £" << ticketPrice << std::endl;
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

void Fan::getPlayersSignatures(int numCurrentSignatures, int numSignaturesRequired)
{
    int oldNumSignatures = numCurrentSignatures;
    while (numCurrentSignatures < numSignaturesRequired)
    {
        ++numCurrentSignatures;
        std::cout << name << " has got another signature" << std::endl;
    }
    std::cout << name << " has got " << numSignaturesRequired - oldNumSignatures << " new players signatures" << std::endl;
}

struct Medic
{
    std::string qualifications {"The FA Level 4 Emergency Medical Management in Football"};
    std::string name {"Doctor Pepper"};
    double salary {178909.99};
    bool isExPlayer = true;
    bool hasITSkills = true;
    Medic();

    void giveSteriodInjection(std::string player, std::string bodyPart, bool servePain);
    void giveMassageTreatment(std::string player, std::string therapyTargetArea);
    float provideFitnessAssessmentScore(int restingBPM, int maxBPM, int bloodPressure);
    void orderMedicines(int numCurrentMedicines, int numRequiredMedicines);
};


Medic::Medic() : isExPlayer(true), hasITSkills(true)
{
    std::cout << "\nMedic being constructed!" << std::endl;
}

void Medic::giveSteriodInjection(std::string player, std::string bodyPart, bool severePain)
{
    if (severePain)
    {
        std::cout << player << " received steriod injection to " << bodyPart << " from " << name << std::endl;
    }

}

void Medic::giveMassageTreatment(std::string player, std::string therapyTargetArea)
{
    std::cout << player << " received massage treatment to " << therapyTargetArea << " from " << name << std::endl;
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

void Medic::orderMedicines(int numCurrentMedicines, int numRequiredMedicines)
{
    while (numCurrentMedicines < numRequiredMedicines)
        {
            ++numCurrentMedicines;
            std::cout << name << " has ordered more medicine" << std::endl;
        }
}

struct Stadium
{
    int numSeats {62850};
    int numToilets {66};
    float pitchAreaInSqMetres;
    bool trainingPitch;
    double constructionCost;
    Stadium();

    void hostHomeGame(std::string nameVisitingTeam);
    bool provideCovidVaccinationCentre(int numberOfUnvaccinated, float RNumber);
    void maintance(bool brokenToilet);
    void mowPitch();
};

Stadium::Stadium() : pitchAreaInSqMetres(7123.89f), trainingPitch(true), constructionCost(1200500700.99)
{
    std::cout << "\nStadium being constructed!" << std::endl;
}

void Stadium::hostHomeGame(std::string nameVisitingTeam)
{
    std::cout << "Welcome " << nameVisitingTeam << " to our stadium. It cost £"<< constructionCost << " and has " << numSeats << " seats. "<<std::endl;
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

void Stadium::mowPitch()
{
    float areaOfPitchMowed {0.0f};
    int mowingLengths {0};
    while (areaOfPitchMowed < pitchAreaInSqMetres)
        {
            areaOfPitchMowed += 25.4f;
            ++mowingLengths;
        }
    std::cout << "The pitch has now been fully mowed" << std::endl;
    std::cout << "It took " << mowingLengths << " lengths with the mower to complete" <<std::endl;
}

struct SportsTeam
{
    Player teamCaptain;
    Coach coach;
    Fan numberOneFan;
    Medic bestMedic;
    Stadium stadium;
    SportsTeam();

    bool winHomeGame(int goalsScoredFor, int goalsScoredAgainst);
    bool winAwayGame(int goalsScoredFor, int goalsScoredAgainst);
    bool winChampionship(int gamesPlayed, int gamesWon, int gamesLost, int gamesDrawn, int totalGoalsScoredFor, int totalGoalsScoredAgainst);
    void playLeaugeMatches(int numberOfMatachesPlayed, int numTotalLeaugueMAtchesInYear);
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

void SportsTeam::playLeaugeMatches(int numberOfMatachesPlayed, int numTotalLeaugueMatchesInYear)
{
    while (numberOfMatachesPlayed < numTotalLeaugueMatchesInYear)
        {
            ++numberOfMatachesPlayed;
        }
    std::cout << numTotalLeaugueMatchesInYear << " matches now played" << std::endl;
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
    coffeeShop.addDailyTakingsToAnnualProfit(345, 789.99f);

    CoffeeShop::Employee employee;
    employee.fullyTrained = coffeeShop.trainStaff(employee, "Milk frothing");
    std::cout << "Is employee number: " << employee.employeeID << " " << employee.firstName << " " << employee.lastName << " fully trained? " << (employee.fullyTrained == 0 ? "No" : "Yes") << std::endl;

    employee.deservesPromotion();
    employee.takeHoliday(156, 167);
    employee.makeDeliveries(13, 12);
    std::cout << employee.firstName << " " << employee.lastName << " made deliveries to " << employee.deliveryNumCustomers << " customers over " << employee.deliveryDistTravelled << " km" << std::endl;
    employee.takeOutTrash(11, 3);

    School school;
    school.trainTeachers(false, "SEN");
    school.produceStudentsChristmasPlay(44, "Peter Pan", 20);
    school.cleanClassrooms(11);

    Farm farm;
    farm.sellSheep(12.11f);

    std::cout << "The farm made income of £" << farm.harvestCrop(true, 4, true, 1.30) << " from this years harvest." << std::endl; 
    farm.constructNewBarn(true, 12345.45f);
    std::cout << "The farm has spent £" << farm.annualExpenses << " this year. It's remaining profit is £" << farm.annualProfit <<  "." << std::endl;
    farm.milkCows(120.0f, 35.0f, 3.50f);

    CommercialAeroplane commercialAeroplane;
    commercialAeroplane.accelerateForTakeOff(278, true, true, true);
    commercialAeroplane.provideInflightEntertainment(234, "Love Actually");
    commercialAeroplane.transportPeople(156, 7);
    commercialAeroplane.increaseGroundSpeed(26.8f);

    CommercialAeroplane::Cockpit cockpit;
    cockpit.autopilotDisengagement(true);
    cockpit.groundProximityWarningAlarm(true, 200);
    std::cout << "You are within " << cockpit.proximityWarningThreshold << " metres of the ground!" << std::endl;
    std::cout << "New airspeed is " << cockpit.increaseAirSpeed(122.1f, 345.f) << " mph" << std::endl;
    cockpit.increaseAltitude(20000.0f);
    
    Player player;
    player.run(10, 100, true);
    std::cout << "The player ran at " << player.speed << " m/s" << std::endl;
    player.score(true, true);
    player.train("strength", 3.2f);
    player.loseWeight(90.5f);

    Coach coach;
    coach.deliverMotivationalSpeech(false);
    coach.loseJob(8);
    coach.givePressConference(true);
    coach.buyPlayers(50000000.f, 12000000.f);

    Fan fan;
    fan.buyTicketToGame(32.45f, "Chelsea");
    fan.cheer(true);
    fan.wearTeamColours(true);
    fan.getPlayersSignatures(4,13);

    Medic medic;
    medic.giveSteriodInjection("David Davidson", "knee", true);
    medic.giveMassageTreatment("David Davidson", "shoulder");
    std::cout << "Fitness assement score: " << medic.provideFitnessAssessmentScore(70, 180, 90) << std::endl;
    medic.orderMedicines(33,40);

    Stadium stadium;
    stadium.hostHomeGame("Chelsea");
    stadium.provideCovidVaccinationCentre(20000, 1.7f);
    stadium.maintance(true);
    stadium.mowPitch();

    SportsTeam sportsTeam;
    sportsTeam.winHomeGame(3, 5);
    sportsTeam.winAwayGame(5,3);
    sportsTeam.winChampionship(38, 28, 10, 0, 56, 22);
    sportsTeam.playLeaugeMatches(18, 32);
    
}
