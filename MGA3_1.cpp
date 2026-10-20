#include <iostream>
using namespace std;

void menu() {
    cout << "===================================================== \n";
    cout << "      BELIZE TRADING CO. - DAILY SALES ANALYZER \n";
    cout << "===================================================== \n";
    cout << "Shift Location: Orange walk, Sugar city \n";
    cout << "Currency: Belize Dollars (BZ$) \n";
    cout << "  1. Record a New Sale Transaction \n";
    cout << "  2. View Shift Snapshot (Interim Totals) \n";
    cout << "  3. Close Shift & Print Daily Audit \n";
    cout << "  4. Exit Without Saving \n";
    cout << "Enter choice (1-4): ";
}

int main() {
    int choice, cate_choice,countGrocery,countGeneral,countBeverages;
double sale_amount,revenueGeneral,totalRevenue,revenueGrocery,revenueBeverages;
    char res;
    double highestSale = 0.0;
    double lowestSale = 0.0;
    bool firstTransaction = true;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int saleCount = 1;
                do {
cout << "      \n";
cout << "--- Record Sale #" << saleCount << " --- \n";
cout << "Enter sale amount ($BZ): ";
cin >> sale_amount;
                    
if (sale_amount <= 0.00) {
cout << "Invalid entry! Sale amount must be greater than $BZ 0.00. \n";
                    } 
else {
cout << "Select Category: \n";
cout << "  [1] Grocery & Produce \n";
cout << "  [2] Beverages & Snacks \n";
cout << "  [3] General Merchandise \n";
cout << "Enter category choice (1-3): ";
cin >> cate_choice;
                        
if (cate_choice == 1) {
countGrocery++;
revenueGrocery += sale_amount;
cout << ">> Sale of $BZ " << sale_amount << " recorded under Grocery & Produce. \n";
                        }
else if (cate_choice == 2) {
countBeverages++;
revenueBeverages += sale_amount;
cout << ">> Sale of $BZ " << sale_amount << " recorded under Beverages & Snacks. \n";
                        }
else if (cate_choice == 3) {
countGeneral++;
revenueGeneral += sale_amount;
cout << ">> Sale of $BZ " << sale_amount << " recorded under General Merchandise. \n";
                        }
                        else {
cout << "Invalid entry! Please choose from the categories given. \n"; }
if (firstTransaction) {
highestSale = sale_amount;
lowestSale = sale_amount;
firstTransaction = false;
                        } else {
if (sale_amount > highestSale) {
highestSale = sale_amount;
}
if (sale_amount < lowestSale) {
lowestSale = sale_amount;
    }
        }
            }
                    
cout << "      \n";
cout << "Do you want to enter another transaction? (y/n): ";
cin >> res;
saleCount++;
cout << "      \n";
} while (res == 'y' || res == 'Y'); 

break;
            }
            case 2: (choice ==2 ); {
cout<<"This opion is currently in development,Please choose the other options.\n"; 
            break;}
            
case 3: {
                double totalRevenue = revenueGrocery + revenueBeverages + revenueGeneral;
                int totalTransactions = countGrocery + countBeverages + countGeneral;
                double avgSale = 0.0;
                if (totalTransactions > 0) {
                    avgSale = totalRevenue / totalTransactions;
                }

cout << "===================================================== \n";
cout << "         BELIZE TRADING CO. - DAILY AUDIT REPORT      \n";
cout << "===================================================== \n";
cout << "Total Transactions: " << totalTransactions << "\n";
cout << "Total Daily Revenue: $BZ " << totalRevenue << "\n";
cout << "Average Transaction Value: $BZ " << avgSale << "\n";
                
if (firstTransaction) {
cout << "Highest Sale: $BZ 0.00 \n";
cout << "Lowest Sale: $BZ 0.00 \n";
                } else {
cout << "Highest Sale: $BZ " << highestSale << "\n";
cout << "Lowest Sale: $BZ " << lowestSale << "\n";
                }
                
cout << "----------------------------------------------------- \n";
cout << "Category Breakdown: \n";
                
double percentGrocery = 0.0;
if (totalRevenue > 0) {
percentGrocery = (revenueGrocery / totalRevenue) * 100.0;}

cout << "1. Grocery & Produce -> Count: " << countGrocery << ", Revenue: $BZ " << revenueGrocery << " (" << percentGrocery << "%)\n";

double percentBeverages = 0.0;
if (totalRevenue > 0) {
percentBeverages = (revenueBeverages / totalRevenue) * 100.0;
                }
cout << "2. Beverages & Snacks -> Count: " << countBeverages << ", Revenue: $BZ " << revenueBeverages << " (" << percentBeverages << "%)\n";

double percentGeneral = 0.0;
if (totalRevenue > 0) {percentGeneral = (revenueGeneral / totalRevenue) * 100.0;
                }
cout << "3. General Merchandise -> Count: " << countGeneral << ", Revenue: $BZ " << revenueGeneral << " (" << percentGeneral << "%)\n";
                
cout << "===================================================== \n";
cout << "Shift closed successfully. Saving daily audit... \n";
                
choice = 4; 
break;
            }
        } //switch case.
    } while (choice != 4);
    cout << "Program has ended. \n";
    return 0;
}