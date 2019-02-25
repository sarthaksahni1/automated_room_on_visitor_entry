#include<LiquidCrystal.h> 
LiquidCrystal lcd(13,12,11,10,9,8); 
int In = 4; 
int Out = 5; 
int relay = 2; 
int count=0; 
void setup() 
{ 
  lcd.begin(16,2); 
  lcd.print("Visitor Counter"); 
  delay(2000); 
  pinMode(In, INPUT); 
  pinMode(Out, INPUT); 
  pinMode(relay, OUTPUT); 
  lcd.clear(); 
  lcd.print("Person In Room:"); 
  Serial.begin(9600); 
} 
void loop() 
{    
  if (digitalRead(In) == LOW){ 
    count++; 
  } 
 
  else if (digitalRead(Out) == LOW){ 
    count--; 
  } 
   
  else if (count > 0) 
  { 
    digitalWrite(relay, HIGH); 
  } 
 
  else if(count <= 0){ 
    digitalWrite(relay, LOW); 
  } 
 
  lcd.setCursor(0,1); 
  lcd.print(count); 
  Serial.println(count);  
 
  delay(700); 
} 

