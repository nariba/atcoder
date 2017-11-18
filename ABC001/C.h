#ifndef _TARGET_H_
#define _TARGET_H_

double wind_dis_convert(int deg);
double wind_deg_convert(double deg, int w);

int wind_deg(double deg, int w, char *ret);
int wind_dis(double dis);

#endif /* _TARGET_H_ */
