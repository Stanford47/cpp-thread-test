#include <iostream>
#include <thread>
#include <chrono>
#include <pthread.h>

static bool is_going = true;
static bool is_going_a = true;

void thread2() {
  while(is_going) {
    std::cout << "hello!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

void thread3() {
  while(is_going_a) {
    std::cout << "helloo!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }
}

int main() {
  std::thread new_thread1(thread2);
  std::thread new_thread2(thread3);

  std::cin.get();
  is_going_a = false;
  
 
  std::cin.get();
  is_going = false;
  
  new_thread2.join();
  new_thread1.join();

  return 0;
}