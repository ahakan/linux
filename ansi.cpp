#include <cstdint>
#include <iostream>

int main(int argc, const char **argv) {
  std::cout << "Bold- Bckgrnd- Bright- Underline\n";

  for (std::uint8_t i = 30; i < 38; i++) {
    std::cout << "\033[1;" << unsigned(i) << "mtext\033[0m\t";
    std::cout << "\033[1;" << unsigned(i + 10) << "m\033[1;37mtext\033[0m   \t";
    std::cout << "\033[0;" << unsigned(i) << "mtext\033[0m   \t";
    std::cout << "\033[4;" << unsigned(i) << "mtext\033[0m\n";
  }
  return 0;
}