/*
 * Copyright (C) 2025 Maxim Konovalov, maxim.konovalov@gmail.com
 *
 * This work is under 2-clause BSD license
 *
 * The project was created as part of the game with my son for
 * the Arduino Uno R3 board.
 */

/*
 * Make the onboard LED blink
 */

#define LED 13
#define DELAY 500

/*
 * Bootstrap
 */
void setup() {
  /*
   * There is an onboard LED that connected to the
   * pin 13 which is defined as "LED".
   * Reconfigure the port to the output mode.
   */
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.print("*");
}

void loop() {
  Serial.print(".");
  digitalWrite(LED, HIGH);
  delay(DELAY);
  digitalWrite(13, LOW);
  delay(DELAY);
}

/* EOF */
