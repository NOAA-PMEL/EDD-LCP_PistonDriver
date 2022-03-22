EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 11
Title ""
Date "2020-06-17"
Rev "R0.1"
Comp ""
Comment1 "Design by: Matt Casari"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 1800 5150 0    50   Input ~ 0
12V_ENABLE
$Comp
L PMEL_PowerICs:LMR50410 U4
U 1 1 5EF38167
P 5200 1950
F 0 "U4" H 5175 2315 50  0000 C CNN
F 1 "BD9G102G-LB" H 5175 2224 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 5150 1650 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/lmr50410.pdf?ts=1591402847494&ref_url=https://www.ti.com/product/LMR50410" H 5050 2100 50  0001 C CNN
F 4 "BD9G102G-LB" H 5200 1950 50  0001 C CNN "MPN"
	1    5200 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR056
U 1 1 5EF38EC6
P 8600 1600
F 0 "#PWR056" H 8600 1450 50  0001 C CNN
F 1 "+3V3" H 8615 1773 50  0000 C CNN
F 2 "" H 8600 1600 50  0001 C CNN
F 3 "" H 8600 1600 50  0001 C CNN
	1    8600 1600
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR046
U 1 1 5EF39847
P 3200 1550
F 0 "#PWR046" H 3200 1400 50  0001 C CNN
F 1 "+BATT" H 3215 1723 50  0000 C CNN
F 2 "" H 3200 1550 50  0001 C CNN
F 3 "" H 3200 1550 50  0001 C CNN
	1    3200 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C19
U 1 1 5EF3A56E
P 3300 2100
F 0 "C19" H 3415 2146 50  0000 L CNN
F 1 "1uF" H 3415 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3338 1950 50  0001 C CNN
F 3 "~" H 3300 2100 50  0001 C CNN
F 4 "C1608X5R1H105K080AB" H 3300 2100 50  0001 C CNN "MPN"
	1    3300 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C21
U 1 1 5EF3B4D1
P 3650 2100
F 0 "C21" H 3765 2146 50  0000 L CNN
F 1 "0.1uF" H 3765 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3688 1950 50  0001 C CNN
F 3 "~" H 3650 2100 50  0001 C CNN
F 4 "GCM188R71H104KA57J" H 3650 2100 50  0001 C CNN "MPN"
	1    3650 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C26
U 1 1 5EF3B84D
P 6150 2050
F 0 "C26" H 6265 2096 50  0000 L CNN
F 1 "0.1uF" H 6265 2005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6265 1959 50  0001 L CNN
F 3 "~" H 6150 2050 50  0001 C CNN
F 4 "GRM155R71A104KA01D" H 6150 2050 50  0001 C CNN "MPN"
	1    6150 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C28
U 1 1 5EF3C1D4
P 7750 2050
F 0 "C28" H 7865 2096 50  0000 L CNN
F 1 "10uF" H 7865 2005 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 7788 1900 50  0001 C CNN
F 3 "~" H 7750 2050 50  0001 C CNN
F 4 "CL31B106KPHVPNE" H 7750 2050 50  0001 C CNN "MPN"
	1    7750 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C29
U 1 1 5EF3C643
P 8150 2050
F 0 "C29" H 8265 2096 50  0000 L CNN
F 1 "10uF" H 8265 2005 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 8188 1900 50  0001 C CNN
F 3 "~" H 8150 2050 50  0001 C CNN
F 4 "CL31B106KPHVPNE" H 8150 2050 50  0001 C CNN "MPN"
	1    8150 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 1850 6150 1850
Wire Wire Line
	6150 1850 6150 1900
Wire Wire Line
	5500 1950 5850 1950
Wire Wire Line
	5850 1950 5850 2250
Wire Wire Line
	5850 2250 6150 2250
Wire Wire Line
	6150 2250 6150 2200
