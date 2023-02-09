#pragma once

const int COLORS_COUNT = 8;
const int MODELS_COUNT = 5;
const int CHARGER_OPTIONS_COUNT = 2;

struct IPhone
{
private:
  std::string colors[COLORS_COUNT] = {"black", "red", "pink", "white", "blue", "orange", "purple", "green"};
  int models[MODELS_COUNT] = {10, 11, 12, 13, 14};
  bool hasChargerOptions[CHARGER_OPTIONS_COUNT] = {true, false};

public:
  std::string color;
  int model;
  bool hasCharger;

  IPhone();
};