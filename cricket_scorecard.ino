#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address and size (16x2)
const int buttonPin = 2; // Pin connected to the button
const int buttonPin2 = 8; 
const int buttonPin3 = 7;
const int buttonPin4 = 12; 
const int buttonPin5 = 13; 
const int buttonPin6 = 5; 
const int buttonPin7 = 6; 
int runs=0;
int wickets=0;
int balls=0;
int overs=0;
int fir_inn=1;
int sec_inn=0;
double runrate=0;
double req_runrate=0;
int A_runs=0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as input with internal pull-up resistor

  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP); 
   pinMode(buttonPin4, INPUT_PULLUP);
    pinMode(buttonPin5, INPUT_PULLUP);
       pinMode(buttonPin6, INPUT_PULLUP);
          pinMode(buttonPin7, INPUT_PULLUP);
  Serial.begin(9600);               // Initialize serial communication
  lcd.init();        // Initialize the LCD
  lcd.backlight();   // Turn on the backlight
   lcd.print(runs);         
    lcd.print("/");
    lcd.print(wickets);
    lcd.print(" TEAM-A ");
    lcd.print(overs);
    lcd.print(".");
    lcd.print(balls);
    lcd.setCursor(0, 1); 
    lcd.print("runrate:");
   
    lcd.print(runrate);
     // Display initial message
  lcd.setCursor(7, 0); // Move cursor to the second line
 
}
void print_runs(){
  lcd.clear();
  lcd.print(runs);         
    lcd.print("/");
    lcd.print(wickets); 
   lcd.print(" TEAM-A ");
    lcd.print(overs);
    lcd.print(".");
    lcd.print(balls);

    lcd.setCursor(0, 1); 
    lcd.print("runrate:");
     runrate = (double)6 * (runs / (double)(overs * 6 + balls));

    lcd.print(runrate);
    
     
    delay(500); 
    loop();        

}
void second(){
  lcd.clear();
  lcd.print(runs);         
    lcd.print("/");
    lcd.print(wickets); 
   lcd.print(" B ");
    lcd.print(overs);
    lcd.print(".");
    lcd.print(balls);

    
    
     runrate = (double)6 * (runs / (double)(overs * 6 + balls));
   lcd.print(" ");
    lcd.print(runrate);
    lcd.setCursor(0, 1); 
    int req_run=A_runs-runs+1;
    lcd.print(req_run);
    lcd.print(" in ");
    int in_ball=12-(overs*6+balls);
    lcd.print(in_ball);
    lcd.print(" ");
  req_runrate=(double)6 * (req_run / (double)in_ball);

  lcd.print(req_runrate);

    
     
    delay(500); 
    loop(); 
}

