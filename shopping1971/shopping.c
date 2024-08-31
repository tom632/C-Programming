#include <stdio.h>

//Function to calculate the total of the value of goods.
int calculateTotal(int item1, int item2, int item3) {
    return item1 + item2 + item3;
}

/*
This programme will calculate the value of change in Pounds, shillings and pennies
*/
int main() {
    //This is the conversion rate
    /*
        1 pound = 20 shillings 
        1 shillings =  12 pennies
    */

    //Set the constants for the money values.
    const int POUNDS = 1;
    const int SHILLINGS = 20;
    const int PENNIES = 12;

    //Vaiables to be use on conversion
    int candy, bonbons, lollies, cashGiven, changeInPounds, totalOfGoods;
    float total, totalChange, total3, total4, changeInShillings, changeInPennies;

    //Ask the user for the values and store them.
    printf("Candy is £");
    scanf("%d", &candy);
    printf("BonBons are £");
    scanf("%d", &bonbons);
    printf("Lollys are £");
    scanf("%d", &lollies);

    //Calculate the values that have been entered
    totalOfGoods = calculateTotal(candy, bonbons, lollies);

    //The total value of the goods.
    printf("Total is %d\n", totalOfGoods);

    //The amount of cash the user has given.
    printf("Casht Given is ");
    scanf("%d", &cashGiven);

    //This works out the amount of change needed.
    totalChange = cashGiven - totalOfGoods;

    //Change in pounds.
    changeInPounds = totalChange * POUNDS;

    //Change in shillings.
    changeInShillings = totalChange * SHILLINGS;

    //Change in pennies.
    changeInPennies = changeInPounds * SHILLINGS * PENNIES;

    //Print out the total change and the different values
    printf("Your change is %d pounds or %.0f shillings or %.0f pennies\n", changeInPounds, changeInShillings, changeInPennies);

    return 0;
}