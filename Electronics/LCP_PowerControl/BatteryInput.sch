EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 11
Title ""
Date "2020-06-17"
Rev "R0.1"
Comp ""
Comment1 "Design by: Matt Casari"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 9600 1850 2    50   Output ~ 0
BATT_V+
Text HLabel 9600 1950 2    50   Input ~ 0
BATT_V-
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 5EF29935
P 3900 1950
F 0 "J3" H 3818 1625 50  0000 C CNN
F 1 "Conn_01x02" H 3818 1716 50  0000 C CNN
F 2 "Connector_Molex:Molex_Micro-Fit_3.0_43045-0212_2x01_P3.00mm_Vertical" H 3900 1950 50  0001 C CNN
F 3 "~" H 3900 1950 50  0001 C CNN
	1    3900 1950
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J9
U 1 1 5EF2A22F
P 3900 2850
F 0 "J9" H 3818 2525 50  0000 C CNN
F 1 "Conn_01x02" H 3818 2616 50  0000 C CNN
F 2 "Connector_Molex:Molex_Micro-Fit_3.0_43045-0212_2x01_P3.00mm_Vertical" H 3900 2850 50  0001 C CNN
F 3 "~" H 3900 2850 50  0001 C CNN
	1    3900 2850
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J10
U 1 1 5EF2A6FE
P 3900 3850
F 0 "J10" H 3818 3525 50  0000 C CNN
F 1 "Conn_01x02" H 3818 3616 50  0000 C CNN
F 2 "Connector_Molex:Molex_Micro-Fit_3.0_43045-0212_2x01_P3.00mm_Vertical" H 3900 3850 50  0001 C CNN
F 3 "~" H 3900 3850 50  0001 C CNN
	1    3900 3850
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J11
U 1 1 5EF2AC09
P 3900 4850
F 0 "J11" H 3818 4525 50  0000 C CNN
F 1 "Conn_01x02" H 3818 4616 50  0000 C CNN
F 2 "Connector_Molex:Molex_Micro-Fit_3.0_43045-0212_2x01_P3.00mm_Vertical" H 3900 4850 50  0001 C CNN
F 3 "~" H 3900 4850 50  0001 C CNN
	1    3900 4850
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J12
U 1 1 5EF2B236
P 3900 5950
F 0 "J12" H 3818 5625 50  0000 C CNN
F 1 "Conn_01x02" H 3818 5716 50  0000 C CNN
F 2 "Connector_Molex:Molex_Micro-Fit_3.0_43045-0212_2x01_P3.00mm_Vertical" H 3900 5950 50  0001 C CNN
F 3 "~" H 3900 5950 50  0001 C CNN
	1    3900 5950
	-1   0    0    1   
$EndComp
$Comp
L Device:D D5
U 1 1 5EF2F687
P 5150 5850
F 0 "D5" H 5150 6066 50  0000 C CNN
F 1 "D" H 5150 5975 50  0000 C CNN
F 2 "Diode_SMD:D_SMA" H 5150 5850 50  0001 C CNN
F 3 "~" H 5150 5850 50  0001 C CNN
F 4 "SK53A-LTP" H 5150 5850 50  0001 C CNN "MPN"
	1    5150 5850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4100 5950 4450 5950
Wire Wire Line
	4450 5950 4450 4850
Wire Wire Line
	4450 1950 4100 1950
Wire Wire Line
	4100 2850 4450 2850
Connection ~ 4450 2850
Wire Wire Line
	4450 2850 4450 1950
Wire Wire Line
	4100 3850 4450 3850
Connection ~ 4450 3850
Wire Wire Line
	4450 3850 4450 2850
Wire Wire Line
	4100 4850 4450 4850
Connection ~ 4450 4850
Wire Wire Line
	4450 4850 4450 3850
Wire Wire Line
	4100 5850 5000 5850
Wire Wire Line
	4100 4750 5650 4750
Wire Wire Line
	5650 4750 5650 5850
Wire Wire Line
	5650 5850 5300 5850
Wire Wire Line
	4100 3750 5650 3750
Wire Wire Line
	5650 3750 5650 4750
Connection ~ 5650 4750
Wire Wire Line
	5650 2750 5650 3750
Connection ~ 5650 3750
Wire Wire Line
	4100 2750 5650 2750
Wire Wire Line
	4100 1850 5650 1850
Connection ~ 5650 2750
Connection ~ 5650 1850
Wire Wire Line
	5650 1850 5650 2750
Connection ~ 4450 1950
Text Notes 2650 5950 0    50   ~ 0
External Power Connector\n(DC Supply)
Text Notes 2850 1950 0    50   ~ 0
Battery #1 Connector
Text Notes 2850 2850 0    50   ~ 0
Battery #2 Connector
Text Notes 2850 3800 0    50   ~ 0
Battery #3 Connector
Text Notes 2850 4800 0    50   ~ 0
Battery #4 Connector
Text Notes 1050 1300 0    50   ~ 0
Battery Connections:\nExpected Battery Pack\n18SP1 Stacks, Alkaline, Diode Protected
$Comp
L Connector:TestPoint TP?
U 1 1 5F052069
P 6600 1600
AR Path="/5EE2A7AF/5F052069" Ref="TP?"  Part="1" 
AR Path="/5EE4388C/5F052069" Ref="TP?"  Part="1" 
AR Path="/5EE2A57D/5F052069" Ref="TP22"  Part="1" 
F 0 "TP22" H 6658 1718 50  0000 L CNN
F 1 "TestPoint" H 6658 1627 50  0000 L CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 6800 1600 50  0001 C CNN
F 3 "~" H 6800 1600 50  0001 C CNN
F 4 "5000" H 6600 1600 50  0001 C CNN "MPN"
	1    6600 1600
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP?
U 1 1 5F052070
P 7050 1600
AR Path="/5EE2A7AF/5F052070" Ref="TP?"  Part="1" 
AR Path="/5EE4388C/5F052070" Ref="TP?"  Part="1" 
AR Path="/5EE2A57D/5F052070" Ref="TP23"  Part="1" 
F 0 "TP23" H 7108 1718 50  0000 L CNN
F 1 "TestPoint" H 7108 1627 50  0000 L CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 7250 1600 50  0001 C CNN
F 3 "~" H 7250 1600 50  0001 C CNN
F 4 "5001" H 7050 1600 50  0001 C CNN "MPN"
	1    7050 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 1600 6600 1850
Wire Wire Line
	5650 1850 6600 1850
Connection ~ 6600 1850
Wire Wire Line
	6600 1850 9600 1850
Wire Wire Line
	7050 1600 7050 1950
Wire Wire Line
	4450 1950 7050 1950
Connection ~ 7050 1950
Wire Wire Line
	7050 1950 9600 1950
$EndSCHEMATC
