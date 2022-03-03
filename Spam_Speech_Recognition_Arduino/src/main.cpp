#include <Servo.h>  
#include <Arduino.h>  
#include <SoftwareSerial.h>

SoftwareSerial softSerial1(6,5);   //6为RX，5为TX
SoftwareSerial softSerial2(3,2);   //3为RX，5为TX
Servo myservo1;  // 定义舵机一
Servo myservo2;  // 定义舵机二
int a;



void setup() {
  myservo1.attach(9);  // D9为舵机一信号口      1号舵机
  myservo2.attach(10); // D10为舵机二信号口     2号舵机
  Serial.begin(9600);
  softSerial1.begin(9600);
  softSerial2.begin(9600);
}

void loop() {
  softSerial1.listen();
  a=softSerial1.read();      //读取串口1的值
  switch(a)
  {
    
    case 0x01:
      Serial.println("1号舵机旋转90度");
      
      break;
    case 0x02:
      Serial.println("可回收垃圾 2号舵机旋转0度");
     
      //  delay(5000);
      //  Serial.println("延时5s, 2号舵机归为 ，1号舵机复位");
      //  myservo2.write(0);        //舵机一旋转90°  
      //  delay(1000);               //延迟一段时间，也就是扔垃圾的时间
      //  myservo1.write(0);        
      //  delay(5);                 //给舵机一个转动的时间
      break;
    case 0x03:
      Serial.println("厨余垃圾 2号舵机旋转90度");
     
      //  delay(5000);
      //  Serial.println("延时5s, 2号舵机归为 ，1号舵机复位");
      //  myservo2.write(0);        //舵机一旋转90°  
      //  delay(1000);               //延迟一段时间，也就是扔垃圾的时间
      //  myservo1.write(0);        
      //  delay(5);                 //给舵机一个转动的时间
      break;
    case 0x04:
      Serial.println("有害垃圾 2号舵机旋转180度 ");
     
      //  delay(5000);
      //  Serial.println("延时5s, 2号舵机归为 ，1号舵机复位");
      //  myservo2.write(0);        //舵机一旋转90°  
      //  delay(1000);               //延迟一段时间，也就是扔垃圾的时间
      //  myservo1.write(0);        
      //  delay(5);                 //给舵机一个转动的时间
      break;
      case 0x05:
      Serial.println("其他垃圾垃圾 旋转270度");
     
      //  delay(5000);
      //  Serial.println("延时5s, 2号舵机归为 ，1号舵机复位");
      //  myservo2.write(0);        //舵机一旋转90°  
      //  delay(1000);               //延迟一段时间，也就是扔垃圾的时间
      //  myservo1.write(0);        
      //  delay(5);                 //给舵机一个转动的时间
      break;

    default:
      
      break;
  }
}