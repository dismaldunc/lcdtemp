/* 



Arduino Tutorial: Learn how to use an LCD 16x2 screen
   More info: http://www.ardumotive.com/how-to-use-an-lcd-dislpay-en.html 
   
   this is a temp reader with a pre set alarm 
   
   */

//Include LCD library
#include <LiquidCrystal.h>

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 7 on the Arduino
#define ONE_WIRE_BUS 7

// Setup a oneWire instance to communicate with any OneWire devices
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Only 6 signal are required, RS, Enable, D4, D5, D6 and D7.
//The R/W pin must be connected to ground. Pins D0, D1, D2 and D3
//are left unconnected

int buzzer = 8 ;

// buzzer object connected to digital port 8



void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temperature");
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  // Start up the library
  sensors.begin();

}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);

  sensors.requestTemperatures(); // Send the command to get temperatures

  lcd.print(sensors.getTempCByIndex(0));
  lcd.print("   Celcius");
  delay(500);
  Serial.print(sensors.getTempCByIndex(0));
  lcd.print("    ");

// the code below here is the alarm function currently set to 30 degrees

  int temp = (sensors.getTempCByIndex(0));

  Serial.print (temp);
  if (temp >= 30) digitalWrite(buzzer, HIGH);

  else if(temp <= 30)  digitalWrite (buzzer, LOW);

}
