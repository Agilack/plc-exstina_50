EESchema Schematic File Version 2
LIBS:exstina_50-r01
LIBS:exstina_50-r01-cache
EELAYER 24 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 6
Title "Exstina-50"
Date "17 Jul 2015"
Rev "0.1"
Comp "Agilack"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L AQHX213 OC201
U 1 1 559BB43A
P 6500 1350
F 0 "OC201" H 6500 1850 60  0000 C CNN
F 1 "AQHX213" H 6500 850 60  0000 C CNN
F 2 "" H 6650 1350 60  0000 C CNN
F 3 "" H 6650 1350 60  0000 C CNN
F 4 "Panasonic" H 6500 1350 60  0001 C CNN "Manufacturer"
F 5 "AQH3213J" H 6500 1350 60  0001 C CNN "Manuf Ref"
	1    6500 1350
	1    0    0    -1  
$EndComp
$Comp
L AQHX213 OC202
U 1 1 559BB449
P 6500 2750
F 0 "OC202" H 6500 3250 60  0000 C CNN
F 1 "AQHX213" H 6500 2300 60  0000 C CNN
F 2 "" H 6650 2750 60  0000 C CNN
F 3 "" H 6650 2750 60  0000 C CNN
F 4 "Panasonic" H 6500 2750 60  0001 C CNN "Manufacturer"
F 5 "AQH3213J" H 6500 2750 60  0001 C CNN "Manuf Ref"
	1    6500 2750
	1    0    0    -1  
$EndComp
$Comp
L AQHX213 OC203
U 1 1 559BB458
P 6500 4150
F 0 "OC203" H 6500 4650 60  0000 C CNN
F 1 "AQHX213" H 6500 3700 60  0000 C CNN
F 2 "" H 6650 4150 60  0000 C CNN
F 3 "" H 6650 4150 60  0000 C CNN
F 4 "Panasonic" H 6500 4150 60  0001 C CNN "Manufacturer"
F 5 "AQH3213J" H 6500 4150 60  0001 C CNN "Manuf Ref"
	1    6500 4150
	1    0    0    -1  
$EndComp
$Comp
L AQHX213 OC204
U 1 1 559BB467
P 6500 5550
F 0 "OC204" H 6500 6050 60  0000 C CNN
F 1 "AQHX213" H 6500 5100 60  0000 C CNN
F 2 "" H 6650 5550 60  0000 C CNN
F 3 "" H 6650 5550 60  0000 C CNN
F 4 "Panasonic" H 6500 5550 60  0001 C CNN "Manufacturer"
F 5 "AQH3213J" H 6500 5550 60  0001 C CNN "Manuf Ref"
	1    6500 5550
	1    0    0    -1  
$EndComp
Text GLabel 7350 1400 2    60   Output ~ 0
OUT1-1
Wire Wire Line
	7350 1050 7150 1050
Wire Wire Line
	7350 1400 7150 1400
NoConn ~ 7150 1650
Text GLabel 7350 1050 2    60   Output ~ 0
OUT1-2
NoConn ~ 7150 3050
NoConn ~ 7150 4450
NoConn ~ 7150 5850
$Comp
L R R201
U 1 1 559BB796
P 5500 1100
F 0 "R201" V 5600 1100 50  0000 C CNN
F 1 "165" V 5500 1100 45  0000 C CNN
F 2 "" H 5500 1100 60  0000 C CNN
F 3 "" H 5500 1100 60  0000 C CNN
	1    5500 1100
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR01
U 1 1 559BB7A5
P 5150 1000
F 0 "#PWR01" H 5150 960 30  0001 C CNN
F 1 "+3.3V" H 5150 1110 30  0000 C CNN
F 2 "" H 5150 1000 60  0000 C CNN
F 3 "" H 5150 1000 60  0000 C CNN
	1    5150 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 1000 5150 1100
Wire Wire Line
	5150 1100 5250 1100
Wire Wire Line
	5750 1100 5850 1100
Wire Wire Line
	5750 2500 5850 2500
$Comp
L R R203
U 1 1 559BB7C2
P 5500 2500
F 0 "R203" V 5600 2500 50  0000 C CNN
F 1 "165" V 5500 2500 45  0000 C CNN
F 2 "" H 5500 2500 60  0000 C CNN
F 3 "" H 5500 2500 60  0000 C CNN
	1    5500 2500
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR02
U 1 1 559BB7DB
P 5150 2400
F 0 "#PWR02" H 5150 2360 30  0001 C CNN
F 1 "+3.3V" H 5150 2510 30  0000 C CNN
F 2 "" H 5150 2400 60  0000 C CNN
F 3 "" H 5150 2400 60  0000 C CNN
	1    5150 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 2400 5150 2500
