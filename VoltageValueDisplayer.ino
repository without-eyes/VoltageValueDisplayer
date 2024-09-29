#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  double averageVoltage = findAverageValue();
  int adcValue = analogRead(A0);
  double voltageValue = convertAdcValueToVoltage(adcValue);

  lcd.clear();

  printVoltageValue(voltageValue);
  printAvarageVoltageValue(averageVoltage);

  delay(200);
}

double findAverageValue() {
  double sumVoltage = 0;
  for (int i = 0; i < 50; i++) {
    int adcValue = analogRead(A0);
    sumVoltage += ((double)adcValue / 1023) * 5;
    delay(20);
  }
  return sumVoltage / 50;
}

double convertAdcValueToVoltage(int adcValue) {
  return ((double)adcValue / 1023) * 5;
}

void printVoltageValue(double voltageValue) {
  lcd.setCursor(0, 0);
  lcd.print("U: ");
  lcd.print(voltageValue, 2);
  lcd.print(" [V]");
}

void printAvarageVoltageValue(double averageVoltage) {
  lcd.setCursor(0, 1);
  lcd.print("Usr: ");
  lcd.print(averageVoltage, 2);
  lcd.print(" [V]");
}