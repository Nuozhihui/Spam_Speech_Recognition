#include <Servo.h>  
#include <Arduino.h>  
#include <SoftwareSerial.h>

SoftwareSerial softSerial1(6,5);   //6为RX，5为TX
SoftwareSerial softSerial2(3,2);   //3为RX，5为TX
Servo myservo1;  // 定义舵机一
Servo myservo2;  // 定义舵机二
int a;

void speech1(){         //播放：提示音msgd
  unsigned char i = 0;
  unsigned char head[10];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x07;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0x6D;
  head[6] = 0x73;
  head[7] = 0x67;
  head[8] = 0x64;
  head[9] = 0xE6;

  for(i=0; i<10; i++){
    softSerial2.write(head[i]);
  }
}

void speech2(){          //播放：可回收垃圾
  unsigned char j = 0;
  unsigned char head1[16];

  head1[0] = 0xFD;
  head1[1] = 0x00;
  head1[2] = 0x0D;
  head1[3] = 0x01;
  head1[4] = 0x00;
  head1[5] = 0xBF;
  head1[6] = 0xC9;
  head1[7] = 0xBB;
  head1[8] = 0xD8;
  head1[9] = 0xCA;
  head1[10] = 0xD5;
  head1[11] = 0xC0;
  head1[12] = 0xAC;
  head1[13] = 0xBB;
  head1[14] = 0xF8;
  head1[15] = 0xD4;

  for(j=0; j<16; j++){
    softSerial2.write(head1[j]);
  }
}

void speech3(){            //播放：其他垃圾
  unsigned char k = 0;
  unsigned char head2[14];

  head2[0] = 0xFD;
  head2[1] = 0x00;
  head2[2] = 0x0B;
  head2[3] = 0x01;
  head2[4] = 0x00;
  head2[5] = 0xC6;
  head2[6] = 0xE4;
  head2[7] = 0xCB;
  head2[8] = 0xFB;
  head2[9] = 0xC0;
  head2[10] = 0xAC;
  head2[11] = 0xBB;
  head2[12] = 0xF8;
  head2[13] = 0xCA;

  for(k=0; k<14; k++){
    softSerial2.write(head2[k]);
  }
}

void setup() {
  myservo1.attach(9);  // D9为舵机一信号口
  myservo2.attach(10); // D10为舵机二信号口
  Serial.begin(9600);
  softSerial1.begin(9600);
  softSerial2.begin(9600);
}

void loop() {
  softSerial1.listen();
  a=softSerial1.read();      //读取串口1的值
  switch(a)
  {
    case 1:
      Serial.println("收到");
      speech1();            //播放提示音
      break;
    case 2:
      Serial.println("可回收垃圾");
      speech2();              //识别到是可回收垃圾，并播报出来
      delay(1000);
      myservo1.write(90);        //舵机一旋转90°  
      delay(3000);               //延迟一段时间，也就是扔垃圾的时间
      myservo1.write(0);        
      delay(5);                 //给舵机一个转动的时间
      break;
    case 3:
      Serial.println("其他垃圾");
      speech3();
      delay(1000);            //识别到是其他垃圾，并播报出来
      myservo2.write(90);        //舵机二旋转90°
      delay(3000);
      myservo2.write(0);        
      delay(5); 
      break;
    default:
      break;
  }
}