**Studentnummer:** 1153786
**Datum:** 28-09-2026

# Onderzoeksverslag: sensorkeuze voor detectie van de speelbal

## Inleiding
Voor de flipperkast die in dit project wordt gebouwd, moet de kast kunnen herkennen
wanneer de metalen speelbal langskomt, bijvoorbeeld om punten toe te kennen of te
bepalen dat de bal kwijt is. Er is nog geen sensor voor gekozen, dus is onderzocht welke
sensor hiervoor het meest geschikt is.

Twee sensoren uit de kit zijn vergeleken: een infrarood-reflectiesensor (bereik 2-30 cm)
en een ultrasone afstandssensor HC-SR04 (2-500 cm). Beide zijn getoetst aan drie eisen:
de bal moet gedetecteerd kunnen worden, dit moet binnen 200 ms gebeuren en dit moet
minstens 99 van de 100 keer lukken. Doel is een onderbouwde keuze voor de beste sensor.

## Onderzoek

### Kan de sensor de bal detecteren?
De HC-SR04 meet afstand met geluid dat terugkaatst. Volgens de fabrikant werkt dit alleen
goed bij een vlak oppervlak van minstens 0,5 m² [1]. De speelbal is klein en rond, en
kaatst geluid daardoor in veel richtingen weg in plaats van terug naar de sensor. De
HC-SR04 is dus niet goed geschikt voor zo'n klein object.

De IR-sensor werkt met een lampje en een lichtsensor die kijkt of er licht terugkomt [2].
De datasheet stelt geen eis aan het oppervlak. Metaal reflecteert licht bovendien goed,
wat in het voordeel van deze sensor werkt. Op basis hiervan lijkt de IR-sensor beter
geschikt voor een klein metalen object dan de HC-SR04.

### Is de sensor snel genoeg (<200 ms)?
Voor de HC-SR04 wordt geadviseerd om metingen minstens 60 ms uit elkaar te laten
plaatsvinden [1]. Dat past nog wel binnen 200 ms, maar geeft weinig ruimte om de bal
meerdere keren te meten tijdens een snelle passage.

De IR-sensor reageert in minder dan 2 ms [3], veel sneller dan nodig. Hierdoor kan de
sensor de bal meerdere keren meten tijdens één passage, wat een gemiste detectie
onwaarschijnlijker maakt.

### Wordt de bal minstens 99 van de 100 keer gedetecteerd?
Dit volgt uit de vorige twee punten. Omdat de HC-SR04 een groot vlak oppervlak nodig
heeft en de bal dat niet biedt, is de kans groot dat metingen mislukken. Een score van
99/100 lijkt daarom niet haalbaar.

De IR-sensor combineert een goed reflecterend doel (metaal) met een zeer snelle reactie,
waardoor er meerdere kansen per passage zijn om de bal te detecteren. Wel is de
gevoeligheid instelbaar met een schroefje, dus de uiteindelijke betrouwbaarheid moet nog
in de praktijk getest en afgesteld worden.

## Conclusie
Uit de vergelijking blijkt dat de HC-SR04 niet goed werkt voor een klein, rond object
zoals de speelbal, omdat de sensor een groot vlak oppervlak nodig heeft. De
IR-reflectiesensor heeft die beperking niet, profiteert van de goede reflectie van
metaal en is ruim snel genoeg. Daarom is gekozen voor de IR-reflectiesensor om de
speelbal te detecteren. De uiteindelijke betrouwbaarheid moet nog in de praktijk
getest worden.

## Bronvermelding
[1] Elecfreaks, "Ultrasonic Ranging Module HC-SR04," datasheet. [Online]. Beschikbaar:
https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf. [Geraadpleegd:
28-sep-2026].

[2] SunFounder, "IR Obstacle Avoidance Sensor Module," productspecificatie. [Online].
Beschikbaar: https://www.sunfounder.com/products/ir-obstacle-avoidance-sensor-module.
[Geraadpleegd: 28-sep-2026].

[3] ElectroDragon, "Infrared(IR) Reflective Obstacle Avoidance Module, ADJ 2~30CM,"
productpagina. [Online]. Beschikbaar:
https://www.electrodragon.com/product/infraredir-obstacle-avoidance-sensor-moduleadjust-distance/.
[Geraadpleegd: 28-sep-2026].
