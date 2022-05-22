#include <HID-Project.h>
#include <HID-Settings.h>
#include <IRremote.h>

#define REVERSED false                      
int val = 0;
int previousval = 0;
int val2 = 0;
int RECV_PIN = 4;


const int switch1 = 8;
const int switch2 = 10;
const int switch3 = 12;
const int switch4 = 13;
const int switch5 = 3;
IRrecv irrecv(RECV_PIN);


decode_results results;

#define CH1 0xFFA25D
#define CH 0xFF629D
#define CH2 0xFFE21D
#define PREV 0xFF22DD
#define NEXT 0xFF02FD
#define PLAYPAUSE 0xFFC23D
#define VOL1 0xFFE01F
#define VOL2 0xFFA857
#define EQ 0xFF906F
#define BUTON0 0xFF6897
#define BUTON100 0xFF9867
#define BUTON200 0xFFB04F
#define BUTON1 0xFF30CF
#define BUTON2 0xFF18E7
#define BUTON3 0xFF7A85
#define BUTON4 0xFF10EF
#define BUTON5 0xFF38C7
#define BUTON6 0xFF5AA5
#define BUTON7 0xFF42BD
#define BUTON8 0xFF4AB5
#define BUTON9 0xFF52AD



void setup()
{
 Consumer.begin();                         
  delay(10);                              
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(switch4, INPUT_PULLUP);
  pinMode(switch5, INPUT_PULLUP);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {

//////////////////////////////////////////////////////////////////////////////////////////
  Keyboard.begin();
  int switch1POS = digitalRead(switch1);
  int switch2POS = digitalRead(switch2);
  int switch3POS = digitalRead(switch3);
  int switch4POS = digitalRead(switch4);
  int switch5POS = digitalRead(switch5);
  
  if (switch1POS == LOW){
  delay(100);
  Keyboard.press('1');  
  delay(100);
  Keyboard.releaseAll();}
  
  if (switch2POS == LOW){
  Keyboard.press('2');  
  delay(100);
  Keyboard.releaseAll();}
  delay(100);
  
  if (switch3POS == LOW){
  delay(100);
  Keyboard.press('3');  
  delay(100);
  Keyboard.releaseAll();}
  
  if (switch4POS == LOW){
  delay(100);
  Keyboard.press('4');  
  delay(100);
  Keyboard.releaseAll();}

  if (switch5POS == LOW){
  delay(100);
  Keyboard.press('5');  
  delay(100);
  Keyboard.releaseAll();}

   
//////////////////////////////////////////////////////////////////////////////////////////////////

  val = analogRead(A0);                      
  val = map(val, 0, 1023, 0, 101);          
  if(REVERSED) {
    val = 101 - val;
  }
  if (irrecv.decode(&results))
  {
    if (results.value == VOL1)
    {
      Consumer.write(MEDIA_VOLUME_DOWN);
      val2--; 
      delay(2);
      val2--; 
      delay(2);
      
    }

    if (results.value == VOL2)
    {
      Consumer.write(MEDIA_VOLUME_UP);
      val2++;    
      delay(2);
      val2++;    
      delay(2); 
     
    }

    if (results.value == EQ)
    {
      Consumer.write(MEDIA_VOLUME_MUTE);
      delay(2);      
     
    }
    if (results.value == PLAYPAUSE)
    {
      Consumer.write(MEDIA_PLAY_PAUSE);
      delay(2);         
     
    }
    if (results.value == PREV)
    {
      Consumer.write(MEDIA_PREVIOUS);
      delay(2);         
     
    }
    if (results.value == NEXT)
    {
      Consumer.write(MEDIA_NEXT);
      delay(2);         
     
    }
    
  }
             
      
    
      irrecv.resume();
      Keyboard.end();
      
    }
   
 
  
