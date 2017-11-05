/*
    Modified FSM example code - Push Button 
*/


const int  buttonPin = 2;    
const int ledPin1 = 13;      
const int ledPin2 = 12;
const int ledPin3 = 11;

int buttonPushCounter = 0;    // counter for the number of button presses
int buttonState = 0;          // current state of the button
int lastButtonState = 0;      // previous state of the button

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  
  buttonState = digitalRead(buttonPin);       // read the pushbutton input pin:
  
  if (buttonState != lastButtonState) {       // compare the buttonState to its previous state
    
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {      
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      Serial.println("off");
    }
    
    delay(50);                      // Delay a little bit to avoid bouncing
  }
  
  lastButtonState = buttonState;    // save the current state as the last state, for next time through the loop

  if (buttonPushCounter == 1) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  } else if (buttonPushCounter == 2) {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin3, LOW);
  } else if (buttonPushCounter == 3) {
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, LOW);
  } else {
    buttonPushCounter = 1;
  }

}