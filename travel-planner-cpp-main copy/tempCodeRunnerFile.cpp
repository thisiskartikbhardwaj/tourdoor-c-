struct Admin {
    char name[50];
    char email[50];
    char phone[15];
    char password[20];
};

int main() {
    ifstream inFile("admins.txt", ios::binary);
    ofstream tempFile("temp_admins.txt", ios::binary);

    if (!inFile.is_open() || !tempFile.is_open()) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    Admin adminData;

    // Read from the original file and copy to the temp file, excluding "Abhilasha Bansal"
    while (inFile.read(reinterpret_cast<char*>(&adminData), sizeof(adminData))) {
        if (strcmp(adminData.name, "Abhilasha Bansal") != 0) {
            tempFile.write(reinterpret_cast<char*>(&adminData), sizeof(adminData));
        }
    }

    // Close the files
    inFile.close();
    tempFile.close();

    // Remove the original file
    remove("admins.txt");

    // Rename the temp file to the original file name
    rename("temp_admins.txt", "admins.txt");

    // Open the original file in append mode to add Paras' details
    ofstream outFile("admins.txt", ios::binary | ios::app);

    if (!outFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Add Paras' details
    Admin parasAdmin;
    strcpy(parasAdmin.name, "Paras");
    strcpy(parasAdmin.email, "paras@example.com");
    strcpy(parasAdmin.phone, "1234567890");
    strcpy(parasAdmin.password, "new_password");

    outFile.write(reinterpret_cast<char*>(&parasAdmin), sizeof(parasAdmin));

    outFile.close();

    cout << "Admin details updated!" << endl;
    return 0;
}
