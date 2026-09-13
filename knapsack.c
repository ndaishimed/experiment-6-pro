#include <stdio.h>
struct Item{
    float weight;
    float profit;
    float ratio;
};

int main(){
    struct Item item[100], temp;
    int n, i, j;
    float capacity, totalProfit = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weight and profit of each item:\n");
    for (i = 0; i < n; i++){
        scanf("%f %f", &item[i].weight, &item[i].profit);
        item[i].ratio = item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);
    for (i = 0; i < n - 1; i++)
{
        for (j = i + 1; j < n; j++){
            if (item[i].ratio < item[j].ratio){
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++){
        if (capacity >= item[i].weight){
            capacity -= item[i].weight;
            totalProfit += item[i].profit;
        }
        else{
            totalProfit += item[i].ratio * capacity;
            break;
        }
    }
    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}
