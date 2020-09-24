/* Adrian Wojciechowski
 * 
 * number system converter
 * lcd 16x2 on AVT 1615
 */

#include <LiquidCrystal.h>
#define BUTTON1 0
#define BUTTON2 1
#define BUTTON3 2
#define BUTTON4 3

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //(Rs, E, D4, D5, D6, D7)

void setup() {
  lcd.begin(16,2);                   //Initialize screen size
  pinMode(BUTTON1, INPUT);           //Initialize input buttons
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  lcd.clear();                       //Alway clear at the beggining to avoid unwanted characters on screen.
  lcd.print("Adrian");               //Welcome screen.
  lcd.setCursor(0,1);
  lcd.print("Wojciechowski");
  delay(3000);
}

void loop() {
  unsigned int n = 0;
  int convTo = 2;
  while (true) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(n);
    lcd.setCursor(0,1);
    lcd.print(valuate(n, convTo));
    if (digitalRead(BUTTON1) == LOW && n < 65536) n++;
    else if (digitalRead(BUTTON2) == LOW && n > 0) n--;
    else if (digitalRead(BUTTON3) == LOW && convTo < 10) convTo++;
    else if (digitalRead(BUTTON4) == LOW && convTo > 2) convTo--;
    delay(100);
  }
}

// Calculating convertion to string.
String valuate(unsigned int n, int convTo) {
  String result = "";
  // Calculating from first to before the last one position
  while (n >= convTo) {
    result += (n%convTo);
    n /= convTo;
  }
  // Copying last position
  result += n;
  // Reverse string
  for (int i = 0; i < result.length()/2; i++) {
    char temp = result[i];
    result[i] = result[result.length()-1-i];
    result[result.length()-1-i] = temp;
  }
  return result;
}
