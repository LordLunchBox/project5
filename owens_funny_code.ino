//Traffic lights with 3 functions
//Owen Clark

#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define yellowBlinkTime 500
boolean trafficWest = true;  // west = true, east = false
int flowTime = 10000;
int changeDelay = 2000;
void setup() {
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);
  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}
void loop() {
  if (digitalRead(westButton) == HIGH) {
    if (trafficWest != true) {
      trafficWest = true;
      changeLight(westGreen, westYellow, westRed);
      changeLight(eastRed, eastYellow, eastGreen);
      blinkYellow(westYellow);
    }
  }
  if (digitalRead(eastButton) == HIGH) {
    if (trafficWest == true) {
      trafficWest = false;
      changeLight(eastGreen, eastYellow, eastRed);
      changeLight(westRed, westYellow, westGreen);
      blinkYellow(eastYellow);
    }
  }
}
void changeLight(int greenPin, int yellowPin, int redPin)  //func for light states
{
  digitalWrite(greenPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);
  delay(flowTime);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(changeDelay);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(changeDelay);
}
void blinkYellow(int yellowPin)  //blinking yellow light func
{
  for (int a = 0; a < 5; a++) {
    digitalWrite(yellowPin, LOW);
    delay(yellowBlinkTime);
    digitalWrite(yellowPin, HIGH);
    delay(yellowBlinkTime);
  }
  digitalWrite(yellowPin, LOW);
}
void handleTrafficFlowChange()  //func for pedestrian switches
{
  if (digitalRead(westButton) == HIGH) {
    if (trafficWest != true) {
      trafficWest = true;
      delay(flowTime);
      changeLight(westGreen, westYellow, westRed);
      changeLight(eastRed, eastYellow, eastGreen);
      blinkYellow(westYellow);
    }
  }
  if (digitalRead(eastButton) == HIGH) {
    if (trafficWest == true) {
      trafficWest = false;
      delay(flowTime);
      changeLight(eastGreen, eastYellow, eastRed);
      changeLight(westRed, westYellow, westGreen);
      blinkYellow(eastYellow);
    }
  }
}
