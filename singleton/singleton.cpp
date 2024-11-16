#include <string>
#include <iostream>

using namespace std;

class SingletonDB {
  private:
    static SingletonDB *instance;
    string name;

  public:
    SingletonDB (string name) {
      this->name = name;
    }

    static SingletonDB * getInstance() {
      if (!instance) {
        instance = new SingletonDB("The only name");
        return instance;
      }
      return instance;
    }

    string getName() {
      return this->name;
    }
};

SingletonDB* SingletonDB::instance = 0;

int main() {
  SingletonDB *db1 = SingletonDB::getInstance();
  cout << "db1's name:" <<  db1->getName() << endl;
  SingletonDB *db2 = SingletonDB::getInstance();
  cout << "db2's name:" << db2->getName() << endl;
}
