#include <iostream>

using namespace std;

class PriceTemplateMethod {
  public:
    int getDrinkPrice(int price) {
      float discount = primitive_discount();
      return price * discount;
    }

  protected:
    virtual float primitive_discount() {
      return 1;
    }
};


class StudentPrice : public PriceTemplateMethod {
  protected:
    float primitive_discount() override {
      return 0.8;
    }
};

class ElderPrice : public PriceTemplateMethod {
  protected:
    float primitive_discount() override {
      return 0.5;
    }
};

int main() {
  PriceTemplateMethod *priceTemplateMethod = new PriceTemplateMethod();
  PriceTemplateMethod *studentPrice = new StudentPrice();
  PriceTemplateMethod *elderPrice = new ElderPrice();

  cout << priceTemplateMethod->getDrinkPrice(20) << endl;
  cout << studentPrice->getDrinkPrice(20) << endl;
  cout << elderPrice->getDrinkPrice(20) << endl;


  return 0;
}
