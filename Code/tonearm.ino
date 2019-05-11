/*
 * Project Adventures of Cem on the Wheels of Steel
 * Description: Inspired by Per Holmquist's 'Beat Blox' project, I'm trying to develop my own MIDI controller that uses 4 Adafruit APDS9960 proximity sensors that allows users to create their own beats. 
 * The sequence created physically on a rotating disk; a wheel of steel, will be converted to MIDI information and fed to a Digital Audio Workstation such as Ableton Live through USB to be turned and be converted into music.
 * Components: Adafruit APDS9960, SparkFun PID 13906
 * Author: Cem Ergin
 * Date: May 10th 2019
 */

// MIDI USB Dependencies
#include <pitchToFrequency.h>
#include <pitchToNote.h>
#include <frequencyToNote.h>
#include <MIDIUSB_Defs.h>
#include <MIDIUSB.h>

// Proximity Sensor Dependencies
#include <Adafruit_APDS9960.h>

// DEBUG 
#define SHOULD_DEBUG 1

// NUMBER OF CHANNELS
#define NUM_CHANNELS 4

// VARIABLES FOR SELECTOR OUTPUT
#define SELECTOR_ONE 4
#define SELECTOR_TWO 5

// FIRST NOTE IN SERIES
const int NOTE_ONE = 60;

// APDS9960 Instant
Adafruit_APDS9960 apds;
int proximityThreshold = 9; // Optimize to taste

// Note On Off Variables
int colorOffset = 0;

// Sensor Index to switch between sensors
int sensorIndex = 0;
bool noteOn[NUM_CHANNELS];
int midiNotes[NUM_CHANNELS * 2]; 
int lastNote[NUM_CHANNELS];

// Variables for Color Sensing
uint16_t red, green, blue, clear_light;

void setup() {
  // Digital Pin Setup
  pinMode(SELECTOR_ONE, OUTPUT);
  pinMode(SELECTOR_TWO, OUTPUT);

  // Start Serial Output
  Serial.begin(57600);

  // Welcome Message
  if(SHOULD_DEBUG) {
    Serial.println("Adventures on the Wheels of Steel");
    Serial.println("Have fun and don't forget to make some noise!");
  }
  
  // Setup Sensors
  setupSensors();

  // Initialize Note On Off Arrays
  setupNotes();

}

void loop() {
  
  // Reset colorOffset for each loop
  colorOffset = 0;

  // Check proximity reading
  int prox = apds.readProximity();

  if ( prox > proximityThreshold ) {
    if(!noteOn[sensorIndex]) {
      
      // Object got close, start note
      noteOn[sensorIndex] = true;

      // Check color of object
      apds.getColorData(&red, &green, &blue, &clear_light);

      // If more blue than red play variation
      if (blue > red) {
        colorOffset = NUM_CHANNELS;
      }

      // Record last note played for note off
      lastNote[sensorIndex] = midiNotes[sensorIndex + colorOffset];
        
      // Send note on MIDI message
      midiEventPacket_t noteOn = {0x09, 0x90, lastNote[sensorIndex], 100};
      MidiUSB.sendMIDI(noteOn);
      MidiUSB.flush();
      
      } 
      
  } else {
    if (noteOn[sensorIndex]) {
      // Object got away, end note
      noteOn[sensorIndex] = false;

      // Send note off MIDI message
      midiEventPacket_t noteOff = {0x09, 0x80, lastNote[sensorIndex], 0};
      MidiUSB.sendMIDI(noteOff);
      MidiUSB.flush();
      
      }
    
    }
  incrementSensorIndex();
}

// Sets up the noteOn, midiNote and lastNote arrays depending on NUM_CHANNELS
void setupNotes() {
  
  if(SHOULD_DEBUG) {
    Serial.println("Initializing MIDI Channels");
  }

  for ( int i = 0; i < NUM_CHANNELS; i++) {
    noteOn[i] = false;
    midiNotes[i] = NOTE_ONE + i;
    lastNote[i] = NOTE_ONE + i;
    midiNotes[i + NUM_CHANNELS] = NOTE_ONE + i + NUM_CHANNELS;
     
    if(SHOULD_DEBUG) {
    Serial.println("Channel #" + String(i) + " Notes: " + String(midiNotes[i]) + " & " + String(midiNotes[i+NUM_CHANNELS]));
    }
    
  }
 
  return;  

}

void setupSensors() {
  
  if(SHOULD_DEBUG) {
    Serial.println("Setting up APDS9960 Sensors");
  }
  // Reset sensorIndex just in case
  resetSensorIndex();
  selectSensor(sensorIndex);
  delay(10);

  for ( int i = 0; i < NUM_CHANNELS; i++) {
  if(!apds.begin()){
      if(SHOULD_DEBUG){
        Serial.println("Failed to initialize Sensor # " + String(sensorIndex) + " !");
       }
    } else {
        Serial.println("Sensor #" + String(sensorIndex) + " initialized!");  
    }
    apds.enableProximity(true); // Enable proximity mode
    apds.enableColor(true); // Enable color mode  
    incrementSensorIndex(); // Increement sensor index to setup next sensor
  }
  
  return;
    
}

void resetSensorIndex() {
  sensorIndex = 0;
}

// Selects sensor to read using SparkFun PID 13906
// Additional code is needed to allow more than 4 sensors to work
void selectSensor(int i) {
  int modulus = i % 2;
  int division = i / 2;

  if (modulus >= 1) {
    digitalWrite(SELECTOR_ONE, HIGH);
  } else {
    digitalWrite(SELECTOR_ONE, LOW);
  }

  if (division > 0) {
    digitalWrite(SELECTOR_TWO, HIGH);
  } else {
    digitalWrite(SELECTOR_TWO, LOW);
  }  
}

void incrementSensorIndex() {
  
  // Increment Sensor Index
  sensorIndex++;

  // If sensorIndex greater than number of channels reset 
  if ( sensorIndex >= NUM_CHANNELS ) {
    resetSensorIndex();
  } 

  // Break the news to the selector chip
  selectSensor(sensorIndex);  
}

