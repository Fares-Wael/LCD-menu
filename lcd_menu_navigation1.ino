#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);
byte Arrow[8]={
  B10000,
  B11000,
  B11100,
  B11110,
  B11110,
  B11100,
  B11000,
  B10000
};
byte c=0;
byte read=0;
byte read1=0;
byte UpButton=3;
byte DownButton=4;
void setup() {
lcd.init();
lcd.backlight();
lcd.createChar(0, Arrow);
pinMode(UpButton,INPUT);
pinMode(DownButton,INPUT);
lcd.setCursor(0,0);
lcd.write(byte(0));
lcd.setCursor(1,0);
lcd.print("Select Programe");
lcd.setCursor(0,1);
lcd.print("Settings");
}
void Mode1(){
lcd.clear();
lcd.setCursor(0,0);
lcd.write(byte(0));
lcd.setCursor(1,0);
lcd.print("Select Programe");
lcd.setCursor(0,1);
lcd.print("Settings");
}
void Mode2(){
lcd.clear();
lcd.setCursor(0,1);
lcd.write(byte(0));
lcd.setCursor(0,0);
lcd.print("Select Programe");
lcd.setCursor(1,1);
lcd.print("Settings");
}
void Mode3(){
  lcd.clear();
lcd.setCursor(0,1);
lcd.write(byte(0));
lcd.setCursor(0,0);
lcd.print("Settings");
lcd.setCursor(1,1);
lcd.print("Power Saving");
}
void Mode4(){
  lcd.clear();
lcd.setCursor(0,1);
lcd.write(byte(0));
lcd.setCursor(0,0);
lcd.print("Power Saving");
lcd.setCursor(1,1);
lcd.print("Shutdown");
}
void Mode5(){
  lcd.clear();
lcd.setCursor(0,0);
lcd.write(byte(0));
lcd.setCursor(1,0);
lcd.print("Power Saving");
lcd.setCursor(0,1);
lcd.print("Shutdown");
}
void Mode6(){
  lcd.clear();
lcd.setCursor(0,0);
lcd.write(byte(0));
lcd.setCursor(1,0);
lcd.print("Settings");
lcd.setCursor(0,1);
lcd.print("Power Saving");
}

void loop() {
read=digitalRead(UpButton);
read1=digitalRead(DownButton);
if (read==HIGH&&c==0){
Mode2();
c=1;
}
else if (read1==HIGH&&c==0){
c=0;
Mode1();
}
else if (read==HIGH&&c==1){
Mode3();
c=2;
}
else if (read1==HIGH&&c==1){
Mode2();
c=0;
}
else if (read==HIGH&&c==2){
Mode4();
c=3;
}
else if (read1==HIGH&&c==2){
Mode3();
c=1;
}
else if (read==HIGH&&c==3){
Mode5();
c=4;
}
else if (read1==HIGH&&c==3){
Mode4();
c=2;
}
else if (read1==HIGH&&c==4){
Mode6();
c=5;
}
  if (c==4){
    Mode4();
    c=3;
  }
}