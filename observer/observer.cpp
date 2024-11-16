using namespace std;

#include <iostream>
#include <vector>

class IObserver {
  public:
    virtual void print(string str) = 0;

};

class ISubject {
  protected:
    vector<IObserver *> observers;

  public:
    virtual void add_observer(IObserver *observer) = 0;

};

class Subject: public ISubject {
  public:
    void add_observer(IObserver *observer) override {
      observers.push_back(observer);
    }

    void notify_Observer() {
      for (IObserver *ob: observers) {
        ob->print("Hi, Update the info to you");
      }

    }

};

class Observer: public IObserver {
  public:
    void print(string str) override {
      cout << str << endl;
    }
};

int main() {
  Observer *observer = new Observer();
  Subject *subject = new Subject();

  subject->add_observer(observer);

  subject->notify_Observer();
}
