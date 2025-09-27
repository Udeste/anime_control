/*
 * Anime Control - A command-line tool for controlling Anime Matrix devices on Asus ROG laptops.
*/

#include "../include/animectl.h"
#include "../include/helpers.h"
#include "../include/main.h"
#include <iostream>
#include <string>

// Main function
int main(int argc, char* argv[]) {

  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <actions>" << std::endl;
    std::cout << "Actions:" << std::endl;
    std::cout << "  -e <0|1>  Enable/Disable matrix" << std::endl;
    std::cout << "  -b <0-3>  Set brightness (0-3)" << std::endl;
    std::cout << "  -a <0|1>  Enable/Disable built-in animation" << std::endl;
    return 1;
  }

  AnimeCtl animectl(VENDOR_ID, PROD_ID);
  animectl.init();
  // animectl.init_device();

  switch (argv[1][1]) {
    case 'e':
      if (argv[2] == nullptr) {
        std::cerr << "Missing argument for -e" << std::endl;
        return 1;
      }
      handle_enable_command(std::stoi(argv[2]) != 0, animectl);
      break;
    case 'b':
      if (argv[2] == nullptr) {
        std::cerr << "Missing argument for -b" << std::endl;
        return 1;
      }
      handle_brightness_command(std::stoi(argv[2]), animectl);
      break;
    case 'a':
      if (argv[2] == nullptr) {
        std::cerr << "Missing argument for -a" << std::endl;
        return 1;
      }
      handle_enable_builtin_anim_command(std::stoi(argv[2]) != 0, animectl);
    default:
      std::cerr << "Unknown action: " << argv[1] << std::endl;
      return 1;
  }

  animectl.close();
  return 0;
}
