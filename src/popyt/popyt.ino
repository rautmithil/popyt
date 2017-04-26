#include <Wire.h>
#include <ADXL345.h>  // ADXL345 Accelerometer Library
#include <HMC5883L.h> // HMC5883L Magnetometer Library
#include <ITG3200.h>
#include <HX711.h>
#include <LiquidCrystal.h>

// Connections on 
// HX711.DOUT  - pin #A2
// HX711.PD_SCK - pin #A1
HX711 scale(A1, A2); // Weight scale sensor
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);  //LCD initalization

//Variables of each on-board sensor
ADXL345 acc; //variable acc is an instance of the ADXL345 library
HMC5883L compass; //variable compass is an instance of the HMC5883L library
ITG3200 gyro = ITG3200(); //variable gyro is an instance of the ITG3200 library
float  gx,gy,gz;
float  gx_rate, gy_rate, gz_rate;
int ix, iy, iz;
float anglegx=0.0, anglegy=0.0, anglegz=0.0;
int ax,ay,az;  
int rawX, rawY, rawZ;
float X, Y, Z;
float rollrad, pitchrad;
float rolldeg, pitchdeg;
float headingDegrees = 0.0;
int error = 0; 
float aoffsetX, aoffsetY, aoffsetZ;
float goffsetX, goffsetY, goffsetZ;
unsigned long time, looptime;
float weight;
static float threshold = 0.0;
static int RepCount = 0;
static boolean RepCountFlag = true;
float hori_angle, vert_angle;

//Physique parameters
int height = 180;

//Variables for parameters
void setup() {

  //Output for HX711 module
  pinMode(A0,OUTPUT);
  digitalWrite(A0,LOW);
  pinMode(A3,OUTPUT);
  digitalWrite(A3,HIGH);

  //LCD Backlight
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  Serial.begin(115200);
  lcd.begin(20,4);

  input_force();
  calibrate_force();
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
  lcd.clear();
}

void loop() {
calculate_accel();
calculate_compass();
//Serial.print(rolldeg);
//Serial.print(",");
calc_angle();
Serial.print("Angle Vert: ");
Serial.print(vert_angle);
Serial.println(" , ");
//Serial.print(pitchdeg);
//Serial.print(",");
//Serial.print(headingDegrees);
//Serial.println(",");
//calculate_gyro();
//Print data

/*lcd.print(rolldeg);
lcd.print(",");
lcd.print(pitchdeg);  // calculated angle in degrees
lcd.print(",");
lcd.print(headingDegrees);
lcd.println(",");*/
//lcd.setCursor(0,2);
//Serial.print(RepCount);
count_reps();
lcd.setCursor(0,4);
lcd.print("Threshold: ");
lcd.print(threshold);
delay(100);
}



// code fragment for Accelerometer angles (roll and pitch)
void calculate_accel(){
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
  headingDegrees = heading * 180/M_PI;
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



float measure_force(){
  //Serial.print("one reading:\t");
  //Serial.print(scale.get_units(), 1);
  //Serial.print("\t| Weight:\t");
  float wei = scale.get_units(10);
  float weight = floor((float)(37.273 * (float)(wei)))/1000;
  if(weight<0)
  {
    weight = 0.0;
  }
  //float weight = (scale.get_units(5));
  Serial.print("Force: ");
  Serial.print(weight);
  Serial.println("          ");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Force: ");
  lcd.print(weight);
  calc_angle();
  lcd.setCursor(0,2);
  lcd.print("Reps: ");
  Serial.print("Reps: ");
  Serial.println(RepCount);
  lcd.print(RepCount);
  //lcd.print(",");
  return weight;
  scale.power_down();              // put the ADC in sleep mode
  delay(100);
  scale.power_up();
}



void count_reps(){
  if(measure_force() > (float)threshold){
    RepCount ++;
    Serial.print("Reps: ");
    Serial.println(RepCount);
    lcd.setCursor(0,2);
    lcd.print("Reps: ");
    lcd.print(RepCount);
    while(measure_force() > (float)threshold){
      lcd.setCursor(0,2);
      lcd.print("Reps: ");
      lcd.print(RepCount);}
  }
  
  //return RepCount;
}

void calc_angle(){
  vert_angle = rolldeg*(-1);
  lcd.setCursor(0,1);
  lcd.print("Angle Vert: ");
  lcd.print(vert_angle);
  //hori_angle = 
  //Serial.print(hori_angle);
  
}

void input_force(){
  Serial.print("Input force in   Kg");
  lcd.print("Input force in   Kg");
  while(Serial.available() == 0){}
  if (Serial.available() > 0) {
    threshold = Serial.parseFloat();
    Serial.print(threshold);
    lcd.setCursor(0,0);
    lcd.print("Received force:");
    lcd.print(threshold);
    delay(2000);
  }
}

void calibrate_force(){
  Serial.println("HX711 Demo");

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());      // print a raw reading from the ADC

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));   // print the average of 20 readings from the ADC

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));   // print the average of 5 readings from the ADC minus the tare weight (not set yet)

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);  // print the average of 5 readings from the ADC minus tare weight (not set) divided 
            // by the SCALE parameter (not set yet)  

  scale.set_scale(2280.f);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();               // reset the scale to 0

  Serial.println("After setting up the scale:");

  Serial.print("read: \t\t");
  Serial.println(scale.read());                 // print a raw reading from the ADC

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));       // print the average of 20 readings from the ADC

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));   // print the average of 5 readings from the ADC minus the tare weight, set with tare()

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);        // print the average of 5 readings from the ADC minus tare weight, divided 
            // by the SCALE parameter set with set_scale

  Serial.println("Readings:");
}


