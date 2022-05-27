//MPCA Elevator Project Project
//Arduino UNO R3
//By:-
//Azhar Ameen (PES1UG20CS098)
//Anush Somasundaram (PES1UG20CS068)

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //I2C Lcd display

#define button0 2 //button 0 assigned to pin 2
#define button1 3 //button 1 assigned to pin 3
#define button2 4 //button 2 assigned to pin 4
#define button3 5 //button 3 assigned to pin 5

#define dir1 6 //motor control 1 assigned to pin 6
#define dir2 7 //motor control 2 assigned to pin 7

#define IR0 8 //ground floor ir sensor assigned to pin 8
#define IR1 9 //first floor ir sensor assigned to pin 9
#define IR2 10 //second floor ir sensor assigned to pin 10
#define IR3 11 //third floor ir sensor assigned to pin 11


int currentfloor=0;
int b0=0,b1=0,b2=0,b3=0,i0=0,i1=0,i2=0,i3=0;

void setup() {
  //Setting the pins which have buttona as inputs
  pinMode(button0, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  //Setting the pins which have ir sensors as inputs
  pinMode(IR0, INPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);

  //Setting the pins which are connected to the motor driver as output
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);

  lcd.begin();
  lcd.backlight();
  lcd.clear();
  Serial.begin(9600);

  lcd.setCursor(0,0);
  lcd.print("Elevator Project");
  lcd.setCursor(0,1);
  lcd.print("Azhar & Anush");
  delay(5000);

  i0 = digitalRead(IR0);
  i1 = digitalRead(IR1);
  i2 = digitalRead(IR2);
  i3 = digitalRead(IR3);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Startup");
  lcd.setCursor(0,1);
  lcd.print("Calibration");

  //The code below is to take the elevator to the ground gloor by default on startup
  while(i0 == HIGH){
    digitalWrite(dir2,HIGH);
    digitalWrite(dir1,LOW);
    i0=digitalRead(IR0);
  }
  digitalWrite(dir2,HIGH);
  digitalWrite(dir1,HIGH);
  delay(2000);
  lcd.clear();  
}

void loop() {
  // Reading the data from the sensors connected to the digital pins
  b0 = digitalRead(button0);
  b1 = digitalRead(button1);
  b2 = digitalRead(button2);
  b3 = digitalRead(button3);

  i0 = digitalRead(IR0);
  i1 = digitalRead(IR1);
  i2 = digitalRead(IR2);
  i3 = digitalRead(IR3);
  lcd.setCursor(0,0);
  lcd.print("Current Floor");
  lcd.setCursor(7,1);
  lcd.print(currentfloor);
  if(i0==LOW ||i1==LOW || i2==LOW || i3==LOW){
    
    if(b0 == HIGH){
      groundfloor();
      digitalWrite(dir2,HIGH);
      digitalWrite(dir1,HIGH);
    }
  
    if(b3 == HIGH){
      thirdfloor();
      digitalWrite(dir2,HIGH);
      digitalWrite(dir1,HIGH);    
    }
  
    if(b2==HIGH){
      secondfloor();
      digitalWrite(dir2,HIGH);
      digitalWrite(dir1,HIGH); 
    }
  
    if(b1==HIGH){
      firstfloor();
      digitalWrite(dir2,HIGH);
      digitalWrite(dir1,HIGH);
    }
  }

  else{

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Error, Moving to");
    lcd.setCursor(0,1);
    lcd.print("Nearest Floor");
    delay(1000);
    
    if(currentfloor == 0){
     while(i0 == HIGH){
        digitalWrite(dir2,HIGH);
        digitalWrite(dir1,LOW);
        i0=digitalRead(IR0);
        delay(10);
      }
      digitalWrite(dir2,HIGH);
      digitalWrite(dir1,HIGH);
      currentfloor=0;
    }

    if(currentfloor == 1){
      while(i0 == HIGH){
        digitalWrite(dir2,HIGH);
        digitalWrite(dir1,LOW);
        i0=digitalRead(IR0);
        delay(10);
     }
      digitalWrite(dir2,HIGH);
      digitalWrite(dir1,HIGH);
      currentfloor=0;
    }

    if(currentfloor == 2){
      while(i1 == HIGH){
        digitalWrite(dir2,HIGH);
        digitalWrite(dir1,LOW);
        i1=digitalRead(IR1);
        delay(10);
      }
      digitalWrite(dir2,HIGH);
      digitalWrite(dir1,HIGH);
      currentfloor=1;
    }

    if(currentfloor == 3){
      while(i2 == HIGH){
        digitalWrite(dir2,HIGH);
        digitalWrite(dir1,LOW);
        i2=digitalRead(IR2);
        delay(10);
      }
      digitalWrite(dir2,HIGH);
      digitalWrite(dir1,HIGH);
      currentfloor=2;
    }
    lcd.clear();
  }
}



void groundfloor(){
  lcd.clear();
  while(i0 == HIGH){
    digitalWrite(dir2,HIGH);
    digitalWrite(dir1,LOW);
    i0=digitalRead(IR0);
    currentfloor = 0;
    lcd.setCursor(0,0);
    lcd.print("Elevator");
    lcd.setCursor(0,1);
    lcd.print("Descending");
    delay(10);
 }
 lcd.clear();
}

void thirdfloor(){
  lcd.clear();
  while(i3 == HIGH){
    digitalWrite(dir2,LOW);
    digitalWrite(dir1,HIGH);
    i3=digitalRead(IR3);
    currentfloor = 3;
    lcd.setCursor(0,0);
    lcd.print("Elevator");
    lcd.setCursor(0,1);
    lcd.print("Ascending");
    delay(10);
 }
 lcd.clear();
}

void secondfloor(){
  lcd.clear();
  if(i0==LOW || i1==LOW){
    while(i2 == HIGH){
      digitalWrite(dir2,LOW);
      digitalWrite(dir1,HIGH);
      i2=digitalRead(IR2);
      currentfloor = 2;
      lcd.setCursor(0,0);
      lcd.print("Elevator");
      lcd.setCursor(0,1);
      lcd.print("Acending");
      delay(10);
    }    
  }
  if(i3==LOW){
    while(i2 == HIGH){
      digitalWrite(dir2,HIGH);
      digitalWrite(dir1,LOW);
      i2=digitalRead(IR2);
      currentfloor = 2;
      lcd.setCursor(0,0);
      lcd.print("Elevator");
      lcd.setCursor(0,1);
      lcd.print("Descending");
      delay(10);
    }    
  }
  lcd.clear();
}

void firstfloor(){
  lcd.clear();
  if(i0==LOW){
    while(i1 == HIGH){
      digitalWrite(dir2,LOW);
      digitalWrite(dir1,HIGH);
      i1=digitalRead(IR1);
      currentfloor = 1;
      lcd.setCursor(0,0);
      lcd.print("Elevator");
      lcd.setCursor(0,1);
      lcd.print("Ascending");
      delay(10);
    }    
  }
  if(i3==LOW || i2==LOW){
    while(i1 == HIGH){
      digitalWrite(dir2,HIGH);
      digitalWrite(dir1,LOW);
      i1=digitalRead(IR1);
      currentfloor = 1;
      lcd.setCursor(0,0);
      lcd.print("Elevator");
      lcd.setCursor(0,1);
      lcd.print("Descending");
      delay(10);
    }    
  }
  lcd.clear();
}
