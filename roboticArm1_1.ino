//*****************************************************************************
//BT_Robotic Arm V1.1
//阿布拉機的3D列印與機器人
//http://arbu00.blogspot.tw/
//
//2016/01/04 Writen By Ashing Tsai
//
//
//******************************************************************************
#include <Servo.h> 
Servo servo6;
Servo servo5;
Servo servo4;
Servo servo3;
Servo servo2;
//==============================

int angle6=20;
int angle5=90;
int angle4=90;
int angle3=90;
int angle2=90;

int angle=90;

int time3, time4;
//=============================
const int refVolts=5;
const int speaker=13;
const int swA=9;     //digital pin 9  0:press button ,claw close  ,1: release  no action
const int swB=10;     //digital pin 10  0:press button ,claw open   ,1: release  no action
const int sw11=11;     //digital pin 11  1:manual mode 0:auto mode
int Sw_flagA,Sw_flagB,Sw_flagD11;
//============================

void setup() 
{ 
 
  Serial.begin(115200);
  pinMode(swA,INPUT);
  pinMode(swB,INPUT);
  pinMode(sw11,INPUT);
  pinMode(speaker,OUTPUT);

   servo6.attach(6);
   servo5.attach(5);
   servo4.attach(4);
   servo3.attach(3);
   servo2.attach(2);

         time3=7;
		     time4=50;

	  Middle();

} 
void loop() 
{
 
  Sw_flagD11=digitalRead(sw11);
//  Serial.print("D11=");
//  Serial.println(Sw_flagD11);

  //Sw_flagA=digitalRead(swA);
//  Serial.print("swA=");
//  Serial.println(Sw_flagA);
 // Sw_flagB=digitalRead(swB);
 // Serial.print("swB=");
 // Serial.println(Sw_flagB);
  //delay(500);

 // GetBatteryvoltage( ) ;
  
    if (Sw_flagD11)    //if 1 =Manualmode;
	{
     Manualmode() ;
	}
	else
	{
	  AutoMode() ;
	}
 
 
 
} 

void Manualmode() 
{

A_XAxis( );  //servo 2
A_YAxis( );  //servo 3
B_XAxis( );  //servo 4
B_YAxis( );  //servo 5
  JoyClickA();   // when press button to close claw
  JoyClickB();    //when press button to open  claw
}

void AutoMode() 
{

         //==============================

		    Servoangle2(50);   //
	      Servoangle3(130); //
	      Servoangle4(50);   // 
	      Servoangle5(150); // 
	      Servoangle6(65)  ; //  Claw closed
	      delay(300);
         //========return===============
    
	      Servoangle3(90); //
	      Servoangle4(90);   // 
	      Servoangle5(90); // 
	   
	   
         //==========================
		 
		    Servoangle2(130);   //
		    Servoangle3(120);   //
	      Servoangle4(50);     //
	      Servoangle5(120);   // 
	      Servoangle6(5)  ;   //Claw open

          delay(300);

   //========return===============
		    Servoangle2(120);   // 
		    Servoangle3(90);   //
	      Servoangle4(90);   //
	      Servoangle5(90);   // 

}

void Middle()
{

      Servoangle2(90); // base
	    Servoangle3(90); //
	    Servoangle4(90); //
	    Servoangle5(90); //
      Servoangle6(20); // claw
      delay(200);
         
}

void Servoangle2A(int angle)
{

                 servo2.write(angle);
                 delay(100);   //100ms

}

