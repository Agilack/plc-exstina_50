EESchema Schematic File Version 2
LIBS:exstina_50-r01
LIBS:exstina_50-r01-cache
EELAYER 24 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 6
Title "Exstina-50"
Date "17 Jul 2015"
Rev "0.1"
Comp "Agilack"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 7600 3350 2100 1350
U 559B965E
F0 "Outputs" 50
F1 "exstina_50-ios.sch" 50
$EndSheet
$Comp
L CONN_8 P2
U 1 1 559B97FD
P 8150 1750
F 0 "P2" H 8150 2350 60  0000 C CNN
F 1 "CONN_8" V 8150 1750 60  0000 C CNN
F 2 "" H 8150 1750 60  0000 C CNN
F 3 "" H 8150 1750 60  0000 C CNN
F 4 "FCI" H 8150 1750 60  0001 C CNN "Manufacturer"
F 5 "20020111-H081A01LF" H 8150 1750 60  0001 C CNN "Manuf Ref"
	1    8150 1750
	1    0    0    -1  
$EndComp
$Comp
L CONN_8 P1
U 1 1 559B9818
P 3350 1750
F 0 "P1" H 3350 1150 60  0000 C CNN
F 1 "CONN_8" V 3350 1750 60  0000 C CNN
F 2 "" H 3350 1750 60  0000 C CNN
F 3 "" H 3350 1750 60  0000 C CNN
F 4 "FCI" H 3350 1750 60  0001 C CNN "Manufacturer"
F 5 "20020111-H081A01LF" H 3350 1750 60  0001 C CNN "Manuf Ref"
	1    3350 1750
	-1   0    0    1   
$EndComp
Text GLabel 4100 1100 2    60   Output ~ 0
PWR_V+
Text GLabel 4100 1250 2    60   Output ~ 0
PWR_V-
Wire Wire Line
	3700 1400 3800 1400
Text GLabel 4100 1550 2    60   BiDi ~ 0
COMM_1
Text GLabel 4100 1700 2    60   BiDi ~ 0
COMM_2
Wire Wire Line
	3700 1650 3950 1650
Wire Wire Line
	3700 1550 4100 1550
Text GLabel 7400 1000 0    60   Input ~ 0
OUT1-1
Text GLabel 7400 1150 0    60   Input ~ 0
OUT1-2
Text GLabel 7400 1450 0    60   Input ~ 0
OUT2-1
Text GLabel 7400 1600 0    60   Input ~ 0
OUT2-2
Text GLabel 7400 1900 0    60   Input ~ 0
OUT3-1
Text GLabel 7400 2050 0    60   Input ~ 0
OUT3-2
Text GLabel 7400 2350 0    60   Input ~ 0
OUT4-1
Text GLabel 7400 2500 0    60   Input ~ 0
OUT4-2
Wire Wire Line
	7400 1000 7750 1000
Wire Wire Line
	7400 1150 7700 1150
Wire Wire Line
	7400 1450 7600 1450
Wire Wire Line
	7400 1600 7550 1600
Wire Wire Line
	7800 1300 7750 1300
Wire Wire Line
	7750 1300 7750 1000
Wire Wire Line
	7800 1400 7700 1400
Wire Wire Line
	7700 1400 7700 1150
Wire Wire Line
	7800 1550 7600 1550
Wire Wire Line
	7600 1550 7600 1450
Wire Wire Line
	7800 1650 7550 1650
Wire Wire Line
	7550 1650 7550 1600
Wire Wire Line
	7400 1900 7550 1900
Wire Wire Line
	7550 1900 7550 1850
Wire Wire Line
	7550 1850 7800 1850
Wire Wire Line
	7400 2050 7600 2050
Wire Wire Line
	7600 2050 7600 1950
Wire Wire Line
	7600 1950 7800 1950
Wire Wire Line
	7800 2100 7700 2100
Wire Wire Line
	7700 2100 7700 2350
Wire Wire Line
	7700 2350 7400 2350
Wire Wire Line
	7400 2500 7750 2500
Wire Wire Line
	7750 2500 7750 2200
Wire Wire Line
	7750 2200 7800 2200
Wire Wire Line
	3700 1300 3750 1300
Text GLabel 4100 1950 2    60   Output ~ 0
EXT-IN-1
Text GLabel 4100 2100 2    60   Output ~ 0
EXT-IN-2
Text GLabel 4100 2250 2    60   Output ~ 0
EXT-IN-3
Text GLabel 4100 2400 2    60   Output ~ 0
EXT-IN-4
Wire Wire Line
	3700 1950 3950 1950
Wire Wire Line
	3950 1950 3950 2100
Wire Wire Line
	3700 2100 3900 2100
Wire Wire Line
	3900 2100 3900 2250
Wire Wire Line
	3700 2200 3850 2200
$Sheet
S 1700 4900 2100 1350
U 559FDB28
F0 "Power" 50
F1 "exstina_50-power.sch" 50
$EndSheet
$Sheet
S 1700 3350 2100 1350
U 55A039B8
F0 "Inputs" 50
F1 "exstina_50-inputs.sch" 50
$EndSheet
Wire Wire Line
	4100 1250 3800 1250
Wire Wire Line
	3800 1250 3800 1400
Wire Wire Line
	4100 1100 3750 1100
Wire Wire Line
	3750 1100 3750 1300
Wire Wire Line
	4100 1700 3950 1700
Wire Wire Line
	3950 1700 3950 1650
Wire Wire Line
	3900 2250 4100 2250
Wire Wire Line
	3950 2100 4100 2100
Wire Wire Line
	3700 1850 4000 1850
Wire Wire Line
	4000 1850 4000 1950
Wire Wire Line
	4000 1950 4100 1950
Wire Wire Line
	4100 2400 3850 2400
Wire Wire Line
	3850 2400 3850 2200
$Sheet
S 4000 3350 3400 2900
U 55A690D0
F0 "Processor Unit" 50
F1 "exstina_50-CPU.sch" 50
$EndSheet
$Sheet
S 7600 4900 2100 1350
U 55A8DC87
F0 "Communication" 50
F1 "exstina_50-comm.sch" 50
$EndSheet
$EndSCHEMATC
