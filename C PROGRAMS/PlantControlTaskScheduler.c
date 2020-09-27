
// A typical Embedded System, real­time tasks, rtos, internals and performance

//Plant Control Task

#define CYCLE_RATE_MS 10
#define MAX_COMMS_DELAY_MS 2

void PlantControlTask( void *pvParameters ) // HIGHEST PRIORITY TASK
{
	TickType_t xLastWakeTime;
	
	DataType Data1, Data2;
	
	InitialiseTheQueue();
	
	// A
	xLastWakeTime = xTaskGetTickCount();
	
	// B
	for( ;; )
	{
		// C
		vTaskDelayUntil( &xLastWakeTime, CYCLE_RATE_MS ); // 10MS
		
		// Request data from the sensors.
		TransmitRequest();
		
		// D
		if( xQueueReceive( xFieldBusQueue, &Data1, MAX_COMMS_DELAY ) )  // Block until data arrives.
		{
			// E
			if( xQueueReceive( xFieldBusQueue, &Data2, MAX_COMMS_DELAY ) ) // Block until data arrives.
			{
				PerformControlAlgorithm();
				// Process data received from sensors and Transmit results to actuator(s)
				TransmitResults();
			}
		}
	}
	// Will never get here!
}

//RS232 Interface
void RS232Task( void *pvParameters ) // MEDIUM PRIORITY TASK
{
	DataTypeB Data;
	for( ;; )
	{
		// Block until data arrives. xRS232Queue is
		// filled by the RS232 interrupt service routine.
		if( xQueueReceive( xRS232Queue, &Data, MAX_DELAY ) )
		{
			ProcessSerialCharacters( Data );
		}
	}
}

//Keypad Scanning and LCD update Task
#define DELAY_PERIOD_MS 4
void KeyScanTask( void *pvParmeters ) // MEDIUM PRIORITY TASK
{
	char Key;
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	
	for( ;; )
	{
		// Wait for the next cycle.
		vTaskDelayUntil( &xLastWakeTime, DELAY_PERIOD ); // 4MS
		
		// Scan the keyboard.
		if( KeyPressed( &Key ) )
		{
			UpdateDisplay( Key );
		}
	}
}

//LED flashing task
#define DELAY_PERIOD_MS 1000
void LEDTask( void *pvParmeters ) // LOW/MEDIUM PRIORITY TASK
{
	TickType_t xLastWakeTime;
	
	xLastWakeTime = xTaskGetTickCount();
	
	for( ;; )
	{
		// Wait for the next cycle.
		vTaskDelayUntil( &xLastWakeTime, DELAY_PERIOD ); // 1S
		
		// Flash the appropriate LED.
		if( SystemIsHealthy() )
		{
			FlashLED( GREEN );
		}
		else
		{
			FlashLED( RED );
		}
	}
}

//Embedded Web Server Task
void WebServerTask( void *pvParameters ) // LOW PRIORITY TASK
{
	DataTypeA Data;
	for( ;; )
	{
		// Block until data arrives. xEthernetQueue is filled by the
		// Ethernet interrupt service routine/Ethernet Driver
		if( xQueueReceive( xEthernetQueue, &Data, MAX_DELAY ) )
		{
			//embedded networking code – soft real-time code
			ProcessHTTPData( Data );
		}
	}
}

//Typical Firmware implementation without RTOS
int TimerExpired;

// Service routine for a timer interrupt. 
// This is configured to execute every 10ms.
void TimerInterrupt( void )
{
	TimerExpired = true;
}


int main( void )
{
	Initialise();
	
	for( ;; )
	{
		// Spin until it is time for the next cycle.
		if( TimerExpired )
		{
			PlantControlCycle();
			
			TimerExpired = false;
			
			ScanKeypad();
			
			UpdateLCD();
			
			// Comms buffers must be large
			// enough to hold 10ms worth of data.
			ProcessRS232Characters();
			
			// The LEDs could use a count of
			// the number of interrupts, or a different timer.
			ProcessLEDs();
			
			ProcessHTTPRequests();
		}
	}
	// Should never get here.
	return 0;
}
