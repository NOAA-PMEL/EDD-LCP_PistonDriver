# Console Command List

This document lists all of the user console commands, intended function, and associated errors.


## Console COM Connection
The console is found on Connector J1 of the LCP Piston Control PCB.  J1 is connected to UART UCA0 of the MSP430FR5989.  J1 was designed to be connected with a standard 3.3V FTDI USB-to-UART cable.

### Connection Info
| Description | Setting |
|---|---|
| Baudrate | 115200 |
| Data Bits | 8 |
| Parity | None |
| Stop Bits | 1 |


## Console
The user console is designed as a debuging and system integration test peripheral.  It is *not* designed
for use as the primary control port, and as such has a lower priority than the I2C port which *is* intended
for primary control between systems.

### Console Characteristics
When correctly connected to J1 over UART, the console terminal looks like:

>PISTxxxx>

where:<br>
>PIST is the LCP Piston Control designator <br>
>xxxx is the serial number of the Piston Controller <br>
> \> is terminal prompt


All commands are terminated with carriage return ('\r')\

___
### Command Set
---
#### Basic Commands
| Command | Description |
| --- | --- |
| help | List all commands |
| hello | Returns 'Hello from PISTxxxx!\r' |
| restart | Restart board (clear temporary values) |

---
#### LED Commands
| Command | Description | Key Name | Value |
|---|---|---|---|
| LED *name* *state* | Set commanded LED to requested state | GREEN or BLUE | ON, OFF or BLINK | 

---
#### System Information
| Command | Description | 
|---|---|
| ser | Display serial number |
| id | System ID (LCP-PPC) |
| ver | Firmware Version (major.minor.build) |
| report | Display report of system information |

---
#### GET/SET Commands 
The GET/SET commands read and write (respectively) the system control variables used to set the various states,
speeds, etc. The command structure is:

> get *key* 

OR

> set *key* *value*

* The *key* is the variable that the user wishes to read or write to.  
* The *value* is the value (int, float, string, etc.) the user wishes to write to the *key* variable



##### KEY/VALUE 
The following is a list of key/value that can be used with the *get* or *set* functions:

| **KEY** | **VALUE (type)** | **GET** | **SET** |  **DESCRIPTION** |
|---|---|---|---|---|
| vset | float | X | X | Volume Setpoint [in^3] |
| vtotal | float | X | | Current Total Volume [in^3] |
| vsmall | float | X |  | Current Volume of small piston [in^3] |
| vlarge | float | X |  | Current Volume of large piston [in^3] |
| vhouse | float | X |  | Housing Volume [in^3] | 
| asmall | float | X |  | Small piston area [in^2] | 
| alarge | float | X |  | Large piston area [in^2] |
| ltotal | float | X |  | Length of full piston [in] |
| lsmall | float | X |  | Length of small piston [in] |
| llarge | float | X |  | Length of large piston [in] |
| pmin | float | X | X | Piston Minimum Position [in] | 
| pmax | float | X | X | Piston Maximum Position [in] |
| prate | float | X |  | Piston rate, current [in/sec] |
| tdir | int | X |  | Piston travel direction, extension = 1, retraction = -1 |
| teng | bool | X |  | Travel engaged (halted=False, running=True) |
| tzero | bool | X |  | Travel position at full retraction (No=False, Yes=True) |
| tfull | bool | X |  | Travel position at full extension (No=False, Yes=True) |
| pidp | float | X | X | PID Coefficient (P) | 
| pidi | float | X | X | PID Coefficient (I) |
| pidd | float | X | X | PID Coefficient (D) | 
| user | string | X | X | User Name (default: **guest**) |
| level | int | X | X | Logging Level (0-Off, 1-Debug+, 2-Warning+, 3-Errors Only)|
| restart | None |  | X | Restart system |


---
The following list can be used if the username is set to **admin**

| **KEY** | **VALUE (type)** | **GET** | **SET** |  **DESCRIPTION** |
|---|---|---|---|---|
| utest | int | X | X | Test mode (read next section for description) |
| udir | int | X | X | User defined direction (extension = 1, retraction = -1) |
| ueng | bool | X | X| User defined power engaged (Off=False, On=True) |
| urate | float | X | X| User defined piston rate (approx) [in/sec] |
| ulset | float | X | X | User defined total length setpoint (in) |
| serial | string | X | X | User defined serial number |
| factory | string |  | X | Factory reset (string must be PMEL to be accepted) | 


##### RAM Commands
It is possible to read & write to the I2C command RAM space over the console.  Use the following syntax

> set *-r* *addr* *length* *value*

* *-r* Flag setting RAM location
* *addr* Address offset location (0x0Y00 - 0x0YFF) (Y=0,1,2)
* *length* Number of bytes to read/write (int)
* *value* Hex values to write (no 0x before hex string)



#### Test Modes
The following are the available test modes

| Mode | Test Description | 
|---|---|
| 0 | Test(s) OFF |
| 1 | Run to fully extended |
| 2 | Run to fully retracted |
| 3 | Run to half extension |
| 4 | Zero > Full, 1/2" increments |
| 5 | Full > Zero, 1/2" increments |
| 6 | Zero > Full > Zero, 1/2" increments |
| 7 | Zero > Full > Zero, loop until keystroke |
| 8 | Zero > Full > Zero, 1/2" increments, loop until keystroke |