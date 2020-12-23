EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 11
Title ""
Date "2020-06-17"
Rev "R0.1"
Comp ""
Comment1 "Design by: Matt Casari"
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
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 3700 3650 50  0001 C CNN
F 3 "~" H 3700 3650 50  0001 C CNN
F 4 "61300611121" H 3700 3650 50  0001 C CNN "MPN"
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
	4150 3850 4150 3900
Text HLabel 6450 3450 2    50   Input ~ 0
CONSOLE_RX
Text HLabel 6450 3550 2    50   Output ~ 0
CONSOLE_TX
Text HLabel 6450 3650 2    50   Output ~ 0
CONSOLE_PWR
NoConn ~ 3900 3750
NoConn ~ 3900 3350
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5EED0A72
P 4500 3900
F 0 "#FLG0103" H 4500 3975 50  0001 C CNN
F 1 "PWR_FLAG" H 4500 4073 50  0000 C CNN
F 2 "" H 4500 3900 50  0001 C CNN
F 3 "~" H 4500 3900 50  0001 C CNN
	1    4500 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 3900 4500 3900
Connection ~ 4150 3900
Wire Wire Line
	4150 3900 4150 4100
Wire Wire Line
	3900 3650 6450 3650
Wire Wire Line
	3900 3550 6450 3550
Wire Wire Line
	3900 3450 6450 3450
$EndSCHEMATC
