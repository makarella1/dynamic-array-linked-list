#include "iphone.h"

#include <iostream>

IPhone::IPhone()
{
  color = colors[rand() % COLORS_COUNT];
  model = models[rand() % MODELS_COUNT];
  hasCharger = hasChargerOptions[rand() % CHARGER_OPTIONS_COUNT];
}