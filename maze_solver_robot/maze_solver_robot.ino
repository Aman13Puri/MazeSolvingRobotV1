

    // definitions and declarations of variables of the robot code maze resolver;
    
    #define vel_motor_left 10  // controls left motor speed;
    #define vel_motor_right 11  // controls right motor speed;         
    #define l1 8  // controls the direction of rotation of the left motor;
    #define l2 9  // controls the direction of rotation of the left motor;
    #define r1 12  //controls the direction of rotation of the right motor;
    #define r2 7  //controls the direction of rotation of the right motor
 
    int trigger_front = A4; // controls the pulse sent from the front sensor
    int echo_front = A5; // controls the pulse revieved from the front sensor    
    int trigger_left = A2;// controls the pulse sent from the left sensor
    int echo_left = A3;// controls the pulse recieved from the left sensor
    int trigger_right = A0;// controls the pulse sent from the right sensor
    int echo_right = A1;// controls the pulse recieved from the right sensor
    
    //configuration of input types of declared variables;    
    void setup()
    {
        pinMode(trigger_front, OUTPUT); // trigger_front arduino signal output
        pinMode(echo_front, INPUT);// trigger_front arduino signal input
        
        pinMode(trigger_left, OUTPUT);// trigger_left arduino signal output
        pinMode(echo_left, INPUT);// trigger_front arduino signal input        
        
        pinMode(trigger_right, OUTPUT);// trigger_right arduino signal output
        pinMode(echo_right, INPUT);// trigger_front arduino signal input
       
        pinMode(vel_motor_left, OUTPUT);// arduino signal output from left motor speed
        pinMode(vel_motor_right, OUTPUT);// arduino signal output from right motor speed
     
        pinMode(l1, OUTPUT);// arduino signal output from the left motor rotation direction control
        pinMode(l2, OUTPUT);// arduino signal output from the left motor rotation direction control
        pinMode(r1, OUTPUT);// arduino signal output from the right motor rotation direction control
        pinMode(r2, OUTPUT);// arduino signal output from the right motor rotation direction control      
        delay(5000);
    }
    
    //code in infinite repetition of the project;
    void loop()
    {
     // declaration of variables used to control the project;
     long duration_front, duration_left, duration_right, right, left, front; 
     
     
     digitalWrite(trigger_front, LOW);  
     delayMicroseconds(2);
     digitalWrite(trigger_front, HIGH);  
     delayMicroseconds(5);             
     digitalWrite(trigger_front, LOW); 
     duration_front = pulseIn(echo_front, HIGH);
     front = duration_front/29/2;
    
     digitalWrite(trigger_left, LOW);
     delayMicroseconds(2);
     digitalWrite(trigger_left, HIGH);
     delayMicroseconds(5);
     digitalWrite(trigger_left, LOW); 
     duration_left = pulseIn(echo_left, HIGH);
     left = duration_left/29/2;
    
     digitalWrite(trigger_right, LOW);
     delayMicroseconds(2);
     digitalWrite(trigger_right, HIGH);
     delayMicroseconds(5);
     digitalWrite(trigger_right, LOW); 
     duration_right = pulseIn(echo_right, HIGH);
     right = duration_right/29/2; 
     
     analogWrite(vel_motor_left, 0);  
     analogWrite(vel_motor_right, 0); 
     analogWrite(l1, 0);            
     analogWrite(l2, 0);              
     analogWrite(r1, 0);            
     analogWrite(r2, 0);            
     
       if(front >8) // if there is a free path ahead it follows this logic below::
         {  
           
          //the use of the four if's below within this if is for the control of the robot's handling,
  
           
           if(right >7 && right< 13) 
           {               
               analogWrite(vel_motor_left, 120);
               analogWrite(vel_motor_right, 150);
           
               analogWrite(l1, 200);
               analogWrite(l2, 0);
               analogWrite(r1, 0);
               analogWrite(r2, 200);                                                        
             }
         
           if(right >=13)  
           {
               analogWrite(vel_motor_left, 255);
               analogWrite(vel_motor_right, 60);
           
               analogWrite(l1, 255);
               analogWrite(l2, 0);
               analogWrite(r1, 0);
               analogWrite(r2, 255);                               
             }
             
                 
           if(right <=7)   
           {
               analogWrite(vel_motor_left, 60);
               analogWrite(vel_motor_right, 255);
           
               analogWrite(l1, 255);
               analogWrite(l2, 0);
               analogWrite(r1, 0);
               analogWrite(r2, 255);                   
             }
         }
         
              
       if(left <=20 && right>20 && front <=8) right_turn();  
       if(right <=20 && left>20 && front <=8) left_turn(); 
       if(right<=20 && left<=20 && front<=8) rotate(); 
    }
       
    void left_turn() // 
function to make the robot rotate 90º to left if it does not have front and right;
      {
       
        analogWrite(vel_motor_left, 120);
        analogWrite(vel_motor_right, 120);
           
        analogWrite(l1, 0);
        analogWrite(l2, 255);
        analogWrite(r1, 0);
        analogWrite(r2, 255);
        delay(700);      
        
      }
    
    void right_turn() // function to make the robot rotate 90º to right if it does not have front and left;
      {
        
      
        analogWrite(vel_motor_left, 120);
        analogWrite(vel_motor_right, 120);
        
        analogWrite(l1, 255);
        analogWrite(l2, 0);
        analogWrite(r1, 255);
        analogWrite(r2, 0);             
        delay(800);
               
      }
    
    void rotate() // function to make the robot rotate 180º if there is no forward, left and right exit;
      {
       
        analogWrite(vel_motor_left, 120);
        analogWrite(vel_motor_right, 120);
           
        analogWrite(l1, 255);
        analogWrite(l2, 0);
        analogWrite(r1, 255);
        analogWrite(r2, 0);
        delay(1200); 
         
               }   
  
    
    
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
