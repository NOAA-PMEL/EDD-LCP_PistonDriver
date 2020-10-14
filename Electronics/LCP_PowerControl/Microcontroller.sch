EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr B 17000 11000
encoding utf-8
Sheet 8 11
Title ""
Date "2020-06-17"
Rev "R0.1"
Comp ""
Comment1 "Design by: Matt Casari"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3900 3150 0    50   BiDi ~ 0
BM_SDA
Text HLabel 3900 3250 0    50   Output ~ 0
BM_SCL
Text HLabel 3900 3050 0    50   Input ~ 0
BM_IRQ
Text HLabel 3900 3600 0    50   Input ~ 0
CONTROL_EN
Text HLabel 3900 3700 0    50   BiDi ~ 0
CONTROL_SDA
Text HLabel 3900 3800 0    50   Input ~ 0
CONTROL_SCL
Text HLabel 3900 4900 0    50   Input ~ 0
CONSOLE_TX
Text HLabel 3900 4800 0    50   Output ~ 0
CONSOLE_RX
Text HLabel 15050 3800 2    50   Output ~ 0
MD_EN
Text HLabel 15050 3900 2    50   Output ~ 0
MD_PH
Text HLabel 15050 4100 2    50   Input ~ 0
~MD_FAULT
Text HLabel 15050 4200 2    50   UnSpc ~ 0
MD_IPROPI
Text HLabel 15050 4300 2    50   Output ~ 0
MD_PMODE
Text HLabel 15050 4000 2    50   Output ~ 0
~MD_SLEEP
Text HLabel 3900 5550 0    50   Output ~ 0
12V_ENABLE
$Comp
L PMEL_Microcontroller:MSP430FR5989 U3
U 1 1 5EE55967
P 8300 4750
F 0 "U3" H 9750 7050 50  0000 C CNN
F 1 "MSP430FR5989" H 7100 7050 50  0000 C CNN
F 2 "Package_QFP:LQFP-64_10x10mm_P0.5mm" H 7700 6450 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/msp430fr5989.pdf?ts=1591995725922&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FMSP430FR5989" H 7700 6450 50  0001 C CNN
F 4 "https://www.ti.com/lit/ug/slau367p/slau367p.pdf?ts=1591999289180&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FMSP430FR5989" H 8450 1800 50  0001 C CNN "UserGuide"
F 5 "https://www.ti.com/lit/er/slaz523y/slaz523y.pdf?ts=1591999307418&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FMSP430FR5989" H 8450 1700 50  0001 C CNN "Errata"
F 6 "MSP430FR5989IPMR" H 8300 4750 50  0001 C CNN "MPN"
	1    8300 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR021
U 1 1 5EE57E22
P 8000 7400
F 0 "#PWR021" H 8000 7150 50  0001 C CNN
F 1 "GND" H 8005 7227 50  0000 C CNN
F 2 "" H 8000 7400 50  0001 C CNN
F 3 "" H 8000 7400 50  0001 C CNN
	1    8000 7400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 7200 7900 7300
Wire Wire Line
	7900 7300 8000 7300
Wire Wire Line
	8100 7300 8100 7200
Wire Wire Line
	8000 7400 8000 7300
Connection ~ 8000 7300
Wire Wire Line
	8000 7300 8100 7300
Wire Wire Line
	8000 7200 8000 7300
$Comp
L power:GNDA #PWR022
U 1 1 5EE591BB
P 8650 7400
F 0 "#PWR022" H 8650 7150 50  0001 C CNN
F 1 "GNDA" H 8655 7227 50  0000 C CNN
F 2 "" H 8650 7400 50  0001 C CNN
F 3 "" H 8650 7400 50  0001 C CNN
	1    8650 7400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 7400 8650 7300
Wire Wire Line
	8550 7200 8550 7300
Wire Wire Line
	8550 7300 8650 7300
Connection ~ 8650 7300
Wire Wire Line
	8650 7300 8650 7200
Wire Wire Line
	8750 7200 8750 7300
Wire Wire Line
	8750 7300 8650 7300
Wire Wire Line
	8450 7300 8550 7300
Connection ~ 8550 7300
Connection ~ 8100 7300
Wire Wire Line
	8150 7300 8100 7300
$Comp
L Jumper:SolderJumper_2_Bridged JP1
U 1 1 5EE58F4C
P 8300 7300
F 0 "JP1" H 8300 7400 50  0000 C CNN
F 1 "SolderJumper_2_Bridged" H 8300 7000 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged_RoundedPad1.0x1.5mm" H 8300 7300 50  0001 C CNN
F 3 "~" H 8300 7300 50  0001 C CNN
	1    8300 7300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J5