$Comp
L Device:L L1
U 1 1 5EF3E9E5
P 6950 1850
F 0 "L1" V 7140 1850 50  0000 C CNN
F 1 "12uH" V 7049 1850 50  0000 C CNN
F 2 "Inductor_SMD:L_Bourns-SRN8040_8x8.15mm" H 6950 1850 50  0001 C CNN
F 3 "~" H 6950 1850 50  0001 C CNN
F 4 "SDR0805-120ML" H 6950 1850 50  0001 C CNN "MPN"
	1    6950 1850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6800 1850 6550 1850
Connection ~ 6150 1850
Wire Wire Line
	8150 1850 8150 1900
Wire Wire Line
	7750 1900 7750 1850
Connection ~ 7750 1850
Wire Wire Line
	7750 1850 8150 1850
$Comp
L power:GND #PWR051
U 1 1 5EF3F866
P 5200 2450
F 0 "#PWR051" H 5200 2200 50  0001 C CNN
F 1 "GND" H 5205 2277 50  0000 C CNN
F 2 "" H 5200 2450 50  0001 C CNN
F 3 "" H 5200 2450 50  0001 C CNN
	1    5200 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR054
U 1 1 5EF3FD44
P 7750 2400
F 0 "#PWR054" H 7750 2150 50  0001 C CNN
F 1 "GND" H 7755 2227 50  0000 C CNN
F 2 "" H 7750 2400 50  0001 C CNN
F 3 "" H 7750 2400 50  0001 C CNN
	1    7750 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 2400 7750 2300
Wire Wire Line
	7750 2300 8150 2300
Wire Wire Line
	8150 2300 8150 2200
Connection ~ 7750 2300
Wire Wire Line
	7750 2300 7750 2200
Wire Wire Line
	8150 1850 8600 1850
Wire Wire Line
	8600 1850 8600 1600
Connection ~ 8150 1850
Wire Wire Line
	7100 1850 7250 1850
$Comp
L Device:R R16
U 1 1 5EF42F65
P 7250 2150
F 0 "R16" H 7320 2196 50  0000 L CNN
F 1 "51k" H 7320 2105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7180 2150 50  0001 C CNN
F 3 "~" H 7250 2150 50  0001 C CNN
F 4 "RC0603FR-0751KL" H 7250 2150 50  0001 C CNN "MPN"
	1    7250 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R17
U 1 1 5EF433B6
P 7250 2900
F 0 "R17" H 7320 2946 50  0000 L CNN
F 1 "15k" H 7320 2855 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7180 2900 50  0001 C CNN
F 3 "~" H 7250 2900 50  0001 C CNN
F 4 "RC0402JR-0715KL" H 7250 2900 50  0001 C CNN "MPN"
	1    7250 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR053
U 1 1 5EF43697
P 7250 3150
F 0 "#PWR053" H 7250 2900 50  0001 C CNN
F 1 "GND" H 7255 2977 50  0000 C CNN
F 2 "" H 7250 3150 50  0001 C CNN
F 3 "" H 7250 3150 50  0001 C CNN
	1    7250 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3050 7250 3150
Wire Wire Line
	7250 2000 7250 1850
Connection ~ 7250 1850
Wire Wire Line
	7250 1850 7450 1850
Wire Wire Line
	4850 1850 4600 1850
Wire Wire Line
	3200 1850 3200 1550
Connection ~ 3300 1850
Wire Wire Line
	3300 1850 3200 1850
Wire Wire Line
	3300 1850 3300 1950
Wire Wire Line
	3650 1950 3650 1850
Connection ~ 3650 1850
Wire Wire Line
	3650 1850 3300 1850
Wire Wire Line
	5200 2450 5200 2300
$Comp
L power:GND #PWR047
U 1 1 5EF475D1
P 3500 2500
F 0 "#PWR047" H 3500 2250 50  0001 C CNN
F 1 "GND" H 3505 2327 50  0000 C CNN
F 2 "" H 3500 2500 50  0001 C CNN
F 3 "" H 3500 2500 50  0001 C CNN
	1    3500 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2500 3500 2400
Wire Wire Line
	3500 2400 3650 2400
