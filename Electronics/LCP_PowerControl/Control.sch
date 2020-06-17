EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 11
Title ""
Date "2020-06-17"
Rev "R0.1"
Comp ""
Comment1 "Design by: Matt Casari"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 8950 3800 2    50   BiDi ~ 0
CONTROL_SDA
Text HLabel 8950 3700 2    50   Output ~ 0
CONTROL_EN
Text HLabel 8950 3900 2    50   Output ~ 0
CONTROL_SCL
Wire Wire Line
	8950 3800 7300 3800
Wire Wire Line
	4400 3900 7200 3900
$Comp
L power:GND #PWR010
U 1 1 5EE31A75
P 5500 4300
F 0 "#PWR010" H 5500 4050 50  0001 C CNN
F 1 "GND" H 5505 4127 50  0000 C CNN
F 2 "" H 5500 4300 50  0001 C CNN
F 3 "" H 5500 4300 50  0001 C CNN
	1    5500 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 4000 5500 4000
Wire Wire Line
	5500 4000 5500 4300
$Comp
L Device:Polyfuse F1
U 1 1 5EE32249
P 4950 3600
F 0 "F1" V 4850 3600 50  0000 C CNN
F 1 "1A" V 5000 3750 50  0000 C CNN
F 2 "Fuse:Fuse_Bourns_MF-RG650" H 5000 3400 50  0001 L CNN
F 3 "~" H 4950 3600 50  0001 C CNN
F 4 "MF-R065" V 4950 3600 50  0001 C CNN "MPN"
	1    4950 3600
	0    1    1    0   
$EndComp
$Comp
L power:+BATT #PWR09
U 1 1 5EE32FBC
P 5500 3400
F 0 "#PWR09" H 5500 3250 50  0001 C CNN
F 1 "+BATT" H 5515 3573 50  0000 C CNN
F 2 "" H 5500 3400 50  0001 C CNN
F 3 "" H 5500 3400 50  0001 C CNN
	1    5500 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 3400 5500 3600
Wire Wire Line
	5500 3600 5100 3600
Wire Wire Line
	4400 3600 4800 3600
$Comp
L power:GND #PWR034
U 1 1 5EED44A2
P 7100 5200
F 0 "#PWR034" H 7100 4950 50  0001 C CNN
F 1 "GND" H 7105 5027 50  0000 C CNN
F 2 "" H 7100 5200 50  0001 C CNN
F 3 "" H 7100 5200 50  0001 C CNN
	1    7100 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 5200 7100 5050
Wire Wire Line
	7200 5000 7200 5050
Wire Wire Line
	7200 5050 7100 5050
Connection ~ 7100 5050
Wire Wire Line
	7100 5050 7100 5000
Wire Wire Line
	7300 5000 7300 5050
Connection ~ 7200 5050
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J15
U 1 1 5EED0364
P 7200 4700
F 0 "J15" V 7159 4412 50  0000 R CNN
F 1 "Conn_02x04_Odd_Even" V 7250 4412 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x04_P2.54mm_Vertical" H 7200 4700 50  0001 C CNN
F 3 "~" H 7200 4700 50  0001 C CNN
F 4 "SALEAE_TEST" V 7341 4412 50  0000 R CNN "Field4"
	1    7200 4700
	0    -1   1    0   
$EndComp
Wire Wire Line
	7400 5000 7400 5050
Wire Wire Line
	7200 5050 7300 5050
Wire Wire Line
	7300 5050 7400 5050
Connection ~ 7300 5050
Wire Wire Line
	7100 4500 7100 3700
Wire Wire Line
	4400 3700 7100 3700
Connection ~ 7100 3700
Wire Wire Line
	7100 3700 8950 3700
Wire Wire Line
	7200 4500 7200 3900
Connection ~ 7200 3900
Wire Wire Line
	7200 3900 8950 3900
Wire Wire Line
	7300 4500 7300 3800
Connection ~ 7300 3800
Wire Wire Line
	7300 3800 4400 3800
NoConn ~ 7400 4500
$Comp
L Connector_Generic:Conn_01x05 J2
U 1 1 5EED17CB
P 4200 3800
F 0 "J2" H 4118 3375 50  0000 C CNN
F 1 "Conn_01x05" H 4118 3466 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 4200 3800 50  0001 C CNN
F 3 "~" H 4200 3800 50  0001 C CNN
	1    4200 3800
	-1   0    0    1   
$EndComp
$EndSCHEMATC
