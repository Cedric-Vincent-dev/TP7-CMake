#include "dynamic_calculatrice.h"
#include<stdio.h>

float dynamicAddition(float firstNumber, float secondNumber){
  return firstNumber + secondNumber;

}

float dynamicSubtraction(float firstNumber, float secondNumber){
  return firstNumber - secondNumber;

}

float dynamicMultiplication(float firstNumber, float secondNumber){
  return firstNumber * secondNumber;

}

float dynamicDivision(float firstNumber, float secondNumber){
  if (secondNumber == 0.0){
    puts("Invalid! Division by zero is not possible");
    return 0.0;

  }

  return firstNumber / secondNumber;
}
