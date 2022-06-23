const int A = 2; // Primeiramente setamos os 7 pinos dos segmentos
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;


int VM=11;
int AM=9;
int AZ=10;

const int l = 1, d = 0;

void setup () {
  pinMode(A, OUTPUT); // seta todos as portas que estão os leds do display como saída
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode (VM,OUTPUT);
  pinMode (AM,OUTPUT);
  pinMode (AZ,OUTPUT);
  Serial.begin (9600);
  Serial.println("Configurando... ");
  Serial.println("MEDIAÇÃO DO NÍVEL DE ÁGUA");
}

void zero(){
  digitalWrite(A, l); //acende os leds que representam o número 0
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, l);
  digitalWrite(E, l);
  digitalWrite(F, l);
  digitalWrite(G, d);
  }

void um(){
  digitalWrite(A, d); //acende os leds que representam o número 1
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, d);
  digitalWrite(E, d);
  digitalWrite(F, d);
  digitalWrite(G, d);
  }

void dois(){
  digitalWrite(A, l); //acende os leds que representam o número 2
  digitalWrite(B, l);
  digitalWrite(C, d);
  digitalWrite(D, l);
  digitalWrite(E, l);
  digitalWrite(F, d);
  digitalWrite(G, l);
  }

void tres(){
  digitalWrite(A, l); //acende os leds que representam o número 3
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, l);
  digitalWrite(E, d);
  digitalWrite(F, d);
  digitalWrite(G, l);
  }

void quatro(){
  digitalWrite(A, d); //acende os leds que representam o número 4
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, d);
  digitalWrite(E, d);
  digitalWrite(F, l);
  digitalWrite(G, l);
  }

void cinco(){
  digitalWrite(A, l); //acende os leds que representam o número 5
  digitalWrite(B, d);
  digitalWrite(C, l);
  digitalWrite(D, l);
  digitalWrite(E, d);
  digitalWrite(F, l);
  digitalWrite(G, l);
  }

void seis(){
  digitalWrite(A, d); //acende os leds que representam o número 6
  digitalWrite(B, d);
  digitalWrite(C, l);
  digitalWrite(D, l);
  digitalWrite(E, l);
  digitalWrite(F, l);
  digitalWrite(G, l);
  }

  
void loop() {
  int valor = analogRead(A0);
  Serial.println(valor);
  if (valor > 400) {
    Serial.println("NÍVEL ALTO");
    digitalWrite(AZ, LOW);
    digitalWrite(AM, HIGH);
    digitalWrite(VM, HIGH);
    }
  else if ((valor > 300) and (valor <= 400)) {
    Serial.println("NÍVEL MÉDIO");
    digitalWrite(AM, LOW);
    digitalWrite(VM, HIGH);
    digitalWrite(AZ, HIGH);
    }
  else if(valor <= 300){
    Serial.println("NÍVEL BAIXO");
    digitalWrite(VM, LOW);
    digitalWrite(AZ, HIGH);
    digitalWrite(AM ,HIGH);
    delay(100);
    }
  if(valor < 100){
    zero();
    }
  if((valor >= 100) and (valor < 200)){
    um();
    }
  if((valor >= 200) and (valor < 300)){
    dois();
  }
  if((valor >= 300) and (valor < 400)){
    tres();
  }
  if((valor >= 400) and (valor < 500)){
    quatro();
  }
  if((valor >= 500) and (valor < 600)){
    cinco();
    }
  if((valor >= 600) and (valor < 700)){
    seis();
  }
}

  
