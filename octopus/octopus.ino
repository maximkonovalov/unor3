/*
 * Copyright (C) 2025 Maxim Konovalov, maxim.konovalov@gmail.com
 *
 * This work is under 2-clause BSD license
 *
 * The project was created as part of the game with my son for
 * the Arduino Uno R3 board.
 */

#include <IRremote.h>

/* Remote Control Codes */
#define FWRD		0x00FF18E7
#define BACK		0x00FF4AB5
#define LEFT		0x00FF10EF
#define RIGHT		0x00FF5AA5
#define STOP		0x00FF38C7

#define irPin		12

#define MOTOR_A_PIN1	2
#define MOTOR_A_PIN2	4
#define MOTOR_B_PIN1	10
#define MOTOR_B_PIN2	11

IRrecv ir(irPin);
decode_results results;

void
motor_command(int motor_a_pin1, int motor_a_pin2,
	int motor_b_pin1, int motor_b_pin2) {
  Serial.println(__func__);

  digitalWrite(MOTOR_A_PIN1, motor_a_pin1);
  digitalWrite(MOTOR_A_PIN2, motor_a_pin2);
  digitalWrite(MOTOR_B_PIN1, motor_b_pin1);
  digitalWrite(MOTOR_B_PIN2, motor_b_pin2);
}

void
motor_forward() {
  Serial.println(__func__);

  motor_command(HIGH, LOW, LOW, HIGH);
}

void
motor_stop() {
  Serial.println(__func__);

  motor_command(LOW, LOW, LOW, LOW);
}

void
motor_right_turn() {
  Serial.println(__func__);

  motor_command(LOW, HIGH, LOW, HIGH);
}

void
motor_left_turn() {
  Serial.println(__func__);

  motor_command(HIGH, LOW, HIGH, LOW);
}

void
motor_backward() {
  Serial.println(__func__);

  motor_command(LOW, HIGH, HIGH, LOW);
}

void
setup() {
  Serial.begin(9600);
  Serial.println(__func__);

  pinMode(MOTOR_A_PIN1, OUTPUT);
  pinMode(MOTOR_A_PIN2, OUTPUT);
  pinMode(MOTOR_B_PIN1, OUTPUT);
  pinMode(MOTOR_B_PIN2, OUTPUT);

  ir.enableIRIn();
}

void
loop() {
  if (ir.decode(&results)) {
    if (1 /* results.value != lastCommand */) {
      if (results.value != 0xFFFFFFFF) {
        /* lastCommand = results.value; */
        switch (results.value) {
          case FWRD:
            Serial.println("FORWARD command");
            motor_forward();
            delay(1000);
            motor_stop();
            break;
          case BACK:
            Serial.println("BACKWARD command");
            motor_backward();
            delay(1000);
            motor_stop();
            break;
          case RIGHT:
            Serial.println("RIGHT command");
            motor_right_turn();
            delay(500);
            motor_stop();
            break;
          case LEFT:
            Serial.println("LEFT command");
            motor_left_turn();
            delay(400);
            motor_stop();
            break;
          case STOP:
            Serial.println("STOP command");
            motor_stop();
            break;
          default:
            Serial.println("Unknown command");
            Serial.println(results.value, HEX);
            break;
        }
      }
    }
    ir.resume();
    delay(100);
  }

  if (!ir.isIdle()) {
    delay(50);
  }
}

/* EOF */
