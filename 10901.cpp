//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Ferry Loading III : 10901 : Brayzen
//
//Data structure required : Queues, vectors, strings, pairs
//
//Tricks of the trade :
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cases, numCars, timeToCross, lines, arriveTime, time;
	cin >> cases;
	for (int i = 0; i < cases; i++){
		time = 0;
		bool leftSide = 1;
		string arriveBank;
		pair<int, int> carTime, temp;
		queue<pair<int, int> > leftbank, rightbank, ferry;
		cin >> numCars >> timeToCross >> lines;
		vector<pair<int,int> > inputOrder(lines);
		vector<int> output(lines);
		//get input and put into 2 queues
		for (int j = 0; j < lines; j++){
			cin >> arriveTime >> arriveBank;
			inputOrder[j].first = arriveTime;
			inputOrder[j].second = j;
			if (arriveBank == "left"){
				leftbank.push(inputOrder[j]);
			}
			else{
				rightbank.push(inputOrder[j]);
			}
		}
		while (!leftbank.empty() || !rightbank.empty()){
			//set time to first car and switch sides if needed, both sides aren't empty
			if (!rightbank.empty() && !leftbank.empty() && rightbank.front().first > time && leftbank.front().first > time) {
				if (rightbank.front() < leftbank.front()) {
					if (leftSide) {
						time = rightbank.front().first + timeToCross;
						leftSide = !leftSide;
					}
					else {
						time = rightbank.front().first;
					}
				}
				else {
					if (!leftSide) {
						time = leftbank.front().first + timeToCross;
						leftSide = !leftSide;
					}
					else {
						time = leftbank.front().first;
					}
				}
			}
			//handle setting time forward if one of the banks are empty
			else if(!rightbank.empty() && leftbank.empty() && rightbank.front().first > time) {
				if (leftSide) {
					time = rightbank.front().first + timeToCross;
					leftSide = !leftSide;
				}
				else {
					time = rightbank.front().first;
				}
			}
			//handle setting time forward if one of the banks are empty
			else if (rightbank.empty() && !leftbank.empty() && leftbank.front().first > time) {
				if (!leftSide) {
					time = leftbank.front().first + timeToCross;
					leftSide = !leftSide;
				}
				else {
					time = leftbank.front().first;
				}
			}
			//load onto ferry
			if (leftSide && !leftbank.empty()){
				while (!leftbank.empty() && leftbank.front().first <= time && ferry.size() < numCars){
					temp = leftbank.front();
					leftbank.pop();
					ferry.push(temp);
				}
			}
			if (!leftSide && !rightbank.empty()){
				while (!rightbank.empty() && rightbank.front().first <= time && ferry.size() < numCars){
					temp = rightbank.front();
					rightbank.pop();
					ferry.push(temp);
				}
			}
			//transport across
			time += timeToCross;
			leftSide = !leftSide;
			int s = ferry.size();
			for (int j = 0; j < s; j++){
				temp = ferry.front();
				ferry.pop();
				output[temp.second] = time;
			}
		}
		//output
		for (int j = 0; j < output.size(); j++) {
			cout << output[j] << "\n";
		}
		if (i < cases - 1) {
			cout << "\n";
		}
	}
	return 0;
}