#include <iostream>
#include "../include/animectl.h"

// Function definitions
void handle_enable_command(bool enable, AnimeCtl &animectl) {
  if (enable) {
    std::cout << "Enabling matrix" << std::endl;
    animectl.enable_matrix(true);
  } else {
    std::cout << "Disabling matrix" << std::endl;
    animectl.enable_matrix(false);
  }
}

void handle_brightness_command(int brightness, AnimeCtl &animectl) {
  if (brightness > 3 || brightness < 0) {
    throw std::out_of_range("Brightness must be between 0 and 3");
  }

  std::cout << "Setting brightness to " << brightness << std::endl;
  animectl.set_brightness(brightness);
}

void handle_enable_builtin_anim_command(bool enable, AnimeCtl &animectl) {
  if (enable) {
    std::cout << "Enabling built-in animation" << std::endl;
    animectl.enable_builtin_anim(true);
  } else {
    std::cout << "Disabling built-in animation" << std::endl;
    animectl.enable_builtin_anim(false);
  }
}
