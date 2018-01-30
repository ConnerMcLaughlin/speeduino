#ifndef STORAGE_H
#define STORAGE_H

void writeAllConfig();
void writeConfig();
void loadConfig();
void loadCalibration();
void writeCalibration();

#define EEPROM_MAX_WRITE_BLOCK 30 //The maximum number of write operations that will be performed in one go. If we try to write to the EEPROM too fast (Each write takes ~3ms) then the rest of the system can hang)
bool eepromWritesPending = false;

/*
Current layout of EEPROM data (Version 3) is as follows (All sizes are in bytes):
|---------------------------------------------------|
|Byte # |Size | Description                         |
|---------------------------------------------------|
| 0     |1    | Data structure version              |
| 1     |2    | X and Y sizes for VE table          |
| 3     |256  | VE Map (16x16)                      |
| 259   |16   | VE Table RPM bins                   |
| 275   |16   | VE Table MAP/TPS bins               |
| 291   |128   | Page 2 settings (Non-Map page)      |
| 419   |2    | X and Y sizes for Ign table         |
| 421   |256  | Ignition Map (16x16)                |
| 677   |16   | Ign Table RPM bins                  |
| 693   |16   | Ign Table MAP/TPS bins              |
| 709   |128   | Page 4 settings (Non-Map page)      |
| 837   |2    | X and Y sizes for AFR table         |
| 839   |256  | AFR Target Map (16x16)              |
| 1093   2       spare
| 1095   |16   | AFR Table RPM bins                  |
| 1111   |16   | AFR Table MAP/TPS bins              |
| 1127   |64   | Remaining Page 3 settings           |
| 1191  |64   | Page 4 settings                     |
| 1127  |2    | X and Y sizes for boost table       |
| 1287  |160  | PAGE 6 Settings                      Boost Map (8x8)   
| 1355  |     | X and Y sizes (page 7 map 1)        |
| 1357  |     | PAGE 7 Map1                         |
| 1421  |     | X and Y BINS                        | 
| 1437  |     | X and Y sizes (page 7 map 2)        |
| 1439  |     | PAGE 7 Map2                         | 
| 1503  |     | 
| 1511  |     |
| 1519  |     |
| 1521  |     |
| 1585  |     |
| 1593  |     |
| 1601  |     | X and Y sizes (page8 map1)          |
| 1603  |     | PAGE 8 MAP1
| 1639  |
| 1645  |
| 1651  |2    | X and Y sizes                       |
| 1653  |64   | PAGE 8 MAP2                         |
| 1275  |8    | Xbins Map2                          |
| 1283  |8    | Ybins Map2                          |
| 1291  |2    | X and Y sizes1                      |
| 1293``|36   | PAGE 9 MAP1                         |
| 1329  |12   | X and Y Bins1                       |
| 1341  |2    | X and Y size2                       |
| 1343  |36   | PAGE 9 MAP2                         |
| 1379  |6    | X and Y Bins2                       |
| 1391  |2    | X and Y sizes3                      |
| 1393  |36   | PAGE 9 MAP3                         |
| 1429  |6    | X and Y Bins3                       |
| 1441  |2    | X and Y size4                       |
| 1443  |36   | PAGE 9 MAP4                         |
| 1479  |6    | X and Y Bins4                       |
| 1500  |128  | CANBUS config and data (Table 10_)  |NOTE:!!! last 16 bytes are NOT saved to eeprom only kept in ram!!
| 1628  |192  | Table 11 - General settings         |
|                                                   |
| 2559  |512  | Calibration data (O2)               |
| 3071  |512  | Calibration data (IAT)              |
| 3583  |512  | Calibration data (CLT)              |
-----------------------------------------------------
*/

#define EEPROM_DATA_VERSION   0

