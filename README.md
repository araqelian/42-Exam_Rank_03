# 📌 get_next_line&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;subject.en.txt
<br>

<p>
Assignment name : &nbsp;&nbsp;get_next_line<br>
Expected files : &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;get_next_line.c &nbsp;&nbsp;&nbsp;get_next_line.h<br>
Allowed functions: &nbsp;&nbsp;&nbsp;read, &nbsp;&nbsp;free, &nbsp;&nbsp;malloc<br>

_________________________________________________________________________________________________________________________________
</p>

<ul>
<li>Write a function named <b>get_next_line</b> which prototype should be:<br>
char &nbsp;&nbsp;*get_next_line(int fd);<br><br>


<li>Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succesion of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).<br><br>

<li>The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.<br><br>

<li>In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.<br><br>

<li>Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.<br><br>

<li>Caling your function get_next_line in a lop will therefore allow you to read the text avaiable on a file descriptor one line at a time until the end of the text, no matter the size od either the text or one of its lines.<br><br>

<li>Make sure that your function behaves wel when it reads from a file, from the standard output, from a redirection, etc...<br><br>

<li>No call to another function will be done on the file descriptor between 2 calls of get_next_line. Finally we consider that get_next_line has an undefined behaviour when reading from a binary file.
</ul>