Wire Wire Line
	3650 2400 3650 2250
Wire Wire Line
	3300 2250 3300 2400
Wire Wire Line
	3300 2400 3500 2400
Connection ~ 3500 2400
Wire Wire Line
	4850 1950 4600 1950
Wire Wire Line
	4600 1950 4600 1850
Connection ~ 4600 1850
Wire Wire Line
	4600 1850 3650 1850
Text Notes 5300 1100 0    100  ~ 0
3V3 Regulator
Text Notes 5300 3850 0    100  ~ 0
12V Regulator
$Comp
L Connector:TestPoint TP?
U 1 1 5EE966A4
P 1000 6450
AR Path="/5EE2A7AF/5EE966A4" Ref="TP?"  Part="1" 
AR Path="/5EE4388C/5EE966A4" Ref="TP7"  Part="1" 
F 0 "TP7" H 1058 6568 50  0000 L CNN
F 1 "TestPoint" H 1058 6477 50  0000 L CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 1200 6450 50  0001 C CNN
F 3 "~" H 1200 6450 50  0001 C CNN
F 4 "" H 1000 6450 50  0001 C CNN "MPN"
	1    1000 6450
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP13
U 1 1 5EE9710E
P 2000 5050
F 0 "TP13" H 2058 5168 50  0000 L CNN
F 1 "TestPoint" H 2058 5077 50  0000 L CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 2200 5050 50  0001 C CNN
F 3 "~" H 2200 5050 50  0001 C CNN
F 4 "" H 2000 5050 50  0001 C CNN "MPN"
	1    2000 5050
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP?
U 1 1 5EE97C87
P 1500 6450
AR Path="/5EE2A7AF/5EE97C87" Ref="TP?"  Part="1" 
AR Path="/5EE4388C/5EE97C87" Ref="TP9"  Part="1" 
F 0 "TP9" H 1558 6568 50  0000 L CNN
F 1 "TestPoint" H 1558 6477 50  0000 L CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 1700 6450 50  0001 C CNN
F 3 "~" H 1700 6450 50  0001 C CNN
F 4 "" H 1500 6450 50  0001 C CNN "MPN"
	1    1500 6450
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP?
U 1 1 5EE98832
P 1950 6450
AR Path="/5EE2A7AF/5EE98832" Ref="TP?"  Part="1" 
AR Path="/5EE4388C/5EE98832" Ref="TP11"  Part="1" 
F 0 "TP11" H 2008 6568 50  0000 L CNN
F 1 "TestPoint" H 2008 6477 50  0000 L CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 2150 6450 50  0001 C CNN
F 3 "~" H 2150 6450 50  0001 C CNN
F 4 "" H 1950 6450 50  0001 C CNN "MPN"
	1    1950 6450
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP8
U 1 1 5EE9A555
P 1000 7200
F 0 "TP8" H 1058 7318 50  0000 L CNN
F 1 "TestPoint" H 1058 7227 50  0000 L CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 1200 7200 50  0001 C CNN
F 3 "~" H 1200 7200 50  0001 C CNN
F 4 "" H 1000 7200 50  0001 C CNN "MPN"
	1    1000 7200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR037
U 1 1 5EE9D7F2
P 1000 7350
F 0 "#PWR037" H 1000 7100 50  0001 C CNN
F 1 "GND" H 1005 7177 50  0000 C CNN
F 2 "" H 1000 7350 50  0001 C CNN
F 3 "" H 1000 7350 50  0001 C CNN
	1    1000 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 7200 1000 7350
