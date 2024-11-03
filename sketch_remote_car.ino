#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_TEMPLATE_ID "TMPL30apj_DBx"
#define BLYNK_TEMPLATE_NAME "Home Safety"


// Motor A pins
#define IN1 16
#define IN2 17
#define ENA 21  // Motor A enable pin

// Motor B pins
#define IN3 18
#define IN4 19
#define ENB 22  // Motor B enable pin

// Your WiFi credentials
char ssid[] = "Amshu GT 2";
char pass[] = "Amshu@399";
#define BLYNK_AUTH_TOKEN "YourAuthToken"

BlynkTimer timer;

void setup() {
  // Set motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Set motor speed to full
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  // Initialize serial communication
  Serial.begin(115200);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Function to stop the motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Function to move forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to move backward
void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Function to turn left
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to turn right
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Blynk virtual pin functions for button controls

BLYNK_WRITE(V0) {
  int buttonState = param.asInt();  // Get the button state
  if (buttonState == 1) {
    moveForward();
  } else {
    stopMotors();
  }
}

BLYNK_WRITE(V1) {
  int buttonState = param.asInt();  // Get the button state
  if (buttonState == 1) {
    moveBackward();
  } else {
    stopMotors();
  }
}

BLYNK_WRITE(V2) {
  int buttonState = param.asInt();  // Get the button state
  if (buttonState == 1) {
    turnLeft();
  } else {
    stopMotors();
  }
}

BLYNK_WRITE(V3) {
  int buttonState = param.asInt();  // Get the button state
  if (buttonState == 1) {
    turnRight();
  } else {
    stopMotors();
  }
}

void loop() {
  Blynk.run();  // Run Blynk
  timer.run();  // Run the timer
}
