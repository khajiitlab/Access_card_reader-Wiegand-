#include <LiquidCrystal.h>
#include <Wiegand.h>

#define FALSE 0      
#define TRUE  1 

WIEGAND wg;
int RS = 12;
int E = 11;
int DB4 = 4;
int DB5 = 5;
int DB6 = 6;
int DB7 = 7;
int DATA0 = 2;
int DATA1 = 3;

LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

void setup() {
  Serial.begin(9600); 
  lcd.begin(16, 2);
  wg.D0PinA = DATA0;   
  wg.D1PinA = DATA1; 
  wg.begin(TRUE, FALSE, FALSE);
  
  lcd.print(" Waiting card...");
}

void loop() {
  
  if(wg.available())
  {
    lcd.clear();
    
    Serial.print("Wiegand HEX = ");
    Serial.print(wg.getCode(),HEX);
    
    Serial.print(", DECIMAL = ");
    Serial.print(wg.getCode());
    lcd.setCursor(0, 0);
    lcd.print("  DEC : ");
    lcd.print(wg.getCode());
    
    Serial.print(", Gate= ");
    Serial.print(wg.getGateActive());
    
    Serial.print(", Type W");
    Serial.println(wg.getWiegandType());  
    lcd.setCursor(0, 1);
    lcd.print("  TYPE : ");
    lcd.print(wg.getWiegandType());
  }
}
