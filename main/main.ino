#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);
int bp1 = 2;
int button_state;

int brochepot = A0;
int valpot;
int conversion;

void setup() {
  pinMode(bp1, INPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.display();
  lcd.setCursor(0, 0);
  lcd.print("BAC PRO SN - IRIS");
}

void loop() {
  button_state = digitalRead(bp1);
  valpot = analogRead(brochepot);
  conversion = map(valpot, 0, 1024, 0, 180);

  lcd.setCursor(0, 1);
  if (button_state == 1) {
    lcd.print("Button state: ON    ");
  } else {
    lcd.print("Button state: OFF");
  }

  lcd.setCursor(0, 2);
  lcd.print("Potentiometre " + String(conversion));
}
