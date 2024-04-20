#include <sys/mman.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

typedef unsigned long long ull;

int main() {
  int pid;
  ull address;
  cout << "Enter pid: ";
  cin >> pid;
  cout << "Enter address: ";
  cin >> hex >> address;

  int value;
  ifstream mem = ifstream("/proc/" + to_string(pid) + "/mem", ios::binary);

  while (true) {
    ptrace(PTRACE_ATTACH, pid, 0);
    waitpid(pid, 0, 0);

    mem.seekg(address);
    mem.read((char *)&value, sizeof(int));

    cout << "Read value: " << value << "\n";

    ptrace(PTRACE_DETACH, pid, 0, 0);
  }

  mem.close();
  return 0;
}
