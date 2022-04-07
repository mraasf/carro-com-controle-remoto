#include <IRremote.h> 
 
float Codigo; 
 
int R1D = 2; 
int R1E = 3; 
int R2D = 4;
int R2E = 5;
int buz = 8;
 
IRrecv irrecv(11); 
decode_results results; 
 
void setup() 
{ 
 pinMode(R1D, OUTPUT); 
 pinMode(R1E, OUTPUT); 
 pinMode(R2D, OUTPUT); 
 pinMode(R2E, OUTPUT); 
 pinMode(buz, OUTPUT);
 Serial.begin(9600); 
 
 irrecv.enableIRIn(); 
} 
 
void loop() 
{ 
 if (irrecv.decode(&results)) 
 { 
 Codigo = (results.value); 
 if (Codigo == 16718055) //Frente 
 { 
 Frente(); 
 } 
 
 if (Codigo == 16730805) //Atras 
 { 
 Atras(); 
 } 
 
 if (Codigo == 16734885) //Direita 
 { 
 Direita(); 
 } 
 
 if (Codigo == 16716015) //Esquerda 
 { 
 Esquerda(); 
 } 
 
 if(Codigo == 0xFF02FD)
 {
 Buzina();
 }
 irrecv.resume();
 
 
 } 
}
 
void Frente()
{
 digitalWrite(R1D, HIGH);
 digitalWrite(R2D, LOW);
 delay(1000);
 digitalWrite(R1D, HIGH);
 digitalWrite(R2D, HIGH);
}
 

void Esquerda()
{
 digitalWrite(R1D, HIGH);
 digitalWrite(R2D, LOW);
 delay(500);
 digitalWrite(R1D, HIGH);
 digitalWrite(R2D, HIGH); 
}
 
void Direita()
{
 digitalWrite(R1D, LOW);
 digitalWrite(R2D, HIGH);
 delay(500);
 digitalWrite(R1D, HIGH);
 digitalWrite(R2D, HIGH);
}
 
void Buzina()
{
 digitalWrite(buz, HIGH);
 delay(500);
 digitalWrite(buz, LOW);
}


