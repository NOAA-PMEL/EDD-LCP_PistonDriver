EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 10 11
Title ""
Date "2020-06-17"
Rev "R0.1"
Comp ""
Comment1 "Design by: Matt Casari"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4850 3150 0    50   Input ~ 0
ACTUATOR_POWER+
Text HLabel 4850 3250 0    50   Input ~ 0
ACTUATOR_POWER-
Text HLabel 4850 3950 0    50   Input ~ 0
HALL_EFFECT_V+
Text HLabel 4850 4050 0    50   Output ~ 0
HALL_EFFECT_CH_A
Text HLabel 4850 4150 0    50   Output ~ 0
HALL_EFFECT_CHB
Text HLabel 4850 4250 0    50   Input ~ 0
HALL_EFFECT_V-
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5EE8A2E1
P 7450 3150
AR Path="/5EE2AB43/5EE8A2E1" Ref="J?"  Part="1" 
AR Path="/5EE7B956/5EE8A2E1" Ref="J17"  Part="1" 
F 0 "J17" H 7530 3142 50  0000 L CNN
F 1 "Conn_01x02" H 7530 3051 50  0000 L CNN
F 2 "Connector_Molex:Molex_Micro-Fit_3.0_43045-0212_2x01_P3.00mm_Vertical" H 7450 3150 50  0001 C CNN
F 3 "~" H 7450 3150 50  0001 C CNN
F 4 "0430450213" H 7450 3150 50  0001 C CNN "MPN"
	1    7450 3150
	1    0    0    -1  
$EndComp
Text Notes 6800 3450 0    50   ~ 0
TO 12VDC BLDC MOTOR (LINEAR ACTUATOR)
Wire Wire Line
	4850 3150 7250 3150
Wire Wire Line
	4850 3250 7250 3250
$Comp
L Connector_Generic:Conn_01x04 J18
U 1 1 5EE8A71A
P 7450 4050
F 0 "J18" H 7530 4042 50  0000 L CNN
F 1 "Conn_01x04" H 7530 3951 50  0000 L CNN
F 2 "Connector_Molex:Molex_Micro-Fit_3.0_43045-0400_2x02_P3.00mm_Horizontal" H 7450 4050 50  0001 C CNN
F 3 "~" H 7450 4050 50  0001 C CNN
F 4 "0430450413" H 7450 4050 50  0001 C CNN "MPN"
	1    7450 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3950 7250 3950
Wire Wire Line
	7250 4050 4850 4050
Wire Wire Line
	4850 4150 7250 4150
Wire Wire Line
	7250 4250 4850 4250
Text Notes 6350 4450 0    50   ~ 0
TO QUADRATURE ENCODER (HALL EFFECT ON LINEAR ACTUATOR)
$EndSCHEMATC
