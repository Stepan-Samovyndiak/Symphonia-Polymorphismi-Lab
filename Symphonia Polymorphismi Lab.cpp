#include <iostream>
#include <string>
#include <vector>

class Instrument {
protected:
    std::string name;
    std::string sound;

public:
    Instrument(std::string n, std::string s) : name(n), sound(s) {}
    virtual ~Instrument() {}

    virtual void play() {
        std::cout << name << ": " << sound << std::endl;
    }
};

class Trumpet : public Instrument {
public:
    Trumpet() : Instrument("Trumpet", "doot") {}
    void play() override {
        std::cout << name << ": " << sound << " " << sound << " " << sound << std::endl;
    }
};

class Violin : public Instrument {
public:
    Violin() : Instrument("Violin", "vwa") {}
    void play() override {
        std::cout << name << ": " << sound << " " << sound << " " << sound << " " << sound << " " << sound << std::endl;
    }
};

class Piano : public Instrument {
public:
    Piano() : Instrument("Piano", "Dee") {}
    void play() override {
        std::cout << name << ": " << sound << " " << sound << std::endl;
    }
};

class Trombone : public Instrument {
public:
    Trombone() : Instrument("Trombone", "Dwooooo~") {}
    void play() override {
        std::cout << name << ": " << sound << std::endl;
    }
};

class Singer : public Instrument {
public:
    Singer() : Instrument("Singer", "blah") {}
    void play() override {
        std::cout << name << ": " << sound << " " << sound << " " << sound << " " << sound << " " << sound << " " << sound << std::endl;
    }
};

class Orchestra {
private:
    std::vector<Instrument*> composition;

public:
    ~Orchestra() {
        for (Instrument* inst : composition) {
            delete inst;
        }
    }

    void add_instrument(Instrument* inst) {
        composition.push_back(inst);
    }

    void play() {
        for (Instrument* inst : composition) {
            inst->play();
        }
    }
};

int main() {
    Orchestra myOrchestra;

    myOrchestra.add_instrument(new Trumpet());
    myOrchestra.add_instrument(new Violin());
    myOrchestra.add_instrument(new Piano());
    myOrchestra.add_instrument(new Trombone());
    myOrchestra.add_instrument(new Trumpet());
    myOrchestra.add_instrument(new Singer());

    myOrchestra.play();

    return 0;
}