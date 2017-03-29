#include <Wire.h>
#include <ADXL345.h>  // ADXL345 Accelerometer Library
#include <HMC5883L.h> // HMC5883L Magnetometer Library
#include <ITG3200.h>

//Variables of each on-board sensor
ADXL345 acc; //variable adxl is an instance of the ADXL345 library
HMC5883L compass; //variable adxl is an instance of the HMC5883L library
ITG3200 gyro = ITG3200(); //variable adxl is an instance of the ITG3200 library

//Variables for parameters


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  acc.powerOn();
  compass = HMC5883L();
  
  error = compass.SetScale(1.3); // Set the scale to +/- 1.3 Ga of the compass
  
  if(error != 0) // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));
  
 // Serial.println("Setting measurement mode to continous");
  error = compass.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
  if(error != 0) // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));
    for (int i = 0; i <= 200; i++) {
    acc.readAccel(&ax, &ay, &az);
    if (i == 0) {
      aoffsetX = ax;
      aoffsetY = ay;
      aoffsetZ = az;
    }
    if (i > 1) {
      aoffsetX = (ax + aoffsetX) / 2;
      aoffsetY = (ay + aoffsetY) / 2;
      aoffsetZ = (az + aoffsetZ) / 2;
    }
  }
}

void loop() {

calculate_roll_pitch();
calculate_compass();
//calculate_gyro();

Serial.print(rolldeg);
Serial.print(",");
Serial.print(pitchdeg);  // calculated angle in degrees
Serial.print(",");
Serial.print(headingDegrees);
Serial.println(",");


}

// code fragment for Accelerometer angles (roll and pitch)
void calculate_accel{
  time = millis();
  acc.readAccel(&ax, &ay, &az); //read the accelerometer values and store them in variables  x,y,z
  rawX = ax - aoffsetX;
  rawY = ay - aoffsetY;
  rawZ = az  - (255 - aoffsetZ);
  X = rawX/256.00; // used for angle calculations
  Y = rawY/256.00; // used for angle calculations
  Z = rawZ/256.00; // used for angle calculations
  rollrad = atan(Y/sqrt(X*X+Z*Z));  // calculated angle in radians
  pitchrad = atan(X/sqrt(Y*Y+Z*Z)); // calculated angle in radians
  rolldeg = 180*(atan(Y/sqrt(X*X+Z*Z)))/PI; // calculated angle in degrees
  pitchdeg = 180*(atan(X/sqrt(Y*Y+Z*Z)))/PI; // calculated angle in degrees
}

// Code fragment for Magnetometer heading (yaw)
void calculate_compass(){
  MagnetometerRaw raw = compass.ReadRawAxis();
  MagnetometerScaled scaled = compass.ReadScaledAxis();
  int MilliGauss_OnThe_XAxis = scaled.XAxis;// (or YAxis, or ZAxis)
  float heading = atan2(scaled.YAxis, scaled.XAxis);
  float declinationAngle = 0.0457;
  heading += declinationAngle;
  if(heading < 0)
    heading += 2*PI;
  if(heading > 2*PI)
    heading -= 2*PI;
  float headingDegrees = heading * 180/M_PI;
}

// Code fragment for Gyroscope (roll, pitch, yaw)  
void calculate_gyro(){
  gyro.readGyro(&gx,&gy,&gz); 
  looptime = millis() - time;
  gx_rate = (gx-goffsetX) / 14.375;
  gy_rate = (gy-goffsetY) / 14.375;
  gz_rate = (gz-goffsetZ) / 14.375;
  delay(100);
 /* Serial.print(gx_rate);  // calculated angle in degrees
  Serial.print(",");
  Serial.print(gy_rate);
  Serial.print(",");
  Serial.print(gz_rate); 
  Serial.println(","); 
*/    
  anglegx = anglegx + (gx_rate * looptime);
  anglegy = anglegy + (gx_rate * looptime);
  anglegz = anglegz + (gz_rate * looptime);
}

