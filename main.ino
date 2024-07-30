#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SENSOR_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

int upButton = 7;
int downButton = 6;
int selectButton = 5;
int menu = 1;
int Timer = 0;
int Timer_1 = 0;
int Timer2 = 0;
int Timer3 = 0;
int Timer4= 0;
int lastState = HIGH; 
int currentState; 


void setup() {
  lcd.init();
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  pinMode(SENSOR_PIN, INPUT);
  

  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Carbolutor V1");
  lcd.setCursor(1, 1);
  lcd.print("Day planner");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Saving Earth");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("One activity");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("a time!");
  digitalWrite(8,HIGH);
  delay(400);
  digitalWrite(8,LOW);
  delay(50);
  digitalWrite(9,HIGH);
  delay(400);
  digitalWrite(9,LOW);
  delay(50);
  digitalWrite(11,HIGH);
  delay(400);
  digitalWrite(11,LOW);
  delay(50);
  digitalWrite(10,HIGH);
  delay(400);
  digitalWrite(10,LOW);
 
  for (int brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(3, brightness); 
    delay(50);
  }
  lcd.clear();
  
  updateMenu();
}

void loop() {
  if (!digitalRead(downButton)){
    menu++;
    updateMenu();
    delay(100);
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton)){
    menu--;
    updateMenu();
    delay(100);
    while(!digitalRead(upButton));
  }
  if (!digitalRead(selectButton)){
    executeAction();
    updateMenu();
    delay(100);
    while (!digitalRead(selectButton));
  }
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      digitalWrite(13, HIGH); 
      delay(300);           
      digitalWrite(13, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(">Morning cleanup");
      break;
    case 2:
      lcd.clear();
      digitalWrite(13, HIGH); 
      delay(300);           
      digitalWrite(13, LOW);
      lcd.setCursor(0, 0);
      lcd.print(">To college(car)");
      break;
    case 3:
      lcd.clear();
      digitalWrite(13, HIGH); 
      delay(300);           
      digitalWrite(13, LOW); 
      lcd.setCursor(0, 0);
      lcd.print(">Lectures");
      break;
    case 4:
      lcd.clear();
      digitalWrite(13, HIGH); 
      delay(300);           
      digitalWrite(13, LOW);
      lcd.setCursor(0, 0);
      lcd.print(">Canteen lunch");
      break;
    case 5:
      lcd.clear();
      digitalWrite(13, HIGH); 
      delay(300);           
      digitalWrite(13, LOW);
      lcd.setCursor(0, 0);
      lcd.print(">Car to home");
      break;
    case 6:
      lcd.clear();
      digitalWrite(13, HIGH); 
      delay(300);           
      digitalWrite(13, LOW);
      lcd.setCursor(0, 0);
      lcd.print(">Nap");
      break;
    case 7:
      lcd.clear();
      digitalWrite(13, HIGH); 
      delay(300);           
      digitalWrite(13, LOW);
      lcd.setCursor(0, 0);
      lcd.print(">Exercise");
      break;
    case 8:
      lcd.clear();
      digitalWrite(13, HIGH); 
      delay(300);           
      digitalWrite(13, LOW);
      lcd.setCursor(0, 0);
      lcd.print(">Veg Dinner");
      break;
    case 9:
      lcd.clear();
      digitalWrite(13, HIGH); 
      delay(300);           
      digitalWrite(13, LOW);
      lcd.setCursor(0, 0);
      lcd.print(">Assignments");
      break;
    case 10:
      lcd.clear();
      digitalWrite(13, HIGH); 
      delay(300);           
      digitalWrite(13, LOW);
      lcd.setCursor(0, 0);
      lcd.print(">meditation");
      break;
    case 11:
      lcd.clear();
      digitalWrite(13, HIGH); 
      delay(300);           
      digitalWrite(13, LOW);
      lcd.setCursor(0, 0);
      lcd.print(">Sleep");
      break;
  }
}

void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
    case 5:
      action5();
      break;
    case 6:
      action6();
      break;
    case 7:
      action7();
      break;
    case 8:
      action8();
      break;
    case 9:
      action9();
      break;
    case 10:
      action10();
      break;
    case 11:
      action11();
      break;
  }
}

void action1() {
  digitalWrite(13, HIGH); 
  delay(300);           
  digitalWrite(13, LOW);
  lcd.setCursor(0,0);
  lcd.print("Water Level 3");
  lcd.setCursor(0,1);
  lcd.print("Save water!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Time");
  lcd.setCursor(0,0);
  lcd.print("8:00AM-8:30AM");
  delay(1500);
}

void action2() {
  digitalWrite(13, HIGH); 
  delay(300);           
  digitalWrite(13, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Emission Level:7");
  lcd.setCursor(0,1);
  lcd.print("Cycle preferable");
  delay(1500);
}

void action3() {
  digitalWrite(13, HIGH); 
  delay(300);           
  digitalWrite(13, LOW);
  lcd.setCursor(0,0);
  lcd.print("EmissionLevel:0");
  lcd.setCursor(0,1);
  lcd.print("Int +10");
  delay(1500);
}

void action4() {
  digitalWrite(13, HIGH); 
  delay(300);           
  digitalWrite(13, LOW);
  lcd.setCursor(0,0);
  lcd.print("Emission level 3");
  lcd.setCursor(0,1);
  lcd.print("Eat healthy!");
 delay(1500);
}

void action5() {
  digitalWrite(13, HIGH); 
  delay(300);           
  digitalWrite(13, LOW);
  lcd.setCursor(0,0);
  lcd.print("Emission level 7");
  lcd.setCursor(0,1);
  lcd.print("Can do better");
 delay(1500);
}

void action6() {
  digitalWrite(13, HIGH); 
  delay(300);           
  digitalWrite(13, LOW);
  lcd.setCursor(0,0);
  lcd.print("Emission Level:0");
  lcd.setCursor(0,1);
  lcd.print("Use fans!");
  delay(1500);
}

void action7() {
  digitalWrite(13, HIGH); 
  delay(300);           
  digitalWrite(13, LOW);
  lcd.setCursor(0,0);
  lcd.print("Emission Level:2");
  lcd.setCursor(0,1);
  lcd.print("Stay active!");
  delay(1500);
}

void action8() {
  digitalWrite(13, HIGH); 
  delay(300);           
  digitalWrite(13, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Emission Level:3");
  lcd.setCursor(0,1);
  lcd.print("Healthy meal");
  delay(1500);
}

void action9() {
  digitalWrite(13, HIGH); 
  delay(300);           
  digitalWrite(13, LOW);
  lcd.setCursor(0,0);
  lcd.print("Emission Level:0");
  lcd.setCursor(0,1);
  lcd.print("Int+1");
  delay(1500);
}

void action10() {
  digitalWrite(13, HIGH); 
  delay(300);           
  digitalWrite(13, LOW);
  lcd.setCursor(0,0);
  lcd.print("Emission level 0");
  lcd.setCursor(0,1);
  lcd.print("Lights off");
 delay(1500);
}

void action11() {
  digitalWrite(13, HIGH); 
  delay(300);           
  digitalWrite(13, LOW);
  lcd.setCursor(0,0);
  lcd.print("Emission level 0");
  lcd.setCursor(0,1);
  lcd.print("Turn off light");
 delay(1500);
}
