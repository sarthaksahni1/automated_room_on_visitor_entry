# Automated_Room_On_Visitor_Entry
We built an IoT based system which can automatically switch ON room lights and fan when at least one person is present in the room. If room is empty, the lights and fan will automatically get switch off. It also displays count of persons present in the room.

![Prototype](https://raw.githubusercontent.com/sarthaksahni1/automated_room_on_visitor_entry/master/Prototype.jpg)<br>
Automatically turn the room lights and fan ON when at least one person is present in the room.<br>

## Project Overview<br>
For building this application we have used arduino along with IR sensors and relay module.<br>
We have used two IR sensors one for detecting person entering into the room and other for detecting person leaving (exit) the room.<br>
Also these IR sensors are also used to count the person entering and leaving the room. This person counting will help to automate the room's fan and light. That means when the room is empty, the room's light and fan will remain off. But if someone enters the room then the room's light and fan will get turned ON automatically with person count displayed on LCD.

## Project Implementation<br>
When person enters the room infrared signal bounces back and get received by infrared receiver which is considered as entry.

Therefore count is incremented. 
```
if (digitalRead(In) == LOW) 
   {  
   count++;  
   }  
```
Similarly for person leaving the room, count is decremented on detection.
```
else if (digitalRead(Out) == LOW) 
  {  
   count--;  
  }  
```
When count is more than zero,Relay gets high therefore room lights and fan turn on  
and for count less than or equal to zero relay gets low, so light and fan will get turn off.
```
else if (count > 0)  
 {  
   digitalWrite(relay, HIGH);  
 }  
 
 else if(count <= 0){  
   digitalWrite(relay, LOW);  
 }  
```

## Connection Diagram
![CircuitDiagram](https://raw.githubusercontent.com/sarthaksahni1/automated_room_on_visitor_entry/master/circuit_diagram.jpg)<br>

## Design Steps<br>
1. Now to design this circuit we have to interface 16x2 LCD with Arduino UNO as shown in diagram.<br>
2. Two IR sensors are connected to digital input pin 4 and 5 of Arduino UNO. (Pin 4 is for entry and pin 5 is for exit.)<br>
3. Relay module is connected to GPIO pin of Arduino UNO.<br><br>
4. Bulb and DC motor with propeller are connected in series with relay.<br>
5. Upload the code to the Arduino UNO.
