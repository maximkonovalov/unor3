/*
 * Copyright (C) 2025 Maxim Konovalov, maxim.konovalov@gmail.com
 *
 * This work is under 2-clause BSD license
 *
 * The project was created for my son to play with Arduino board
 */

/*
 * NewPing library wiki
 * https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home
 *
 * Unfortunatelly, it conflicts with the Tone library.  I
 * just put "TIMER_ENABLED false" in NewPing.h
 */
#include <NewPing.h>

#define DELAY		20

#define LED1_PIN	9
#define LED2_PIN	5
#define SPEAKER_PIN	8

/* HC-SR04 Ultrasonic Sensors PINs */

#define SENSOR1_TRIG	3
#define SENSOR1_ECHO	2
#define SENSOR2_TRIG	11
#define SENSOR2_ECHO	12

#define INTENSITY_MAX	50
#define DISTANCE	100

int intensity1;
int intensity2;
int increment1;
int increment2;
int step = 10;

int loop_count = 0;

NewPing sonar1(SENSOR1_TRIG, SENSOR1_ECHO, 50);
NewPing sonar2(SENSOR2_TRIG, SENSOR2_ECHO, 50);

/*
 * Bootstrap
 */
void
setup() {
  Serial.begin(9600);
  Serial.print("*");

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  intensity1 = 0;
  increment1 = step;

  intensity2 = INTENSITY_MAX;
  increment2 = -1 * step;
}

void
loop() {
  int distance1 = 10000;
  int distance2 = 10000;

  loop_count++;

  if (loop_count / 5) {
    intensity1 += increment1;
    intensity2 += increment2;

    Serial.println(intensity1);
    Serial.println(intensity2);

    if (intensity1 >= INTENSITY_MAX)
      increment1 = -1 * step;
    else if (intensity1 <= 0)
      increment1 = step;

    if (intensity2 >= INTENSITY_MAX)
      increment2 = -1 * step;
    else if (intensity2 <= 0)
      increment2 = step;

    distance1 = sonar1.ping_cm();
    Serial.print("Sensor 1: ");
    Serial.println(distance1);

    distance2 = sonar2.ping_cm();
    Serial.print("Sensor 2: ");
    Serial.println(distance2);

    loop_count = 0;
  }
  if ((distance1 && distance1 < DISTANCE) ||
      (distance2 && distance2 < DISTANCE)) {
    analogWrite(LED1_PIN, intensity1);
    analogWrite(LED2_PIN, intensity2);

    tone(SPEAKER_PIN, map(intensity2, 0, INTENSITY_MAX, 50, 2000));
    delay(DELAY);
    noTone(SPEAKER_PIN);

    analogWrite(LED1_PIN, 0);
    analogWrite(LED2_PIN, 0);
  } else
    delay(DELAY);
}

/* EOF */
