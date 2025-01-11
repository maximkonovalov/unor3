/*
 * Copyright (C) 2025 Maxim Konovalov, maxim.konovalov@gmail.com
 *
 * This work is under 2-clause BSD license
 *
 * The project was created as part of the game with my son for
 * the Arduino Uno R3 board.
 */

/*
 *
 */
#include <LiquidCrystal.h>

const int switchPin = 6;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*
 * Bootstrap
 */
void setup() {
  lcd.begin(16, 2);
  lcd.home();
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystall Ball! ");
  lcd.cursor();
  lcd.blink();
}

void loop() {
  int switchState = 0;
  int prevSwitchState = 0;
  int reply;

  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(8);

      lcd.clear();
      lcd.home();
      lcd.print("The ball says:");
      lcd.setCursor(0, 1);
      switch (reply) {
        case 0:
          lcd.print("Yes ");
          break;
        case 1:
          lcd.print("Most likely ");
          break;
        case 2:
          lcd.print("Certainly ");
          break;
        case 3:
          lcd.print("Outlook good ");
          break;
        case 4:
          lcd.print("Unsure ");
          break;
        case 5:
          lcd.print("Ask again ");
          break;
        case 6:
          lcd.print("Doubtful ");
          break;
        case 7:
          lcd.print("No ");
          break;
        default:
          break;
      }
    }
  }
  prevSwitchState = switchState;
}

/* EOF */
