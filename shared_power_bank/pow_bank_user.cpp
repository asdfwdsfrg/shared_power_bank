#include <iostream>
#include <string>
#include "pow_bank_user.h"
#include "location_service.h"
using namespace std;

void PowBankUser::GetInfo(string name, string phone_number) {
	user_name = name;
	user_phone_number = phone_number;
}
void PowBankUser::GetLocation() {
	current_location = LocService::GetLocation();
}
void PowBankUser::ChoosePowDep() {

}
void PowBankUser::GetChkCode() {

}
int PowBankUser::ShowChkCode() {

}
void PowBankUser::ReturnPow() {

}
void PowBankUser::CreateOrder() {

}
void PowBankUser::CalculateCost() {

}