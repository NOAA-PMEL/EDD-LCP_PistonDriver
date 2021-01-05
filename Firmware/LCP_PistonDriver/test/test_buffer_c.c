#include "unity.h"
#include "buffer_c.h"

sCircularBufferC_t TestBuf;

void setUp(void)
{
	BufferC_Clear(&TestBuf);
}

void tearDown(void)
{
}


void test_BufferC_Put_should_AddData_to_Buffer(void){
	uint16_t i;
	char testval = 'a';

	// printf("%d,%d,%d\n",TestBuf.size,TestBuf.read,TestBuf.write);
	for(i=0;i<BUFFER_C_SIZE;i++){
		// printf("%lu: %d,%d,%d\n",i,TestBuf.size,TestBuf.read,TestBuf.write);
		TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_putc(&TestBuf,testval));
		TEST_ASSERT_EQUAL(testval,TestBuf.buffer[i]);
		testval++;
	}
	
}

void test_BufferC_Put_should_Block_when_BufferFull(void){
	uint16_t i;
	char testval = 'a';

	/** Add a bunch of data and see if the buffer is valid */
	for(i=0;i<BUFFER_C_SIZE;i++){
		TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_putc(&TestBuf,testval));
		TEST_ASSERT_EQUAL(testval,TestBuf.buffer[i]);
		testval++;
	}

	/** Try to add more data, should block */
	TEST_ASSERT_EQUAL(BUFFER_C_FULL,BufferC_putc(&TestBuf,'9'));
	TEST_ASSERT_EQUAL(BUFFER_C_FULL,BufferC_putc(&TestBuf,'8'));
	TEST_ASSERT_EQUAL(BUFFER_C_FULL,BufferC_putc(&TestBuf,'7'));
	TEST_ASSERT_EQUAL(BUFFER_C_FULL,BufferC_putc(&TestBuf,'6'));

	/** Make sure the original data is there */
	testval = 'a';
	for(i=0;i<BUFFER_C_SIZE;i++){
		TEST_ASSERT_EQUAL(testval,TestBuf.buffer[i]);
		testval++;
	}
}



void test_BufferC_getc_should_Return_ValidChar_NoError(void){

	uint16_t i;
	char testval = 'a';
	char retval = 0;

	/** Set the buffer with chars */
	for(i=0;i<BUFFER_C_SIZE;i++){
		TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_putc(&TestBuf,testval));
		testval++;
	}

	/** Reset the test value */
	testval = 'a';

	/** Retreive the buffer values */
	for(i=0;i<BUFFER_C_SIZE;i++){
		
		TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_getc(&TestBuf,&retval));
		TEST_ASSERT_EQUAL(testval,retval);
		testval++;
	}
}

void test_BufferC_putc_should_Wrap_when_StartingFromHigherIndex(void){
	uint16_t i;
	char testval = 0;
	char retval = 0;
	char teststr[ACTUAL_BUFFER_C_SIZE];
	uint8_t testlen = 20;

	/** Partially set the buffer (5 deep) with chars */
	for(i=0;i<testlen;i++){
		testval = (i+'A');
		TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_putc(&TestBuf,testval));
		testval++;
	}
	/** Retreive those 5 values so the write index is greater than 0 */
	strncpy(teststr,TestBuf.buffer,BUFFER_C_SIZE);
	// printf("%s\n",teststr);
	for(i=0;i<testlen;i++){
		testval = (i+'A');
		TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_getc(&TestBuf,&retval));
		TEST_ASSERT_EQUAL(testval,retval);
		testval++;
	}


	/** Set the write and read index to a middle register */
	TestBuf.write = testlen;
	TestBuf.read = testlen;

	/** Write a full buffer worth, should wrap after index = BUFFER_C_SIZE */
	for(i=0;i<BUFFER_C_SIZE;i++){
		testval = (i+'0');
		// printf("%d: %u,%u,%c\n",i,TestBuf.read,TestBuf.write,testval);
		TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_putc(&TestBuf,testval));
		testval++;
	}

	/** Retreive the buffer values to see if wrap is successful*/
	for(i=0;i<BUFFER_C_SIZE;i++){
		
		testval = (i+'0');
		TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_getc(&TestBuf,&retval));
		// printf("%c,",retval);
		// printf("%d: %c,%c\n",i,testval,retval);
		// printf("%d,%d\n",TestBuf.read,TestBuf.write);
		TEST_ASSERT_EQUAL(testval,retval);
		testval++;
	}


}


