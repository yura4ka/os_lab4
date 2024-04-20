#include <unistd.h>

#include <iostream>

using std::cout, std::cin;

int main() {
  int value;
  cout << "The pid of this process is: " << getpid() << "\n";
  cout << "The address of the value is: " << &value << "\n";

  while (true) {
    cout << "Enter the value: ";
    if (!(cin >> value)) {
      cin.clear();
      cin.ignore(1000, '\n');
    }
  }

  return 0;
}