int pinVerde = 10;  //varíavel para o led de ligar
int pinVermelho = 9; //variável para o led de desligar
int botaoLiga = 8  //variável para o botão de ligar
int botaoDesliga = 7 //variável para o botão de desligar
int motor = 6  // variável para o motor do portão
Servo s; // Variável para o motor do portão
int pos; // Posição Servo
int S4; // sensor de travamento

void setup()
{
  pinMode(pinVerde,OUTPUT);
  pinMode(pinVermelho,OUTPUT);
  pinMode(botaoLiga,INPUT);
  pinMode(botaoDesliga,INPUT);
  pinMode(moto,OUTPUT);
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(90); // Inicia motor posição final(quando ele está fechado)
  
}

void loop()
{
  if (botaoLiga== HIGH){
    digitalWrite(pinVerde,HIGH);
    digitalWrite(pinVermelho,LOW);
  
  for(pos = 90; pos >= 0; pos--)  // o motor do portão vai abrir 
  {
    s.write(pos);
    delay(12); //vai demorar 12 segundos para ele abrir
    do{
      digitalWrite(S4==HIGH); // sensor atuador de travamento liga
      delay(2) // delay de 2 segundos de travamento        
        s.write(pos); // motor continua na posição onde estava    
        delay(6) // vai demorar metado do tempo para finalizar o fechamento do motor
       
      }while(botaoDesliga==HIGH)
  }
    if (botaoDesliga== HIGH){
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinVermelho,HIGH);
  
  for(pos = 0; pos < 90; pos++)  // o motor do portão vai abrir 
  {
    s.write(pos);
    delay(12); //vai demorar 12 segundos para ele abrir
    do{
      digitalWrite(S4==HIGH); // sensor atuador de travamento liga
      delay(2) // delay de 2 segundos de travamento        
        s.write(pos); // motor continua na posição onde estava    
        delay(6) // vai demorar metado do tempo para finalizar o fechamento do motor
       
      }while(botaoliga==HIGH);
  } //fechamento do for
    
    
     } // fechamento do if
  
  

} //fechamento do loop principal
