/* 
 * Project Lab 5 Receiver
 * Author: Chase & Cody
 * Date: 10/7/24
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

void setup() {
  // Start the Serial Monitor for viewing data
  Serial.begin(9600); 
  
  // Start Serial1 communication (UART) for receiving data
  Serial1.begin(9600);
  
  Serial.println("Setup complete, waiting for data...");
}

void loop() {
  // Check if data is available from Serial1
  if (Serial1.available()) {
    Serial.println("Data available!");
    
    // Read data character by character
    while (Serial1.available()) {
      char receivedChar = Serial1.read();
      Serial.print(receivedChar);  // Print each character as it's received
    }
    Serial.println(); // Print a newline after receiving all data
  } else {
    Serial.println("No data received.");
  }
  delay(1000); // Delay for readability in the serial monitor
}

