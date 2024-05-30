#include <iostream>
#include <string>
using namespace std;﻿

class Herbivores
{
public:
    virtual void EatGrass() = 0;
    virtual int GetWeight() = 0;
    virtual bool IsAlive() = 0;
    virtual void Die() = 0;
};


class Predators
{
public:
    virtual void Eat(Herbivores* herbivore) = 0;
    virtual int GetPower() = 0;
};


class Wildebeest : public Herbivores 
{
private:
    int weight;
    bool alive;
public:
    Wildebeest() 
    {
        weight = 100;
        alive = true;
    }
    void EatGrass() 
    {
        weight += 10;
    }
    int GetWeight() 
    {
        return weight;
    }
    bool IsAlive()  
    {
        return alive;
    }
    void Die() 
    {
        alive = false;
    }
};

class Bison : public Herbivores
{
private:
    int weight;
    bool alive;
public:
    Bison()
    {
        weight = 200;
        alive = true;
    }
    void EatGrass() 
    {
        weight += 10;
    }
    int GetWeight() 
    {
        return weight;
    }
    bool IsAlive() 
    {
        return alive;
    }
    void Die()
    {
        alive = false;
    }
};

class Elk : public Herbivores
{
private:
    int weight;
    bool alive;
public:
    Elk()
    {
        weight = 140;
        alive = true;
    }
    void EatGrass() 
    {
        weight += 10;
    }
    int GetWeight() 
    {
        return weight;
    }
    bool IsAlive() 
    {
        return alive;
    }
    void Die()
    {
        alive = false;
    }
};



class Lion : public Predators 
{
private:
    int power;
public:
    Lion() 
    {
        power = 220;
    }
    void Eat(Herbivores* herbivore) 
    {
        if (power >= herbivore->GetWeight()) 
        {
            power += 10;
        }
        else 
        {
            power -= 10;
        }
    }
    int GetPower() 
    {
        return power;
    }
};

class Wolf : public Predators
{
private:
    int power;
public:
    Wolf()
    {
        power = 50;
    }
    void Eat(Herbivores* herbivore) 
    {
        if (power >= herbivore->GetWeight())
        {
            power += 10;
        }
        else
        {
            power -= 10;
        }
    }
    int GetPower() 
    {
        return power;
    }
};

class Tiger : public Predators
{
private:
    int power;
public:
    Tiger()
    {
        power = 150;
    }
    void Eat(Herbivores* herbivore) 
    {
        if (power >= herbivore->GetWeight())
        {
            power += 10;
        }
        else
        {
            power -= 10;
        }
    }
    int GetPower() 
    {
        return power;
    }
};




class ContinentFactory
{
public:
    virtual Herbivores* CreateHerbivore() = 0;
    virtual Predators* CreatePredator() = 0;
};

class Africa : public ContinentFactory
{
public:
    Herbivores* CreateHerbivore() 
    {
        return new Bison;
    }

    Predators* CreatePredator() 
    {
        return new Lion;
    }
};

class NorthAmerica : public ContinentFactory
{
public:
    Herbivores* CreateHerbivore()
    {
        return new Wildebeest;
    }

    Predators* CreatePredator()
    {
        return new Wolf;
    }
};

class Eurasia : public ContinentFactory
{
public:
    Herbivores* CreateHerbivore()
    {
        return new Elk;
    }

    Predators* CreatePredator()
    {
        return new Tiger;
    }
};


class AnimalWorld 
{
private:
    Herbivores* herbivores;
    Predators* predators;

public:
    AnimalWorld(ContinentFactory* factory) 
    {
        herbivores = factory->CreateHerbivore();
        predators = factory->CreatePredator();
    }
    void MealsHerbivores() 
    {
        herbivores->EatGrass();
    }
    void NutritionCarnivores() 
    {
        predators->Eat(herbivores);
    }

    void Stats() 
    {
        cout << "Herbivore weight: " << herbivores->GetWeight() << "\n";
        cout << "Predator power: " << predators->GetPower() << "\n";
        cout << "Herbivore is alive?\n";
        if (herbivores->IsAlive()) 
        {
            cout << "Yes.\n\n";
        }
        else 
        {
            cout << "No.\n\n";
        }
    }
};

int main()
{

    Africa Afr;
    NorthAmerica NrAmer;
    Eurasia EUA;

    AnimalWorld AfricanAnimal(&Afr);
    AnimalWorld AmericanAnimal(&NrAmer);
    AnimalWorld EurasianAnimal(&EUA);

    cout << "African World:\n";
    AfricanAnimal.Stats();
    AfricanAnimal.MealsHerbivores();
    AfricanAnimal.NutritionCarnivores();
    AfricanAnimal.Stats();

    cout << "North American World:\n";
    AmericanAnimal.Stats();
    AmericanAnimal.MealsHerbivores();
    AmericanAnimal.NutritionCarnivores();
    AmericanAnimal.Stats();

    cout << "Eurasian World:\n";
    EurasianAnimal.Stats();
    EurasianAnimal.MealsHerbivores();
    EurasianAnimal.NutritionCarnivores();
    EurasianAnimal.Stats();
}
