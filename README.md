# POPYT
EC500 C1: This is the repository for the project Portable Physical Therapy device Spring 2017.

# Background

As people age, they tend to lose flexibility, strength and often their balance, so maintaining the desired level of fitness becomes increasingly challenging. People playing racquet sports put a strain on their muscles in arms and shoulder. Ex: Tennis, Squash, Racquetball, Table tennis, Baseball etc. One of the problems which come often times is shoulder pain or injury. Common causes of shoulder pain are :

Rotator cuff tendinopathy

Impingement

Rotator cuff tear

Adhesive capsulitis Frozen Shoulder

Glenohumeral arthritis

One of the recommended methods to fix these problems is Physical Therapy(PT). With shoulder injury there are a lot of recommended PT excercises as shown below.

![alt tag](https://cloud.githubusercontent.com/assets/13759991/24084935/9f9fbd08-0cc9-11e7-9ba7-92c0fa546036.jpg)

These set of excercises use resistance bands of varying strengths which need to be pulled in sets at various angles as recommended by a Therapist.

# Description:

The aim of this project is to:

Create a Physical Therapy gadget that will be lightweight, portable, and easy to install.

It will indicate with a visual feedback the force exerted, number of sets completed, angle of pull and calories burned.

# Approach

Create a gadget fitted with sensors which measure the orientation in which the user is pulling the bands. Additionally count the number of reps. The device consists of a GY-85 IMU sensor which is a 9 DOF sensor. It has a accelerometer, a gyroscope, a magnetometer. The data from these sensors can be used to calculate the orientation and direction of the device. The roll pitch and yaw angles of the device can be calculated. These angles will be used to determine in which orientation the user is performing the excercise.

GY-85 sensor link

https://www.amazon.com/gp/product/B01DIPN2R6/ref=oh_aui_detailpage_o00_s00?ie=UTF8&psc=1

![alt tag](https://images-na.ssl-images-amazon.com/images/I/617J%2BuUu7%2BL._SL1000_.jpg)

Additionally, the device consists of a load cell sensor. This sensor creates a small deviation in voltage based on the amount of strain (both pull or push) excerted on the sensor. This sensor will be used to measure the force with which the user pulls. This data over time will be used to count the number of reps performed by the user.

50 Kg micro load cell

http://www.robotshop.com/en/micro-load-cell-50-kg.html?gclid=Cj0KEQjw2LjGBRDYm9jj5JSxiJcBEiQAwKWACyjiyPJ162P4czn0xqS1zmk6GbavGpfsvf0XkgNSoN0aAmhB8P8HAQ

![alt tag](http://www.robotshop.com/media/catalog/product/cache/1/image/900x900/9df78eab33525d08d6e5fb8d27136e95/m/i/micro-load-cell-50-kg_1.jpg)

# Design

The structure consists of a Grip, the gadget and the resistance bands. The grip is used to hold or attach to a surface. The gadgets goes between the resistance bands and the grip along the same axis.

![alt tag](https://cloud.githubusercontent.com/assets/13759991/24085360/12a135d2-0cd1-11e7-822c-2a006b77c7a7.JPG)

![alt tag](https://cloud.githubusercontent.com/assets/13759991/24086033/d4ac6668-0cdd-11e7-929e-72c978b765ea.png)

# Progress so far

1.  Tested code with acceleroemeter ADXL345 and Arduino. Realised an accelerometer only gives the roll, pitch values of a sensor. Need a magnetormeter for the yaw angle.

2. Ordered a luggage weight sensor with the idea to hack its chip and tap the signal which provides the value of the weight.

3. The weight sensor has a black blob, a.k.a Chip-on-board whose signals cannot be tapped without breaking the chip. Hence the circuit cannot be used however, I plan to utilize the load cell from the scale and attach a wheatstone bridge with amplifier to get a proper reading for the very small deviation coming from the load cell.

5. Ordered an IMU sensor (GY-85) which has all the sensors required for determining the orientation of an object.

6. Tested code with GY-85 and Arduino. Able to receive values for roll, pitch and yaw. Looks good to go into the gadget. One issue is that it needs to be calibrated at the beginning of a power cycle. 

# Next step

1. Create a box with acrylic from the tinker lab. Make place for hosting the sensors and the Arduino.

2. Look for a solution to the calibration problem.

Team member: Mithil Raut

mithil@bu.edu

www.mithilraut.com
