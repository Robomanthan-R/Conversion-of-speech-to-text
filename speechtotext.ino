#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define pins for Bluetooth communication
const int bluetoothTx = 10; // TX pin of Bluetooth module connected to Arduino digital pin 10
const int bluetoothRx = 11; // RX pin of Bluetooth module connected to Arduino digital pin 11

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx); // Create a SoftwareSerial object for Bluetooth communication

// Define OLED display parameters
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  bluetooth.begin(9600); // Start Bluetooth communication

  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32 OLED display
  display.display();
  delay(2000); // Delay for OLED initialization
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Speech to Text");
  display.display();
  delay(2000); // Delay to show the title on OLED display
}

void loop() {
  if (bluetooth.available()) { // Check if data is available to read from Bluetooth
    String speechInput = bluetooth.readStringUntil('\n'); // Read the incoming speech input
    
    // Display the speech input on OLED display
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Speech Input:");
    display.println(speechInput);
    display.display();
  }
}

