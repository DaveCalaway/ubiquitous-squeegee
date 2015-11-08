/* Servo control Tassinari's edition
 *  Viene richiesto un'angolo da seriale, compreso tra 30 & 150 , per muovere il servo.
 *  
 *  Dave.Calaway
*/
#include <Servo.h> 

 
Servo myservo;  
                
 
int pos = 30;    // posizione inziale
int in;
 
void setup() 
{ 
  myservo.attach(9);  // pin controllo servo 
  myservo.write(pos); // manda il servo in posizione iniziale
  Serial.begin(9600);
  Serial.println("Servo control Tassinari's edition");
  Serial.println("Inserire una posizione compresa tra 30 e 150");
} 
 
 
void loop(){ 
  if (Serial.available()) {
    
    in=Serial.parseInt();
    Serial.println(in);
  
    while( pos != in ){   // finchè poss è diverso da in resta in quest ciclo

       if(in < 30 || in > 150 ){
         Serial.println("valore fuori portata, riprovare");
         in=pos;
       }
         
       if(in > pos){
         pos++;
         myservo.write(pos);
         delay(15);
       }
      
       else{
         pos--;
         myservo.write(pos);
         delay(15);
       }
     }
  }
}
