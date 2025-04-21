// AZ-Visual-Testsketch
// Niklas Heinzel
// 2022

#include <WEMOS_SHT3X.h>          // Library for the SHT3X temperature and humidity sensor
#include <Adafruit_SSD1306.h>     // Library for the SSD1306 OLED display
#include <splash.h>               // Splash screen definitions
#include <Adafruit_GFX.h>         // Core graphics library
#include <Adafruit_MonoOLED.h>    // OLED-specific library
#include <Adafruit_SPITFT.h>      // SPI TFT display library
#include <Adafruit_SPITFT_Macros.h> // SPI TFT macros
#include <gfxfont.h>              // Font definitions
#include <Wire.h>                 // I2C communication

// Initialize the SHT3X sensor with the I2C address 0x44
SHT3X sht30(0x44);

// Define OLED display dimensions
#define SCREEN_WIDTH 128 // OLED width in pixels
#define SCREEN_HEIGHT 32 // OLED height in pixels

// Declaration for SSD1306 display connected via I2C
#define OLED_RESET -1    // Reset pin # (-1 if shared with Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Define the analog input pin connected to the LDR
const int analogInPin = A0;
int sensorValue = 0; // Variable to store ADC readings from the LDR

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  pinMode(sensorValue, INPUT); // Set ADC pin as input

  // Initialize the OLED display with address 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 initialization failed")); // Error message
    for (;;); // Halt execution if initialization fails
  }

  // Display Adafruit splash screen
  display.display();
  delay(2000); // Wait for 2 seconds

  // Clear the display buffer
  display.clearDisplay();

  // Set text size and color for initial display message
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 10); // Set text position
  display.println(F("AZ-Visual"));

  // Render the text on the OLED display
  display.display();
  delay(3000);
  display.clearDisplay();
}

void loop() {
  // Print separator line to the serial monitor
  Serial.println("----------------------------------------------");

  // Read the ADC value from the analog input pin
  int sensorValue = analogRead(analogInPin);
  Serial.print("LDR Value: "); // Display the sensor value label
  Serial.println(sensorValue); // Output the ADC value
  Serial.println("----------------------------------------------");

  // Clear the display buffer
  display.clearDisplay();

  // Display sensor data on the OLED screen
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0); // Set text position
  display.println(F("Sensor Values:"));
  display.print("LDR=");
  display.println(sensorValue);

  // Retrieve temperature and humidity values from the SHT3X sensor
  if (sht30.get() == 0) {
    Serial.print("Temperature in Celsius: ");
    Serial.println(sht30.cTemp);
    Serial.print("Temperature in Fahrenheit: ");
    Serial.println(sht30.fTemp);
    Serial.print("Relative Humidity: ");
    Serial.println(sht30.humidity);
    Serial.println();
  } else {
    Serial.println("Error reading SHT3X sensor!");
  }

  // Display temperature and humidity values on the OLED screen
  display.print("Temperature=");
  display.println(sht30.cTemp);
  display.print("Humidity=");
  display.println(sht30.humidity);

  // Render the updated content on the OLED display
  display.display();

  delay(5000); // Wait for 5 seconds before the next iteration
}
