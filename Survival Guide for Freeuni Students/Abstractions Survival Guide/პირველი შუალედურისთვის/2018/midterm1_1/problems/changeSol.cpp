#include "changeSol.h"


bool giveChangeRec(Vector<int> &bills, int price, Vector<int> &res) {
	if (price == 0) {
		//cout << "Res: " << res.toString() << endl;
		return true;
	}
	if (bills.size() == 0) {
		return false;
	}
	int bill = bills[bills.size()-1];
	bills.remove(bills.size()-1);
	res.add(bill);
	bool b = giveChangeRec(bills, price-bill, res);
	if (b) {
		return true;
	}
	res.remove(res.size()-1);
	b = giveChangeRec(bills, price, res);
	if (b) {
		return true;
	}
	bills.add(bill);

	return false;
}


bool giveChangeSol(Vector<int> &cshBills, Vector<int> &cstBills, int price) {
	Vector<int> bills, res;
	for (int i=0; i<cshBills.size(); i++) {
		bills.add(-cshBills[i]);
	}
	for (int i=0; i<cstBills.size(); i++) {
		bills.add(cstBills[i]);
	}
	//cout << "price: " << price << endl;
	return giveChangeRec(bills, price, res);
}

