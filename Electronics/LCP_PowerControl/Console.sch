EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 11
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x06 J1
U 1 1 5EE385DA
P 3700 3650
F 0 "J1" H 3618 3125 50  0000 C CNN
F 1 "Conn_01x06" H 3618 3216 50  0000 C CNN
F 2 "" H 3700 3650 50  0001 C CNN
F 3 "~" H 3700 3650 50  0001 C CNN
	1    3700 3650
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5EE39E78
P 4150 4100
F 0 "#PWR08" H 4150 3850 50  0001 C CNN
F 1 "GND" H 4155 3927 50  0000 C CNN
F 2 "" H 4150 4100 50  0001 C CNN
F 3 "" H 4150 4100 50  0001 C CNN
	1    4150 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 3850 4150 3850
Wire Wire Line
	4150 3850 4150 4100
Text HLabel 6450 3450 2    50   Input ~ 0
CONSOLE_RX
Text HLabel 6450 3550 2    50   Output ~ 0
CONSOLE_TX
Wire Wire Line
	6450 3450 5500 3450
Wire Wire Line
	3900 3550 5400 3550
Text HLabel 6450 3650 2    50   Output ~ 0
CONSOLE_PWR
Wire Wire Line
	6450 3650 5300 3650
$Comp
L power:GND #PWR?
U 1 1 5EED83B1
P 5300 4850
AR Path="/5EE2AA1B/5EED83B1" Ref="#PWR?"  Part="1" 
AR Path="/5EE2A864/5EED83B1" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5300 4600 50  0001 C CNN
F 1 "GND" H 5305 4677 50  0000 C CNN
F 2 "" H 5300 4850 50  0001 C CNN
F 3 "" H 5300 4850 50  0001 C CNN
	1    5300 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 4850 5300 4700
Wire Wire Line
	5400 4650 5400 4700
Wire Wire Line
	5400 4700 5300 4700
Connection ~ 5300 4700
Wire Wire Line
	5300 4700 5300 4650
Wire Wire Line
	5500 4650 5500 4700
Connection ~ 5400 4700
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J?
U 1 1 5EED83BF
P 5400 4350
F 0 "J?" V 5359 4062 50  0000 R CNN
F 1 "Conn_02x04_Odd_Even" V 5450 4062 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x04_P2.54mm_Vertical" H 5400 4350 50  0001 C CNN
F 3 "~" H 5400 4350 50  0001 C CNN
F 4 "SALEAE_TEST" V 5541 4062 50  0000 R CNN "Field4"
	1    5400 4350
	0    -1   1    0   
$EndComp
Wire Wire Line
	5600 4650 5600 4700
Wire Wire Line
	5400 4700 5500 4700
Wire Wire Line
	5500 4700 5600 4700
Connection ~ 5500 4700
Wire Wire Line
	5300 4150 5300 3650
Connection ~ 5300 3650
Wire Wire Line
	5300 3650 3900 3650
Wire Wire Line
	5400 4150 5400 3550
Connection ~ 5400 3550
Wire Wire Line
	5400 3550 6450 3550
Wire Wire Line
	5500 4150 5500 3450
Connection ~ 5500 3450
Wire Wire Line
	5500 3450 3900 3450
NoConn ~ 5600 4150
$EndSCHEMATC
