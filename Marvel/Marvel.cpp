#include <iostream>
#include<vector>
using namespace std;


class ISuperSpeed abstract{
public:
    virtual void SuperSpeed() = 0;
    virtual ~ISuperSpeed() {};
};

class ISuperPower abstract{
public:
    virtual void SuperPower() = 0;
    virtual ~ISuperPower() {};
};

class IFly abstract {
public:
    virtual void Fly() = 0;
    virtual ~IFly() {};
};

class IHighIntelect abstract{
public:
    virtual void HaveIntelect() = 0;
    virtual ~IHighIntelect() {};
};

class ISayJokes abstract {
public:
    virtual void SayJokes() = 0;
    virtual ~ISayJokes() {};
};

class IHaveLaserEye abstract {
public:
    virtual void HaveLaserEye() = 0;
    virtual ~IHaveLaserEye() {};
};

class IHaveChuika abstract{
public:
    virtual void HaveChuika() = 0;
    virtual ~IHaveChuika() {};
};

class IMakeLigtning abstract {
public:
    virtual void MakeLigtning() = 0;
    virtual ~IMakeLigtning() {};
};

class Ability abstract : public IMakeLigtning, public IHaveChuika, public IHaveLaserEye, public ISayJokes, public IHighIntelect, public IFly, public ISuperPower, public ISuperSpeed {
public:
    virtual ~Ability() {};
    virtual void HaveChuika() override {
        cout << "I have chuika\n";
    }
    virtual void MakeLigtning() override {   
        cout << "I can make ligtning\n";
    }
    virtual void HaveLaserEye()override {
        cout << "I can shoot lasers by my eyes\n"; 
    }
    virtual void SayJokes() override {
        cout << "I can say jokes\n";
    }
    virtual void Fly() override {
        cout << "I can fly\n";
    }
    virtual void HaveIntelect() override {
        cout << "I am very smart\n";
    }
    virtual void SuperPower() override {
        cout << "I am very strong\n";
    }
    virtual void SuperSpeed() override {
        cout << "I am very fast\n";
    }
};

class Good abstract {
public:
    virtual void DoGoodThings(string thing) = 0;
    virtual ~Good() {};
};

class Bad abstract {
public:
    virtual void DoBadThings(string thing) = 0;
    virtual ~Bad() {};
};

class God abstract : protected Ability {
    /*string name;*/
    int count = 0;
    string life = "infinity";   
    vector <void (Ability::*)()> abilities;     
public:
    
    God() {
        //cout << "God\n";
    }

    virtual ~God() {}

    string GetLife()
    {
        return life;
    }

    int GetCount() {
        return count;
    }

    void AddAbility(void(Ability::* ability)())
    {
        //void* method = *(void**)(&abilitie);
        abilities.push_back(ability);
        count++;
    }

    auto Search(void(Ability::* ability)())
    {
        for (int i = 0; i < count; i++)
        {
            if (ability == abilities[i]) {
                return 1;
            }
        }
        return 0;
    }

    void ShowAbilities()
    {
        for (auto ability : abilities)
        {
            if (ability == &Ability::Fly)
                cout << "Fly ";
            else if (ability == &Ability::HaveIntelect)
                cout << "High Intelect ";
            else if (ability == &Ability::HaveChuika)
                cout << "Chuika ";
            else if (ability == &Ability::HaveLaserEye)
                cout << "Laser eyes ";
            else if (ability == &Ability::MakeLigtning)
                cout << "Throw Ligtning ";
            else if (ability == &Ability::SayJokes)
                cout << "Say some jokes ";
            else if (ability == &Ability::SuperPower)
                cout << "Super power ";
            else if (ability == &Ability::SuperSpeed)
                cout << "Super speed ";
            //(this->*ability)();
        }
        cout << "\n";
    }
    
};

class People abstract : protected Ability{ 
    /*string name;*/
    int life;
    vector <void (Ability::*)()> abilities;
    int count = 0;
public:

    People() {
       // cout << "People\n";
    }

    virtual ~People() {}

    void SetLife(int life) {
        this->life = life;
    }

    int GetLife() {
        return life;
    }
    
