#include <string>
#include <iostream>

using namespace std;

class Bread {
  protected:
    string topping;

  public:
    Bread(string topping) {
      this->topping = topping;
    }

    virtual void printBreadStatus() = 0;
};

class CircleBread: public Bread {
  public:
    CircleBread(string topping) : Bread(topping){

    }

    void printBreadStatus() override {
      cout << "CircleBread with topping: " << this->topping << endl;
    }

};

class SquareBread: public Bread {
  public:
    SquareBread(string topping) : Bread(topping){

    }

    void printBreadStatus() override {
      cout << "SquareBread with topping: " << this->topping << endl;
    }
};


class AbstractFactory {
  public:
    virtual Bread * createCircleBread() = 0;

    virtual Bread * createSqaureBread() = 0;
};

class HoneyFactory: public AbstractFactory {
  public:
    Bread * createCircleBread() override {
      return new CircleBread("Honey");
    }

    Bread * createSqaureBread() override {
      return new SquareBread("Honey");
    }
};

class BaconFactory: public AbstractFactory {
  public:
    Bread * createCircleBread() override {
      return new CircleBread("Bacon");
    }

    Bread * createSqaureBread() override {
      return new SquareBread("Bacon");
    }
};



int main() {
  AbstractFactory *honeyFactory = new HoneyFactory();
  AbstractFactory *baconFactory = new BaconFactory();

  Bread *circleBread1 = honeyFactory->createCircleBread();
  Bread *circleBread2 = baconFactory->createCircleBread();

  Bread *squareBread1= honeyFactory->createSqaureBread();
  Bread *squareBread2 = baconFactory->createSqaureBread();

  circleBread1->printBreadStatus();
  circleBread2->printBreadStatus();

  squareBread1->printBreadStatus();
  squareBread2->printBreadStatus();

  return 0;
}
