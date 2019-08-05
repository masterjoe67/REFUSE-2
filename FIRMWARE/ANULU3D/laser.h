#ifndef laser_h
#define laser_h

extern bool LaserState;
extern int LaserPWR; 

extern bool LaserEnabled;
extern bool LaserVacumEnabled;
extern bool LaserGasEnabled;

void setup_laserpin();
void setup_laser_enable_pin();
void setup_laser_vacum_pin();
void setup_laser_gas_pin();
void LaserON();
void LaserOFF();
void LaserSetPwr(float pwr);
void LaserEnable();
void LaserDisable();
void LaserVacumEnable();
void LaserVacumDisable();
void LaserGasEnable();
void LaserGasDisable();

#endif
