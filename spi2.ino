#include <Servo.h>
  Servo myservo;
  Servo myservo2;

  int pos1=0;
   
   
   void setup() {
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  myservo.attach(7);
  myservo2.attach(8);


}

void loop() {
  call_status(3000); 
}
void forward_x(int main_delay){
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  Serial.println("forward on X");
  delay(main_delay);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);

}
 
void backward_x(int main_delay){
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  Serial.println("Backward on X");
  delay(main_delay);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}


void forward_y(int main_delay){
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
  Serial.println("forward on Y");
  delay(main_delay);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);

}
 
void backward_y(int main_delay){
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  Serial.println("Backward on Y");  
  delay(main_delay);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
   

void status_11(int normal_delay){
  bool s1,s2,s3;
  s1 = digitalRead(A0);
  s2 = digitalRead(A1);
  s3 = digitalRead(A2);
  Serial.println("11");
  while (s3 == 1){
  if (s1 ==0 && s2 ==1){
     
    backward_x(normal_delay);
    float j=0;
    myservo2.write(j);
    while(j<90){
    j=j+0.001;
  }
   status_01(normal_delay);
  }

  if (s1 == 0 && s2 ==0){
    
    backward_x(normal_delay);
    forward_y(normal_delay);
   float i = 180;
      float j = 180;
  while (i>90&& j >90){
    myservo.write(i);
    myservo2.write(j);
    j=  j-0.001;
    i = i-0.001;
    }
   status_00(normal_delay);
   
  }

  if (s1 == 1 && s2 ==0){
    
    forward_y(normal_delay);
      float i = 180;
  while (i>90){
    myservo.write(i);
    i = i-0.001;
    }
   status_10(normal_delay);
  
  }

  if (s1 == 1 && s2 ==1){

  }
  else {
    call_status(normal_delay);
  }
  s3 = digitalRead(A2);
  }

}

void status_00(int normal_delay){
  bool s1,s2,s3;
  s1 = digitalRead(A0);
  s2 = digitalRead(A1);
  s3 = digitalRead(A2);
  Serial.println("00");
  while (s3 == 1){
  if (s1 ==0 && s2 ==1){
    backward_y(normal_delay);
    float i=0;
     myservo.write(i);
    while(i<90){
      i=i+0.001;
    }
    status_01(normal_delay);
     
     
  }
  if (s1 == 0 && s2 ==0){
    
  }
  if (s1 == 1 && s2 ==0){
    forward_x(normal_delay);
    float j=0;
     myservo2.write(j);
    while(j<90){
      j=j+0.001;
    }
    status_10(normal_delay);
    
  }
  if (s1 == 1 && s2 ==1){
    forward_x(normal_delay);
    forward_y(normal_delay);
    float i = 0;
      float j = 0;
  while (i<90&& j <90){
    myservo.write(i);
    myservo2.write(j);
    j=  j+0.001;
    i = i+0.001;
    }
    status_11(normal_delay);
  }
  else {
    call_status(normal_delay);
  }
  s3 = digitalRead(A2);
  }

}
void status_01(int normal_delay){
  bool s1,s2,s3;
  s1 = digitalRead(A0);
  s2 = digitalRead(A1);
  s3 = digitalRead(A2);
  Serial.println("01");
  while (s3 == 1){
  if (s1 ==0 && s2 ==1){
    
  }
  if (s1 == 0 && s2 ==0){
    forward_y(normal_delay);
    float i = 180;
    myservo.write(i);
    while ( i>90){
      i=i-0.001;
    }
   status_00(normal_delay);
  }
  if (s1 == 1 && s2 ==0){
   
    forward_x(normal_delay);
    forward_y(normal_delay);
    float i = 180;
      float j = 0;
  while (i>90&& j <90){
    myservo.write(i);
    myservo2.write(j);
    j=  j+0.001;
    i = i-0.001;
    }
   status_10(normal_delay);
    
  }
  if (s1 == 1 && s2 ==1){
    
    forward_x(normal_delay);
    float j=0;
    myservo2.write(j);
    while(j<90){
      j=j+0.001;
    }
   status_11(normal_delay);
  }
  else {
    call_status(normal_delay);
  }
  s3 = digitalRead(A2);
  }

}
void status_10(int normal_delay){
  bool s1,s2,s3;
  s1 = digitalRead(A0);
  s2 = digitalRead(A1);
  s3 = digitalRead(A2);
  Serial.println("10");
  while (s3 == 1){
  if (s1 ==0 && s2 ==1){
    backward_x(normal_delay);
     float i = 180;
      float j = 180;
  while (i>90&& j >90){
    myservo.write(i);
    myservo2.write(j);
    j=  j-0.001;
    i = i-0.001;
    }
    status_01(normal_delay);
   
  }
  if (s1 == 0 && s2 ==0){
    backward_x(normal_delay);
    float j=180;
    while(j>90){
       myservo2.write(j);
      j= j-0.001;
    }
    
    status_00(normal_delay);
    
  }
  if (s1 == 1 && s2 ==0){
   
    
  }
  if (s1 == 1 && s2 ==1){
    backward_x(normal_delay);
    backward_y(normal_delay);
    float j=0;
    while(j<90){
       myservo2.write(j);
      j= j+0.001;
    }
    status_11(normal_delay);
    
  }
  else {
    call_status(normal_delay);
  }
  s3 = digitalRead(A2);
  }

}

void call_status(int normal_delay){
  bool s1,s2,s3;
  s1 = digitalRead(A4);
  s2 = digitalRead(A5);
  s3 = digitalRead(A3);
  while(s3 ==1){

  if (s1 ==0 && s2 ==1){
    status_01(normal_delay);

  }
  if (s1 == 0 && s2 ==0){
    status_00(normal_delay);
    
  
  }
  if (s1 == 1 && s2 ==0){
    status_10(normal_delay);
    
    
    
  }
  if (s1 == 1 && s2 ==1){
  
  status_11(normal_delay);
 
 
  }
  s3 = digitalRead(A3);
}
}
