#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double wind_dis_convert(int dis) {
    double ret;
    ret = round(dis / 6.0);
    ret = ret / 10;
    return ret;
}

double wind_deg_convert(int deg) {
    return deg/10.0;
}

int wind_deg(double deg, int w, char *ret) {
    if (w == 0) {
        strcpy(ret, "C");
    }
    else if (11.25 <= deg && deg < 33.75) {
        strcpy(ret, "NNE");
    }
    else if (33.75 <= deg && deg < 56.25) {
        strcpy(ret, "NE");
    }
    else if (56.25 <= deg && deg < 78.75) {
        strcpy(ret, "ENE");
    }
    else if (78.75 <= deg && deg < 101.25) {
        strcpy(ret, "E");
    }
    else if (101.25 <= deg && deg < 123.75) {
        strcpy(ret, "ESE");
    }
    else if (123.75 <= deg && deg < 146.25) {
        strcpy(ret, "SE");
    }
    else if (146.25 <= deg && deg < 168.75) {
        strcpy(ret, "SSE");
    }
    else if (168.75 <= deg && deg < 191.25) {
        strcpy(ret, "S");
    }
    else if (191.25 <= deg && deg < 213.75) {
        strcpy(ret, "SSW");
    }
    else if (213.75 <= deg && deg < 236.25) {
        strcpy(ret, "SW");
    }
    else if (236.25 <= deg && deg < 258.75) {
        strcpy(ret, "WSW");
    }
    else if (258.75 <= deg && deg < 281.25) {
        strcpy(ret, "W");
    }
    else if (281.25 <= deg && deg < 303.75) {
        strcpy(ret, "WNW");
    }
    else if (303.75 <= deg && deg < 326.25) {
        strcpy(ret, "NW");
    }
    else if (326.25 <= deg && deg < 348.75) {
        strcpy(ret, "NNW");
    }
    else {
        strcpy(ret, "N");
    }


    return 0;
}

int wind_dis(double dis) {
    int w;
    if (dis <= 0.2) {
        w = 0;
    }
    else if (dis <= 1.5) {
        w = 1;
    }
    else if (dis <= 3.3) {
        w = 2;
    }
    else if (dis <= 5.4) {
        w = 3;
    }
    else if (dis <= 7.9) {
        w = 4;
    }
    else if (dis <= 10.7) {
        w = 5;
    }
    else if (dis <= 13.8) {
        w = 6;
    }
    else if (dis <= 17.1) {
        w = 7;
    }
    else if (dis <= 20.7) {
        w = 8;
    }
    else if (dis <= 24.4) {
        w = 9;
    }
    else if (dis <= 28.4) {
        w = 10;
    }
    else if (dis <= 32.6) {
        w = 11;
    }
    else {
        w = 12;
    }

    return w;
}


int main() {
    int deg, dis;
    scanf("%d %d", &deg, &dis);
    int w = wind_dis(wind_dis_convert(dis));
    char dir[3];
    wind_deg(wind_deg_convert(deg), w, dir);
    printf("%s %d\n", dir, w);
    return 0;
}