void Servoangle2(int angle)
{

  if  (angle2!=angle){
		     while (angle2>angle)
		 {
		         angle2=angle2-2;
                 servo2.write(angle2);
                 delay(time4);  //50ms
		  }
		  while (angle2<angle)
		 {
		         angle2=angle2+2;
                 servo2.write(angle2);
                 delay(time4);  //50ms
		  }
	}else
    {
                 servo2.write(angle2);
                 delay(time4);   //50ms
	}	
    
}
void Servoangle3(int angle)
{

  if  (angle3!=angle){
		     while (angle3>angle)
		 {
		         angle3=angle3-2;
                 servo3.write(angle3);
                 delay(time4);  //50ms
		  }
		  while (angle3<angle)
		 {
		         angle3=angle3+2;
                 servo3.write(angle3);
                 delay(time4);  //50ms
		  }
	}else
    {
                 servo3.write(angle3);
                 delay(30);   //50ms
	}	
    
}
void Servoangle4(int angle)
{

  if  (angle4!=angle){
		     while (angle4>angle)
		 {
		         angle4=angle4-2;
                 servo4.write(angle4);
                 delay(time4);  //50ms
		  }
		  while (angle4<angle)
		 {
		         angle4=angle4+2;
                 servo4.write(angle4);
                 delay(time4);  //50ms
		  }
	}else
    {
                 servo4.write(angle4);
                 delay(time4);   //50ms
	}	
    
}
void Servoangle5(int angle)
{

  if  (angle5!=angle){
		     while (angle5>angle)
		 {
		         angle5=angle5-2;
                 servo5.write(angle5);
                 delay(time4);  //50ms
		  }
		  while (angle5<angle)
		 {
		         angle5=angle5+2;
                 servo5.write(angle5);
                 delay(time4);  //50ms
		  }
	}else
    {
                 servo5.write(angle5);
                 delay(time4);   //50ms
	}	
    
}
void Servoangle6(int angle)
{

  if  (angle6!=angle){
		     while (angle6>angle)
		 {
		         angle6=angle6-2;
                 servo6.write(angle6);
                 delay(time4);  //50ms
		  }
		  while (angle6<angle)
		 {
		         angle6=angle6+2;
                 servo6.write(angle6);
                 delay(time4);  //50ms
		  }
	}else
    {
                 servo6.write(angle6);
                 delay(time4);   //50ms
	}	
    
}
void A_XAxis( void)   //servo 2
{
int val1;
float volts;
    //A_X axis===================================================
  val1=analogRead(1);
  volts=(float)val1*refVolts/1024;  
//  Serial.print("A_X_voltage=");
 // Serial.print(volts,2);
 // Serial.println("V");


   if (volts>=4.0)
   {
          if (angle2<=170) { angle2=angle2+1;}
             servo2.write(angle2);
             delay(time3);       //50ms
    }else if (volts<=1.0)
            {
              if (angle2>=10){ angle2=angle2-1;}
              servo2.write(angle2);
              delay(time3);         //50ms
            }
     else {
                    servo2.write(angle2);
                      delay(time3);           //50ms
          }
  
  //-------------------------------------------------------------------------------------------------------------
    
}
void A_YAxis( void)    //servo 3
{
int val0;
float volts;
   //A_Y axis servo 3===========================================
  val0=analogRead(0);
  volts=(float)val0*refVolts/1024;  
 // Serial.print("A_Y_voltage=");
 // Serial.print(volts,2);
 // Serial.println("V");

	
   if (volts>=4.0)
	 {
       if (angle3<=170) { 
	       angle3=angle3+1;
        }     
            servo3.write(angle3);
            delay(15);      //50ms
    }else if (volts<=1.0){

              if (angle3>=10) { 
                              angle3=angle3-1;
                             }     	            
                              servo3.write(angle3);
                              delay(time3);         //50ms
		                   }
	   else {    
                 servo3.write(angle3);
                 delay(15);     
	        }
	
	//------------------------------------------------------------------------------------------------
    
}

void B_XAxis( void)   //servo 4
{
int val3;
float volts;
    //B_X axis===================================================
  val3=analogRead(3);
  volts=(float)val3*refVolts/1024;  
//  Serial.print("B_X_voltage=");
//  Serial.print(volts,2);
//  Serial.println("V");


   if (volts>=4.0)
   {
          if (angle4<=170) { angle4=angle4+1;}
             servo4.write(angle4);
             delay(time3);       //50ms
    }else if (volts<=1.0)
            {
              if (angle4>=10){ angle4=angle4-1;}
              servo4.write(angle4);
              delay(time3);         //50ms
            }
     else {
                    servo4.write(angle4);
                      delay(time3);           //50ms
          }
  
  //-------------------------------------------------------------------------------------------------------------
    
}
void B_YAxis( void)    //servo 5
{
int val2;
float volts;
   //B_Y axis servo 5===========================================
  val2=analogRead(2);
  volts=(float)val2*refVolts/1024;  
//  Serial.print("B_Y_voltage=");
//  Serial.print(volts,2);
//  Serial.println("V");

  
   if (volts>=4.0)
   {
       if (angle5<=170) { 
         angle5=angle5+1;
        }     
            servo5.write(angle5);
            delay(time3);      //50ms
    }else if (volts<=1.0){

              if (angle5>=10) { 
                              angle5=angle5-1;
                             }                  
                              servo5.write(angle5);
                              delay(time3);         //50ms
                       }
     else {    
                 servo5.write(angle5);
                 delay(time3);     
          }
  
  //------------------------------------------------------------------------------------------------
    
}
void JoyClickA(void )
{
  pinMode(swA,INPUT);

   //Joystick click button===================================================
  Sw_flagA=digitalRead(swA);
//  Serial.print("Switch=");
//  Serial.print(Sw_flagA,2);



      if (Sw_flagA==0)                    // 0:press button
	    {
          
            if (angle6<=65)
	        {  
              angle6=angle6+1;
              servo6.write(angle6);         //Claw close
              delay(7);                      
            }else
            { 
              servo6.write(angle6);         //keep
              delay(7);                     
            }
 
         }

    
}
void JoyClickB(void )
{
  pinMode(swB,INPUT);
   //Joystick click button===================================================
  Sw_flagB=digitalRead(swB);
 // Serial.print("Switch=");
 // Serial.print(Sw_flagB,2);


  if (Sw_flagB==0)                    // 0:press button
      {
          
            if (angle6>=5)
          {  
              angle6=angle6-1;
              servo6.write(angle6);              //Claw open
              delay(7);                     
            }else
            { 
              servo6.write(angle6);              //keep
              delay(7);                      
            }
 
         }
}

//---below are not neccessary--------
void GetBatteryvoltage( void)   
{
int val4;
float volts;
  const int refVoltsBattery=8.6; 
  val4=analogRead(4);
  volts=(float)val4*refVoltsBattery/1024;  
//  Serial.print("Battery_voltage=");
//  Serial.print(volts,2);
//  Serial.println("V");



 if (volts<7.0)
   {
     Speakersound();   
   }
  
  //------------------------------------------------------------------------------------------------
    
}

void Speakersound() 
{
  for(int i=0;i<10;i++)
  {
    tone(speaker,1000);
    delay(25);
    tone(speaker,500);
    delay(25);
  }
  noTone(speaker);
}



