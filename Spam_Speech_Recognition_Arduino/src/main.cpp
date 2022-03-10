//t
#include <Servo.h>  
#include <Arduino.h>  
#include <SoftwareSerial.h>

SoftwareSerial softSerial1(6,5);   //6为RX，5为TX
SoftwareSerial softSerial2(3,2);   //3为RX，5为TX
Servo myservo1;  // 定义舵机一
Servo myservo2;  // 定义舵机二
int a;           //定义缓存(串口数据)


void setup() {
  myservo1.attach(9,500,2500);  // D9为舵机一信号口      1号舵机
  myservo2.attach(10,500,2500); // D10为舵机二信号口     2号舵机
  Serial.begin(9600);           //设置波特率
  softSerial1.begin(9600);      //监听软串口通信 
  softSerial2.begin(9600);      //监听软串口通信 
  myservo1.write(0);        //舵机一旋转0 归位
  myservo2.write(0);        //舵机一旋转0 归位
}

void loop() {
  softSerial1.listen();
  a=softSerial1.read();      //读取串口1的值
  switch(a)
  {
    
    case 0x01:    //召唤
      Serial.println("1号舵机旋转90度");
      myservo2.write(90);        //舵机一旋转90°  

      break;
    case 0x02:    
      Serial.println("可回收垃圾 2号舵机旋转0度");
       myservo1.write(0);        //舵机一旋转0°  ******************
       delay(5000);
       Serial.println("延时5s, 2号舵机归位");
       myservo2.write(0);        //舵机二旋转复位  (门舵机)
       delay(1000);               //延迟一段时间，也就是扔垃圾的时间
       Serial.println("延时1s,1号舵机归位");
       myservo1.write(0);        //复位1号舵机(旋转舵机)
       delay(5);                 //给舵机一个转动的时间
        Serial.println("完成 可回收垃圾");
      break;

    case 0x03:    //90
      Serial.println("厨余垃圾 2号舵机旋转90度");
      myservo1.write(65);        //舵机一旋转0°  ******************
       delay(5000);
       Serial.println("延时5s, 2号舵机归位");
       myservo2.write(0);        //舵机二号旋转复位    (门舵机)
       delay(1000);               //延迟一段时间，也就是扔垃圾的时间
       Serial.println("延时1s,1号舵机归位");
       myservo1.write(0);        
       delay(5);                 //给舵机一个转动的时间
         Serial.println("完成 厨余垃圾");
      break;

    case 0x04:
      Serial.println("有害垃圾 2号舵机旋转180度 ");
       myservo1.write(120);        //舵机一旋转0°  ******************
       delay(5000);
       Serial.println("延时5s, 2号舵机归归位");
       myservo2.write(0);        //舵机二旋转复位    (门舵机)
       delay(1000);               //延迟一段时间，也就是扔垃圾的时间
       Serial.println("延时1s,1号舵机归位");
       myservo1.write(0);        
       delay(5);                 //给舵机一个转动的时间
         Serial.println("完成 有害垃圾");
      break;
      case 0x05:
      Serial.println("其他垃圾垃圾 旋转270度");
       myservo1.write(270);        //舵机一旋转0°  ******************
       delay(5000);
       Serial.println("延时5s, 2号舵机归位 ");
       myservo2.write(0);        //舵机二旋转复位    (门舵机)
       delay(1000);               //延迟一段时间，也就是扔垃圾的时间
       Serial.println("延时1s,1号舵机归位");
       myservo1.write(0);       
       delay(5);                 //给舵机一个转动的时间
      Serial.println("完成 其他垃圾");
      break;

    default:
      
      break;
  }
}