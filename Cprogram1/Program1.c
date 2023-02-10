#include <stdio.h>
#include "sales.h"

int main(void)
{
    char months[12][10] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    float numbers[12];

    read_file("input.txt", numbers);

    sales_report(months, numbers); 

    sales_summary(months, numbers);

    six_month_average(months, numbers);

    sorted_sales(months, numbers);

    return 0;
}
