EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 9 11
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 8650 3650 2    50   Output ~ 0
HALL_EFFECT_V+
Text HLabel 8650 3750 2    50   Input ~ 0
HALL_EFFECT_CH_A
Text HLabel 8650 3850 2    50   Input ~ 0
HALL_EFFECT_CH_B
Text HLabel 8650 3950 2    50   Output ~ 0
HALL_EFFECT_V-
$Comp
L Device:Polyfuse F?
U 1 1 5EE9B5F6
P 7800 3500
AR Path="/5EE2AA1B/5EE9B5F6" Ref="F?"  Part="1" 
AR Path="/5EE7B8CC/5EE9B5F6" Ref="F?"  Part="1" 
F 0 "F?" V 7700 3500 50  0000 C CNN
F 1 "250mA" V 7850 3650 50  0000 C CNN
F 2 "Fuse:Fuse_Bourns_MF-RG650" H 7850 3300 50  0001 L CNN
F 3 "~" H 7800 3500 50  0001 C CNN
F 4 "MF-R065" V 7800 3500 50  0001 C CNN "MPN"
	1    7800 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	7950 3500 8050 3500
Wire Wire Line
	8050 3500 8050 3650
Wire Wire Line
	8050 3650 8650 3650
$Comp
L power:+3V3 #PWR?
U 1 1 5EE9B7A7
P 7450 3250
F 0 "#PWR?" H 7450 3100 50  0001 C CNN
F 1 "+3V3" H 7465 3423 50  0000 C CNN
F 2 "" H 7450 3250 50  0001 C CNN
F 3 "" H 7450 3250 50  0001 C CNN
	1    7450 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 3250 7450 3500
Wire Wire Line
	7450 3500 7650 3500
$Comp
L power:GND #PWR?
U 1 1 5EE9CB1B
P 7450 4200
F 0 "#PWR?" H 7450 3950 50  0001 C CNN
F 1 "GND" H 7455 4027 50  0000 C CNN
F 2 "" H 7450 4200 50  0001 C CNN
F 3 "" H 7450 4200 50  0001 C CNN
	1    7450 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 3950 7450 3950
Wire Wire Line
	7450 3950 7450 4200
Text HLabel 3050 3750 0    50   Input ~ 0
ENCODER_CH_A
Text HLabel 3050 3850 0    50   Input ~ 0
ENCODER_CH_B
Wire Wire Line
	3050 3850 3650 3850
$Comp
L Device:R_Pack02 RN?
U 1 1 5EEF0BC5
P 5100 3300
AR Path="/5EE2A5A7/5EEF0BC5" Ref="RN?"  Part="1" 
AR Path="/5EE7B8CC/5EEF0BC5" Ref="RN?"  Part="1" 
F 0 "RN?" H 5188 3346 50  0000 L CNN
F 1 "R_Pack02" H 5188 3255 50  0000 L CNN
F 2 "" V 5275 3300 50  0001 C CNN
F 3 "~" H 5100 3300 50  0001 C CNN
	1    5100 3300
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5EEF0BCB
P 5000 2950
AR Path="/5EE2A5A7/5EEF0BCB" Ref="#PWR?"  Part="1" 
AR Path="/5EE7B8CC/5EEF0BCB" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5000 2800 50  0001 C CNN
F 1 "+3V3" H 5015 3123 50  0000 C CNN
F 2 "" H 5000 2950 50  0001 C CNN
F 3 "" H 5000 2950 50  0001 C CNN
	1    5000 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2950 5000 3000
Wire Wire Line
	5100 3100 5100 3000
Wire Wire Line
	5100 3000 5000 3000
Connection ~ 5000 3000
Wire Wire Line
	5000 3000 5000 3100
Wire Wire Line
	5000 3500 5000 3750
Connection ~ 5000 3750
Wire Wire Line
	5000 3750 4100 3750
Wire Wire Line
	5100 3500 5100 3850
Connection ~ 5100 3850
$Comp
L Connector:TestPoint TP?
U 1 1 5EEF683F
P 3650 3550
AR Path="/5EE2AB43/5EEF683F" Ref="TP?"  Part="1" 
AR Path="/5EE7B8CC/5EEF683F" Ref="TP?"  Part="1" 
F 0 "TP?" H 3708 3668 50  0000 L CNN
F 1 "TestPoint" H 3708 3577 50  0000 L CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 3850 3550 50  0001 C CNN
F 3 "~" H 3850 3550 50  0001 C CNN
	1    3650 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3550 3650 3850
$Comp
L Connector:TestPoint TP?
U 1 1 5EEF6EB6
P 4100 3550
AR Path="/5EE2AB43/5EEF6EB6" Ref="TP?"  Part="1" 
AR Path="/5EE7B8CC/5EEF6EB6" Ref="TP?"  Part="1" 
F 0 "TP?" H 4158 3668 50  0000 L CNN
F 1 "TestPoint" H 4158 3577 50  0000 L CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 4300 3550 50  0001 C CNN
F 3 "~" H 4300 3550 50  0001 C CNN
	1    4100 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3550 4100 3750
Wire Wire Line
	5000 3750 8650 3750
Wire Wire Line
	5100 3850 8650 3850
Connection ~ 4100 3750
Wire Wire Line
	4100 3750 3050 3750
Connection ~ 3650 3850
Wire Wire Line
	3650 3850 5100 3850
$EndSCHEMATC