#define EEPROM_CONFIG1_XSIZE  1
#define EEPROM_CONFIG1_YSIZE  2
#define EEPROM_CONFIG1_MAP    3
#define EEPROM_CONFIG1_XBINS  259
#define EEPROM_CONFIG1_YBINS  275
#define EEPROM_CONFIG2_START  291
#define EEPROM_CONFIG2_END    419 // (+128
#define EEPROM_CONFIG3_XSIZE  419 // (+0
#define EEPROM_CONFIG3_YSIZE  420 // (+1
#define EEPROM_CONFIG3_MAP    421 // (+1
#define EEPROM_CONFIG3_XBINS  677 // (+256
#define EEPROM_CONFIG3_YBINS  693 // (+16
#define EEPROM_CONFIG4_START  709 // (+16
#define EEPROM_CONFIG4_END    837 // (+128
#define EEPROM_CONFIG5_XSIZE  837 
#define EEPROM_CONFIG5_YSIZE  838
#define EEPROM_CONFIG5_MAP    839
#define EEPROM_CONFIG5_XBINS  1095
#define EEPROM_CONFIG5_YBINS  1111
#define EEPROM_CONFIG6_START  1127
#define EEPROM_CONFIG6_END    1287  //1254
#define EEPROM_CONFIG7_XSIZE1 1355 //1255
#define EEPROM_CONFIG7_YSIZE1 1356 //1256
#define EEPROM_CONFIG7_MAP1   1357 //1257
#define EEPROM_CONFIG7_XBINS1 1421 //1321 (+64)
#define EEPROM_CONFIG7_YBINS1 1429 //1329 (+8)
#define EEPROM_CONFIG7_XSIZE2 1437//1337 (+8
#define EEPROM_CONFIG7_YSIZE2 1438//1338 (+1
#define EEPROM_CONFIG7_MAP2   1439//1339 (+1
#define EEPROM_CONFIG7_XBINS2 1503//1403 (+64
#define EEPROM_CONFIG7_YBINS2 1511//1411 (+8

#define EEPROM_CONFIG7_XSIZE3 1519//1419 (+8
#define EEPROM_CONFIG7_YSIZE3 1520//1420 (+1
#define EEPROM_CONFIG7_MAP3   1521//1421 (+1

#define EEPROM_CONFIG7_XBINS3 1585//1485 (+64
#define EEPROM_CONFIG7_YBINS3 1593//1493  (+8
#define EEPROM_CONFIG7_END    1601//1501  (8
#define EEPROM_CONFIG8_XSIZE1 1601//1501  (0
#define EEPROM_CONFIG8_YSIZE1 1602//1502 (1
#define EEPROM_CONFIG8_MAP1   1603//1503 (1
#define EEPROM_CONFIG8_XBINS1 1639//1539 (+36
#define EEPROM_CONFIG8_YBINS1 1645//1545 (6
#define EEPROM_CONFIG8_XSIZE2 1651//1551 (6
#define EEPROM_CONFIG8_YSIZE2 1652//1552 (1
#define EEPROM_CONFIG8_MAP2   1653//1553 (1
#define EEPROM_CONFIG8_XBINS2 1689//1589 (36
#define EEPROM_CONFIG8_YBINS2 1695//1595 (6
#define EEPROM_CONFIG8_XSIZE3 1701//1601 (6
#define EEPROM_CONFIG8_YSIZE3 1702//1602 (1
#define EEPROM_CONFIG8_MAP3   1703//1603 (1 
#define EEPROM_CONFIG8_XBINS3 1739//1639 (36
#define EEPROM_CONFIG8_YBINS3 1745//1645 (6
#define EEPROM_CONFIG8_XSIZE4 1751//1651 (6
#define EEPROM_CONFIG8_YSIZE4 1752//1652 (1
#define EEPROM_CONFIG8_MAP4   1753//1653 (1
#define EEPROM_CONFIG8_XBINS4 1789//1689
#define EEPROM_CONFIG8_YBINS4 1796//1695
#define EEPROM_CONFIG9_START 1810//1710
#define EEPROM_CONFIG9_END   1938//1838
#define EEPROM_CONFIG10_START 1938//1838
#define EEPROM_CONFIG10_END   2130//2030

//Calibration data is stored at the end of the EEPROM (This is in case any further calibration tables are needed as they are large blocks)
#define EEPROM_LAST_BARO      2558
#define EEPROM_CALIBRATION_O2 2559
#define EEPROM_CALIBRATION_IAT 3071
#define EEPROM_CALIBRATION_CLT 3583

#endif // STORAGE_H
