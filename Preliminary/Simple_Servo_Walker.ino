#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#define START 4
#define STOP 5
#define SPEED 2
#define DIRECTION 3
#define LEFT 1
#define RIGHT -1
#define SERVO_OFFSET 90
#define WALK 5
#define TROT 20

boolean run = false;
int dir = LEFT;
int speed = WALK;

LiquidCrystal lcd(0);
Servo walker;

void setup(){
  lcd.begin(16, 2);
  lcd.print("Hello");
  
  walker.attach(9);
  walker.write( 90 );
  
  pinMode( START, INPUT );
  pinMode( STOP, INPUT );
  pinMode( DIRECTION, INPUT );
  pinMode( SPEED, INPUT);
  
  delay(1000);
  lcd.clear();
  lcd.print( "Stopped" );
  
}

void loop(){
  
  if( !run ){ settings(); }
  if( run ){ running(); }
  
}

void settings(){
  walker.write( 90 );
  
  if( !digitalRead( START )){
    delay(5);
    if( !digitalRead( START )){
      run = true;
      lcd.setCursor( 0, 0 );
      lcd.print("Running");
      
      lcd.setCursor( 0, 1 );
      if( speed == WALK ){
        lcd.print( "Walking ");
      }
      
      else{
        lcd.print( "Trotting" );
      }
      
      lcd.setCursor( 9, 1 );
      if( dir == LEFT ){
        lcd.print( "Left ");
      }
      
      else{
        lcd.print( "Right" );
      }
      
      while( !digitalRead( START)){}
      return;
    }
  }
  
  if( !digitalRead( DIRECTION )){
    delay(5);
    if( !digitalRead( DIRECTION )){
      
      if( dir == LEFT ) dir = RIGHT;
      else dir = LEFT;
      
      lcd.setCursor( 9, 1 );
      if( dir == LEFT ){
        lcd.print( "Left ");
      }
      
      else{
        lcd.print( "Right" );
      }
      
      while( !digitalRead( DIRECTION )){}
    }
  }
  
  if( !digitalRead( SPEED )){
    delay(5);
    if( !digitalRead( SPEED )){
      
      if( speed == WALK) speed = TROT;
      else speed = WALK;
      
      lcd.setCursor( 0, 1 );
      if( speed == WALK ){
        lcd.print( "Walking ");
      }
      
      else{
        lcd.print( "Trotting" );
      }
      while( !digitalRead( SPEED )){}
    }
  }
  
  
}

void running(){
  if( !digitalRead( STOP ) ){
    delay(5);
    if( !digitalRead( STOP )){
      run = false;
      lcd.setCursor( 0, 0 );
      lcd.print("Stopped");
      lcd.setCursor(0,1);
      lcd.print("                ");
      while( !digitalRead( STOP )){}
      return;
    }
  }
  
    if( !digitalRead( DIRECTION )){
    delay(5);
    if( !digitalRead( DIRECTION )){
      
      if( dir == LEFT ) dir = RIGHT;
      else dir = LEFT;
      
      lcd.setCursor( 9, 1 );
      if( dir == LEFT ){
        lcd.print( "Left ");
      }
      
      else{
        lcd.print( "Right" );
      }
      
      while( !digitalRead( DIRECTION )){}
    }
  }
  
  if( !digitalRead( SPEED )){
    delay(5);
    if( !digitalRead( SPEED )){
      
      if( speed == WALK) speed = TROT;
      else speed = WALK;
      
      lcd.setCursor( 0, 1 );
      if( speed == WALK ){
        lcd.print( "Walking ");
      }
      
      else{
        lcd.print( "Trotting" );
      }
      while( !digitalRead( SPEED )){}
    }
  }
    
    walker.write( speed * dir + SERVO_OFFSET );
}