U 1 1 5EE5C9EF
P 11500 2300
F 0 "J5" V 11459 2580 50  0000 L CNN
F 1 "Conn_02x05_Odd_Even" V 11550 2580 50  0000 L CNN
F 2 "Connector_PinSocket_1.27mm:PinSocket_2x05_P1.27mm_Vertical" H 11500 2300 50  0001 C CNN
F 3 "~" H 11500 2300 50  0001 C CNN
F 4 "JTAG_MINI" V 11641 2580 50  0000 L CNN "Field4"
	1    11500 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	9900 3000 11500 3000
Wire Wire Line
	11500 3000 11500 2600
Wire Wire Line
	9900 3100 11400 3100
Wire Wire Line
	11400 3100 11400 2600
Wire Wire Line
	9900 3200 11700 3200
Wire Wire Line
	9900 3300 11600 3300
Wire Wire Line
	11600 3300 11600 2600
Wire Wire Line
	9900 3400 10850 3400
Wire Wire Line
	10850 3400 10850 1950
Wire Wire Line
	11400 1950 11400 2100
Wire Wire Line
	11300 3500 11300 2600
$Comp
L power:GND #PWR026
U 1 1 5EE608C6
P 11850 2000
F 0 "#PWR026" H 11850 1750 50  0001 C CNN
F 1 "GND" H 11855 1827 50  0000 C CNN
F 2 "" H 11850 2000 50  0001 C CNN
F 3 "" H 11850 2000 50  0001 C CNN
	1    11850 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	11300 2100 11300 1850
Wire Wire Line
	11850 1850 11850 2000
Wire Wire Line
	11700 2100 11700 1850
Connection ~ 11700 1850
Wire Wire Line
	11700 1850 11850 1850
Wire Wire Line
	11600 2100 11600 1850
Wire Wire Line
	11300 1850 11500 1850
Connection ~ 11600 1850
Wire Wire Line
	11600 1850 11700 1850
Connection ~ 11500 1850
Wire Wire Line
	11500 1850 11600 1850
Wire Wire Line
	11500 1850 11500 2100
Text Label 10050 3000 0    50   ~ 0
TDO
Text Label 10050 3100 0    50   ~ 0
TDI
Text Label 10050 3200 0    50   ~ 0
TMS
Text Label 10050 3300 0    50   ~ 0
TCK
Text Label 10050 3400 0    50   ~ 0
SBWTCK
Text Label 10050 3500 0    50   ~ 0
~RESET
Wire Wire Line
	10850 1950 11400 1950
$Comp
L power:+3V3 #PWR019
U 1 1 5EE675AF
P 6150 1850
F 0 "#PWR019" H 6150 1700 50  0001 C CNN
F 1 "+3V3" H 6165 2023 50  0000 C CNN
F 2 "" H 6150 1850 50  0001 C CNN
F 3 "" H 6150 1850 50  0001 C CNN
	1    6150 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 5EE688B2
P 7550 2100
F 0 "C11" H 7665 2146 50  0000 L CNN
F 1 "0.1uF" H 7665 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7588 1950 50  0001 C CNN
F 3 "~" H 7550 2100 50  0001 C CNN
F 4 "885012207045" H 7550 2100 50  0001 C CNN "MPN"
	1    7550 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 1950 6600 1900
Wire Wire Line
	6600 1900 7050 1900
Connection ~ 7050 1900
Wire Wire Line
	7050 1900 7050 1950
Wire Wire Line
	7550 1950 7550 1900
Wire Wire Line
	7550 1900 7050 1900
$Comp
L power:GND #PWR020
U 1 1 5EE6C2B0
P 6150 2350
F 0 "#PWR020" H 6150 2100 50  0001 C CNN
F 1 "GND" H 6150 2200 50  0000 C CNN
F 2 "" H 6150 2350 50  0001 C CNN
F 3 "" H 6150 2350 50  0001 C CNN
	1    6150 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 2250 6600 2300
Wire Wire Line
	7550 2250 7550 2300
Wire Wire Line
	7550 1900 8050 1900
Wire Wire Line
	8050 1900 8050 2250
Connection ~ 7550 1900
Wire Wire Line
	7950 2400 7950 2250
Wire Wire Line
	7950 2250 8050 2250
Connection ~ 8050 2250
Wire Wire Line
	8050 2250 8050 2400
Wire Wire Line
	8150 2250 8050 2250
Wire Wire Line
	8150 2250 8150 2400
