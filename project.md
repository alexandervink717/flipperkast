# Flipperkast

Arduino-project voor een flipperkast. De code is opgedeeld in drie categorieën:
game logic, sensor en output.

## Structuur

```
flipperkast.ino      <- game logic
src/config.h         <- instellingen (drempelwaardes)
src/sensor/          <- alles wat binnenkomt (input)
src/output/          <- alles wat naar buiten gaat (output)
```

## Status

| Teken | Betekenis |
|---|---|
| `+` | klaar |
| `-` | bezig |
| `x` | niet begonnen |

## 1. Game logic — `flipperkast.ino`

Hier staan de spelregels. Deze laag weet niets van pinnen of hardware, hij
roept alleen functies uit sensor en output aan.

Variabelen:

| Variabele | Betekenis |
|---|---|
| `GameRound` | huidige ronde (spel stopt na 3) |
| `points` | score van de speler |
| `pointsStart` | score bij het begin van de beurt |
| `playing` | is er nu een bal in het spel |

Functies:

| St. | Functie | Doet |
|---|---|---|
| `+` | `setup()` | start de seriële monitor, de sensoren en het display |
| `+` | `loop()` | hoofdlus: leest de flipperknoppen, telt bumperpunten op, controleert of de speler af is en werkt het display bij |
| `+` | `roundManager()` | reset het spel na ronde 3 en start een nieuwe game bij ronde 0 |
| `+` | `PlayerDeadDection()` | bal is onderaan of de kast is getilt. Zonder punten gewonnen krijgt de speler een gratis nieuwe bal, anders gaat de ronde omhoog |
| `+` | `PointsBuffer(addPoints, bufferTime)` | telt punten op, maar negeert hertriggers binnen `bufferTime` ms zodat één bumperhit niet dubbel telt |

## 2. Sensor — `src/sensor/`

Alles wat het spel *waarneemt*. Interface staat in `sensor.h`, implementatie in
`sensor.cpp`.

| St. | Functie | Doet |
|---|---|---|
| `-` | `sensorSetup()` | start de I2C-bus en wekt de MPU-6050 (tilt-sensor) — pinnen voor bal/bumper/knoppen nog niet |
| `+` | `tilted()` | leest de accelerometer, som van X+Y boven `DemplePuntForTilt` = tilt |
| `x` | `sensorBallDetectedLow()` | bal onderaan / bal kwijt |
| `x` | `bumperDetected()` | bal raakt een bumper |
| `x` | `flipperButton(char LorR)` | linker- of rechterknop ingedrukt |

De tilt-drempel staat in `src/config.h` (`DemplePuntForTilt`).

## 3. Output — `src/output/`

Alles wat het spel *doet*. Interface in `output.h`.

| St. | Functie | Doet |
|---|---|---|
| `x` | `Updatedisplay(points)` | zet de score op het display |
| `x` | `FlipperRechts()` | beweegt de rechterflipper |
| `x` | `FlipperLinks()` | beweegt de linkerflipper |
| `x` | `displaySetup()` / `displayShow()` (`display.c`) | aansturing van het display zelf |

## Notes

Cables te kort