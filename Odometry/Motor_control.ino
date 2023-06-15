// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B connections
int enB = 10;
int in3 = 6;
int in4 = 5;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Initialize the serial communication
  Serial.begin(9600);
}

void loop() {
  // Motor A forward at maximum speed
  motorControl(enA, in1, in2, 255, HIGH, LOW);

  // Motor B forward at maximum speed
  motorControl(enB, in3, in4, 255, HIGH, LOW);

  delay(2000); // Wait for 2 seconds
  
  // Motor A backward at half speed
  motorControl(enA, in1, in2, 127, LOW, HIGH);

  // Motor B backward at half speed
  motorControl(enB, in3, in4, 127, LOW, HIGH);

  delay(2000); // Wait for 2 seconds
  
  // Stop both motors
  motorControl(enA, in1, in2, 0, LOW, LOW);
  motorControl(enB, in3, in4, 0, LOW, LOW);

  delay(2000); // Wait for 2 seconds
}

// Function to control a motor using PWM for speed control
void motorControl(int enPin, int inPin1, int inPin2, int speed, int direction1, int direction2) {
  analogWrite(enPin, speed); // Set the motor speed using PWM
  digitalWrite(inPin1, direction1); // Set the motor direction
  digitalWrite(inPin2, direction2);
}
