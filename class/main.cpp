#include <iostream>
#include <string>
using namespace std;

class MyClass
{                  // The class
public:            // Access specifier
  int myNum;       // Attribute (int variable)
  string myString; // Attribute (string variable)
};

class Rectangle
{
  int width, height;

public:
  Rectangle(int width, int height) : width(width), height(height) {}
  void set_values(int x, int y)
  {
    width = x;
    height = y;
  }
  int area() { return width * height; }
};

int main()
{
  MyClass myObj; // Create an object of MyClass

  myObj.myNum = 15;
  myObj.myString = "Some text";

  MyClass a; // = new MyClass();
  a.myNum = 16;

  // cout << a.myNum << "\n";
  cout << sizeof(a.myNum) << "\n";

  cout << "Hello world"
       << "\n";

  cout << "Duong" << endl;
  return 0;
}