$Comp
L Device:C C9
U 1 1 5EE77368
P 6600 2100
F 0 "C9" H 6715 2146 50  0000 L CNN
F 1 "0.1uF" H 6715 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6638 1950 50  0001 C CNN
F 3 "~" H 6600 2100 50  0001 C CNN
F 4 "885012207045" H 6600 2100 50  0001 C CNN "MPN"
	1    6600 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 5EE7D564
P 7050 2100
F 0 "C10" H 7165 2146 50  0000 L CNN
F 1 "0.1uF" H 7165 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7088 1950 50  0001 C CNN
F 3 "~" H 7050 2100 50  0001 C CNN
F 4 "885012207045" H 7050 2100 50  0001 C CNN "MPN"
	1    7050 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 2300 7050 2300
Wire Wire Line
	7050 2300 7050 2250
Connection ~ 7050 2300
Wire Wire Line
	6600 2300 7050 2300
Wire Wire Line
	6150 2350 6150 2300
Wire Wire Line
	6150 1950 6150 1900
Wire Wire Line
	6150 1900 6600 1900
Connection ~ 6600 1900
Wire Wire Line
	6150 1850 6150 1900
Connection ~ 6150 1900
$Comp
L Device:CP C8
U 1 1 5EE8FA10
P 6150 2100
F 0 "C8" H 6268 2146 50  0000 L CNN
F 1 "10uF" H 6268 2055 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_4x4.5" H 6188 1950 50  0001 C CNN
F 3 "~" H 6150 2100 50  0001 C CNN
F 4 "EEE-HB1C100R" H 6150 2100 50  0001 C CNN "MPN"
	1    6150 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 2300 6150 2300
Connection ~ 6600 2300
Connection ~ 6150 2300
Wire Wire Line
	6150 2300 6150 2250
$Comp
L power:GND #PWR024
U 1 1 5EE9175C
P 9500 2300
F 0 "#PWR024" H 9500 2050 50  0001 C CNN
F 1 "GND" H 9500 2150 50  0000 C CNN
F 2 "" H 9500 2300 50  0001 C CNN
F 3 "" H 9500 2300 50  0001 C CNN
	1    9500 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 2300 9500 2250
Wire Wire Line
	8850 2400 8850 1900
Wire Wire Line
	8850 1900 9050 1900
Wire Wire Line
	9500 1900 9500 1950
$Comp
L Device:Crystal Y1
U 1 1 5EE440C9
P 10100 6500
F 0 "Y1" V 10054 6631 50  0000 L CNN
F 1 "32.768kHz" V 10145 6631 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_3215-2Pin_3.2x1.5mm" H 10100 6500 50  0001 C CNN
F 3 "~" H 10100 6500 50  0001 C CNN
F 4 "ABS07-32.768KHZ-9-T" V 10100 6500 50  0001 C CNN "Field4"
	1    10100 6500
	0    1    1    0   
$EndComp
Wire Wire Line
	9900 6350 10000 6350
Wire Wire Line
	10000 6350 10000 6250
Wire Wire Line
	10000 6250 10100 6250
Wire Wire Line
	10100 6250 10100 6350
Wire Wire Line
	9900 6650 10000 6650
Wire Wire Line
	10000 6650 10000 6750
Wire Wire Line
	10000 6750 10100 6750
Wire Wire Line
	10100 6750 10100 6650
NoConn ~ 9900 6000
NoConn ~ 9900 5700
$Comp
L Device:C_Small C14
U 1 1 5EE4E312
P 10450 6250
F 0 "C14" V 10350 6250 50  0000 C CNN
F 1 "9pF" V 10550 6250 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 10450 6250 50  0001 C CNN
F 3 "~" H 10450 6250 50  0001 C CNN
F 4 "CBR06C909B5GAC" V 10450 6250 50  0001 C CNN "MPN"
	1    10450 6250
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C15
U 1 1 5EE4EDD6
P 10450 6750
F 0 "C15" V 10350 6750 50  0000 C CNN
F 1 "9pf" V 10550 6750 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 10450 6750 50  0001 C CNN
F 3 "~" H 10450 6750 50  0001 C CNN
F 4 "CBR06C909B5GAC" V 10450 6750 50  0001 C CNN "MPN"
	1    10450 6750
	0    1    1    0   
$EndComp
Wire Wire Line
	10350 6750 10100 6750
Connection ~ 10100 6750
Wire Wire Line
	10100 6250 10350 6250
