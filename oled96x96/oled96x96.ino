/*
 * Copyright (C) 2025 Maxim Konovalov, maxim.konovalov@gmail.com
 *
 * This work is under 2-clause BSD license
 *
 * The project was created as part of the game with my son for
 * the Arduino Uno R3 board.
 */

/*
 * OLED 96x96 experiments with Seeed OLED Display 96*96 library
 * https://github.com/Seeed-Studio/OLED_Display_96X96
 */
#include <Wire.h>
#include <SeeedGrayOLED.h>

/*
 * Bootstrap
 */
void setup() {
  int i, max_rows = 16;

  Wire.begin();
  SeeedGrayOled.init(SH1107G);

  SeeedGrayOled.clearDisplay();
  SeeedGrayOled.setNormalDisplay();
  SeeedGrayOled.setVerticalMode();

  for (i = 0; i < max_rows; i++) {
    SeeedGrayOled.setTextXY(i, 0);
    SeeedGrayOled.putString("0123456789012345");
  }
}

void loop() {
}

/* EOF */
