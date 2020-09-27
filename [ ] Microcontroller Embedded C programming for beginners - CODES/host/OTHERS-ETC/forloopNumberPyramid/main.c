

#include<stdio.h>
#include<stdint.h>

void wait_for_user_input(void);


int main(void)
{

	uint32_t height;
	uint32_t i = 1, j;
	printf("Enter height of pyramid: ");
	scanf("%d",&height);


	for( ; i <= height  ; i++  )
	{
		for(j = i; j > 0 ; j--)
		{
			printf("%d  ",j);
		}
		printf("\n");
	}


   wait_for_user_input();
}


void wait_for_user_input(void)
{

	printf("Press enter key to exit this application");

    while(getchar() != '\n')
    {
    	//just read the input buffer and do nothing
    }
    getchar();

}