Wire Wire Line
	5150 2500 5250 2500
$Comp
L R R205
U 1 1 559BB7F1
P 5500 3900
F 0 "R205" V 5600 3900 50  0000 C CNN
F 1 "165" V 5500 3900 45  0000 C CNN
F 2 "" H 5500 3900 60  0000 C CNN
F 3 "" H 5500 3900 60  0000 C CNN
	1    5500 3900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 3900 5850 3900
Wire Wire Line
	5150 3800 5150 3900
Wire Wire Line
	5150 3900 5250 3900
$Comp
L +3.3V #PWR03
U 1 1 559BB81D
P 5150 3800
F 0 "#PWR03" H 5150 3760 30  0001 C CNN
F 1 "+3.3V" H 5150 3910 30  0000 C CNN
F 2 "" H 5150 3800 60  0000 C CNN
F 3 "" H 5150 3800 60  0000 C CNN
	1    5150 3800
	1    0    0    -1  
$EndComp
$Comp
L R R207
U 1 1 559BB82C
P 5500 5300
F 0 "R207" V 5600 5300 50  0000 C CNN
F 1 "165" V 5500 5300 45  0000 C CNN
F 2 "" H 5500 5300 60  0000 C CNN
F 3 "" H 5500 5300 60  0000 C CNN
	1    5500 5300
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR04
U 1 1 559BB845
P 5150 5200
F 0 "#PWR04" H 5150 5160 30  0001 C CNN
F 1 "+3.3V" H 5150 5310 30  0000 C CNN
F 2 "" H 5150 5200 60  0000 C CNN
F 3 "" H 5150 5200 60  0000 C CNN
	1    5150 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 5200 5150 5300
Wire Wire Line
	5150 5300 5250 5300
Wire Wire Line
	5750 5300 5850 5300
Text GLabel 7350 2800 2    60   Output ~ 0
OUT2-1
Text GLabel 7350 2450 2    60   Output ~ 0
OUT2-2
Wire Wire Line
	7350 2450 7150 2450
Wire Wire Line
	7150 2800 7350 2800
Wire Wire Line
	7350 3850 7150 3850
Wire Wire Line
	7350 4200 7150 4200
Text GLabel 7350 4200 2    60   Output ~ 0
OUT3-1
Text GLabel 7350 3850 2    60   Output ~ 0
OUT3-2
Text GLabel 7350 5600 2    60   Output ~ 0
OUT4-1
Text GLabel 7350 5250 2    60   Output ~ 0
OUT4-2
Wire Wire Line
	7350 5250 7150 5250
Wire Wire Line
	7150 5600 7350 5600
$Comp
L T_NPN Q201
U 1 1 559BB96E
P 4700 1650
F 0 "Q201" H 4650 1850 50  0000 R CNN
F 1 "T_NPN" H 5150 1600 50  0000 R CNN
F 2 "" H 4700 1650 60  0000 C CNN
F 3 "" H 4700 1650 60  0000 C CNN
	1    4700 1650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 559BB97D
P 4800 1950
F 0 "#PWR05" H 4800 1950 30  0001 C CNN
F 1 "GND" H 4800 1880 30  0001 C CNN
F 2 "" H 4800 1950 60  0000 C CNN
F 3 "" H 4800 1950 60  0000 C CNN
	1    4800 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1450 4800 1350
Wire Wire Line
	5850 1450 5750 1450
Wire Wire Line
	5750 1450 5750 1650
Connection ~ 5750 1550
Wire Wire Line
	5750 1650 5850 1650
Wire Wire Line
	4800 1950 4800 1850
Wire Wire Line
	4800 1350 5150 1350
Wire Wire Line
	5150 1350 5150 1550
Wire Wire Line
	5150 1550 5850 1550
$Comp
L R R202
U 1 1 559BBA86
P 4150 1650
F 0 "R202" V 4250 1650 50  0000 C CNN
F 1 "10k" V 4150 1650 45  0000 C CNN
F 2 "" H 4150 1650 60  0000 C CNN
F 3 "" H 4150 1650 60  0000 C CNN
	1    4150 1650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 1650 4500 1650
Text GLabel 3800 1650 0    60   Input ~ 0
OUT1
Wire Wire Line
	3800 1650 3900 1650
$Comp
L T_NPN Q202
U 1 1 559BBB4D
P 4700 3050
F 0 "Q202" H 4650 3250 50  0000 R CNN
F 1 "T_NPN" H 5150 3000 50  0000 R CNN
F 2 "" H 4700 3050 60  0000 C CNN
F 3 "" H 4700 3050 60  0000 C CNN
	1    4700 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2850 4800 2750
Wire Wire Line
	4800 2750 5150 2750
Wire Wire Line
	5150 2750 5150 2950
