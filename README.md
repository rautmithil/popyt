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

![alt tag](https://cloud.githubusercontent.com/assets/13759991/24086088/1b39686e-0cdf-11e7-813e-c13ea7e8f84e.jpeg)

![alt tag](https://cloud.githubusercontent.com/assets/13759991/24086087/1b3772e8-0cdf-11e7-986c-c18c97e3a388.jpeg)

5. Ordered an IMU sensor (GY-85) which has all the sensors required for determining the orientation of an object.

6. Tested code with GY-85 and Arduino. Able to receive values for roll, pitch and yaw. Looks good to go into the gadget. One issue is that it needs to be calibrated at the beginning of a power cycle.

7. Ordered a HX711 wheatstone bridge amplifier. Interfaced and tested it with the load cell from the luggage weigh scale. The update rate of the circuit is 10 reading per second which is less than expected.

8. Build a clamp that can be used single handedly.

![alt tag](https://cloud.githubusercontent.com/assets/13759991/25096512/80c51c3c-236e-11e7-999b-ae876b7fa8f0.png)

9. Make a PCB.

![alt tag](https://cloud.githubusercontent.com/assets/13759991/25096186/32125362-236d-11e7-9753-1022bc27547a.png)

10. Create a box with acrylic from the tinker lab. Make place for hosting the sensors and the Arduino.

11. Connect a screen and display data.

![alt tag](https://cloud.githubusercontent.com/assets/13759991/25096306/b21f5974-236d-11e7-80ec-9a43040e935b.jpg)

12. Interface with an Android application.

![alt tag](https://cloud.githubusercontent.com/assets/13759991/25096307/b21ff3b6-236d-11e7-8487-f32d83885991.png)

13. Calibrate the weight sensor

![alt tag](https://cloud.githubusercontent.com/assets/13759991/25096308/b222be48-236d-11e7-8367-b15ca236ffcf.jpg)

Refer calibration data updated in docs.

14.  Complete the program for basic function of counting the number of reps.

15.  Implement a function for measuring the angle of the exercise.

16. Interface with an android application to input the threshold force.

![lcd_display](https://cloud.githubusercontent.com/assets/13759991/25774478/4a297800-325d-11e7-8e17-b19a903841f7.jpg)


Final setup  and video

https://drive.google.com/file/d/0B4X2bi7UNs5bVlZYTXJ2TGg3cTQ/view?usp=sharing

![final hardware](https://cloud.githubusercontent.com/assets/13759991/25774560/8610e068-325f-11e7-85c7-a91d6b4389b7.jpg)


Team member: Mithil Raut

mithil@bu.edu

www.mithilraut.com
