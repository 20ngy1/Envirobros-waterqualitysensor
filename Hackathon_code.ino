//Enviro-bros - display water conductivity and temperature 

int conductivityReading; //initialize a variable for the sensor reading
int tempReading;       
  
const int BTState = 2; //bluetooth module state pin 2

void setup() {
  pinMode(BTState, INPUT);
  Serial.begin(9600); // set up the serical communiction to print the reading
}

void loop() {
  conductivityReading = analogRead(A0); //get the analog reading of the sensor
  tempReading = analogRead(A1);

  float voltage = conductivityReading*(5.0/1023.0)-2.32;    //put the data in terms of voltage used(5 volts)
  float temperature = ((tempReading)-273-32)*5/9-19;                 //convert temperature to celcius and calibrate

  Serial.println("Voltage:   " + String(voltage)+"         " + "Temperature:   " + String(temperature)); //print the voltage and temp reading to the serial monitor

}
