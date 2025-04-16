/*
 * Copyright (C) 2025 Maxim Konovalov, maxim.konovalov@gmail.com
 *
 * This work is under 2-clause BSD license
 *
 * The project was created as part of the game with my son for
 * the Arduino Uno R3 board.
 */

#include <IRremote.h>
#include <AFMotor.h>

/* Remote Control Codes */
#define FWRD  0x00FF18E7
#define BACK  0x00FF4AB5
#define LEFT  0x00FF10EF
#define RIGHT 0x00FF5AA5
#define STOP  0x00FF38C7

#define irPin 12

IRrecv ir(irPin);
decode_results results;

AF_DCMotor motor_right(3);
AF_DCMotor motor_left(4);

void motor_forward() {
  Serial.println("motor_forward()");

  motor_right.setSpeed(127);
  motor_left.setSpeed(127);

  motor_right.run(RELEASE);
  motor_left.run(RELEASE);

  delay(10);

  motor_right.run(FORWARD);
  motor_left.run(FORWARD);
}

void motor_stop() {
  Serial.println("motor_stop()");
  motor_right.run(RELEASE);
  motor_left.run(RELEASE);
}

void motor_right_turn() {
  Serial.println("motor_left_turn()");

  motor_right.setSpeed(127);
  motor_left.setSpeed(127);

  motor_right.run(RELEASE);
  motor_left.run(RELEASE);

  delay(10);

  motor_right.run(FORWARD);
  motor_left.run(BACKWARD);

  delay(300);

  motor_right.setSpeed(0);
  motor_left.setSpeed(0);
}

void motor_left_turn() {
  Serial.println("motor_left_turn()");

  motor_right.setSpeed(127);
  motor_left.setSpeed(127);

  motor_right.run(RELEASE);
  motor_left.run(RELEASE);

  delay(10);

  motor_right.run(BACKWARD);
  motor_left.run(FORWARD);

  delay(300);

  motor_right.setSpeed(0);
  motor_left.setSpeed(0);
}

void motor_backward() {
  Serial.println("motor_backward()");

  motor_right.setSpeed(127);
  motor_left.setSpeed(127);

  motor_right.run(RELEASE);
  motor_left.run(RELEASE);

  delay(10);

  motor_right.run(BACKWARD);
  motor_left.run(BACKWARD);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("motor test");

  ir.enableIRIn();

  motor_right.setSpeed(127);
  motor_right.run(RELEASE);

  motor_left.setSpeed(127);
  motor_left.run(RELEASE);
}

void loop()
{
  if (ir.decode(&results)) {
    if (1 /* results.value != lastCommand */) {
      if (results.value != 0xFFFFFFFF) {
        /* lastCommand = results.value; */
        switch (results.value) {
          case FWRD:
            Serial.println("FORWARD command");
            motor_forward();
            break;
          case BACK:
            Serial.println("BACKWARD command");
            motor_backward();
            break;
          case RIGHT:
            Serial.println("RIGHT command");
            motor_right_turn();
            break;
          case LEFT:
            Serial.println("LEFT command");
            motor_left_turn();
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
