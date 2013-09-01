#include <stdio.h>
#include <stdlib.h>


void sort(int *d, int *e, long *cross, int start, int end)
{
    int center = (start + end) / 2;
    int i;
    int n_d = 0;
    int n_e = 0;
    /*
    printf("%d-%d center=%d\n",start,end,center);
    for (i = 0; i <= 9; i++) {
        printf("%d ", d[i]);
    }
    printf("\n ");
    getchar();
    */

    if (start == end)
        return;

    for (i = start; i <= end; i++) {
        if (d[i] <= center) {
            d[start + n_d] = d[i];
            n_d++;
            *cross += n_e;
        } else {
            e[n_e++] = d[i];
        }
    }

    for (i = 0; i < n_e; i++) {
        d[start + n_d + i] = e[i];
    }

    sort(d, e, cross, start, center);
    sort(d, e, cross, center + 1, end);
}


int main(int argc, char *argv[])
{
    FILE *fp;
    int c;
    int n_data = 0;
    fp  = fopen(argv[1], "r");
    while ((c = getc(fp)) != EOF) {
        //        printf("%c",(char)c);
        if (c == '\n')
            n_data++;
    }
    fclose(fp);

    int *d;
    long cross = 0;
    int i, j;
    d = (int *)malloc((n_data + 1) * sizeof(int));
    fp  = fopen(argv[1], "r");
    for (i = 1; i <= n_data; i++) {
        fscanf(fp, "%d", &d[i]);
    }
    fclose(fp);

    int *e;
    //    e = (int *)malloc((n_data + 1) / 2 * sizeof(int));
    e = (int *)malloc(n_data * sizeof(int));

    sort(d, e, &cross, 1, n_data);

    printf("# of crossing point = %ld\n", cross);

    free(d);
    free(e);
    return 0;
}

