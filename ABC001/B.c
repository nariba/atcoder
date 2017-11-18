#include <stdio.h>

int visibility(int m) {
    int vv;
    if(m < 100) {
        vv = 0;
    }
    else if (m <= 5000) {
        vv = m*10 / 1000;
    }
    else if (m <= 30000) {
        vv = m/1000 + 50;
    }
    else if (m <= 70000) {
        vv = (m/1000-30)/5+80;
    }
    else {
        vv = 89;
    }
    return vv;
}

int main(int argc, char *argv[]) {
    int m;
    scanf("%d", &m);

    printf("%02d\n", visibility(m));

    return 0;
}
