// ------------------------------------------------------------------
// PROJECT: Intelligent Dual-Axis Solar Tracker (Closed-Loop Control)
// Microcontroller: Arduino Nano
// Components: 4 LDRs, 2 Servo Motors
// ------------------------------------------------------------------

#include <Servo.h> 

// Define Analog Pins for the 4 LDR sensors
#define LDR_TOP_LEFT    A0
#define LDR_TOP_RIGHT   A1
#define LDR_DOWN_LEFT   A2
#define LDR_DOWN_RIGHT  A3

// Define Digital Pins for the 2 Servo Motors
#define PIN_HORIZONTAL  3
#define PIN_VERTICAL    5

Servo horizontal_servo; // Object for the Horizontal Axis Servo
Servo vertical_servo;   // Object for the Vertical Axis Servo

// Initial positions (90 degrees = centered)
int pos_h = 90; 
int pos_v = 90;

// Threshold for error acceptance (Control Sensitivity)
// The system only moves if the light difference is greater than 10
const int THRESHOLD = 10; 

// ------------------------------------------------------------------
// SETUP: Runs once when the Arduino starts
// ------------------------------------------------------------------
void setup() {
  // Start Serial communication for debugging (Optional but Recommended)
  Serial.begin(9600); 

  // Attach Servo objects to their control pins
  horizontal_servo.attach(PIN_HORIZONTAL);
  vertical_servo.attach(PIN_VERTICAL);

  // Set the initial position to the center
  horizontal_servo.write(pos_h);
  vertical_servo.write(pos_v);
  
  delay(1000); 
}

// ------------------------------------------------------------------
// LOOP: Main control logic (Runs repeatedly for Closed-Loop Control)
// ------------------------------------------------------------------
void loop() {
  
  // 1. Read the current analog values from all four LDRs
  int val_tl = analogRead(LDR_TOP_LEFT);
  int val_tr = analogRead(LDR_TOP_RIGHT);
  int val_dl = analogRead(LDR_DOWN_LEFT);
  int val_dr = analogRead(LDR_DOWN_RIGHT);

  // 2. Calculate Horizontal Error (Left vs. Right)
  int left_sum = val_tl + val_dl;  
  int right_sum = val_tr + val_dr;
  int diff_h = left_sum - right_sum; // Positive diff means light is stronger on the left

  // 3. Calculate Vertical Error (Up vs. Down)
  int up_sum = val_tl + val_tr;
  int down_sum = val_dl + val_dr;
  int diff_v = up_sum - down_sum; // Positive diff means light is stronger on the top

  // --- 4. Incremental Horizontal Control Logic ---
  if (diff_h > THRESHOLD) {
    // Light is stronger on the left, move horizontally +1 degree
    pos_h = pos_h + 1; 
  }
  else if (diff_h < -THRESHOLD) {
    // Light is stronger on the right, move horizontally -1 degree
    pos_h = pos_h - 1; 
  }
  
  // Constrain the angle between 0 and 180 degrees
  pos_h = constrain(pos_h, 0, 180); 
  horizontal_servo.write(pos_h);
  
  // --- 5. Incremental Vertical Control Logic ---
  if (diff_v > THRESHOLD) {
    // Light is stronger on the top, move vertically +1 degree
    pos_v = pos_v + 1; 
  }
  else if (diff_v < -THRESHOLD) {
    // Light is stronger on the bottom, move vertically -1 degree
    pos_v = pos_v - 1;
  }

  // Constrain the angle between 0 and 180 degrees
  pos_v = constrain(pos_v, 0, 180);
  vertical_servo.write(pos_v);
  
  delay(50); // Small delay to stabilize the movement
}
