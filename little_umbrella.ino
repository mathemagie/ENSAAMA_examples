#include <Process.h>
#include <Bridge.h>
#include <Servo.h>

Servo monServo;

void setup() {
  Bridge.begin();   // Initialize the Bridge
  monServo.attach(9); 
}

void loop() {
  
  Process p;
  p.runShellCommand("/usr/bin/curl 'http://mathemagie.net/little_umbrella/?city=newyork&id=1'");
  //please update ID parameter with your ID 
  Serial.println("run curl command");


  while(p.running());  

  // Read command output. runShellCommand() should have passed "Signal: xx&":
  while (p.available()) {
    int result = p.parseInt();  
    Serial.println("nombre de degred a appliquer au servo moteur : ");
    Serial.println(result);
    

   // apply to servo
    monServo.write(result);
  
  } 
  delay(2000);  // wait 2 seconds before you do it again
}