Wire Wire Line
	5150 2950 5850 2950
Wire Wire Line
	5850 2850 5750 2850
Wire Wire Line
	5750 2850 5750 3050
Connection ~ 5750 2950
Wire Wire Line
	5750 3050 5850 3050
Wire Wire Line
	4800 3250 4800 3350
$Comp
L GND #PWR06
U 1 1 559BBC26
P 4800 3350
F 0 "#PWR06" H 4800 3350 30  0001 C CNN
F 1 "GND" H 4800 3280 30  0001 C CNN
F 2 "" H 4800 3350 60  0000 C CNN
F 3 "" H 4800 3350 60  0000 C CNN
	1    4800 3350
	1    0    0    -1  
$EndComp
$Comp
L R R204
U 1 1 559BBC35
P 4150 3050
F 0 "R204" V 4250 3050 50  0000 C CNN
F 1 "10k" V 4150 3050 45  0000 C CNN
F 2 "" H 4150 3050 60  0000 C CNN
F 3 "" H 4150 3050 60  0000 C CNN
	1    4150 3050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 3050 4500 3050
Text GLabel 3800 3050 0    60   Input ~ 0
OUT2
Wire Wire Line
	3800 3050 3900 3050
$Comp
L T_NPN Q203
U 1 1 559BBD84
P 4700 4450
F 0 "Q203" H 4650 4650 50  0000 R CNN
F 1 "T_NPN" H 5150 4400 50  0000 R CNN
F 2 "" H 4700 4450 60  0000 C CNN
F 3 "" H 4700 4450 60  0000 C CNN
	1    4700 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 4250 4800 4150
Wire Wire Line
	4800 4150 5150 4150
Wire Wire Line
	5150 4150 5150 4350
Wire Wire Line
	5150 4350 5850 4350
Wire Wire Line
	5850 4250 5750 4250
Wire Wire Line
	5750 4250 5750 4450
Connection ~ 5750 4350
Wire Wire Line
	5750 4450 5850 4450
Wire Wire Line
	4800 4750 4800 4650
$Comp
L GND #PWR07
U 1 1 559BBE60
P 4800 4750
F 0 "#PWR07" H 4800 4750 30  0001 C CNN
F 1 "GND" H 4800 4680 30  0001 C CNN
F 2 "" H 4800 4750 60  0000 C CNN
F 3 "" H 4800 4750 60  0000 C CNN
	1    4800 4750
	1    0    0    -1  
$EndComp
$Comp
L R R206
U 1 1 559BBE6F
P 4150 4450
F 0 "R206" V 4250 4450 50  0000 C CNN
F 1 "10k" V 4150 4450 45  0000 C CNN
F 2 "" H 4150 4450 60  0000 C CNN
F 3 "" H 4150 4450 60  0000 C CNN
	1    4150 4450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 4450 4500 4450
Wire Wire Line
	3800 4450 3900 4450
Text GLabel 3800 4450 0    60   Input ~ 0
OUT3
$Comp
L T_NPN Q204
U 1 1 559BBEF1
P 4700 5850
F 0 "Q204" H 4650 6050 50  0000 R CNN
F 1 "T_NPN" H 5150 5800 50  0000 R CNN
F 2 "" H 4700 5850 60  0000 C CNN
F 3 "" H 4700 5850 60  0000 C CNN
	1    4700 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 5650 4800 5550
Wire Wire Line
	4800 5550 5150 5550
Wire Wire Line
	5150 5550 5150 5750
Wire Wire Line
	5150 5750 5850 5750
Wire Wire Line
	5850 5650 5750 5650
Wire Wire Line
	5750 5650 5750 5850
Connection ~ 5750 5750
Wire Wire Line
	5750 5850 5850 5850
Wire Wire Line
	4800 6150 4800 6050
$Comp
L GND #PWR08
U 1 1 559BC037
P 4800 6150
F 0 "#PWR08" H 4800 6150 30  0001 C CNN
F 1 "GND" H 4800 6080 30  0001 C CNN
F 2 "" H 4800 6150 60  0000 C CNN
F 3 "" H 4800 6150 60  0000 C CNN
	1    4800 6150
	1    0    0    -1  
$EndComp
$Comp
L R R208
U 1 1 559BC046
P 4150 5850
F 0 "R208" V 4250 5850 50  0000 C CNN
F 1 "10k" V 4150 5850 45  0000 C CNN
F 2 "" H 4150 5850 60  0000 C CNN
F 3 "" H 4150 5850 60  0000 C CNN
	1    4150 5850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 5850 4500 5850
Wire Wire Line
	3800 5850 3900 5850
Text GLabel 3800 5850 0    60   Input ~ 0
OUT4
$EndSCHEMATC
