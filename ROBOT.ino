#define TRIG_PIN 7  // Ορισμός του πείρου που στέλνει τον υπέρηχο
#define ECHO_PIN 6  // Ορισμός του πείρου που λαμβάνει την αντανάκλαση του υπερήχου
#define MOTOR_L1 2  // Ορισμός του πείρου που ελέγχει το μοτέρ αριστερά (μπροστά)
#define MOTOR_L2 3  // Ορισμός του πείρου που ελέγχει το μοτέρ αριστερά (πίσω)
#define MOTOR_R1 4  // Ορισμός του πείρου που ελέγχει το μοτέρ δεξιά (μπροστά)
#define MOTOR_R2 5  // Ορισμός του πείρου που ελέγχει το μοτέρ δεξιά (πίσω)

void setup() {
  Serial.begin(9600);  // Εκκίνηση της σειριακής επικοινωνίας στα 9600 baud για εκτύπωση δεδομένων

  pinMode(TRIG_PIN, OUTPUT);  // Ορισμός του TRIG_PIN ως έξοδος (για αποστολή παλμού)
  pinMode(ECHO_PIN, INPUT);   // Ορισμός του ECHO_PIN ως είσοδος (για





Είπες:
καντο στα αγγλικα
Το ChatGPT είπε:
Here is your code with comments in English explaining each command:

cpp
Αντιγραφή
Επεξεργασία
#define TRIG_PIN 7  // Define the pin that sends the ultrasonic signal
#define ECHO_PIN 6  // Define the pin that receives the reflected ultrasonic signal
#define MOTOR_L1 2  // Define the pin controlling the left motor (forward)
#define MOTOR_L2 3  // Define the pin controlling the left motor (backward)
#define MOTOR_R1 4  // Define the pin controlling the right motor (forward)
#define MOTOR_R2 5  // Define the pin controlling the right motor (backward)

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud for debugging

  pinMode(TRIG_PIN, OUTPUT);  // Set TRIG_PIN as output (to send a pulse)
  pinMode(ECHO_PIN, INPUT);   // Set ECHO_PIN as input (to receive the pulse)

  pinMode(MOTOR_L1, OUTPUT);  // Set motor pins as outputs
  pinMode(MOTOR_L2, OUTPUT);
  pinMode(MOTOR_R1, OUTPUT);
  pinMode(MOTOR_R2, OUTPUT);
}

// Function to measure distance using the ultrasonic sensor
float getDistance() {
  digitalWrite(TRIG_PIN, LOW);  
  delayMicroseconds(2);  // Ensure a clean pulse signal
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);  // Send a 10-microsecond pulse
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);  // Measure time for the echo to return
  return duration * 0.034 / 2;  // Convert time into distance in cm
}

// Function to move the robot forward
void moveForward() {
  digitalWrite(MOTOR_L1, HIGH);
  digitalWrite(MOTOR_L2, LOW);
  digitalWrite(MOTOR_R1, HIGH);
  digitalWrite(MOTOR_R2, LOW);
}

// Function to move the robot backward
void moveBackward() {
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_L2, HIGH);
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_R2, HIGH);
}

// Function to turn the robot left
void turnLeft() {
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_L2, HIGH);
  digitalWrite(MOTOR_R1, HIGH);
  digitalWrite(MOTOR_R2, LOW);
}

// Function to stop the motors
void stopMotors() {
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_L2, LOW);
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_R2, LOW);
}

void loop() {
  float distance = getDistance();  // Get the distance measurement
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 15 || distance == 0) {  
    // Move forward for 0.5 seconds and check again
    moveForward();
    delay(500);
    stopMotors();
    delay(100);
  } else {  
    // Object detected within 15 cm
    stopMotors();
    delay(200);
    
    moveBackward();
    delay(300);
    
    stopMotors();
    delay(200);
    
    turnLeft();
    delay(500);  // Turn left for 0.5 sec
    
    stopMotors();
    delay(200);
  }
}