Connection ~ 10100 6250
$Comp
L power:GND #PWR025
U 1 1 5EE53328
P 10750 6900
F 0 "#PWR025" H 10750 6650 50  0001 C CNN
F 1 "GND" H 10755 6727 50  0000 C CNN
F 2 "" H 10750 6900 50  0001 C CNN
F 3 "" H 10750 6900 50  0001 C CNN
	1    10750 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 6750 10750 6750
Wire Wire Line
	10750 6750 10750 6900
Wire Wire Line
	10550 6250 10750 6250
Wire Wire Line
	10750 6250 10750 6750
Connection ~ 10750 6750
Wire Wire Line
	8450 7200 8450 7300
Connection ~ 8450 7300
$Comp
L Device:C C13
U 1 1 5EE9116F
P 9500 2100
F 0 "C13" H 9615 2146 50  0000 L CNN
F 1 "0.1uF" H 9615 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9538 1950 50  0001 C CNN
F 3 "~" H 9500 2100 50  0001 C CNN
F 4 "885012207045" H 9500 2100 50  0001 C CNN "MPN"
	1    9500 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5EE5E4B2
P 9050 2100
F 0 "C12" H 9165 2146 50  0000 L CNN
F 1 "0.1uF" H 9165 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9088 1950 50  0001 C CNN
F 3 "~" H 9050 2100 50  0001 C CNN
F 4 "885012207045" H 9050 2100 50  0001 C CNN "MPN"
	1    9050 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 2250 9500 2250
Connection ~ 9500 2250
Wire Wire Line
	9050 1950 9050 1900
Connection ~ 9050 1900
Wire Wire Line
	9050 1900 9500 1900
Wire Wire Line
	8700 1900 8850 1900
Connection ~ 8850 1900
$Comp
L power:+3V3 #PWR023
U 1 1 5EE6AE4A
P 9500 1800
F 0 "#PWR023" H 9500 1650 50  0001 C CNN
F 1 "+3V3" H 9515 1973 50  0000 C CNN
F 2 "" H 9500 1800 50  0001 C CNN
F 3 "" H 9500 1800 50  0001 C CNN
	1    9500 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 1800 9500 1900
Connection ~ 9500 1900
$Comp
L Device:R R13
U 1 1 5EE6DC32
P 12150 3300
F 0 "R13" H 12220 3346 50  0000 L CNN
F 1 "470" H 12220 3255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 12080 3300 50  0001 C CNN
F 3 "~" H 12150 3300 50  0001 C CNN
F 4 "CRGCQ0805F470R" H 12150 3300 50  0001 C CNN "MPN"
	1    12150 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C16
U 1 1 5EE6DF21
P 12150 3700
F 0 "C16" H 12265 3746 50  0000 L CNN
F 1 "1000pF" H 12265 3655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 12188 3550 50  0001 C CNN
F 3 "~" H 12150 3700 50  0001 C CNN
F 4 "GCJ188R72A102KA01D" H 12150 3700 50  0001 C CNN "MPN"
	1    12150 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	12150 3550 12150 3500
Connection ~ 11300 3500
Connection ~ 12150 3500
Wire Wire Line
	12150 3500 12150 3450
$Comp
L power:GND #PWR028
U 1 1 5EE7A5D7
P 12150 3900
F 0 "#PWR028" H 12150 3650 50  0001 C CNN
F 1 "GND" H 12155 3727 50  0000 C CNN
F 2 "" H 12150 3900 50  0001 C CNN
F 3 "" H 12150 3900 50  0001 C CNN
	1    12150 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	12150 3900 12150 3850
$Comp
L power:+3V3 #PWR027
U 1 1 5EE7CF82
P 12150 3050
F 0 "#PWR027" H 12150 2900 50  0001 C CNN
F 1 "+3V3" H 12165 3223 50  0000 C CNN
F 2 "" H 12150 3050 50  0001 C CNN
F 3 "" H 12150 3050 50  0001 C CNN
	1    12150 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	12150 3050 12150 3150
$Comp
L Switch:SW_Push SW1
U 1 1 5EE80380
P 12650 3500
F 0 "SW1" H 12650 3785 50  0000 C CNN
F 1 "SW_Push" H 12650 3694 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_TL3305A" H 12650 3700 50  0001 C CNN
F 3 "~" H 12650 3700 50  0001 C CNN
F 4 "PTS810 SJS 250 SMTR LFS" H 12650 3500 50  0001 C CNN "MPN"
	1    12650 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	11300 3500 12150 3500
Wire Wire Line
	12150 3500 12450 3500
