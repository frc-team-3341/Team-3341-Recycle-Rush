#include <Wire.h>

const int enables[] = {4, 5, 6, 7};
const int sensors[] = {A0, A1, A2, A3};
//                    
// update manually with number of sensors in list
const int numSensors = 2;
unsigned int array[4] = {0,0,0,0};
int sensor = 0; // do not use anywhere except sendSensorData
void setup()
{
    for(int i = 0; i < numSensors; i++)
    {
        pinMode(enables[i], OUTPUT);
        digitalWrite(enables[i], LOW);
        pinMode(sensors[i], INPUT);
    }
    
    // enter the I2C Bus with Address 41
    Wire.begin(41);
    // setup interrupt
   // Wire.onRequest(sendData);
    Wire.onRequest(sendData);
    // for debugging purposes
    Serial.begin(9600);
    //Serial.write("sizeof int");
    //int i;
    //Serial.println(sizeof(i));
}

void loop()
{
    getIR();
    //Wire.onRequest(getIR);
    //delay(2000);
}

void getIR()
{
  int values[] = {0, 0, 0, 0};
  Serial.println("IR3, IR2, IR1, IR0");
    for(int i = 0; i < numSensors; i++)
    {
        // enable the current sensor
        digitalWrite(enables[i], HIGH);

        // allow some time for the sensor to fully enable
        delay(26);

        values[i] = analogRead(sensors[i]);
        
        Serial.print("Sensor ");
        Serial.print(i);
        Serial.print(": ");
        Serial.print(values[i]);
        Serial.println(" ");
       
      
        // disable the sensor to prevent interference with other sensors
        digitalWrite(enables[i], LOW);
        
    }
  
  //array = values;
  for(int index = 0; index < 4; ++index)
  {
    array[index] = values[index];
  }
  printArray();
  Serial.println("\n");
}
//SerialO should be in a sep loop, not with Ana Reads
//swtuch bettween getting two sensors and all sensors
void printArray(){


  for(int j = 0; j < numSensors; j++)  {
    Serial.print(array[j]);
    Serial.print(", ");
    
  }
}
void sendData(){/*
  for(int j = 0; j < numSensors;){
    Wire.write(array[j]>>8);
    Wire.write(array[j]);
  }*/
  for(int j = 0; j < numSensors*2;){
    Wire.write(j);
  }
   // Wire.write((byte*)array, (numSensors * sizeof(array[0])));
    
    /*
    for(int j = 0; j < numSensors){
      array[j] = 0;
    }*/
}

void sendSensorData()
{
  if(sensor >= 4){
    sensor = 0;
  }
  // enable the current sensor
  digitalWrite(enables[sensor], HIGH);

  // allow some time for the sensor to fully enable
  delay(26);

  int vol = analogRead(sensors[sensor]);
 

  // disable the sensor to prevent interference with other sensors
  digitalWrite(enables[sensor], LOW);
 
Wire.write(shortToByteArray(sensor),2);
    ++sensor;
}


byte* shortToByteArray(int s) {
        byte arr[] = {(byte) ((s & 0xFF00) >> 8), (byte) (s & 0x00FF) };
	return arr;
}
