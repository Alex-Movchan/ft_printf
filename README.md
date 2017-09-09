# ft_printf

My implementation of the printf function. 
But my function does not have a shared buffer.
I add colors when output to the console.
Only 3 colors:
{red}; 
{bleu};
{green};
{eoc} - remove color.
You can specify a file descriptor.
example
ft_printf("{fd}Error!\n",2);

Тthe default output goes to the first file descriptor.
The rest coincide man printf(3).