$Comp
L power:+12V #PWR041
U 1 1 5EEA1BA0
P 1650 6700
F 0 "#PWR041" H 1650 6550 50  0001 C CNN
F 1 "+12V" H 1665 6873 50  0000 C CNN
F 2 "" H 1650 6700 50  0001 C CNN
F 3 "" H 1650 6700 50  0001 C CNN
	1    1650 6700
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR038
U 1 1 5EEA2081
P 1150 6700
F 0 "#PWR038" H 1150 6550 50  0001 C CNN
F 1 "+BATT" H 1165 6873 50  0000 C CNN
F 2 "" H 1150 6700 50  0001 C CNN
F 3 "" H 1150 6700 50  0001 C CNN
	1    1150 6700
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR043
U 1 1 5EEA399F
P 2100 6700
F 0 "#PWR043" H 2100 6550 50  0001 C CNN
F 1 "+3V3" H 2115 6873 50  0000 C CNN
F 2 "" H 2100 6700 50  0001 C CNN
F 3 "" H 2100 6700 50  0001 C CNN
	1    2100 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 6450 1000 6800
Wire Wire Line
	1000 6800 1150 6800
Wire Wire Line
	1150 6800 1150 6700
Wire Wire Line
	1500 6450 1500 6800
Wire Wire Line
	1500 6800 1650 6800
Wire Wire Line
	1650 6800 1650 6700
Wire Wire Line
	1950 6450 1950 6800
Wire Wire Line
	1950 6800 2100 6800
Wire Wire Line
	2100 6800 2100 6700
$Comp
L Device:L L2
U 1 1 5EEB68B5
P 7000 5050
F 0 "L2" V 7190 5050 50  0000 C CNN
F 1 "10uH" V 7099 5050 50  0000 C CNN
F 2 "Inductor_SMD:L_Coilcraft_XAL1010" H 7000 5050 50  0001 C CNN
F 3 "http://www.coilcraft.com/pdfs/xal1010.pdf" H 7000 5050 50  0001 C CNN
F 4 "XAL1010-103MEB" V 7000 5050 50  0001 C CNN "MPN"
	1    7000 5050
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C18
U 1 1 5EEB7A3A
P 3050 4250
F 0 "C18" H 3165 4296 50  0000 L CNN
F 1 "10uF" H 3165 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric" H 3088 4100 50  0001 C CNN
F 3 "~" H 3050 4250 50  0001 C CNN
F 4 "CL32B106KMVNNWE" H 3050 4250 50  0001 C CNN "MPN"
	1    3050 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C24
U 1 1 5EEB80D6
P 4600 5450
F 0 "C24" H 4715 5496 50  0000 L CNN
F 1 "1.0uF" H 4715 5405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4638 5300 50  0001 C CNN
F 3 "~" H 4600 5450 50  0001 C CNN
F 4 "CL10B105KP8NNNC" H 4600 5450 50  0001 C CNN "MPN"
	1    4600 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C30
U 1 1 5EEB894F
P 9200 5300
F 0 "C30" H 9315 5346 50  0000 L CNN
F 1 "DNP" H 9315 5255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9238 5150 50  0001 C CNN
F 3 "~" H 9200 5300 50  0001 C CNN
	1    9200 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C27
U 1 1 5EEB9788
P 6750 4700
F 0 "C27" H 6865 4746 50  0000 L CNN
F 1 "0.1uF" H 6865 4655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6788 4550 50  0001 C CNN
F 3 "~" H 6750 4700 50  0001 C CNN
F 4 "GRM155R71A104KA01D" H 6750 4700 50  0001 C CNN "MPN"
	1    6750 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C22
U 1 1 5EEB9AFB
P 4000 4250
F 0 "C22" H 4115 4296 50  0000 L CNN
F 1 "0.22uF" H 4115 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4038 4100 50  0001 C CNN
F 3 "~" H 4000 4250 50  0001 C CNN
F 4 "C1608X7R1H224K080AE" H 4000 4250 50  0001 C CNN "MPN"
	1    4000 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C23
U 1 1 5EEBA106
P 4500 4250
F 0 "C23" H 4615 4296 50  0000 L CNN
F 1 "10uF" H 4615 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric" H 4538 4100 50  0001 C CNN
F 3 "~" H 4500 4250 50  0001 C CNN
F 4 "CL32B106KMVNNWE" H 4500 4250 50  0001 C CNN "MPN"
	1    4500 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R14
