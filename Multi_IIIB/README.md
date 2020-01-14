# Task_5 [2017/2018-II]
Task 5 : Circular Double Linked List

# DEADLINE = FEBRUARY 24TH, 2018 - 23:59

## Reading Material
* [git cheat sheet](https://education.github.com/git-cheat-sheet-education.pdf)
* [markdown cheat sheet](https://enterprise.github.com/downloads/en/markdown-cheatsheet.pdf)

## Workflow
1. FORK this repositori ASD_Task_5 to your GitHub account
2. CLONE ASD_Task_5 repository from YOUR OWN ACCOUNT
3. open and modify codes in *.cpp and *.h files inside project ASD_Task_5
4. write your code inside the provided space in each functions/procedures 
5. COMMIT and PUSH your project to your account
6. create a Pull Request

Introduction to Double Circular Linked List  <br>
Create a music player application to implement the double circular linked list data structure

##library integration
1. on Code::Blocks, go into menu project->Build Option
2. go to Linker Settings tab
3. click Add to add new lib function
4. type winmm 
5. click OK

##list.h
modify the elemenList and List structure to implement Double Circular linked list
	
##list.cpp
modify each function to fit the data structure
* createList
* allocate, deallocate
* insertFirst, insertLast, insertAfter
* deleteFirst, deleteLast, deleteAfter
* findElmByID, findElmByName
to implement Double Circular Linked List mechanism
	
##player.cpp
<i>these function are already defined:
* function to produce random integer<br> `int randomInt(int  max_int);` <br>
* function to print music list inserted<br> `void printInfo(List L);` <br>
* function to play current music pointed by P<br> `void playMusic(address P);`   <br>
</i>
TODO : 
create function according to the header defined in player.h

* function to sort the music list by ID <br>
  ``` void sortListByID(List &L); ``` <br>
  
* function to play the music list from the first music and repeat the list n times  <br>`void playRepeat(List &, int n);` <br>
  
* function to delete any music defined by its ID<br>
  ```void deleteMusicByID(List &L, infotype x);```

* function to shuffle the music list<br> `void shuffleList(List &);`<br>simple logic example: <br> 

```	loop n times
		P <- first
		x = randomInt
		for i to x, 
			move P to next element
		delete after P
		insert first P
  ```
  
		
##main.cpp
* modify the main menu progam
* run the application
	
