EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 11 11
Title ""
Date "2020-06-17"
Rev "R0.1"
Comp ""
Comment1 "Design by: Matt Casari"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 7150 4700 2    50   Input ~ 0
DEBUG_LED_1
Text HLabel 7150 4800 2    50   Input ~ 0
DEBUG_LED_2
$Comp
L Device:LED D6
U 1 1 5EF924B3
P 3650 4450
F 0 "D6" V 3689 4333 50  0000 R CNN
F 1 "LED_BLUE" V 3598 4333 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 3650 4450 50  0001 C CNN
F 3 "~" H 3650 4450 50  0001 C CNN
F 4 "APT2012LVBC/D" V 3650 4450 50  0001 C CNN "MPN"
	1    3650 4450
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D7
U 1 1 5EF93B88
P 4250 4450
F 0 "D7" V 4289 4332 50  0000 R CNN
F 1 "LED_GREEN" V 4198 4332 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 4250 4450 50  0001 C CNN
F 3 "~" H 4250 4450 50  0001 C CNN
F 4 "APT2012SGC" V 4250 4450 50  0001 C CNN "MPN"
	1    4250 4450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4250 4700 4250 4600
Wire Wire Line
	3650 4600 3650 4800
$Comp
L Device:R_Pack02 RN4
U 1 1 5EF94B86
P 4000 3800
F 0 "RN4" H 4088 3846 50  0000 L CNN
F 1 "4.7k" H 4088 3755 50  0000 L CNN
F 2 "Resistor_SMD:R_Array_Concave_2x0603" V 4175 3800 50  0001 C CNN
F 3 "~" H 4000 3800 50  0001 C CNN
F 4 "EXB-V4V472JV" H 4000 3800 50  0001 C CNN "MPN"
	1    4000 3800
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR063
U 1 1 5EF95664
P 3950 3400
F 0 "#PWR063" H 3950 3250 50  0001 C CNN
F 1 "+3V3" H 3965 3573 50  0000 C CNN
F 2 "" H 3950 3400 50  0001 C CNN
F 3 "" H 3950 3400 50  0001 C CNN
	1    3950 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 3400 3950 3500
Wire Wire Line
	3950 3500 3900 3500
Wire Wire Line
	3900 3500 3900 3600
Wire Wire Line
	4000 3500 4000 3600
Wire Wire Line
	4000 3500 3950 3500
Connection ~ 3950 3500
Wire Wire Line
	3650 4300 3650 4150
Wire Wire Line
	3650 4150 3900 4150
Wire Wire Line
	3900 4150 3900 4000
Wire Wire Line
	4250 4300 4250 4150
Wire Wire Line
	4250 4150 4000 4150
Wire Wire Line
	4000 4150 4000 4000
Wire Wire Line
	3650 4800 7150 4800
Wire Wire Line
	4250 4700 7150 4700
$EndSCHEMATC