void test_BufferC_Backspace_should_RemoveOneChar(void){
	uint16_t i;
	char testval = 0;
	uint8_t testlen = 5;

	/** Partially set the buffer (5 deep) with chars */
	for(i=0;i<testlen;i++){
		testval = (i+'A');
		TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_putc(&TestBuf,testval));
		testval++;
	}

	TEST_ASSERT_EQUAL(testlen,TestBuf.size);
	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_Backspace(&TestBuf));
	TEST_ASSERT_EQUAL(testlen-1,TestBuf.size);

	
}

void test_BufferC_Backspace_should_Wrap_and_RemoveOneChar(void){
	uint16_t i;
	char testval = 'A';
	uint8_t testlen = 5;

	TestBuf.write = BUFFER_C_SIZE-1;
	TestBuf.read = BUFFER_C_SIZE-1;

	
	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_putc(&TestBuf,testval));
	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_putc(&TestBuf,testval));
	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_putc(&TestBuf,testval));
	TEST_ASSERT_EQUAL(3,TestBuf.size);
	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_Backspace(&TestBuf));
	TEST_ASSERT_EQUAL(2,TestBuf.size);
	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_Backspace(&TestBuf));
	TEST_ASSERT_EQUAL(1,TestBuf.size);
	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_Backspace(&TestBuf));
	TEST_ASSERT_EQUAL(0,TestBuf.size);
	TEST_ASSERT_EQUAL(BUFFER_C_EMPTY,BufferC_Backspace(&TestBuf));

}


void test_BufferC_puts_should_PutAStringOnIt(void){

	uint16_t i;
	char teststr[] = "ALLTHESINGLELADIES";
	uint16_t testlen = sizeof(teststr)/sizeof(teststr[0]);

	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_puts(&TestBuf,&teststr[0],testlen));
}

void test_BufferC_puts_should_Block_StringsOverLength(void){
	char teststr[32];
	uint32_t testlen = 5000;
	TEST_ASSERT_EQUAL(BUFFER_C_STRING_TOO_LONG,BufferC_puts(&TestBuf,&teststr[0],testlen));
}


void test_BufferC_Scan_should_ReturnValidIndex(void){
	uint16_t i;
	char teststr[] = "AAAAAAAAAAAAAAAAAAAABAAAAAAAAAA";
	uint16_t testlen = sizeof(teststr)/sizeof(teststr[0]);
	
	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_puts(&TestBuf,&teststr[0],testlen));

	TEST_ASSERT_EQUAL(21,BufferC_Scan(&TestBuf,'B'));

}


void test_BufferC_gets_should_ReturnValidString(void){
	uint16_t i;
	char teststr[] = "TEST1\r\nTEST2\r\nTEST3\r\n";
	char retstr[64] = "";
	uint16_t testlen = sizeof(teststr)/sizeof(teststr[0]);
	uint16_t retlen = sizeof(retstr)/sizeof(retstr[0]);
	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_puts(&TestBuf,&teststr[0],testlen));

	memset(retstr,0,64);

	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_gets(&TestBuf,&retstr[0],retlen,'\n'));
	TEST_ASSERT_EQUAL_STRING("TEST1\r\n",retstr);

	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_gets(&TestBuf,&retstr[0],retlen, '\n'));
	TEST_ASSERT_EQUAL_STRING("TEST2\r\n",retstr);

	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_gets(&TestBuf,&retstr[0],retlen, '\n'));
	TEST_ASSERT_EQUAL_STRING("TEST3\r\n",retstr);

}


void test_BufferC_gets_Should_ReturnInvalid_if_CharDoesntExist(void){
	uint16_t i;
	char teststr[] = "TEST1TEST2TEST3";
	char retstr[64] = "";
	uint16_t testlen = sizeof(teststr)/sizeof(teststr[0]);
	uint16_t retlen = sizeof(retstr)/sizeof(retstr[0]);


	TEST_ASSERT_EQUAL(BUFFER_C_NO_STRING,BufferC_gets(&TestBuf,&retstr[0],retlen, '\n'));

	TEST_ASSERT_EQUAL(BUFFER_C_OK,BufferC_puts(&TestBuf,&teststr[0],testlen));

	memset(retstr,0,64);

	TEST_ASSERT_EQUAL(BUFFER_C_NO_STRING,BufferC_gets(&TestBuf,&retstr[0],retlen, '\n'));
	

}