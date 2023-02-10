#ifndef _SALES_H_
#define _SALES_H_

void read_file(const char *filename, float *sales);
void sales_report(char months[][10], float sales[]);
void sales_summary(char months[][10], float sales[]);
void six_month_average(char months[][10], float sales[]);
void sorted_sales(char months[][10], float sales[]);

#endif
