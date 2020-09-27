
// structInit

#include<stdint.h>
#include<stdio.h>

struct carModel
{
	uint8_t carSpeed; // 1 byte
	uint32_t carPrice; // 4bytes
};

int main(void)
{	
	// uint32_t i = 2;
	
	struct carModel  carBMW = {200, 123456987};
	
	printf("\n Sizeof of struct carModel is %u bytes\n", sizeof(struct carModel));
	printf("\n Sizeof of carBMW.carSpeed is %u byte  (uint8_t)\n", sizeof(carBMW.carSpeed));
	printf("\n Sizeof of carBMW.carPrice is %u bytes (uint32_t)\n", sizeof(carBMW.carPrice));
	
	printf("\n Addr. of struct carBMW   %p \n", &carBMW);
	printf("\n Addr. of carBMW.carSpeed %p \n", &carBMW.carSpeed);
	printf("\n Addr. of carBMW.carPrice %p \n", &carBMW.carPrice);
	
	printf("\n carSpeed = %d kmph", carBMW.carSpeed);
	printf("\n carPrice = Rs. %d\n", carBMW.carPrice);
	
	carBMW.carSpeed = 250;
	carBMW.carPrice = 987654321;
	
	printf("\n carSpeed = %d kmph", carBMW.carSpeed);
	printf("\n carPrice = Rs. %d", carBMW.carPrice);	
    getchar();

	return 0;
}









