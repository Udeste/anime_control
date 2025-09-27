#pragma once

#include "animectl.h"

void handle_enable_command(bool enable, AnimeCtl &animectl);
void handle_brightness_command(int brightness, AnimeCtl &animectl);
void handle_enable_builtin_anim_command(bool enable, AnimeCtl &animectl);