$Comp
L power:GND #PWR029
U 1 1 5EE88FAD
P 12900 3900
F 0 "#PWR029" H 12900 3650 50  0001 C CNN
F 1 "GND" H 12905 3727 50  0000 C CNN
F 2 "" H 12900 3900 50  0001 C CNN
F 3 "" H 12900 3900 50  0001 C CNN
	1    12900 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	12900 3900 12900 3500
Wire Wire Line
	12900 3500 12850 3500
Text GLabel 10100 4250 2    50   Input ~ 0
ESICH0
Text GLabel 10100 4350 2    50   Input ~ 0
ESICH1
Text GLabel 10100 4450 2    50   Input ~ 0
ESICH2
Text GLabel 10100 4550 2    50   Input ~ 0
ESICH3
Text GLabel 10100 4650 2    50   Input ~ 0
ESICI0
Text GLabel 10100 4750 2    50   Input ~ 0
ESICI1
Text GLabel 10100 4850 2    50   Input ~ 0
ESICI2
Text GLabel 10100 4950 2    50   Input ~ 0
ESICI3
Wire Wire Line
	10100 4950 9900 4950
Wire Wire Line
	9900 4850 10100 4850
Wire Wire Line
	10100 4750 9900 4750
Wire Wire Line
	9900 4650 10100 4650
Wire Wire Line
	10100 4550 9900 4550
Wire Wire Line
	9900 4450 10100 4450
Wire Wire Line
	10100 4350 9900 4350
Wire Wire Line
	9900 4250 10100 4250
Text GLabel 10150 5250 2    50   Input ~ 0
ESICI
Text GLabel 10150 5350 2    50   Input ~ 0
ESICOM
Wire Wire Line
	9900 5250 10150 5250
Wire Wire Line
	10150 5350 9900 5350
$Comp
L Jumper:SolderJumper_2_Bridged JP2
U 1 1 5EECAF59
P 8700 2200
F 0 "JP2" V 8600 2050 50  0000 L CNN
F 1 "SolderJumper_2_Bridged" V 8745 2268 50  0001 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged_RoundedPad1.0x1.5mm" H 8700 2200 50  0001 C CNN
F 3 "~" H 8700 2200 50  0001 C CNN
	1    8700 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	8700 2050 8700 1900
Wire Wire Line
	8700 2350 8700 2400
Wire Wire Line
	3900 3250 4350 3250
Wire Wire Line
	3900 3150 4250 3150
Wire Wire Line
	6650 3050 3900 3050
Wire Wire Line
	6650 3800 5050 3800
Wire Wire Line
	3900 3700 4950 3700
Wire Wire Line
	6650 3600 3900 3600
Wire Wire Line
	3900 4900 6650 4900
Wire Wire Line
	3900 4800 6650 4800
Text GLabel 6200 5600 0    50   Input ~ 0
PWM_TB0.3
Text GLabel 6200 5700 0    50   Input ~ 0
P2.5
Wire Wire Line
	6200 5700 6650 5700
Wire Wire Line
	6650 5600 6200 5600
Text GLabel 6200 5300 0    50   Input ~ 0
PWM_TA0.1
Text GLabel 6200 5400 0    50   Input ~ 0
P1.1
Wire Wire Line
	6200 5400 6650 5400
Wire Wire Line
	6650 5300 6200 5300
Text HLabel 3900 4050 0    50   Output ~ 0
DEBUG_TX
Wire Wire Line
	3900 4050 6650 4050
Text HLabel 3900 4150 0    50   Input ~ 0
DEBUG_RX
Wire Wire Line
	3900 4150 6650 4150
Text HLabel 3900 4250 0    50   Output ~ 0
DEBUG_LED_1
Text HLabel 3900 4350 0    50   Output ~ 0
DEBUG_LED_2
Wire Wire Line
	3900 4250 6650 4250
Wire Wire Line
	6650 4350 3900 4350
Text GLabel 6200 5900 0    50   BiDi ~ 0
P4.0
Text GLabel 6200 6000 0    50   BiDi ~ 0
P4.1
Text GLabel 6200 6100 0    50   BiDi ~ 0
P4.2
Text GLabel 6200 6200 0    50   BiDi ~ 0
P4.3
Wire Wire Line
	6650 5900 6200 5900
Wire Wire Line
	6200 6000 6650 6000
Wire Wire Line
	6650 6100 6200 6100
Wire Wire Line
	6200 6200 6650 6200
Text GLabel 6200 6300 0    50   BiDi ~ 0
P5.0
Text GLabel 6200 6400 0    50   BiDi ~ 0
P5.1
Text GLabel 6200 6500 0    50   BiDi ~ 0
P5.2
Wire Wire Line
	6200 6500 6650 6500
