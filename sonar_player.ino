/* 
 *  
 * Code calcul distance && PLAY command pour un capteur à ultrasons HC-SR04.
 */

/* Constantes pour les broches */
const byte TRIGGER_PIN = 5; // Broche TRIGGER
const byte ECHO_PIN = 6;    // Broche ECHO
 
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

int Pdistance_mm, distance_mm,distancechange_mm;

/** Fonction setup() */
void setup() {
   
  /* Initialise le port série */
  Serial.begin(115200);
   
  /* Initialise les broches */
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
}



 
/** Fonction loop() */
void loop() {


  
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  
  Pdistance_mm=distance_mm ; //previous value & current value 
  
  distance_mm = measure / 2 * SOUND_SPEED; // calculate distance mm

  distancechange_mm = Pdistance_mm - distance_mm ; // calculate distance variation (previous - current)

  /* Affiche les résultats en mm, cm et m */
  /*Serial.print(F("Distance: "));
  Serial.print(distance_mm);
  Serial.print(F("mm ("));
  Serial.print(distance_mm / 10.0, 2);
  Serial.print(F("cm, "));
  Serial.print(distance_mm / 1000.0, 2);
  Serial.println(F("m)"));*/
  Serial.println(distance_mm); // print distance > for debugging


  
if ((distancechange_mm>=300) &&(distance_mm < 1000) && (distance_mm > 0)) {
Serial.println ("PLAY");};
/*send Play if variation greater than 1M (person appears), the distance is less than one meter - sufficient closeness, distance greater than zero - mitigate bugs*/


  /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  delay(1500);
}
  