void loop() {
    
   
   if (digitalRead(buttonPin) == LOW) { // LOW means the button is pressed with the internal pull-up resistor
    
    runs=runs+1;
    if(runs>=A_runs && sec_inn==1){
      lcd.clear();
      lcd.print("winner : TEAM B ");
      lcd.setCursor(0,1);
      lcd.print("win by ");
      int re=10-wickets;
      lcd.print(re);
      lcd.print(" wkts");
      delay(6000);
      lcd.clear();
      runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
    }
    if(fir_inn){
    print_runs();
    } 
    else{
      second();
    }
    
  }
    if (digitalRead(buttonPin4) == LOW) { // LOW means the button is pressed with the internal pull-up resistor
    
    runs=runs+4;
    if(runs>=A_runs && sec_inn==1){
      lcd.clear();
      lcd.print("winner : TEAM B ");
      lcd.setCursor(0,1);
      lcd.print("win by ");
      int re=10-wickets;
      lcd.print(re);
      lcd.print(" wkts");
      delay(6000);
      lcd.clear();
      runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
    }
    balls=balls+1;
    if(balls==6){
      balls=0;
      overs=overs+1;
    }
    if(overs==2){
      if(fir_inn){
      lcd.clear();
      lcd.print("TEAM A score=");
      lcd.print(runs);
      lcd.setCursor(0, 1); 
      lcd.print(runs+1); 
      lcd.print(" runs");
      lcd.print(" to win"); 
      A_runs=runs;
      runs=0;
      wickets=0;
      balls=0;
      overs=0;
      delay(5000);
      lcd.clear();
      fir_inn=0;
      sec_inn=1;
      }
      else{
        if(runs>=A_runs && sec_inn==1){
      lcd.clear();
    
        lcd.print("winner : TEAM B ");
      lcd.setCursor(0,1);
      lcd.print("win by ");
      lcd.print(10-wickets);
      lcd.print(" wkts");
      
      delay(6000);
      lcd.clear();
      runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
    }
    else{
       lcd.clear();
        lcd.print("winner : TEAM A ");
        lcd.setCursor(0, 1); 
        lcd.print("win by ");
        lcd.print(A_runs-runs);
        lcd.print(" runs");
        runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
      delay(6000);
    }
      }
      
    }
    
    if(fir_inn){
    print_runs();
    }  
    else{
      second();
    }       
  }
     if (digitalRead(buttonPin5) == LOW) { // LOW means the button is pressed with the internal pull-up resistor
    lcd.clear();
    runs=runs+6;
    if(runs>=A_runs && sec_inn==1){
      lcd.clear();

      lcd.print("winner : TEAM B ");
      lcd.setCursor(0,1);
      lcd.print("win by ");
      int re=10-wickets;
      lcd.print(re);
      lcd.print(" wkts");
      delay(6000);
      lcd.clear();
      runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
    }
    balls=balls+1;
    if(balls==6){
      balls=0;
      overs=overs+1;
    }
    if(overs==2){
      if(fir_inn){
      lcd.clear();
      lcd.print("TEAM A score=");
      lcd.print(runs);
      lcd.setCursor(0, 1); 
      lcd.print(runs+1); 
      lcd.print(" runs");
      lcd.print(" to win"); 
      A_runs=runs;
      runs=0;
      wickets=0;
      balls=0;
      overs=0;
      delay(5000);
      lcd.clear();
      fir_inn=0;
      sec_inn=1;
      }
      else{
        if(runs>=A_runs && sec_inn==1){
      lcd.clear();
      if(runs==A_runs){
        lcd.print("MATCH DRAWN");
      }
      else{
        lcd.print("winner : TEAM B ");
      lcd.setCursor(0,1);
      lcd.print("win by ");
      lcd.print(10-wickets);
      lcd.print(" wkts");
      }
      
      delay(6000);
      lcd.clear();
      runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
    }
    else{
       lcd.clear();
        lcd.print("winner : TEAM A ");
        lcd.setCursor(0, 1); 
        lcd.print("win by ");
        lcd.print(A_runs-runs);
        lcd.print(" runs");
        runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
      delay(6000);
    }
      }
      
    }
    if(fir_inn){
    print_runs();
    }
    else{
      second();
    } 
           
  }
  if (digitalRead(buttonPin2) == LOW) { // LOW means the button is pressed with the internal pull-up resistor
    lcd.clear();
   
    wickets=wickets+1;
    balls=balls+1;
    if(balls==6){
      balls=0;
      overs=overs+1;
    }
     if(wickets==10){
      if(fir_inn){
      lcd.clear();
      lcd.print("TEAM A score=");
      lcd.print(runs);
      lcd.setCursor(0, 1); 
      lcd.print(runs+1); 
      lcd.print(" runs");
      lcd.print(" to win"); 
      A_runs=runs;
      runs=0;
      wickets=0;
      balls=0;
      overs=0;
      delay(5000);
      lcd.clear();
      fir_inn=0;
      sec_inn=1;
      }
      else{
        lcd.clear();
        lcd.print("winner : TEAM A ");
        lcd.setCursor(0, 1); 
        lcd.print("win by ");
        lcd.print(A_runs-runs);
        lcd.print(" runs");
        runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
        delay(6000);
      }

    }
    else{ 
       if(overs==2){
      if(fir_inn){
      lcd.clear();
      lcd.print("TEAM A score=");
      lcd.print(runs);
      lcd.setCursor(0, 1); 
      lcd.print(runs+1); 
      lcd.print(" runs");
      lcd.print(" to win"); 
      A_runs=runs;
      runs=0;
      wickets=0;
      balls=0;
      overs=0;
      delay(5000);
      lcd.clear();
      fir_inn=0;
      sec_inn=1;
      }
      else{
        if(runs>=A_runs && sec_inn==1){
      lcd.clear();
        lcd.print("winner : TEAM B ");
      lcd.setCursor(0,1);
      lcd.print("win by ");
      lcd.print(10-wickets);
      lcd.print(" wkts");
      
      delay(6000);
      lcd.clear();
      runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
    }
    else{
       lcd.clear();
        lcd.print("winner : TEAM A ");
        lcd.setCursor(0, 1); 
        lcd.print("win by ");
        lcd.print(A_runs-runs);
        lcd.print(" runs");
        runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
      delay(6000);
    }
      }
      
    }
  if(fir_inn){
    print_runs();
    }   
    else{
      second();
    }        
  }

  }
   if (digitalRead(buttonPin3) == LOW) { // LOW means the button is pressed with the internal pull-up resistor
    lcd.clear();
    balls=balls+1;
    if(balls==6){
      balls=0;
      overs=overs+1;
    }
    if(overs==2){
      if(fir_inn){
      lcd.clear();
      lcd.print("TEAM A score=");
      lcd.print(runs);
      lcd.setCursor(0, 1); 
      lcd.print(runs+1); 
      lcd.print(" runs");
      lcd.print(" to win"); 
      A_runs=runs;
      runs=0;
      wickets=0;
      balls=0;
      overs=0;
      delay(5000);
      lcd.clear();
      fir_inn=0;
      sec_inn=1;
      }
      else{
        if(runs>=A_runs && sec_inn==1){
      lcd.clear();

      
        lcd.print("winner : TEAM B ");
      lcd.setCursor(0,1);
      lcd.print("win by ");
      lcd.print(10-wickets);
      lcd.print(" wkts");
      
      delay(6000);
      lcd.clear();
      runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
    }
    else{
       lcd.clear();
        lcd.print("winner : TEAM A ");
        lcd.setCursor(0, 1); 
        lcd.print("win by ");
        lcd.print(A_runs-runs);
        lcd.print(" runs");
        runs=0;
      balls=0;
      wickets=0;
      A_runs=0;
      fir_inn=1;
      sec_inn=0;
      overs=0;
      delay(6000);
    }
      }
      
    }
  if(fir_inn){
    print_runs();
    }   
    else{
      second();
    }     
  }
    if (digitalRead(buttonPin6) == LOW) { 
    lcd.clear();
    balls=balls-1;
    if(fir_inn){
    print_runs();
    }   
    else{
      second();
    }     
  }
   if (digitalRead(buttonPin7) == LOW) { 
    lcd.clear();
   wickets=wickets-1;
    if(fir_inn){
    print_runs();
    }   
    else{
      second();
    }     
  }
  
  
  

}
