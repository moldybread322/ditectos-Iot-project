const int LED_PIN = 3; // Assign pin 3 for the LED
const int PIR_SENSOR_PIN = 2; // Assign pin 2 for PIR Sensor

unsigned long startTime = 0; // Variable to store start time
bool motionDetected = false; // Flag to indicate motion detection

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(LED_PIN, OUTPUT); // Set LED pin as output
  pinMode(PIR_SENSOR_PIN, INPUT_PULLUP); // Set PIR Sensor pin as input with pull-up resistor
  attachInterrupt(digitalPinToInterrupt(PIR_SENSOR_PIN), detection, RISING);
  // Used as a trigger for the detection function and rising mode
}

void detection() {
  Serial.println("MOTION DETECTED"); // Print to serial monitor
  digitalWrite(LED_PIN, HIGH); // Turn on the LED
  startTime = millis(); // Record the start time
  motionDetected = true; // Set the motion detected flag
}

void loop() {
  unsigned long currentTime = millis(); // Current time
  if (motionDetected) { // If motion detected
    if (currentTime - startTime > 2000) { // If 2 seconds have passed
      Serial.println("NO MOTION DETECTED");
      digitalWrite(LED_PIN, LOW); // Turn off the LED
      motionDetected = false; // Reset motion detection flag
    }
  }
  else {
    Serial.println("NO MOTION DETECTED"); // Print to serial monitor
  }
  delay(500); // Delay for stability
}
