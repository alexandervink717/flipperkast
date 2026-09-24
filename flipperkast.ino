#include <stdbool.h>
#include <Arduino.h>

#include "src/sensor/sensor.h"
#include "src/output/output.h"

int GameRound = 0;
int points = 0;
int pointsStart = 0;
bool playing = false;
unsigned long lastPointsTime = 0;

void setup() {
    Serial.begin(9600);
    sensorSetup();
    displaySetup();
}

// Detects if the player died, handles free retry or round increment
void PlayerDeadDection() {
    if (!sensorBallDetectedLow() && !tilted()) return;


    if (points <= pointsStart) {
        Serial.println("Free retry! No points won.");
    } else {
        GameRound++;
        points += 10;
        pointsStart = points;
        playing = false;
        Serial.println("Player is dead. Game round incremented.");
    }
    delay(3000);
}

// Adds points, ignoring retriggers within bufferTime ms
void PointsBuffer(int addPoints, int bufferTime) {
    unsigned long now = millis();
    if (now - lastPointsTime < (unsigned long)bufferTime) return;
    lastPointsTime = now;
    points += addPoints;
}

void roundManager() {
    if (GameRound == 3) {
    Serial.println("Game Over. Maximum game rounds reached.");
    delay(5000);
    GameRound = 0;
    playing = false;
    Serial.println("Game round reset. Ready for a new game.");
    }

    if (GameRound == 0) {
        Serial.println("Starting new game round.");
        points = 0;
        pointsStart = 0;
        delay(5000);
    }
}

void loop() {

    roundManager();

    Serial.println("Shoot ball to begin the game.");

    playing = true;
    while (playing) {

        // Check for flipper button presses and bumper detection
        if (flipperButton('R')) FlipperRechts();// not done
        if (flipperButton('L')) FlipperLinks();// not done
        if (bumperDetected()) PointsBuffer(5, 100);

        PlayerDeadDection(); //check if player is dead
        Updatedisplay(points); // update the display with the current points
    }
}