U 1 1 5EEBA5DD
P 4100 5450
F 0 "R14" H 4170 5496 50  0000 L CNN
F 1 "26.7k" H 4170 5405 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4030 5450 50  0001 C CNN
F 3 "~" H 4100 5450 50  0001 C CNN
F 4 "RC0402FR-0726K7L" H 4100 5450 50  0001 C CNN "MPN"
	1    4100 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R18
U 1 1 5EEBB24E
P 8500 5300
F 0 "R18" H 8430 5254 50  0000 R CNN
F 1 "100k" H 8430 5345 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8430 5300 50  0001 C CNN
F 3 "~" H 8500 5300 50  0001 C CNN
F 4 "RMCF0402FT100K" H 8500 5300 50  0001 C CNN "MPN"
	1    8500 5300
	-1   0    0    1   
$EndComp
$Comp
L Device:R R19
U 1 1 5EEBB6EF
P 8500 5700
F 0 "R19" H 8430 5654 50  0000 R CNN
F 1 "9.09k" H 8430 5745 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8430 5700 50  0001 C CNN
F 3 "~" H 8500 5700 50  0001 C CNN
F 4 "RT0402BRD079K09L" H 8500 5700 50  0001 C CNN "MPN"
	1    8500 5700
	-1   0    0    1   
$EndComp
$Comp
L Device:R R20
U 1 1 5EEBBB45
P 8900 5500
F 0 "R20" V 9107 5500 50  0000 C CNN
F 1 "1k" V 9016 5500 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8830 5500 50  0001 C CNN
F 3 "~" H 8900 5500 50  0001 C CNN
F 4 "PFR05S-102-FNH" V 8900 5500 50  0001 C CNN "MPN"
	1    8900 5500
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C31
U 1 1 5EEBE39D
P 9700 5300
F 0 "C31" H 9815 5346 50  0000 L CNN
F 1 "10uF" H 9815 5255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 9738 5150 50  0001 C CNN
F 3 "~" H 9700 5300 50  0001 C CNN
F 4 "GRM21BR61E106KA73L" H 9700 5300 50  0001 C CNN "MPN"
	1    9700 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C25
U 1 1 5EEC3BDB
P 4900 4250
F 0 "C25" H 5015 4296 50  0000 L CNN
F 1 "10uF" H 5015 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric" H 4938 4100 50  0001 C CNN
F 3 "~" H 4900 4250 50  0001 C CNN
F 4 "CL32B106KMVNNWE" H 4900 4250 50  0001 C CNN "MPN"
	1    4900 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5EEC4098
P 2650 4250
F 0 "C17" H 2765 4296 50  0000 L CNN
F 1 "10uF" H 2765 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric" H 2688 4100 50  0001 C CNN
F 3 "~" H 2650 4250 50  0001 C CNN
F 4 "CL32B106KMVNNWE" H 2650 4250 50  0001 C CNN "MPN"
	1    2650 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C20
U 1 1 5EEC496A
P 3500 4250
F 0 "C20" H 3615 4296 50  0000 L CNN
F 1 "0.22uF" H 3615 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3538 4100 50  0001 C CNN
F 3 "~" H 3500 4250 50  0001 C CNN
F 4 "C1608X7R1H224K080AE" H 3500 4250 50  0001 C CNN "MPN"
	1    3500 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 5550 8500 5500
Wire Wire Line
	8750 5500 8500 5500
Connection ~ 8500 5500
Wire Wire Line
	8500 5500 8500 5450
$Comp
L Device:R R15
U 1 1 5EECB7BB
P 5800 6400
F 0 "R15" V 6007 6400 50  0000 C CNN
F 1 "100k" V 5916 6400 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5730 6400 50  0001 C CNN
F 3 "~" H 5800 6400 50  0001 C CNN
F 4 "RMCF0402FT100K" H 5800 6400 50  0001 C CNN "MPN"
	1    5800 6400
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C32
U 1 1 5EECE2ED
P 10100 5300
F 0 "C32" H 10215 5346 50  0000 L CNN
F 1 "10uF" H 10215 5255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 10138 5150 50  0001 C CNN
F 3 "~" H 10100 5300 50  0001 C CNN
F 4 "GRM21BR61E106KA73L" H 10100 5300 50  0001 C CNN "MPN"
	1    10100 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C33
