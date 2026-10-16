#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cctype>

std::string tolowerstring(std::string n) {
	std::string lower = "";
	for (int i = 0; i < n.length(); ++i) {
		lower += std::tolower(n[i]);
	}
	return lower;
}


class vehicle {
private:
	int vehicleID;
	std::string vehicleType;
	int entryTime;
	int parkingDuration;
	double parkingFee;
	bool isOccupied = false;
public:
	vehicle() {
		vehicleID = 0;
		vehicleType = "";
		entryTime = 0;
		parkingDuration = 0;
		parkingFee = 0.0;
		isOccupied = false;
	}
	vehicle(int id, std::string type, int entry, int duration, double fee, bool occupied) {
		vehicleID = id;
		vehicleType = type;
		entryTime = entry;
		parkingDuration = duration;
		parkingFee = fee;
		isOccupied = occupied;
	}
	void setVehicleID(int id) {
		vehicleID = id;
	}
	int getVehicleID() {
		return vehicleID;
	}
	void setVehicleType(std::string type) {
		if(tolowerstring(type) == "car" || tolowerstring(type) == "motorcycle" || tolowerstring(type) == "bicycle") {
			vehicleType = type;
		}
		else {
			std::cout << "ko hop le" << std::endl;
		}
	}
	std::string getVehicleType() {
		return vehicleType;
	}
	void setEntryTime(int entry) {
		if (entry < 0 || entry > 23) {
			std::cout << "ko hop le" << std::endl;
		}
		else {
			entryTime = entry;
		}
	}
	int getEntryTime() {
		return entryTime;
	}
	void setParkingDuration(int duration) {
		if (duration < 0 || duration > 23) {
			std::cout << "ko hop le" << std::endl;
		}
		else {
			parkingDuration = duration;
		}
	}
	int getParkingDuration() {
		return parkingDuration;
	}
	void setParkingFee(double fee) {
		parkingFee = fee;
	}
	double getParkingFee() {
		return parkingFee;
	}
	void setIsOccupied(bool occupied) {
		isOccupied = occupied;
	}
	bool getIsOccupied() {
		return isOccupied;
	}
	void caculateFee() {
		double fee = 0.0;
		if (tolowerstring(vehicleType) == "car") {
			fee = 6.00;
		}
		if (tolowerstring(vehicleType) == "motorcycle") {
			fee = 4.00;
		}
		if (tolowerstring(vehicleType) == "bicycle") {
			fee = 2.00;
		}
		for (int i = entryTime; i < entryTime + parkingDuration; ++i) {
			if (i == 6 && ) {

			}
		}
	}
};





int main() {
	
}