Wire Wire Line
	6650 6400 6200 6400
Wire Wire Line
	6200 6300 6650 6300
Text GLabel 14750 3900 0    50   BiDi ~ 0
P4.2
Wire Wire Line
	14750 3900 15050 3900
Text GLabel 14750 4000 0    50   BiDi ~ 0
P4.3
Wire Wire Line
	14750 4000 15050 4000
Text GLabel 14750 4100 0    50   BiDi ~ 0
P5.0
Wire Wire Line
	14750 4100 15050 4100
Text GLabel 6200 5500 0    50   UnSpc ~ 0
ADC2
Wire Wire Line
	6200 5500 6650 5500
Wire Wire Line
	13850 4350 13950 4350
Connection ~ 13950 4350
Wire Wire Line
	13950 3800 13950 4350
Wire Wire Line
	13950 3800 15050 3800
Text GLabel 13700 5050 0    50   Input ~ 0
PWM_TA0.1
Wire Wire Line
	13700 5050 13850 5050
Wire Wire Line
	13850 5050 13850 4950
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J4
U 1 1 5EFC98B3
P 13850 4750
F 0 "J4" V 13946 4562 50  0000 R CNN
F 1 "Conn_02x02_Odd_Even" V 13855 4562 50  0000 R CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x02_P2.00mm_Vertical" H 13850 4750 50  0001 C CNN
F 3 "~" H 13850 4750 50  0001 C CNN
	1    13850 4750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	13950 4350 13950 4450
Wire Wire Line
	13850 4350 13850 4450
Text GLabel 14100 5050 2    50   Input ~ 0
PWM_TB0.3
Wire Wire Line
	14100 5050 13950 5050
Wire Wire Line
	13950 5050 13950 4950
Text Notes 13750 4850 2    50   ~ 0
Jumper Select:\nTA0 [P1 + P2]\nTB0 [P3 + P4]\n1 ONLY!!
Text GLabel 14750 4200 0    50   UnSpc ~ 0
ADC2
Wire Wire Line
	14750 4200 15050 4200
Text GLabel 14750 4300 0    50   BiDi ~ 0
P5.1
Wire Wire Line
	14750 4300 15050 4300
Text GLabel 12250 7950 0    50   Input ~ 0
ESICH0
Text GLabel 12250 8050 0    50   Input ~ 0
ESICH1
Text GLabel 12250 8150 0    50   Input ~ 0
ESICH2
Text GLabel 12250 8250 0    50   Input ~ 0
ESICH3
Text GLabel 13300 7950 2    50   Input ~ 0
ESICI0
Text GLabel 13300 8050 2    50   Input ~ 0
ESICI1
Text GLabel 13300 8150 2    50   Input ~ 0
ESICI2
Text GLabel 13300 8250 2    50   Input ~ 0
ESICI3
$Comp
L Connector_Generic:Conn_02x06_Odd_Even J6
U 1 1 5F0F003E
P 12700 8050
F 0 "J6" H 12750 8350 50  0000 C CNN
F 1 "Conn_02x06_Odd_Even" H 12750 7650 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x06_P2.00mm_Vertical" H 12700 8050 50  0001 C CNN
F 3 "~" H 12700 8050 50  0001 C CNN
	1    12700 8050
	1    0    0    -1  
$EndComp
Text GLabel 12250 8350 0    50   Input ~ 0
ESICI
Text GLabel 13300 8350 2    50   Input ~ 0
ESICOM
Wire Wire Line
	13300 8350 13000 8350
Wire Wire Line
	13000 8250 13300 8250
Wire Wire Line
	13300 8150 13000 8150
Wire Wire Line
	13000 8050 13300 8050
Wire Wire Line
	13300 7950 13000 7950
Wire Wire Line
	12500 7950 12250 7950
Wire Wire Line
	12250 8050 12500 8050
Wire Wire Line
	12500 8150 12250 8150
Wire Wire Line
	12250 8250 12500 8250
Wire Wire Line
	12250 8350 12500 8350
$Comp
L power:GND #PWR031
U 1 1 5F139610
P 13450 7650
F 0 "#PWR031" H 13450 7400 50  0001 C CNN
F 1 "GND" H 13455 7477 50  0000 C CNN
F 2 "" H 13450 7650 50  0001 C CNN
F 3 "" H 13450 7650 50  0001 C CNN
	1    13450 7650
	1    0    0    -1  
$EndComp
Wire Wire Line
	13000 7850 13100 7850
Wire Wire Line
	13100 7850 13100 7550
Wire Wire Line
	13100 7550 13450 7550
Wire Wire Line
	13450 7550 13450 7650
