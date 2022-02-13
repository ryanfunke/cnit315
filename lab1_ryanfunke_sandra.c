/* 
Author Name: Ryan Sigfrid Funke
Author Email: funker@purdue.edu
TA Name: Sandra Lee
Lab time: Friday, 11:30am
*/

#include <math.h> 
#include <stdio.h>

int main()
{
    /*
        Max Container size = 40x8x8 ft^3
        Type 1 = 1x1x1 ft^3
        Type 2 = 1x2x2 ft^3
    */

    /* Declaration of Identifiers */
    float containerSpaceVolume = 2560.0;
    float shipCostTypeOne = 20.0;
    float shipCostTypeTwo = 35.0;
    int typeOneQuan = 0;
    int typeTwoQuan = 0;
    float shippingCost = 0.0;
    float finalShippingCost = 0.0;
    float discount = 0.0;

    /* Pseudo-Code 
    Calculate and display reamining number of cubic feet available in shipping container

    Ask user for number of type 1 boxes
        Calculate remaining space for type 2 boxes
        Calculate max number of type 2 boxes that can be stored after  
    Ask user for number of type 2 boxes
    
    Calculate remaining space in container
        Calculate shipping cost before discount
        Calculate total cubic footage of boxes that want to be shipped
        Calculate final shipping cost with discount
    */

    /* Asking for user input for the amount of type 1 boxes, uses a do loop to ensure valid input and within valid bounds*/
    printf("Remaining container space: %.2f ft^3\n", containerSpaceVolume);
    do{
    printf("How many Type 1 boxes would you like to ship?: ");
    scanf("%d", &typeOneQuan);
    
    if(typeOneQuan < 0)
    {
        printf("ERROR: Please input a valid number of Type 1 boxes to ship.\n");
    }
    else if(typeOneQuan > 2560)
    {
        printf("ERROR: Please input a new number of Type 1 boxes to ship, the quantity was too large.\n");
    }
    }while((typeOneQuan < 0 || typeOneQuan > 2560));
    
    /* Prints the remaining container space after the user inputs their Type 1 box quantity, after computing the difference with a simple calculation*/
    containerSpaceVolume = containerSpaceVolume - typeOneQuan;
    printf("Remaining container space: %.2f ft^3\n", containerSpaceVolume);

    /* Calculates the maximum number of type 2 boxes that can be stored, using an explicit type cast to ensure whole boxes are being used and not fractions of one*/
    int maxBoxes = ((int)containerSpaceVolume / 4);
    printf("Max number of Type 2 boxes that can be stored: %d\n", maxBoxes);

    /* Asking for user input for the amount of type 2 boxes, uses a do loop to ensure valid input and within valid bounds*/
    do{
    printf("How many Type 2 boxes would you like to ship?: ");
    scanf("%d", &typeTwoQuan);
    
    if(typeTwoQuan < 0)
    {
        printf("ERROR: Please input a valid number of Type 2 boxes to ship.\n");
    }
    else if(typeTwoQuan > maxBoxes)
    {
        printf("ERROR: Please input a new number of Type 2 boxes to ship, the quantity was too large.\n");
    }
    }while((typeTwoQuan < 0) || (typeTwoQuan > maxBoxes));

    /* Updates the container space and then prints the remaining space to the user */
    containerSpaceVolume = containerSpaceVolume - (typeTwoQuan * 4.0);
    printf("Total footage of boxes to be shipped: %.2f ft^3\n", (2560 - containerSpaceVolume));

    printf("Remaining container space: %.2f ft^3\n", containerSpaceVolume);
    /* Calculates the discount for unused space after user inputs their box selections */
    discount = (2.0 * containerSpaceVolume);
    /* Calculates the shipping cost BEFORE the discount is applied, and then shows the user the discount for unused space and the initial shipping cost */
    shippingCost = (typeOneQuan * shipCostTypeOne) + (typeTwoQuan * shipCostTypeTwo);
    printf("The initial shipping cost is: $%.2f\n", shippingCost);
    printf("The discount for unused space in the container is: $%.2f\n", discount);
    /* Calculates the final shipping cost by now including the discount, then prints the final cost to the user */
    finalShippingCost = shippingCost - discount;
    printf("The total shipping cost is: $%.2f\n", finalShippingCost);

    /* Outputs status message to let user know the program is terminating */
    printf("Program has ended...");
    return 0;
}
