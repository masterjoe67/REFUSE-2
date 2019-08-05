#include "laser.h"
#include "anulu3d.h"

void setup_laserpin()
{
  #if defined(LASER_PIN) && LASER_PIN > -1
    pinMode(LASER_PIN,OUTPUT);
    analogWrite(LASER_PIN,0);
	LaserState = false;
  #endif
}

void setup_laser_enable_pin()
{
  #if defined(LASER_ENABLE) && LASER_ENABLE > -1
    pinMode(LASER_ENABLE,OUTPUT);
    WRITE(LASER_ENABLE,LOW);
	LaserEnabled = false;
  #endif
}

void setup_laser_vacum_pin()
{
  #if defined(LASER_VACUM) && LASER_VACUM > -1
    pinMode(LASER_VACUM,OUTPUT);
    analogWrite(LASER_VACUM,0);
	//LaserState = false;
  #endif
}

void setup_laser_gas_pin()
{
  #if defined(LASER_GAS) && LASER_GAS > -1
    pinMode(LASER_GAS,OUTPUT);
    WRITE(LASER_GAS,LOW);
	//LaserEnabled = false;
  #endif
}

void LaserON()
{
	LaserState = true;
	analogWrite(LASER_PIN, LaserPWR);
}

void LaserOFF() 
{
	LaserState = false;
	analogWrite(LASER_PIN, 0);
}

void LaserEnable()
{
	LaserEnabled = true;
	WRITE(LASER_ENABLE, HIGH);
}

void LaserDisable() 
{
	LaserEnabled = false;
	WRITE(LASER_ENABLE, LOW);
}

void LaserVacumEnable()
{
	LaserVacumEnabled = true;
	WRITE(LASER_VACUM, HIGH);
}

void LaserVacumDisable() 
{
	LaserVacumEnabled = false;
	WRITE(LASER_VACUM, LOW);
}

void LaserGasEnable()
{
	LaserGasEnabled = true;
	WRITE(LASER_GAS, HIGH);
}

void LaserGasDisable() 
{
	LaserGasEnabled = false;
	WRITE(LASER_GAS, LOW);
}

void LaserSetPwr(float pwr)
{
	analogWrite(LASER_PIN, (int)pwr);
}

