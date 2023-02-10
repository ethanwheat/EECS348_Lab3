#include <stdio.h>
#include <stdlib.h>

int football_scores(int points)
{

    printf("possible combinations of scoring plays:\n");

    for (int cnt_8 = 0; cnt_8 <= points/8; cnt_8++)
    {
        int total_minus_8s = points - (cnt_8*8);

        for (int cnt_7 = 0; cnt_7 <= total_minus_8s/7; cnt_7++)
        {
            int total_minus_7s = total_minus_8s - (cnt_7*7);

            for (int cnt_6 = 0; cnt_6 <= total_minus_7s/6; cnt_6++)
            {
                int total_minus_6s = total_minus_7s - (cnt_6*6);

                for (int cnt_3 = 0; cnt_3 <= total_minus_6s/3; cnt_3 ++)
                {
                    int total_minus_3s = total_minus_6s - (cnt_3*3);
                    
                    if (total_minus_3s%2 == 0)
                    {
                        int cnt_2 = total_minus_3s/2;
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",cnt_8,cnt_7,cnt_6,cnt_3,cnt_2);
                    } else { continue; }
                }
            }
        }
    }
    return 0;
}