$Comp
L power:+3V3 #PWR030
U 1 1 5F141006
P 12250 7700
F 0 "#PWR030" H 12250 7550 50  0001 C CNN
F 1 "+3V3" H 12265 7873 50  0000 C CNN
F 2 "" H 12250 7700 50  0001 C CNN
F 3 "" H 12250 7700 50  0001 C CNN
	1    12250 7700
	1    0    0    -1  
$EndComp
Wire Wire Line
	12250 7700 12250 7850
Wire Wire Line
	12250 7850 12500 7850
Text HLabel 15000 6400 2    50   Input ~ 0
ENCODER_CH_A
Text HLabel 15000 6500 2    50   Input ~ 0
ENCODER_CH_B
Text GLabel 13850 6150 0    50   Input ~ 0
ESICI0
Text GLabel 13850 6650 0    50   Input ~ 0
ESICI1
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J7
U 1 1 5F17BAA5
P 14200 6150
F 0 "J7" H 14250 6250 50  0000 C CNN
F 1 "Conn_02x02_Odd_Even" H 14250 5950 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x02_P2.00mm_Vertical" H 14200 6150 50  0001 C CNN
F 3 "~" H 14200 6150 50  0001 C CNN
	1    14200 6150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J8
U 1 1 5F17C61B
P 14200 6650
F 0 "J8" H 14250 6750 50  0000 C CNN
F 1 "Conn_02x02_Odd_Even" H 14250 6450 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x02_P2.00mm_Vertical" H 14200 6650 50  0001 C CNN
F 3 "~" H 14200 6650 50  0001 C CNN
	1    14200 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	14500 6150 14600 6150
Wire Wire Line
	14600 6150 14600 6200
Wire Wire Line
	14600 6250 14500 6250
Wire Wire Line
	14500 6650 14600 6650
Wire Wire Line
	14600 6650 14600 6700
Wire Wire Line
	14600 6750 14500 6750
Wire Wire Line
	14600 6700 14700 6700
Wire Wire Line
	14700 6700 14700 6500
Wire Wire Line
	14700 6500 15000 6500
Connection ~ 14600 6700
Wire Wire Line
	14600 6700 14600 6750
Wire Wire Line
	15000 6400 14700 6400
Wire Wire Line
	14700 6400 14700 6200
Wire Wire Line
	14700 6200 14600 6200
Connection ~ 14600 6200
Wire Wire Line
	14600 6200 14600 6250
Wire Wire Line
	14000 6650 13850 6650
Wire Wire Line
	14000 6150 13850 6150
Text GLabel 13850 6250 0    50   Input ~ 0
P1.1
Wire Wire Line
	13850 6250 14000 6250
Text GLabel 13850 6750 0    50   Input ~ 0
P2.5
Wire Wire Line
	13850 6750 14000 6750
Text GLabel 4350 5550 2    50   Input ~ 0
P2.5
Wire Wire Line
	3900 5550 4350 5550
Wire Wire Line
	9900 3500 11300 3500
$Comp
L Device:R_Pack02 RN1
U 1 1 5EEA03AB
P 4350 2450
F 0 "RN1" H 4438 2496 50  0000 L CNN
F 1 "R_Pack02" H 4438 2405 50  0000 L CNN
F 2 "Resistor_SMD:R_Array_Concave_2x0603" V 4525 2450 50  0001 C CNN
F 3 "~" H 4350 2450 50  0001 C CNN
F 4 "EXB-V4V472JV" H 4350 2450 50  0001 C CNN "MPN"
	1    4350 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Pack02 RN2
U 1 1 5EEA12D1
P 5050 2450
F 0 "RN2" H 5138 2496 50  0000 L CNN
F 1 "R_Pack02" H 5138 2405 50  0000 L CNN
F 2 "Resistor_SMD:R_Array_Concave_2x0603" V 5225 2450 50  0001 C CNN
F 3 "~" H 5050 2450 50  0001 C CNN
F 4 "EXB-V4V472JV" H 5050 2450 50  0001 C CNN "MPN"
	1    5050 2450
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR059
U 1 1 5EEA1A6A
P 4250 2100
F 0 "#PWR059" H 4250 1950 50  0001 C CNN
F 1 "+3V3" H 4265 2273 50  0000 C CNN
F 2 "" H 4250 2100 50  0001 C CNN
F 3 "" H 4250 2100 50  0001 C CNN
	1    4250 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2100 4250 2150
Wire Wire Line
	4350 2250 4350 2150
Wire Wire Line
	4350 2150 4250 2150
