#include<stdio.h>
#include "static_calculatrice.h"
#include "dynamic_calculatrice.h"



int main(){

  float firstNumber, secondNumber;
  int userChoice;


  //Welcome message to user
  puts("=== CALCULATOR CENTER ===");
  puts("Enter the first number:");
  scanf("%f",&firstNumber);

  puts("Enter the sezcond number:");
  scanf("%f",&secondNumber);

  puts("Choose your operation:");
  puts("1. Addition");
  puts("2. Subtraction");
  puts("3. Multiplication");
  puts("4. Division");
  scanf("%i",&userChoice);

  switch(userChoice){
  case 1:
    printf("Static: %.2f + %.2f = %.2f\n", firstNumber, secondNumber, staticAddition(firstNumber, secondNumber));
    printf("Dynamic: %.2f + %.2f = %.2f\n", firstNumber, secondNumber, dynamicAddition(firstNumber, secondNumber));
    break;

  case 2:
    printf("Static: %.2f - %.2f = %.2f\n", firstNumber, secondNumber, staticSubtraction(firstNumber, secondNumber));
    printf("Dynamic: %.2f - %.2f = %.2f\n", firstNumber, secondNumber, dynamicSubtraction(firstNumber, secondNumber));
    break;

  case 3:
    printf("Static: %.2f x %.2f = %.2f\n", firstNumber, secondNumber, staticMultiplication(firstNumber, secondNumber));
    printf("Dynamic: %.2f x %.2f = %.2f\n", firstNumber, secondNumber, dynamicMultiplication(firstNumber, secondNumber));
    break;

  case 4:
    printf("Static: %.2f / %.2f = %.2f\n", firstNumber, secondNumber, staticDivision(firstNumber, secondNumber));
    printf("Dynamic: %.2f / %.2f = %.2f\n", firstNumber, secondNumber, dynamicDivision(firstNumber, secondNumber));
    break;

  default:
    puts("Invalid choice !");

  }

  return 0;

}
