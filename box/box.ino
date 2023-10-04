#include <Servo.h>
#include "button.h"
// создаём объекты для управления сервоприводами
Servo myservo1;
Servo myservo2;
int box =1;           //      состояник вокса 0 открыто 1 закрыто
int akum =1;          //      состояние отсека аккамулятора 0 открыто 1 закрыто
int box_box =1;           //     наличиие груза в вокса 0 нет 1 есть
int akum_box =1;          //      наличиие аккаамулятора в вокса 0 нет 1 есть
int button_box = 7;   //концевик вокса
int button_akum = 8;  //концевик аккамулятора
int flag1 = 0; // идет операция не изменять 
int flag2 = 0; // идет операция не изменять 

button btn1(7); // указываем пин
button btn2(8);


void setup() 
{

    Serial.begin(9600);
  // подключаем сервоприводы к выводам 
  myservo1.attach(3);
  myservo2.attach(10);
} 
 
void loop() 
{
//Serial.println("bu");
 if (btn1.click()){
  Serial.println("press 1");
  if (flag1 ==0){
   Serial.println("press 1 1");
   if (box_box ==1){
    //    Serial.println("press 1 1 0");
        myservo1.write(0);
        box_box =0;
   }else{
        //Serial.println("press 1 1 90");

        myservo1.write(90);
        box_box =1;           
   }
  //  Serial.println("press 1 2");
    flag1 =1; 

  }
 }else{
//    Serial.println("press 1 0");
  flag1 = 0;
 }
 
 

 if (btn2.click()){
  Serial.println("press 2");
  if (flag2 ==0){
 //  Serial.println("press 2 1");
   if (akum_box ==1){
        //Serial.println("press 1 1 0");
        myservo2.write(0);
        akum_box =0;
   }else{
        //Serial.println("press 1 1 90");

        myservo2.write(90);
        akum_box =1;           
   }
  //  Serial.println("press 1 2");
   flag2 = 1; 
  }
 }else{
//    Serial.println("press 1 0");
  flag2 = 0;
}
 
 
// if (btn2.click()) Serial.println("press 2");
  


//if (digitalRead(button_box) == LOW) {
//   Serial.println("button_box");
//  if (flag1 ==0){
//    if (box_box ==1){
    //    myservo1.write(90);
//        box_box =0;
 //   }else{
    //    myservo1.write(0);
//        box_box =1;           
 //   }
 //   flag1 =1; 
//  }
//}else{
//  flag1 = 0;
//}
//if (digitalRead(button_akum) == HIGH) {
//   Serial.println("button_akum");
//}


  // устанавливаем сервоприводы в серединное положение
//  delay(1000);
  // устанавливаем сервоприводы в крайнее левое положение  
//  myservo1.write(0);
//  myservo2.write(0);
 // delay(1000);
  // устанавливаем сервоприводы в крайнее правое положение
//  myservo1.write(90);
//  myservo2.write(90);
//  delay(500);
}