Connection ~ 4250 2150
Wire Wire Line
	4250 2150 4250 2250
Wire Wire Line
	4350 2150 4950 2150
Wire Wire Line
	5050 2150 5050 2250
Connection ~ 4350 2150
Wire Wire Line
	4950 2250 4950 2150
Connection ~ 4950 2150
Wire Wire Line
	4950 2150 5050 2150
Wire Wire Line
	4250 2650 4250 3150
Wire Wire Line
	4350 2650 4350 3250
Connection ~ 4350 3250
Wire Wire Line
	4350 3250 6650 3250
Wire Wire Line
	4950 2650 4950 3700
Connection ~ 4950 3700
Wire Wire Line
	4950 3700 6650 3700
Wire Wire Line
	5050 2650 5050 3800
Connection ~ 5050 3800
Wire Wire Line
	5050 3800 3900 3800
Text GLabel 7250 8750 0    50   BiDi ~ 0
P4.0
Text GLabel 7250 8850 0    50   BiDi ~ 0
P4.1
Text GLabel 7250 8950 0    50   BiDi ~ 0
P5.2
Text GLabel 6500 2950 0    50   BiDi ~ 0
P1.4
Wire Wire Line
	6500 2950 6650 2950
Text GLabel 6500 3500 0    50   BiDi ~ 0
P5.3
Wire Wire Line
	6500 3500 6650 3500
Text GLabel 7250 9050 0    50   BiDi ~ 0
P5.3
Text GLabel 6500 8750 0    50   BiDi ~ 0
P1.4
Text GLabel 10150 3950 2    50   BiDi ~ 0
P2.6
Text GLabel 10150 4050 2    50   BiDi ~ 0
P2.7
Text GLabel 10150 4150 2    50   BiDi ~ 0
P1.3
Wire Wire Line
	10150 4150 9900 4150
Wire Wire Line
	9900 4050 10150 4050
Wire Wire Line
	10150 3950 9900 3950
Text GLabel 6500 9050 0    50   BiDi ~ 0
P2.6
Text GLabel 6500 9150 0    50   BiDi ~ 0
P2.7
Text GLabel 6500 8650 0    50   BiDi ~ 0
P1.3
Text GLabel 6450 4700 0    50   BiDi ~ 0
P2.2
Text GLabel 6450 4600 0    50   BiDi ~ 0
P2.3
Wire Wire Line
	6650 4600 6450 4600
Wire Wire Line
	6650 4700 6450 4700
Text GLabel 6500 8850 0    50   BiDi ~ 0
P2.2
Text GLabel 6500 8950 0    50   BiDi ~ 0
P2.3
Text GLabel 6200 5800 0    50   BiDi ~ 0
P3.3
Wire Wire Line
	6650 5800 6200 5800
Text GLabel 7250 8650 0    50   BiDi ~ 0
P3.3
NoConn ~ 6500 8650
NoConn ~ 6500 8750
NoConn ~ 6500 8850
NoConn ~ 6500 8950
NoConn ~ 6500 9050
NoConn ~ 6500 9150
NoConn ~ 7250 9050
NoConn ~ 7250 8950
NoConn ~ 7250 8850
NoConn ~ 7250 8750
NoConn ~ 7250 8650
Text Notes 6400 8450 0    100  ~ 0
Unused Nets
$Comp
L power:PWR_FLAG #FLG0106
U 1 1 5F032956
P 8450 1750
F 0 "#FLG0106" H 8450 1825 50  0001 C CNN
F 1 "PWR_FLAG" H 8450 1923 50  0000 C CNN
F 2 "" H 8450 1750 50  0001 C CNN
F 3 "~" H 8450 1750 50  0001 C CNN
	1    8450 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 1750 8450 2350
Wire Wire Line
	8450 2350 8700 2350
Connection ~ 8700 2350
$Comp
L power:PWR_FLAG #FLG0107
U 1 1 5F03FA58
P 8950 7250
F 0 "#FLG0107" H 8950 7325 50  0001 C CNN
F 1 "PWR_FLAG" H 8950 7423 50  0000 C CNN
F 2 "" H 8950 7250 50  0001 C CNN
F 3 "~" H 8950 7250 50  0001 C CNN
	1    8950 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 7250 8950 7300
Wire Wire Line
	8950 7300 8750 7300
Connection ~ 8750 7300
Wire Wire Line
	11700 3100 11700 2600
Wire Wire Line
	11700 3200 11700 3100
Connection ~ 11700 3100
Connection ~ 11400 3100
Wire Wire Line
	11400 3100 11700 3100
$EndSCHEMATC
