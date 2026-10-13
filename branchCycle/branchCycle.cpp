/*************************************************
 * Автор: Тенц Ангелина                          *
 * Вариант: 30                                   *
 * Задание: Циклы с ветвлением                   *
 *************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() { 
  const double pi = acos(-1.0);
  double tubeLength, insideDiameter, waterDensity, kinematicViscosity;
  double reynoldsNumber, frictionCoefficient, pressureLoss, power, volumeFlow;
  double averageSpeed;
  int stepCount;

  cout << "Enter tube length: ";
  cin >> tubeLength;

  cout << "Enter inside diameter: ";
  cin >> insideDiameter;

  cout << "Enter water density: ";
  cin >> waterDensity;

  cout << "Enter kinematic viscosity: ";
  cin >> kinematicViscosity;
	
  cout << "w, m/s \t\tRe \t\tlambda \t\tdelta p, Pa \tP, W\n";

  cout << fixed << setprecision(6);

  insideDiameter = insideDiameter / 1000.0;
  stepCount = 7;

  for (int stepIndex = 0; stepIndex < stepCount; ++stepIndex) {
	switch (stepIndex) {
	  case 0:
		averageSpeed = 0.02;
		break;
	  case 1:
		averageSpeed = 0.05;
		break;
	  case 2:
		averageSpeed = 0.1;
		break;
	  case 3:
		averageSpeed = 0.2;
		break;
	  case 4:
		averageSpeed = 0.4;
		break;
	  case 5:
		averageSpeed = 0.6;
		break;
	  case 6:
		averageSpeed = 1.0;
		break;
	}

	reynoldsNumber = (averageSpeed * insideDiameter) / kinematicViscosity;

	if (reynoldsNumber < 2300.0) {
	  frictionCoefficient = 64.0 / reynoldsNumber;
	} else if (reynoldsNumber >= 4000.0) {
	  frictionCoefficient = 0.3164 / pow(reynoldsNumber, 0.25);
	}

	pressureLoss = (frictionCoefficient * tubeLength * waterDensity * pow(averageSpeed, 2.0)) / (insideDiameter * 2.0);
    volumeFlow = (pi * pow(insideDiameter, 2.0) * averageSpeed) / 4.0;
	power = pressureLoss * volumeFlow;
		
	cout << averageSpeed
		 << "\t" << reynoldsNumber
		 << "\t" << frictionCoefficient
		 << "\t" << pressureLoss
		 << "\t" << power << "\n";
  }

  return 0;
}