U 1 1 5EECE52E
P 10500 5300
F 0 "C33" H 10615 5346 50  0000 L CNN
F 1 "10uF" H 10615 5255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 10538 5150 50  0001 C CNN
F 3 "~" H 10500 5300 50  0001 C CNN
F 4 "GRM21BR61E106KA73L" H 10500 5300 50  0001 C CNN "MPN"
	1    10500 5300
	1    0    0    -1  
$EndComp
$Comp
L PMEL_PowerICs:LM61460 U5
U 1 1 5EED6C93
P 5800 5200
F 0 "U5" H 6050 6000 50  0000 C CNN
F 1 "LM61460" H 5500 6000 50  0000 C CNN
F 2 "Converter_DCDC:TI_RJR0014A" H 5200 6400 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/lm61460-q1.pdf?ts=1592411830672&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FLM61460-Q1" H 5200 6400 50  0001 C CNN
F 4 "LMQ61460AFSQRJRRQ1" H 5800 5200 50  0001 C CNN "MPN"
	1    5800 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR052
U 1 1 5EEDFD49
P 5800 5800
F 0 "#PWR052" H 5800 5550 50  0001 C CNN
F 1 "GND" H 5805 5627 50  0000 C CNN
F 2 "" H 5800 5800 50  0001 C CNN
F 3 "" H 5800 5800 50  0001 C CNN
	1    5800 5800
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR048
U 1 1 5EEEEBF6
P 3750 4500
F 0 "#PWR048" H 3750 4250 50  0001 C CNN
F 1 "GND" H 3755 4327 50  0000 C CNN
F 2 "" H 3750 4500 50  0001 C CNN
F 3 "" H 3750 4500 50  0001 C CNN
	1    3750 4500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3500 4400 3500 4450
Wire Wire Line
	3500 4450 3750 4450
Wire Wire Line
	4900 4450 4900 4400
Wire Wire Line
	3750 4500 3750 4450
Connection ~ 3750 4450
Wire Wire Line
	3750 4450 4000 4450
Wire Wire Line
	4000 4400 4000 4450
Connection ~ 4000 4450
Wire Wire Line
	4500 4400 4500 4450
Connection ~ 4500 4450
Wire Wire Line
	4500 4450 4900 4450
Wire Wire Line
	3500 4100 3500 4050
Wire Wire Line
	3500 4050 4000 4050
Wire Wire Line
	4900 4050 4900 4100
Wire Wire Line
	4500 4050 4500 4100
Connection ~ 4500 4050
Wire Wire Line
	4500 4050 4900 4050
Wire Wire Line
	4500 4050 4000 4050
Wire Wire Line
	4000 4050 4000 4100
Connection ~ 4000 4050
Wire Wire Line
	5750 4050 5750 4350
Connection ~ 4900 4050
Wire Wire Line
	4900 4050 5750 4050
Connection ~ 5750 4050
Wire Wire Line
	5750 4050 5850 4050
Wire Wire Line
	5850 4050 5850 4350
Wire Wire Line
	5700 5700 5700 5750
Wire Wire Line
	5700 5750 5800 5750
Wire Wire Line
	5900 5750 5900 5700
Wire Wire Line
	5800 5800 5800 5750
Connection ~ 5800 5750
Wire Wire Line
	5800 5750 5900 5750
Wire Wire Line
	5800 5700 5800 5750
$Comp
L power:+BATT #PWR039
U 1 1 5EF0FFF9
P 2150 4000
F 0 "#PWR039" H 2150 3850 50  0001 C CNN
F 1 "+BATT" H 2165 4173 50  0000 C CNN
F 2 "" H 2150 4000 50  0001 C CNN
F 3 "" H 2150 4000 50  0001 C CNN
	1    2150 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 4000 2150 4050
