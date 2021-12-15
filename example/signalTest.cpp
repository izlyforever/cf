#include <chrono>
#include <thread>
#include <csignal>
#include <iostream>

static bool exitFlag = false;
static void SignalHandler(int sigNo) { exitFlag = true; }

int main() {
  std::signal(SIGQUIT, SignalHandler);
  std::signal(SIGABRT, SignalHandler);
  std::signal(SIGINT, SignalHandler);

  std::cout << "Signal Test" << std::endl;
  while (!exitFlag) {
    std::this_thread::sleep_for(std::chrono::microseconds(233));
  }
  std::cout << "\nGoodBye" << std::endl;
  return 0;
}