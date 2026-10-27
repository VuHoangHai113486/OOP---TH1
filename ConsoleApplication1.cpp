#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cctype>
#include<string>

/*public:
Xe();
Xe(int ma, const string& loai, int gio, int thoiLuong);
int layMaXe() const;
string layLoaiXe() const;
int layGioVao() const;
int layThoiGianDo() const;
double layPhiDoXe() const;
bool layDangChiemCho() const;
void ganMaXe(int ma);
void ganLoaiXe(const string& loai);
void ganGioVao(int gio);
void ganThoiLuongDo(int thoiLuong);
void ganPhiDoXe(double phi);
void ganDangChiemCho(bool trangThai);
static string chuanHoaLoaiXe(const string& loai);
static bool laLoaiXeHopLe(const string& loai);
void tinhPhiDoXe();
void hienThi() const;
};*/
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
	vehicle(int id, std::string type, int entry, int duration) {
		vehicleID = id;
		if (tolowerstring(type) == "car" || tolowerstring(type) == "motorcycle" || tolowerstring(type) == "bicycle") {
			vehicleType = type;
		}
		else {
			std::cout << "type ko hop le" << std::endl;
		}
		entryTime = entry;
		parkingDuration = duration;
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
			return;
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
			return;
		}
		else {
			entryTime = entry;
		}
	}
	int getEntryTime() {
		return entryTime;
	}
	void setParkingTime(int duration) {
		if (duration < 0 || duration > 23) {
			std::cout << "ko hop le" << std::endl;
			return;
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
	double caculateFee() {
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
		int calTime = std::max(entryTime + 2, entryTime + parkingDuration);

		for (int i = 0; i <= calTime; ++i) {
			if (entryTime == 6 || entryTime == 7 || entryTime == 8 || entryTime == 9
				|| entryTime == 15 || entryTime == 16 || entryTime == 17 || entryTime == 18) {
				parkingFee += fee * 130 / 100;
			}
			else {
				parkingFee += fee * 95 / 100;
			}
		}

		for (int i = 3; i <= entryTime + parkingDuration; ++i) {
			parkingFee += fee * 90 / 100;
		}
		return parkingFee;
	}

	void hienthi() {
		std::cout << "ID :" << vehicleID << std::endl;
		std::cout << "Type : " << vehicleType << std::endl;
		std::cout << "EntryTime : " << entryTime << std::endl;
		std::cout << "ParkingDuration : " << parkingDuration << std::endl;
		std::cout << "Fee : " << caculateFee() << std::endl;
	}


};

class ParkingLot {
private:
	int parkID;
	char size;
	vehicle vehicle1, vehicle2, vehicle3;
	bool hasVehicle1, hasVehicle2, hasVehicle3;
public:
	std::vector<vehicle> vehicleParkingLot = { vehicle1 , vehicle2 , vehicle3 };
	ParkingLot() {
		parkID = 0;
		size = ' ';
		hasVehicle1 = false;
		hasVehicle2 = false;
		hasVehicle3 = false;
	}
	ParkingLot(int id, char s) {
		parkID = id;
		size = s;
		if (size == 'S') {
			hasVehicle1 = false;
			hasVehicle2 = true;
			hasVehicle3 = true;
		}
		else if (size == 'M') {
			hasVehicle1 = false;
			hasVehicle2 = false;
			hasVehicle3 = true;
		}
		else if (size == 'L') {
			hasVehicle1 = false;
			hasVehicle2 = false;
			hasVehicle3 = false;
		}
		else {
			std::cout << "ko hop le" << std::endl;
		}
	}

	int getParkID() {
		return parkID;
	}

	bool addVehicle(const vehicle& v) {
		if (size == 'S') {
			if (!hasVehicle1) {
				vehicle1 = v;
				hasVehicle1 = true;
			}
			return hasVehicle1;
		}

		if (size == 'M') {
			if (!hasVehicle1) {
				vehicle1 = v;
				hasVehicle1 = true;
				return true;
			}
			else if (!hasVehicle2) {
				vehicle2 = v;
				hasVehicle2 = true;
				return true;
			}
			return false;
		}

		if (size == 'L') {
			if (!hasVehicle1) {
				vehicle1 = v;
				hasVehicle1 = true;
				return true;
			}
			else if (!hasVehicle2) {
				vehicle2 = v;
				hasVehicle2 = true;
				return true;
			}
			else if (!hasVehicle3) {
				vehicle3 = v;
				hasVehicle3 = true;
				return true;
			}
			return false;
		}
	}

	bool removeVehicle(int id) {
		if (vehicle1.getVehicleID() == id) {
			hasVehicle1 = false;
			return true;
		}
		if (vehicle2.getVehicleID() == id) {
			hasVehicle2 = false;
			return true;
		}
		if (vehicle3.getVehicleID() == id) {
			hasVehicle3 = false;
			return true;
		}
		return false;
	}

	void displayLotInfo() {
		std::cout << "ParkID : " << parkID << std::endl;
		std::cout << "Size : " << size << std::endl;
		if (hasVehicle1) {
			std::cout << "Vehicle1 con trong bai xe" << std::endl;
		}
		if (hasVehicle2) {
			std::cout << "Vehicle2 con trong bai xe" << std::endl;
		}
		if (hasVehicle3) {
			std::cout << "Vehicle3 con trong bai xe" << std::endl;
		}
	}

};

class SystemInterface {
private:
	ParkingLot parkingLot1, parkingLot2, parkingLot3;
	bool hasLot1, hasLot2, hasLot3;
	int soluongbai = 0;
public:
	SystemInterface() {
		hasLot1 = false;
		hasLot2 = false;
		hasLot3 = false;
	}

	void runMenu() {
		std::vector<ParkingLot> parkinglot1 = { parkingLot1 , parkingLot2 , parkingLot3 };
		
		int a;
		do {
			std::cin >> a;

			switch (a) {
			case 1: {
				if (soluongbai >= 3) {
					std::cout << "het slot" << std::endl;
					break;
				}
				std::cout << "ID : ";
				int id;
				std::cin >> id;
				if (id == parkingLot1.getParkID() || id == parkingLot2.getParkID() || id == parkingLot3.getParkID()) {
					std::cout << "ID da ton tai" << std::endl;
					break;
				}
				std::cin.ignore();
				std::cout << "Size : ";
				char size;
				std::cin >> size;
				ParkingLot parkTemp(id, size);
				if (!hasLot1) {
					parkingLot1 = parkTemp;
					hasLot1 = true;
					soluongbai++;
					break;
				}
				if (!hasLot2) {
					parkingLot2 = parkTemp;
					hasLot2 = true;
					soluongbai++;
					break;
				}
				if (!hasLot3) {
					parkingLot3 = parkTemp;
					hasLot3 = true;
					soluongbai++;
					break;
				}

				break;
			}
			case 2: {
				int vehicleID1;
				std::cout << "vehicleID : " << std::endl;
				std::cin >> vehicleID1;
				std::cin.ignore();
				std::cout << "vehicleType : " << std::endl;
				std::string vehicleType1;
				getline(std::cin, vehicleType1);
				std::cout << "entryTime : " << std::endl;
				int entryTime1;
				std::cin >> entryTime1;
				std::cout << "parkingDuration : " << std::endl;
				int parkingDuration1;
				std::cin >> parkingDuration1;

				vehicle a(vehicleID1, vehicleType1, entryTime1, parkingDuration1);
				for (ParkingLot temp : parkinglot1) {
					temp.addVehicle(a);
					if (temp.addVehicle(a) == true) {
						std::cout << "Thêm xe thành công" << std::endl;
						break;
					}
				}

				break;
			}

			case 3: {
				int parkID1;
				std::cout << "ParkID : " << std::endl;
				std::cin >> parkID1;
				ParkingLot tempparkinglot;
				for (ParkingLot temp : parkinglot1) {
					if (temp.getParkID() == parkID1) {
						temp = tempparkinglot;
						break;
					}
				
				}
				std::cout << "ko tìm thấy park" << std::endl;
				break;
			}

			case 4: {
				int vehicleID1;
				std::cout << "Nhập ID: " << std::endl;
				std::cin >> vehicleID1;
				for (ParkingLot temp : parkinglot1) {
					for (vehicle tempVehicle : temp.vehicleParkingLot) {
						if (tempVehicle.getVehicleID() == vehicleID1) {
							temp.removeVehicle(tempVehicle.getVehicleID());
							if (temp.removeVehicle(tempVehicle.getVehicleID()) == true) {
								std::cout << "Remove thành công" << std::endl;
							}
							else {
								std::cout << "ko remove dc" << std::endl;
							}
						}
					}
				}

				break;
			}

			case 5: {
				for (ParkingLot temp : parkinglot1) {
					temp.displayLotInfo();
				}

				break;
			}

			case 6: {
				int parkID1;
				std::cout << "Nhập parkID : " << std::endl;
				std::cin >> parkID1;
				for (ParkingLot temp : parkinglot1) {
					if (temp.getParkID() == parkID1) {
						for (vehicle tempvehicle : temp.vehicleParkingLot) {
							tempvehicle.hienthi();
							break;
						}
					}
				}
				std::cout << "ko thấy xe" << std::endl;
				break;
			}
			

			case 7: {

				break;
			}

			


		} while (a != 9);
	}
};




int main() {
	
}