#include <stdio.h>

void read_file(const char *filename, float *sales)
{
    FILE *input;

    input = fopen(filename, "r");
    if (input == NULL)
    {
        printf("Invalid File\n");
        return;
    }
    for (int i = 0; i < 12; i++)
    {
        if (fscanf(input, "%f", &sales[i]) != 1)
            break;
    }
    fclose(input);
}

void sales_report(char months[][10], float sales[])
{
    printf("Monthly Sales Report for 2022:\n");
    printf("%-10s%s\n", "Month", "Sales");
    for (int i=0; i < 12; i++)
    {
        printf("%-10s$%.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

void sales_summary(char months[][10], float sales[])
{
    float max = sales[0];
    float min = sales[0];
    int max_month = 0; //index of max month
    int min_month = 0; //index on min month
    float average = 0;

    for (int i = 1; i < 12; i++)
    {
        if (sales[i] > max)
        {
            max = sales[i];
            max_month = i;
        }
    }

    for (int i = 1; i < 12; i++)
    {
        if (sales[i] < min)
        {
            min = sales[i];
            min_month = i;
        }
    }

    for (int i = 0; i < 12; i++)
    {
        average += sales[i];
    }
    average /= 12;

    printf("Sales Summary:\n");
    printf("%-15s$%.2f   (%s)\n","Minimum sales:",min,months[min_month]);
    printf("%-15s$%.2f   (%s)\n","Maximum sales:",max,months[max_month]); 
    printf("%-15s$%.2f\n\n","Average sales:",average); 
}

void six_month_average(char months[][10], float sales[])
{
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++)
    {
        float average = 0;
        int j;
        for (j = i; j < i+6; j++)
        {
            average += sales[j];
        }
        average /= 6;

        printf("%-10s- %-10s$%.2f\n",months[i],months[j-1],average);
    }
    printf("\n");
}

void sorted_sales(char months[][10], float sales[])
{
    printf("Sales Report (Highest to Lowest):\n");
    printf("%-10s%s\n","Months","Sales");

    int month_indices[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
    float temp;
    int month_temp;

    for(int i = 0; i < 11; i++)
    {
        for (int j = i+1; j < 12; j++)
        {
            if (sales[i] < sales[j])
            {
                temp = sales[i];
                month_temp = month_indices[i];
                sales[i] = sales[j];
                month_indices[i] = month_indices[j];
                sales[j] = temp;
                month_indices[j] = month_temp;
            }
        }
    }
    
    for (int i = 0; i < 12; i++)
    {
        printf("%-10s$%.2f\n",months[month_indices[i]],sales[i]);
    }
}
