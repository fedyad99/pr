#include <iostream>
#include <ctime>
#include <math.h>

class Fighter
{
private:
    int health_points;
    int health;
    int force_points;
    int defence_points;
    int agility_points;
    int critical_points;
    int points;


    double force()
    {
        return (1 + this->force_points);
    }

    bool critical()
    {
        double temp = (static_cast<double>(rand() % RAND_MAX)) / RAND_MAX;
        if (temp > 1 / (1 + pow(static_cast<double>(this->critical_points) / 4, 4))) return true;
        return false;
    }

    double defence()
    {
        return 1 / (1 + pow(static_cast<double>(this->defence_points) / 4, 4));
    }

    bool agility()
    {
        double temp = (static_cast<double>(rand() % RAND_MAX)) / RAND_MAX;
        if (temp > 1 / (1 + pow(static_cast<double>(this->agility_points) / 4, 4))) return true;
        return false;
    }

public:
    Fighter()
    {
        this->health = 100;
        this->health_points = 0;
        this->force_points = 0;
        this->critical_points = 0;
        this->defence_points = 0;
        this->agility_points = 0;
        this->points = 10;
    }

    Fighter(int health_points, int force_points, int critical_points, int defence_points, int agility_points)
    {
        this->health_points = health_points;
        this->force_points = force_points;
        this->critical_points = critical_points;
        this->defence_points = defence_points;
        this->agility_points = agility_points;
        this->points = 0;
        this->health = 100 + this->health_points * 100;
    }

    bool add_health_points(int points)
    {
        if(points <= this->points)
        {
            this->points -= points;
            this->health_points += points;
            this->health = 100 + this->health_points * 100;
            return true;
        }
        return false;
    }

    bool add_force_points(int points)
    {
        if(points <= this->points)
        {
            this->points -= points;
            this->force_points += points;
            return true;
        }
        return false;
    }

    bool add_defence_points(int points)
    {
        if(points <= this->points)
        {
            this->points -= points;
            this->defence_points += points;
            return true;
        }
        return false;
    }

    bool add_agility_points(int points)
    {
        if(points <= this->points)
        {
            this->points -= points;
            this->agility_points += points;
            return true;
        }
        return false;
    }

    bool add_critical_points(int points)
    {
        if(points <= this->points)
        {
            this->points -= points;
            this->critical_points += points;
            return true;
        }
        return false;
    }

    double attack()
    {
       return this->force() * ( 1 + this->critical());
    }

    double damage(double dmg)
    {
        dmg = (1 - this->agility()) * this->defence() * dmg;
        this->health -= dmg;
        return dmg;
    }

    bool is_dead()
    {
        if(this->health <= 0) return true;
        return false;
    }
};

Fighter setFighterForBot()
{
    Fighter fighter = Fighter();
    int temp = rand() % 11;
    fighter.add_force_points(temp);

    temp = rand() % 11;
    fighter.add_health_points(temp);

    temp = rand() % 11;
    fighter.add_agility_points(temp);

    temp = rand() % 11;
    fighter.add_defence_points(temp);

    temp = rand() % 11;
    fighter.add_critical_points(temp);
    return fighter;
}

void BvB()
{
    Fighter fighter[2] = { setFighterForBot(), setFighterForBot() };
    bool isFighter = rand() % 2;

    while (true) {
        double dmg = fighter[!isFighter].attack();
        fighter[isFighter].damage(dmg);

        std::cout << "Bot " << isFighter + 1 << " received damage of " << dmg << " units" << std::endl;
        if(fighter[isFighter].is_dead())
        {
            std::cout << "Bot " << isFighter + 1 << " winner" << std::endl;
            return;
        }
        isFighter = !isFighter;
    }
}

void PvB()
{
    int health_points, force_points, critical_points, defence_points, agility_points;
    std::cout << "Enter a health_points, force_points, critical_points, defence_points, agility_points: " << std::endl;
    std::cin >> health_points >> force_points >> critical_points >> defence_points >> agility_points;
    Fighter fighter[2] = { Fighter(health_points, force_points, critical_points, defence_points, agility_points), setFighterForBot() };

    bool isFighter = rand() % 2;
    while (true) {
        double dmg = fighter[!isFighter].attack();
        fighter[isFighter].damage(dmg);

        if(isFighter)
        {
            std::cout << "Bot received damage of " << dmg << " units" << std::endl;
        } else std::cout << "User received damage of " << dmg << " units" << std::endl;

        if(fighter[isFighter].is_dead())
        {
            if(!isFighter)
            {
                std::cout << "Bot winner" << std::endl;
            } else std::cout << "User winner" << std::endl;
            return;
        }
        isFighter = !isFighter;
    }
}

void PvP()
{
    Fighter fighter[2];

    int health_points, force_points, critical_points, defence_points, agility_points;

    std::cout << "User1, enter a health_points, force_points, critical_points, defence_points, agility_points: " << std::endl;
    std::cin >> health_points >> force_points >> critical_points >> defence_points >> agility_points;
    fighter[0] = Fighter(health_points, force_points, critical_points, defence_points, agility_points);

    std::cout << "User2, enter a health_points, force_points, critical_points, defence_points, agility_points: " << std::endl;
    std::cin >> health_points >> force_points >> critical_points >> defence_points >> agility_points;
    fighter[1] = Fighter(health_points, force_points, critical_points, defence_points, agility_points);

    bool isFighter = rand() % 2;

    while (true) {
        double dmg = fighter[!isFighter].attack();
        fighter[isFighter].damage(dmg);

        std::cout << "User " << isFighter + 1 << " received damage of " << dmg << " units" << std::endl;
        if(fighter[isFighter].is_dead())
        {
            std::cout << "User " << isFighter + 1 << " winner" << std::endl;
            return;
        }
        isFighter = !isFighter;
    }
}

int main()
{
    srand(time(NULL));

    std::cout << "Select the battle mode:" << std::endl;
    std::cout << "1 - Bot and Bot" << std::endl;
    std::cout << "2 - Bot and User" << std::endl;
    std::cout << "3 - User and User" << std::endl;

    int choise;


    std::cin >> choise;
    switch (choise) {
        case 1:
            BvB();
            break;
        case 2:
            PvB();
            break;
        case 3:
            PvP();
            break;
        default:
            std::cout << "Error. Need 1-3" << std::endl;
            return 0;
    }
}
