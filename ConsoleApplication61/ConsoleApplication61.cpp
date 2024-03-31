#include <iostream>
class Herbivores {
protected:
    float weight = 0;
    bool life = true;
public:
    void EatGrass() {
        std::cout << "+10 weight" << "\n";
        weight += 10;
    }

    virtual void SetWeight() = 0;
    virtual void SetLife() = 0;
    virtual void SetDeath() = 0;

    int GetWeight() const { return weight; }
};
class Wildebeest : public Herbivores {
    void SetWeight() {
        weight = 195;
    }
    void SetLife() {
        life = true;
    }
    void SetDeath() {
        life = false;
    }
};
class Buffalo : public Herbivores {
    void SetWeight() {
        weight = 725;
    }
    void SetLife() {
        life = true;
    }
    void SetDeath() {
        life = false;
    }
};
class Elk : public Herbivores {
    void SetWeight() {
        weight = 540;
    }
    void SetLife() {
        life = true;
    }
    void SetDeath() {
        life = false;
    }
};
class Predators {
protected:
    int power;
public:
    void Eat(Herbivores* herbivores) {
        printf("%s", power > herbivores->GetWeight() ? "+10 power\n" : "-10 power\n");
        power > herbivores->GetWeight() ? power += 10 : power -= 10;
        herbivores->SetDeath();
    }

    virtual void SetPower() = 0;
};
class Lion : public Predators {
    void SetPower() {
        power = 250;
    }
};
class Wolf : public Predators {
    void SetPower() {
        power = 250;
    }
};
class Tiger : public Predators {
    void SetPower() {
        power = 210;
    }
};
class Continent abstract {
public:
    virtual void MsgCreateContinent() abstract;
    virtual Predators* CreatePredators() abstract;
    virtual Herbivores* CreateHerbivores() abstract;
};
class Africa : public Continent {
public:
    void MsgCreateContinent() override {
        std::cout << "Africa\n";
    }
    Predators* CreatePredators() override {
        Predators* predators = new Lion();
        predators->SetPower();

        return predators;
    }
    Herbivores* CreateHerbivores() override {
        Herbivores* herbivores = new Wildebeest();
        herbivores->SetWeight();
        herbivores->SetLife();

        return herbivores;
    }
};
class NorthAmerica : public Continent {
public:
    void MsgCreateContinent() override {
        std::cout << "North America\n";
    }
    Predators* CreatePredators() override {
        Predators* predators = new Wolf();
        predators->SetPower();

        return predators;
    }
    Herbivores* CreateHerbivores() override {
        Herbivores* herbivores = new Buffalo();
        herbivores->SetWeight();
        herbivores->SetLife();

        return herbivores;
    }
};
class Eurasia : public Continent {
    void MsgCreateContinent() override {
        std::cout << "Eurasia\n";
    }
    Predators* CreatePredators() override {
        Predators* predators = new Tiger();
        predators->SetPower();

        return predators;
    }
    Herbivores* CreateHerbivores() override {
        Herbivores* herbivores = new Elk();
        herbivores->SetWeight();
        herbivores->SetLife();

        return herbivores;
    }
};
class AnimalWorld {
    Predators* predators;
    Herbivores* herbivores;
public:
    AnimalWorld(Continent* continent) {
        predators = continent->CreatePredators();
        herbivores = continent->CreateHerbivores();
    }

    void Eat() {
        herbivores->EatGrass();
    }
    void EatHerbivores() {
        predators->Eat(herbivores);
    }
};



int main() {
    Continent* continent = new NorthAmerica();
    AnimalWorld* animalWorld = new AnimalWorld(continent);

    animalWorld->Eat();
    animalWorld->EatHerbivores();

    delete continent;
    delete animalWorld;
    continent = new Africa();
    animalWorld = new AnimalWorld(continent);

    animalWorld->Eat();
    animalWorld->EatHerbivores();

    delete continent;
    delete animalWorld;

    continent = new Eurasia();
    animalWorld = new AnimalWorld(continent);

    animalWorld->Eat();
    animalWorld->EatHerbivores();

    delete continent;
    delete animalWorld;

    return 0;
}
