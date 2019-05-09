double Kp = 36.4;
double DutyCycle = 127;

void setup() {
 // put your setup code here, to run once:
 Serial.begin(9600);
 TCCR0B = TCCR0B & B11111000 | B00000010;

 pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(5, OUTPUT);

}


void loop() {
 // put your main code here, to run repeatedly:

 double ReferenceVoltage = double(analogRead(A0)) * 5 / 1024;
 double OutVoltage = double(analogRead(A1)) * 5 / 1024;
 
 
 double Error = OutVoltage - ReferenceVoltage;
 double proportionalError = Kp * Error;

 DutyCycle = DutyCycle - proportionalError;

constrain(DutyCycle, 0, 255);

 analogWrite(5, int(DutyCycle));
 
 delay(10);
 
}
