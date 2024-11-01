#include <LiquidCrystal_I2C.h> // includes the I2C library

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the address for the I2C module, and the lines and characters per line.

String line1 = "Group no 3 & 5"; // First line message
String line2 = "Mamun Chandan Shoibo Oishee Sufia Reshmi"; // Second line message (long text)

void setup() {
  lcd.init(); // initialize the lcd
  lcd.backlight(); // turn on the backlight
  lcd.setCursor(0, 0); // set cursor position for line 1
  lcd.print(line1); // print first line message
  delay(2000); // display for 2 seconds
}

void loop() {
 // lcd.setCursor(0, 0); // keep first line static
 // lcd.print(line1); // display first line message
  
  lcd.setCursor(0, 1); // start from the first position on the second line
  for (int i = 0; i < line2.length() - 15; i++) { // scroll till the length of the message minus the display width
    //lcd.clear();
    
    lcd.setCursor(0, 0); // keep first line static
    lcd.print(line1); // display first line message

    lcd.setCursor(0, 1); // set cursor for second line scroll
    lcd.print(line2.substring(i, i + 16)); // print 16 characters at a time from the second line message
    delay(200); // speed of scrolling
    lcd.clear();
    //lcd.setCursor(0, 15); // set cursor for second line scroll
    //lcd.print(line2.substring(i, i + 16)); // print 16 characters at a time from the second line message
    //delay(200); // speed of scrolling
  }
}
