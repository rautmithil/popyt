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

It will indicate with a visual feedback the force exerted, number of sets completed, angle of pull and calories calories burned.

# Approach

Create a gadget fitted with sensors which measure the orientation in which the user is pulling the bands. Additionally count the number of reps. The device consists of a GY-85 IMU sensor which is a 9 DOF sensor. It has a accelerometer, a gyroscope, a magnetometer. The data from these sensors can be used to calculate the orientation and direction of the device. The roll pitch and yaw angles of the device can be calculated. These angles will be used to determine in which orientation the user is performing the excercise.

Additionally, the device consists of a load cell sensor. This sensor creates a small deviation in voltage based on the amount of strain (both pull or push) excerted on the sensor. This sensor will be used to measure the force with which the user pulls. This data over time will be used to count the number of reps performed by the user.

# Design

The structure consists of a Grip, the gadget and the resistance bands. The grip is used to hold or attach to a surface. The gadgets goes between the resistance bands and the grip along the same axis.

![alt tag](https://cloud.githubusercontent.com/assets/13759991/24085360/12a135d2-0cd1-11e7-822c-2a006b77c7a7.JPG)

Team member: Mithil Raut

mithil@bu.edu

www.mithilraut.com
