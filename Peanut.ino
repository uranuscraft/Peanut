int ledPin = 9;      // LED connected to digital pin 9
int outPin = 1;      // Tramister connected to analog pin 1
int analogPin = 3;   // receiver connected to analog pin 3
int switchPin = 5;      // switch connected to digital pin 5
int val = 0;         // variable to store the read value

int cycles = 0;// variable to store the amount of cycles
int StDe[10]; // the standard deviation
int Mean[10];

void setup()

{
 pinMode(switchPin, INPUT); // sets the pin as input
 
  pinMode(ledPin, OUTPUT);   // sets the pin as output
  pinMode(outPin, OUTPUT);   // sets the pin as output
}



void loop()

{

 analogWrite(outPin, 50);

 
 

Calibration();
cycles = cycles + 924;// the amount of cycles that have been gone through
if(digitalRead(switchPin) == HIGH) {// if the switch is activated 
  int Read = analogRead(analogPin);
 int AvgOne = Mean[0] + Mean[1] + Mean[2] + Mean[3] + Mean[4] + Mean[5] + Mean[6] + Mean[7] + Mean[8] + Mean[9] + Mean[10];
  int Avg = AvgOne / 10;
   int SDOne = StDe[0] + StDe[1] + StDe[2] + StDe[3] + StDe[4] + StDe[5] + StDe[6] + StDe[7] + StDe[8] + StDe[9] + StDe[10];
  int StD = SDOne / 10;
  
  int FourSD = StD * 4;
   int NegFourSD = StD * -4;
  if(Read > FourSD) {
      digitalWrite(ledPin, HIGH);
  }
  if(Read < NegFourSD) {
   digitalWrite(ledPin, HIGH);
  }
  
}
else{
  
}
}


//read calibration
void Calibration(){// start of calibration function
 int times = 0;
 while(times < 10){
 int amountOfTimes = 0;
 int NumberAtTime[10];
 int Sum = 0;
  while(amountOfTimes < 10){
    
 NumberAtTime[amountOfTimes] = analogRead(analogPin);   // read the input pin
Sum = Sum + NumberAtTime[amountOfTimes];
amountOfTimes++;
}

int average = Sum / 10;
Mean[times] = average;
amountOfTimes = 0;
int Standardone = 0;
int Standardtwo = 0;
 while(amountOfTimes < 10){
Standardone = average - NumberAtTime[amountOfTimes];
Standardtwo = Standardtwo + Standardone;
amountOfTimes++;
 }
 int Standardthree = Standardtwo * Standardtwo;
 int Standardfour = Standardthree / 10;
  StDe[times] = sqrt(Standardfour);
  
  times++;
}

}// end of calibration function




/**
int StDeWR[10]; // the standard deviation
int MeanWR[10];
//write calibration
void CalibrationWR(){// start of calibration function
 int times = 0;
 while(times < 10){
 int amountOfTimes = 0;
 int NumberAtTime[10];
 int Sum = 0;
  while(amountOfTimes < 10){
    
 NumberAtTime[amountOfTimes] = analogRead(outPin);   // read the input pin
Sum = Sum + NumberAtTime[amountOfTimes];
amountOfTimes++;
}

int average = Sum / 10;
MeanWR[times] = average;
amountOfTimes = 0;
int Standardone = 0;
int Standardtwo = 0;
 while(amountOfTimes < 10){
Standardone = average - NumberAtTime[amountOfTimes];
Standardtwo = Standardtwo + Standardone;
amountOfTimes++;
 }
 int Standardthree = Standardtwo * Standardtwo;
 int Standardfour = Standardthree / 10;
  StDeWR[times] = sqrt(Standardfour);
  
  times++;
}

}// end of calibration function
**/ 
