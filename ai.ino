// Project By Geeve George

#define CUSTOM_SETTINGS
#define INCLUDE_TEXT_TO_SPEECH_SHIELD
#define INCLUDE_VOICE_RECOGNIZER_SHIELD
#define CUSTOM_SETTINGS
#define INCLUDE_MIC_SHIELD
#define INCLUDE_SMS_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>



int ledPin = 13;
float sinVal;            

int toneVal;



/* A command which will be compared. */


const char firstCommand[]="what is the temperature now";

/* A command which will be compared. */
const char secondCommand[]="how is the weather today";

/* A command which will be compared. */
const char thirdCommand[]="did i leave the lights on";

const char fourthCommand[]="lights on";

const char fifthCommand[]="lights off";



const int pinTemp = A0;      // pin of temperature sensor

float temperature;
int B=3975;                
float resistance;

/* A name for the LED on pin 13. */

int pinLight = A1;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
   
  
  
    
   /* Always check if a new voice command received. */ 
   if(VoiceRecognition.isNewCommandReceived())
   {
     /* Check if the voice command is the desired one. */
     if(!strcmp(firstCommand,VoiceRecognition.getLastCommand()))
     {
       int val = analogRead(pinTemp);                               // get analog value
    resistance=(float)(1023-val)*10000/val;                      // get resistance
    temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;
       int n= temperature ;
String stringMsg="The Temperature is :";
stringMsg += String(n);
stringMsg +="degree celcius sir";

    


    //Convert our message to a character array so as to tweet it to twitter
    char msg[140];
    stringMsg.toCharArray(msg, 140);
    
      
        TextToSpeech.say(msg);
     }
     /* Check if the voice command is the desired one. */
     else if(!strcmp(secondCommand,VoiceRecognition.getLastCommand()))
     {
       int val = analogRead(pinTemp);                               // get analog value
    resistance=(float)(1023-val)*10000/val;                      // get resistance
    temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;
       int n= temperature ;
String stringMsg="The Temperature is :";
stringMsg += String(n);
stringMsg +="degree celcius sir";

    


    //Convert our message to a character array so as to tweet it to twitter
    char msg[140];
    stringMsg.toCharArray(msg, 140);
    
       if(n >= 40) {
         
       /* 1Sheeld responds using text-to-speech. */
       TextToSpeech.say("the weather is pretty harsh sir");
       }
       else if(n >= 30 && n <= 39) {
         TextToSpeech.say("it is pretty hot outside sir");
     }
     else if(n >= 27 && n  <= 29) {
         TextToSpeech.say("The weather is pretty warm sir");
     }
     else if(n >= 23 && n  <= 26) {
         TextToSpeech.say("The weather is good sir");
     }
     else if(n >= 18 && n <= 22) {
         TextToSpeech.say("The weather is moderate sir");
     }
      else if(n >= 14 && n <= 17) {
         TextToSpeech.say("It is a mild weather sir");
      }
      else if(n >= 10 && n  <= 13) {
         TextToSpeech.say("It is a pretty cool weather sir");
      }
      else if(n >= 6 && n  <= 9) {
         TextToSpeech.say("It is a cold weather sir");
      }
      else if(n >= 0 && n  <= 5) {
         TextToSpeech.say("It is a very cold weather sir");
      }
     }
     
     /* Check if the voice command is the desired one. */
     else if(!strcmp(thirdCommand,VoiceRecognition.getLastCommand()))
         {
     if(analogRead(1)>500) {
     TextToSpeech.say("yes sir you have left the lights on");
     
     }
     else if(analogRead(1)<500) {
     TextToSpeech.say("no sir the lights are turned off");
     
     }
     }

   }
   
  
     
   else if(!strcmp(fourthCommand,VoiceRecognition.getLastCommand()))
         {
     
     digitalWrite(13, HIGH);
     
     
     
     }
     
    
     else if(!strcmp(fifthCommand,VoiceRecognition.getLastCommand()))
         {
     
     digitalWrite(13, LOW);
     
         }
         
     
     }
