
ABSTRACT

Our Project is the implementation of a live cricket screcard. While there are multiple sources that give you the overview of the match using a scorecard with the input files, there werent any which gave you the scorecard as an when the match is going on. We used doubly-linked lists to implement the same and furthermore used the Duckworth Lewis Algorithm to predict the winner in games affected by rain. Furthermore, Hash tables have been used to update the performances of bowlers in real time. 




DESCRIPTION OF DATA STRUCTURE, LOGIC AND FUNCTIONALITY 

    1) Data structures used are doubly-linked lists and Hash Tables
2)  Algorithm: Duckworth Lewis  Algorithm

A doubly-linked list was used to store the batsmen of the batting team. This helped us go back and forth changing the strike of the batsman in real-time while they scored runs. 
A hash table was used to store the bowlers of the bowling team. Using hashing, the bowlers were accessed during their overs and their stats were upgraded in real time.
The Duckworth Lewis Algorithm and their table was used to calculate the DL Par Score as the end of each over.
Input of every ball was taken from the user and was validated before the score was updated.


SCOPE OF IMPROVEMENT IN FUTURE:

1) Taking the user input in overs and not ball by ball, validate the input, in order to make the process less tedious.

2) Take into account Extras and Run-outs and accordingly validate the input from the user.

3) Take into account rain interruptions in the first innings.

4) Take into account multiple rain interruptions in both the innings.

5) Improve the DLS Algorithm and make it more accurate.
	- Follow the Buddha, Then kill the Buddha 


CONCLUSION

We found a our own simple way to make a live scorecard using  various data structures. But there are multiple aspects that can be improved upon as mentioned above. 

We also learnt about the UT-Hash technique and some open-scource work that is going on in this field of data structures and also how we can contribute to it.

Documentation for uthash is available at:

http://troydhanson.github.com/uthash/


