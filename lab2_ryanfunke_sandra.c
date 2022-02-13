/* 
Author Name: Ryan Sigfrid Funke
Author Email: funker@purdue.edu
TA Name: Sandra Lee
Lab time: Friday, 11:30am
*/

#include <math.h> 
#include <stdio.h>
#ifdef M_PI
#define M_PI acos(-1.0)
#endif

int main()
{
    /* Declaration of Identifiers */
    float shallowDepth = -1.0;
    float deepDepth = -1.0;
    float poolWidth = -1.0;
    float poolLength = -1.0;
    float walkLength = -1.0;
    float shallowLength = -1.0;
    float deepLength = -1.0;
    float tubWidth = -1.0;
    float tubDepth = -1.0;
    float totalVolumePool = 0.0;
    float waterGallonsPool = 0.0;
    float totalVolumeTub = 0.0;
    float waterGallonsTub = 0.0;
    float totalCost = 0.0;

    /* These do-while loops ask the user for inputs for each dimension of the pool and hot tub, which has to be within the specified range or it will throw an error. */
    do{
        printf("Please enter the depth of the shallow end (0 - 5 feet): ");
        scanf("%f", &shallowDepth);

        if((shallowDepth < 0.0) || (shallowDepth > 5.0))
        {
            printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 0 AND 5 FEET!!\n");
        }
    }while(((shallowDepth < 0.0) || (shallowDepth > 5.0)));

    do{
        printf("Please enter the depth of the deep end (6 - 15 feet): ");
        scanf("%f", &deepDepth);

        if((deepDepth < 6.0) || (deepDepth > 15.0))
        {
            printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 6 AND 15 FEET!!\n");
        }
    }while(((deepDepth < 6.0) || (deepDepth > 15.0)));

    do{
        printf("Please enter the width of the pool (15 - 30 feet): ");
        scanf("%f", &poolWidth);

        if((poolWidth < 15.0) || (poolWidth > 30.0))
        {
            printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 15 AND 30 FEET!!\n");
        }
    }while(((poolWidth < 15.0) || (poolWidth > 30.0)));

    do{
        printf("Please enter the length of the pool (35 - 70 feet): ");
        scanf("%f", &poolLength);

        if((poolLength < 35.0) || (poolLength > 70.0))
        {
            printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 35 AND 70 FEET!!\n");
        }
    }while(((poolLength < 35.0) || (poolLength > 70.0)));

    do{
        printf("Please enter the length of the walk in (5 - %f feet): ", (poolLength / 3));
        scanf("%f", &walkLength);

        if((walkLength < 5.0) || (walkLength > (poolLength / 3)))
        {
            printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 5 - %f FEET!!\n", (poolLength / 3));
        }
    }while((walkLength < 5.0) || (walkLength > (poolLength / 3)));

    do{
        printf("Please enter the length of the shallow end (10 - %f feet): ", (poolLength / 2));
        scanf("%f", &shallowLength);

        if((shallowLength < 10.0) || (shallowLength > (poolLength / 2)))
        {
            printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 10 - %f FEET!!\n", (poolLength / 2));
        }
    }while((shallowLength < 10.0) || (shallowLength > (poolLength / 2)));

    do{
        printf("Please enter the length of the deep end (12 - %f feet): ", (poolLength / 2));
        scanf("%f", &deepLength);

        if((deepLength < 12.0) || (deepLength > (poolLength / 2)))
        {
            printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 12 - %f FEET!!\n", (poolLength / 2));
        }
    }while((deepLength < 10.0) || (deepLength > (poolLength / 2)));

    do{
        printf("Please enter the width of the hot tub (8 - 14 feet): ");
        scanf("%f", &tubWidth);

        if((tubWidth < 8.0) || (tubWidth > 14.0))
        {
            printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 8 AND 14 FEET!!\n");
        }
    }while(((tubWidth < 8.0) || (tubWidth > 14.0)));

    do{
        printf("Please enter the depth of the hot tub (3 - 5 feet): ");
        scanf("%f", &tubDepth);

        if((tubDepth < 3.0) || (tubDepth > 5.0))
        {
            printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 3 AND 5 FEET!!\n");
        }
    }while(((tubDepth < 3.0) || (tubDepth > 5.0)));

    /* Calculation for the volume of the pool and hot tub, as well as the conversion from cubic feet to gallons in terms of water used to fill the area and how much it would cost. */
    totalVolumePool = (((deepDepth * deepLength)) * poolWidth) + (((deepDepth - shallowDepth) * (poolLength - walkLength - shallowLength - deepLength) / 2) * poolWidth) + (shallowDepth * poolWidth * (poolLength - walkLength - shallowLength - deepLength)) + ((walkLength * (shallowDepth)) * poolWidth / 2) + (shallowLength * poolWidth * (shallowDepth)) - (poolLength * poolWidth * 0.5);
    totalVolumeTub = pow((tubWidth /2), 2) * M_PI * (tubDepth - 0.5);
    totalCost = ((totalVolumePool + totalVolumeTub) * 7.481) * .28;
    waterGallonsPool = totalVolumePool * 7.481;
    waterGallonsTub = totalVolumeTub * 7.481;



    /* This portion of the program outputs the values of the user input, as well as the dimensions of the pool and hot tub which were calculated afterwards. */
    printf("\nPool Dimensions (feet)\n");
    printf("Depth of the shallow end: %.1f\n", shallowDepth);
    printf("Depth of the deep end: %.1f\n", deepDepth);
    printf("Width of the pool: %.1f\n", poolWidth);
    printf("Length of the pool: %.1f\n", poolLength);
    printf("Length of the walk-in: %.1f\n", walkLength);
    printf("Length of the shallow end: %.1f\n", shallowLength);
    printf("Length of the deep end: %.1f\n", deepLength);
    printf("Width of the hot tub: %.1f\n", tubWidth);
    printf("Depth of the hot tub: %.1f\n", tubDepth);

    printf("\nPool Volume\n");
    printf("Total volume of pool: %.1f\n", totalVolumePool);
    printf("Gallons of water to fill: %.1f", waterGallonsPool);

    printf("\nHot Tub Volume\n");
    printf("Total volume of hot tub: %.1f\n", totalVolumeTub);
    printf("Gallons of water to fill: %.1f", waterGallonsTub);

    printf("\nTotal gallons for both: %.1f\n", (waterGallonsPool + waterGallonsTub));
    printf("Total cost for both: $%.2f", totalCost);
    
}