Wire Wire Line
	2150 4050 2650 4050
Connection ~ 3500 4050
Wire Wire Line
	2650 4100 2650 4050
Connection ~ 2650 4050
Wire Wire Line
	2650 4050 3050 4050
Wire Wire Line
	3050 4050 3050 4100
Connection ~ 3050 4050
Wire Wire Line
	3050 4050 3500 4050
Wire Wire Line
	2650 4400 2650 4450
Wire Wire Line
	2650 4450 3050 4450
Connection ~ 3500 4450
Wire Wire Line
	3050 4400 3050 4450
Connection ~ 3050 4450
Wire Wire Line
	3050 4450 3500 4450
Wire Wire Line
	4000 4450 4500 4450
$Comp
L power:GND #PWR050
U 1 1 5EF29D45
P 4600 5800
F 0 "#PWR050" H 4600 5550 50  0001 C CNN
F 1 "GND" H 4605 5627 50  0000 C CNN
F 2 "" H 4600 5800 50  0001 C CNN
F 3 "" H 4600 5800 50  0001 C CNN
	1    4600 5800
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR049
U 1 1 5EF2A043
P 4100 5800
F 0 "#PWR049" H 4100 5550 50  0001 C CNN
F 1 "GND" H 4105 5627 50  0000 C CNN
F 2 "" H 4100 5800 50  0001 C CNN
F 3 "" H 4100 5800 50  0001 C CNN
	1    4100 5800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4100 5800 4100 5600
Wire Wire Line
	4600 5800 4600 5600
Wire Wire Line
	5300 5200 4600 5200
Wire Wire Line
	4600 5200 4600 5300
Wire Wire Line
	5300 4900 4100 4900
Wire Wire Line
	4100 4900 4100 5300
Wire Wire Line
	5300 4750 3950 4750
Wire Wire Line
	3950 4750 3950 5150
Wire Wire Line
	3950 5150 2000 5150
Wire Wire Line
	2000 5050 2000 5150
Connection ~ 2000 5150
Wire Wire Line
	2000 5150 1800 5150
Wire Wire Line
	5650 6400 5100 6400
Wire Wire Line
	5100 6400 5100 5050
Wire Wire Line
	5100 5050 5300 5050
Wire Wire Line
	6300 4900 6450 4900
Wire Wire Line
	6450 4900 6450 4750
Wire Wire Line
	6450 4500 6750 4500
Wire Wire Line
	6750 4500 6750 4550
Connection ~ 6450 4750
Wire Wire Line
	6450 4750 6450 4500
Wire Wire Line
	6300 4750 6450 4750
Wire Wire Line
	6750 4850 6750 5050
Wire Wire Line
	6750 5050 6850 5050
Wire Wire Line
	6300 5050 6750 5050
Connection ~ 6750 5050
Wire Wire Line
	6300 5200 6450 5200
Wire Wire Line
	6450 5200 6450 6400
Wire Wire Line
	6450 6400 5950 6400
Wire Wire Line
	7150 5050 7300 5050
Wire Wire Line
	9200 5050 9200 5150
Wire Wire Line
	8500 5150 8500 5050
Connection ~ 8500 5050
Wire Wire Line
	6450 6400 7300 6400
Wire Wire Line
	7300 6400 7300 5050
Connection ~ 6450 6400
Connection ~ 7300 5050
Wire Wire Line
	7300 5050 8500 5050
Wire Wire Line
	6300 5350 6800 5350
Wire Wire Line
	6800 5350 6800 5500
Wire Wire Line
	6800 5500 8500 5500
Wire Wire Line
	9050 5500 9200 5500
Wire Wire Line
	9200 5500 9200 5450
Wire Wire Line
	8500 5050 9200 5050
Wire Wire Line
	9200 5050 9700 5050
Wire Wire Line
	10500 5050 10500 5150
Connection ~ 9200 5050
Wire Wire Line
	9700 5150 9700 5050
