#include <stdio.h>
#include <stdlib.h>

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

    for (i = 1; i <= n_data; i++) {
        //        printf("%d/%d\n", i, n_data);
        if (d[i] == i)
            continue;

        int prev = d[i];
        for (j = i + 1; j <= n_data; j++) {
            if (d[j] == i) {
                cross += j - i;
                d[j] = prev;
                break;
            } else {
                int tmp = d[j];
                d[j] = prev;
                prev = tmp;
            }
        }
    }

    printf("# of crossing point = %ld\n", cross);

    free(d);
    return 0;
}

