# runlengthencode

implement two of the four run-length encoding methods . 

Method 1) with zero and no wrap-around. 
Method 4) No zero and wrap-around. 

What you need to do for this project:
1) Your program will open the input image file and do all the initialization.
2) The encode method will be given in argv[2]
3) Your program call the given method to perform compression on the image file and outputs the result to a text file.  
4) The name of the compressed file is to be created during the run-time of your program, using the original input file name with an extension “ _EncodeMethodN,”  where N is the method number in which the user entered. For example, if the name of the original image is “image”,  and N is 1 (use method 1)  then the name of the compressed file should be “image_EncodeMethod1”.   (This can be done simply using string concatenation.) *** -6 pts for hard code file name in the program!!!
5) To begin, you implement method 1 from the algorithm steps given in class, then run your program with image1. Check the output to see if it encoded correctly. If it does, then implement method 4. 

6) When both methods work correctly, run your program 2 times, first method 1 and next method 2.
