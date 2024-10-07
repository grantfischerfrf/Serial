// Define the LED pin (usually the built-in LED)
int ledPin = D7; // Change this to the pin you're using for the LED

// Function to setup UART and LED
void setup() {
    Serial1.begin(9600); // Start Serial1 at 9600 baud
    pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

// Loop function
void loop() {
    // Prepare data to send
    String data = "Hello, Particle!";
    
    // Send data over Serial1
    Serial1.println(data);
    
    // Blink the LED
    digitalWrite(ledPin, HIGH); // Turn LED on
    delay(500);                 // Wait for 500 ms
    digitalWrite(ledPin, LOW);  // Turn LED off
    
    // Wait for 2 seconds before sending the next data
    delay(2000);
}