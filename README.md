# Telephone Diary Using C++

## Overview
The **Telephone Diary** project is a simple console-based application built using C++. It allows users to manage their contacts by storing essential details such as Name, Address, Phone, Mobile, and Email. The project employs a file system to store contact information permanently on disk and provides several functionalities for adding, searching, updating, and deleting contacts.

### Key Features:
1. **Add a new contact**: Store the details of a person including their ID, Name, Address, Phone, Mobile, and Email.
2. **Search by name or mobile number**: Quickly retrieve contact information using either the person's name or mobile number.
3. **View all contacts**: Display the complete list of contacts sorted alphabetically by name.
4. **Update contact details**: Modify an existing contact's information using their unique ID.
5. **Delete a contact**: Remove a contact permanently using their ID.
6. **Persistent storage**: All contact information is saved to a file, allowing it to be available even after the program is closed.

## How It Works
The program stores contacts in a binary file called `phone.dat`. Each contact is represented as a `Person` object with attributes such as ID, Name, Address, Phone, Mobile, and Email. The file system is used to store, retrieve, update, and delete contact information.

### Main Functions:
- **Add Contact**: Before adding a new contact, the program checks if the mobile number already exists to avoid duplicates.
- **Search Contact**: Users can search for a contact by either name or mobile number. The program scans the file to find matching records.
- **Display All Contacts**: Lists all contacts stored in the file, sorted alphabetically by name.
- **Update Contact**: Allows users to update a contact’s details by providing the contact’s unique ID.
- **Delete Contact**: The program creates a temporary file to filter out the contact to be deleted and then rewrites the data to the main file.

## Compilation & Setup
This project is compiled using **Turbo C++**. If you're using a different environment, you may need to adjust certain components such as header files.

### Prerequisites:
- A C++ compiler (Turbo C++ recommended)
- Basic knowledge of C++ file handling

### Steps to Compile:
1. Download the source code.
2. Open the code in Turbo C++ or any C++ compiler that supports C++98.
3. Compile and run the code.

### Example Usage:
Upon running the program, you'll be greeted with a menu that offers the following options:
1. Add a new contact
2. Search contact by name
3. Search contact by mobile
4. Display all contacts
5. Update a contact by ID
6. Delete a contact by ID
7. Exit the program

Select the desired option by entering the corresponding number, and follow the prompts to interact with the telephone diary system.
<div>

![main-menu-telephone-diary](https://github.com/user-attachments/assets/76a2ebb7-204c-4a9f-ba41-b363a1f29e16)
</br>Figure 1: Main Menu of Telephone Diary using C++

![adding-new-contact](https://github.com/user-attachments/assets/5e81d9c0-f2eb-487c-aeaf-4a664e9f3b15)
</br>Figure 2: Adding New Contact to Telephone Diary

![show-contact](https://github.com/user-attachments/assets/73e5c619-b390-4b79-b784-a1cdac60c52d)
</br>Figure 3: Show Saved Contact

![update-contact](https://github.com/user-attachments/assets/473bb877-271e-40e0-b024-7375f41a9375)
</br>Figure 4: Update Saved Contact

![delete-contact](https://github.com/user-attachments/assets/c00dfb95-811f-4210-ae86-0a37ab87ae62)
</br>Figure 5: Delete Saved Contact
</div>
## Code Overview

The main components of the project are:
- **Class Person**: Represents a contact and stores attributes like ID, Name, Address, Phone, Mobile, and Email.
- **Main Program**: Contains the menu and controls for file operations, user inputs, and contact management.

```cpp
class Person {
private:
    int ID;
    char Name[20], Address[50], Phone[10], Mobile[10], Email[30];
public:
    void ReadData();
    int GetID();
    void DisplayRecord();
    char* GetMobile();
    char* GetName();
};
```

### File Handling:
- **phone.dat**: The main file where all contacts are stored.
- **temp.txt**: A temporary file used during contact deletion.

## Future Improvements
- **Enhanced Search**: Add the ability to search by other fields like email or address.
- **Dynamic Memory Allocation**: Replace static arrays with dynamic memory for more flexible storage of contact details.
- **User Interface**: Implement a graphical user interface (GUI) for easier navigation and improved user experience.
- **Error Handling**: Improve error handling for invalid inputs and file operations.

## License
This project is open-source and free to use for educational purposes.

---
