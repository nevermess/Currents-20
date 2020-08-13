 int sensor[5]={0,0,0,0,0},kp,p,d,kd,error;
int last_error=0;
void setup() {

pinMode(6,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(7,INPUT);
Serial.begin(9600);

}

void loop() {
 
sensor[0]=digitalRead(2);
sensor[1]=digitalRead(3);
sensor[2]=digitalRead(4);
sensor[3]=digitalRead(5);
sensor[4]=digitalRead(7);

 if(sensor[0]==1&&sensor[1]==1&&sensor[2]==0&&sensor[3]==1&&sensor[4]==1)
   error=0;

 else if(sensor[0]==1&&sensor[1]==1&&sensor[2]==1&&sensor[3]==1&&sensor[4]==0)
    error=4;
 
 else if(sensor[0]==1&&sensor[1]==1&&sensor[2]==1&&sensor[3]==0&&sensor[4]==0)
    error=3;
 
 else if(sensor[0]==1&&sensor[1]==1&&sensor[2]==1&&sensor[3]==0&&sensor[4]==1)
    error=2;
 
 else if(sensor[0]==1&&sensor[1]==1&&sensor[2]==0&&sensor[3]==0&&sensor[4]==1)
    error=1;
 
 else if(sensor[0]==1&&sensor[1]==0&&sensor[2]==0&&sensor[3]==1&&sensor[4]==1)
    error=-1;
 
 else if(sensor[0]==1&&sensor[1]==0&&sensor[2]==1&&sensor[3]==1&&sensor[4]==1)
    error=-2;
 
 else if(sensor[0]==0&&sensor[1]==0&&sensor[2]==1&&sensor[3]==1&&sensor[4]==1)
    error=-3;
 
 else if(sensor[0]==0&&sensor[1]==1&&sensor[2]==1&&sensor[3]==1&&sensor[4]==1)
    error=-4;


 //if(Serial.available()>0)
  {
  // if(Serial.read()%10==1)  //send data as xx1
     kp=20; //18,22

   //else if(Serial.read()%10==2)   //send data as xx2
    kd=37; //5,7,25,28,32,<40
  }  
  p=kp*error;
  d=kd*(error-last_error);
  last_error=error;
  if(!(sensor[0]==0&&sensor[1]==0&&sensor[2]==0&&sensor[3]==1&&sensor[4]==1)&&!(sensor[0]==1&&sensor[1]==1&&sensor[2]==0&&sensor[3]==0&&sensor[4]==0))
 { digitalWrite(6,1);
   digitalWrite(8,0);
   digitalWrite(10,1);
   digitalWrite(12,0);
  analogWrite(9,100-p-d); //120
  
  analogWrite(11,100+p+d);
 }
  
 if(sensor[0]==1&&sensor[1]==1&&sensor[2]==1&&sensor[3]==1&&sensor[4]==1)
  {digitalWrite(6,1);
   digitalWrite(8,0);
   digitalWrite(10,1);
   digitalWrite(12,0);
   analogWrite(9,100-(20*last_error));
   
   analogWrite(11,100+(20*last_error));
  // delay(2);
  }

 /*  else if(sensor[0]==0&&sensor[1]==0&&sensor[2]==0&&sensor[3]==1&&sensor[4]==1)
    {analogWrite(6,100);
     analogWrite(9,0);
     analogWrite(10,0);
     analogWrite(11,100);
     delay(5);
     analogWrite(6,0);
     analogWrite(9,230);
     analogWrite(10,230);
     analogWrite(11,0);
     delay(5);
    }

 else if(sensor[0]==1&&sensor[1]==1&&sensor[2]==0&&sensor[3]==0&&sensor[4]==0)
    {analogWrite(6,100);
     analogWrite(9,0);
     analogWrite(10,0);
     analogWrite(11,100);
     delay(5);
     analogWrite(6,230);
     analogWrite(9,0);
     analogWrite(10,0);
     analogWrite(11,230);
     delay(5);
    }*/     }
