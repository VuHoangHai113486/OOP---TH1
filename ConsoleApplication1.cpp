#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cctype>

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


};

class ParkingLot {
private:
	int parkID;
	char size;
	std::vector<vehicle> ds_vehicle;
	std::vector<bool> ds_occupied;
public:
	ParkingLot() {
		parkID = 0;
		size = ' ';
		ds_vehicle = std::vector<vehicle>(0);
		ds_occupied = std::vector<bool>(0);
	}
	ParkingLot(int id , char s)
};




int main() {
	
}