    int GetCount(){
        return count;
    }

    auto Search(void(Ability::* ability)())
    {
        for (int i = 0; i < count; i++)
        {
            if (ability == abilities[i]) {
                return 1;
            }
        }
        return 0;
    }

    void AddAbility(void (Ability::* ability)()) {
        abilities.push_back(ability);
        count++;       
    }

    void ShowAbility() {
        for (auto ability : abilities)
        {
            /*(this->*ability)();*/
            if (ability == &Ability::Fly)
                cout << "Fly ";
            else if (ability == &Ability::HaveIntelect)
                cout << "High Intelect ";
            else if (ability == &Ability::HaveLaserEye)
                cout << "Laser eyes ";
            else if (ability == &Ability::HaveChuika)
                cout << "Chuika ";
            else if (ability == &Ability::MakeLigtning)
                cout << "Throw Ligtning ";
            else if (ability == &Ability::SayJokes)
                cout << "Say some jokes ";
            else if (ability == &Ability::SuperPower)
                cout << "Super power ";
            else if (ability == &Ability::SuperSpeed)
                cout << "Super speed ";
        }
        cout << "\n";
    }
};

class Hero abstract : public Good{
    vector<string> good_things;
public:

    virtual ~Hero() {}

    virtual void DoGoodThings(string thing) override {
        good_things.push_back(thing + "\n");
    }

    void GetGoodThings()
    {
        for (int i = 0; i < good_things.size(); i++)
            cout << i + 1 << "." << good_things[i];
    }
};

class AntiHero abstract : public Bad{
    vector<string> bad_things;
public:
    virtual ~AntiHero() {}

    void DoBadThings(string thing) override {
        bad_things.push_back(thing);
    }

    void GetGoodThings()
    {
        for (int i = 0; i < bad_things.size(); i++)
            cout << i + 1 << "." << bad_things[i];
    }
};

class IronMan : public People, public Hero{
    friend void ShowAll(void(Ability::* ability)());
public:
    IronMan() {
        People::AddAbility(&Ability::Fly);
        People::AddAbility(&Ability::HaveIntelect);
        People::AddAbility(&Ability::SuperPower);
        People::AddAbility(&Ability::SayJokes);
    }
};

class Thor : public God, public Hero{
    friend void ShowAll(void(Ability::* ability)());
public:
    Thor() {
        God::AddAbility(&Ability::Fly);
        God::AddAbility(&Ability::SuperPower);
        God::AddAbility(&Ability::MakeLigtning);
        God::AddAbility(&Ability::SayJokes);
    }
};

class Joker : public People, public AntiHero{
    friend void ShowAll(void(Ability::* ability)());
public:
    Joker() {        
        People::AddAbility(&Ability::HaveIntelect);        
        People::AddAbility(&Ability::SayJokes);
    }
};

class Loki : public God, public AntiHero{
    friend void ShowAll(void(Ability::* ability)());
public:
    Loki() {
        God::AddAbility(&Ability::HaveIntelect);
        God::AddAbility(&Ability::Fly);
    }
    
};

void ShowAll(IronMan& type, Thor& type2, Loki& type3, Joker& type4, void(Ability::* ability)()) {
    vector<string> ar;
    auto abil = type.Search(ability);
    auto abil2 = type2.Search(ability);
    auto abil3 = type3.Search(ability);
    auto abil4 = type4.Search(ability);

    if (abil)
        ar.push_back("IronMan\n");
    if (abil2)
        ar.push_back("Thor\n");
    if (abil3)
        ar.push_back("Loki\n");
    if (abil4)
        ar.push_back("Joker\n");

    for (int i = 0; i < ar.size(); i++)
        cout << ar[i];
}

int main()
{
    setlocale(0, "");
    /*Hero a;
    a.AddAbility(&Ability::HaveChuika);
    a.DoGoodThings("спас собаку");
    a.ShowAbility();
    a.GetGoodThings();*/
    IronMan man;
    Joker j;
    Thor t;
    Loki l;
    man.ShowAbility();
    ShowAll(man, t, l, j, &Ability::Fly);

}
