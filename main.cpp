#include <iostream>
#include <thread>
#include <chrono>
#include <pthread.h>

static bool is_thread_alive = true;

void da_other_thread() {
  while(is_thread_alive == true){
    std::cout << "Hello from thread 2!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

int main() {
  std::string t;
  std::thread new_thread(da_other_thread);

  std::cin.get();
  is_thread_alive = false;

  new_thread.join();
  std::cout << "Done!";

  std::cin.get();

  return 0;
}