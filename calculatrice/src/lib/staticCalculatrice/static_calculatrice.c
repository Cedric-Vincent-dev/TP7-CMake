#include "static_calculatrice.h"
#include<stdio.h>


float staticAddition(float firstNumber, float secondNumber){
  return firstNumber + secondNumber;

}

float staticSubtraction(float firstNumber, float secondNumber){
  return firstNumber - secondNumber;

}

float staticMultiplication(float firstNumber, float secondNumber){
  return firstNumber * secondNumber;

}

float staticDivision(float firstNumber, float secondNumber){
  if (secondNumber == 0.0){
    puts("Invalid! Division by zero is not possible");
    return 0.0;

  }

  return firstNumber / secondNumber;
}
