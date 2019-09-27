/* File: main.c */
 
#define	STACK_TOP  0x20001000
 
void nmi_handler(void)
{
    for(;;);
}
 
void hardfault_handler(void)
{
    for(;;);
}
 
int main(void)
{
    int i = 0;
 
    for (;;) {
        i++;
    }
}
 
/* vector table */
unsigned int *myvectors[4]
__attribute__ ((section("vectors"))) = {
    (unsigned int *) STACK_TOP,
    (unsigned int *) main,
    (unsigned int *) nmi_handler,
    (unsigned int *) hardfault_handler
};