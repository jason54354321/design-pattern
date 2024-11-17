#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node {
  private: 
    string name;

  public:
    Node(string name) {
      this->name = name;
    }

    // Note:
    // We have to declare a least one virtual method to make this class polymorphic
    // If no others are suitable, the destructor
    // ref: https://stackoverflow.com/questions/15114093/getting-source-type-is-not-polymorphic-when-trying-to-use-dynamic-cast
    virtual ~Node() {}

    string getName() {
      return this->name;
    }
};

class File: public Node{
  public:
    File(string name) : Node(name) {

    }
};

class Folder: public Node {
  private:
    vector<Node *> nodes;

  public:
    Folder(string name) : Node(name) {

    }

    void add_node(Node * node) {
      nodes.push_back(node);
    }

    string printFolder(int indent) {
      string output = "";


      for (Node *node: nodes) {
        File *file = dynamic_cast<File *>(node);
        if (file) {
          // add indent
          for (int i = 0; i < indent; i++) {
            output += "  ";
          }
          output += file->getName() + "\n";
        }
        else {
          // add indent
          for (int i = 0; i < indent; i++) {
            output += "  ";
          }

          Folder *folder = dynamic_cast<Folder *>(node);
          output += folder->getName() + "\n";
          output += folder->printFolder(indent+1);
        }
      }

      return output;
    }
};

int main() {
  Folder *root = new Folder("root");
  Folder *book = new Folder("book");
  Folder *music = new Folder("music");

  File *fileAtRoot = new File("fileAtRoot");
  File *book1 = new File("book1");
  File *book2 = new File("book2");
  File *music1 = new File("music1");
  File *music2 = new File("music2");

  root->add_node(book);
  root->add_node(music);
  root->add_node(fileAtRoot);

  book->add_node(book1);
  book->add_node(book2);

  music->add_node(music1);
  music->add_node(music2);

  string output = root->printFolder(0);

  cout << output << endl;

}