Connection ~ 9700 5050
Wire Wire Line
	9700 5050 10100 5050
Wire Wire Line
	10100 5150 10100 5050
Connection ~ 10100 5050
Wire Wire Line
	10100 5050 10500 5050
$Comp
L power:GND #PWR055
U 1 1 5EFA5358
P 8500 5950
F 0 "#PWR055" H 8500 5700 50  0001 C CNN
F 1 "GND" H 8505 5777 50  0000 C CNN
F 2 "" H 8500 5950 50  0001 C CNN
F 3 "" H 8500 5950 50  0001 C CNN
	1    8500 5950
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR057
U 1 1 5EFA57F5
P 10100 5650
F 0 "#PWR057" H 10100 5400 50  0001 C CNN
F 1 "GND" H 10105 5477 50  0000 C CNN
F 2 "" H 10100 5650 50  0001 C CNN
F 3 "" H 10100 5650 50  0001 C CNN
	1    10100 5650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10100 5650 10100 5550
Wire Wire Line
	10500 5450 10500 5550
Wire Wire Line
	10500 5550 10100 5550
Connection ~ 10100 5550
Wire Wire Line
	10100 5550 10100 5450
Wire Wire Line
	9700 5450 9700 5550
Wire Wire Line
	9700 5550 10100 5550
Wire Wire Line
	8500 5950 8500 5850
$Comp
L power:+12V #PWR058
U 1 1 5EFBC211
P 10650 4950
F 0 "#PWR058" H 10650 4800 50  0001 C CNN
F 1 "+12V" H 10665 5123 50  0000 C CNN
F 2 "" H 10650 4950 50  0001 C CNN
F 3 "" H 10650 4950 50  0001 C CNN
	1    10650 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	10500 5050 10650 5050
Wire Wire Line
	10650 5050 10650 4950
Connection ~ 10500 5050
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 5EED479B
P 7450 1750
F 0 "#FLG0104" H 7450 1825 50  0001 C CNN
F 1 "PWR_FLAG" H 7450 1923 50  0000 C CNN
F 2 "" H 7450 1750 50  0001 C CNN
F 3 "~" H 7450 1750 50  0001 C CNN
	1    7450 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 1750 7450 1850
Connection ~ 7450 1850
Wire Wire Line
	7450 1850 7750 1850
$Comp
L power:PWR_FLAG #FLG0105
U 1 1 5EEDAAA0
P 10100 4950
F 0 "#FLG0105" H 10100 5025 50  0001 C CNN
F 1 "PWR_FLAG" H 10100 5123 50  0000 C CNN
F 2 "" H 10100 4950 50  0001 C CNN
F 3 "~" H 10100 4950 50  0001 C CNN
	1    10100 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 4950 10100 5050
Wire Wire Line
	7250 2300 7250 2650
Wire Wire Line
	7250 2650 5750 2650
Wire Wire Line
	5750 2650 5750 2050
Wire Wire Line
	5750 2050 5500 2050
Connection ~ 7250 2650
Wire Wire Line
	7250 2650 7250 2750
$Comp
L Device:D_Schottky_ALT D8
U 1 1 61591F94
P 6550 2050
F 0 "D8" V 6504 2130 50  0000 L CNN
F 1 "RB060M-60TR" V 6650 2050 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123F" H 6550 2050 50  0001 C CNN
F 3 "~" H 6550 2050 50  0001 C CNN
F 4 "RB060M-60TR" V 6550 2050 50  0001 C CNN "MPN"
	1    6550 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 1900 6550 1850
Connection ~ 6550 1850
Wire Wire Line
	6550 1850 6150 1850
$Comp
L power:GND #PWR031
U 1 1 615B7071
P 6550 2250
F 0 "#PWR031" H 6550 2000 50  0001 C CNN
F 1 "GND" H 6555 2077 50  0000 C CNN
F 2 "" H 6550 2250 50  0001 C CNN
F 3 "" H 6550 2250 50  0001 C CNN
	1    6550 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2200 6550 2250
$EndSCHEMATC
