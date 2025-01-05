#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Constants
#define DHTPIN 2      // Pin connected to DHT sensor
#define DHTTYPE DHT11 // DHT11 or DHT22
#define TEMP_THRESHOLD 30 // Temperature threshold in Celsius
#define HUM_THRESHOLD 70  // Humidity threshold in percentage
#define LEDPIN 13     // Pin connected to LED
#define BUZZERPIN 12  // Pin connected to Buzzer

// Objects
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(LEDPIN, OUTPUT);
    pinMode(BUZZERPIN, OUTPUT);
    dht.begin();
    lcd.begin();
    lcd.backlight();
    lcd.print("Initializing...");
    delay(2000);
    lcd.clear();
}

void loop() {
    // Read temperature and humidity
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    // Check if reading is valid
    if (isnan(temp) || isnan(hum)) {
        lcd.setCursor(0, 0);
        lcd.print("Sensor Error!");
        delay(2000);
        return;
    }

    // Display data on LCD
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(hum);
    lcd.print(" %");

    // Trigger alerts
    if (temp > TEMP_THRESHOLD || hum > HUM_THRESHOLD) {
        digitalWrite(LEDPIN, HIGH);
        digitalWrite(BUZZERPIN, HIGH);
    } else {
        digitalWrite(LEDPIN, LOW);
        digitalWrite(BUZZERPIN, LOW);
    }

    delay(2000); // Update every 2 seconds
}
