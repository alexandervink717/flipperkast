#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool Updatedisplay(int points); // Update the display with the current points
void FlipperRechts(); // Move the right flipper
void flipperLinks(); // Move the left flipper

#ifdef __cplusplus
}
#endif

#endif
