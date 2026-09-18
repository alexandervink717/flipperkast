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
    sensorSetup();
    Serial.begin(9600);
}

// Detects if the player died, handles free retry or round increment
void PlayerDeadDection() {
    if (!sensorBallDetectedLow() || !tilted()) return;

    if (points <= pointsStart) {
        Serial.println("Free retry!");
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

void loop() {
    if (GameRound == 3) {
        Serial.println("Game Over. Maximum game rounds reached.");
        delay(5000);
        GameRound = 0;
        playing = false;
        Serial.println("Game round reset. Ready for a new game.");
        return;
    }

    Serial.println("Shoot ball to begin the game.");
    while (playing) {
        if (flipperButtonRechts()) FlipperRechts();
        if (flipperButtonLinks()) flipperLinks();

        if (bumperDetected()) {
            PointsBuffer(100, 100);
        }

        PlayerDeadDection();
        Updatedisplay(points);
    }
}
