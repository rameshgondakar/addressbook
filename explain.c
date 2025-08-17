/*
main.c file:
program include header contact.h file
initilize the adressBook
run the loop
createing the menu then display the menu contain the List of contact, create contact, search contact, edit contact, delete contact,
initilize contact, save contact,exit. 
Display Menu
Display the main menu to the user:
1.List Contacts
2.Create Contact
3.Search Contact
4.Edit Contact
5.Delete Contact
6.Initilize
7.Save
8.Exit



Contact.h file
The file includes the standard input/output library and strings

The Contact structure holds the information for a single contact. It has three fields:
    1.name: A string (array of characters) to store the contact's name (up to 50 characters).
    2.phone: A string to store the contact's phone number (up to 20 characters).
    3.email: A string to store the contact's email address (up to 50 characters).

The AddressBook structure is used to store the entire collection of contacts:
    contacts[100]: An array of Contact structures, allowing up to 100 contacts to be stored in the address book.
    contactCount: An integer that keeps track of how many contacts are currently stored in the address book.

Function Prototypes are:
listContacts, createContact, searchContact, editContact, deleteContact, initialize,  saveContact.

contact.c file:
program include header contact.h file
Perform Operations Based on User Input:
    1.List Contacts:
    For each contact (from the 0th to the last):
    Print contact details (name, phone, email).
    Return to the menu.

    2.Create Contact
    Check if the number of contacts is less than the maximum limit (100).
    If yes, proceed to add a new contact.
    If no, display an error message "Address book is full. Cannot add more contacts".
    Input contact details (name, phone number, email).
    Validate Input:
        Name: Ensure the name does contain alpha numeric characters.
        Phone: Ensure the phone number contains at least 10 digits.
        Email: Ensure the email contains @ and ends with .com.
    Add the new contact to the contact list.
    Increment the contact count.
    Display "New contact added successfully".
    Return to the menu.

    3.Search Contact
    Input the search term (name to search).
    For each contact:
    If the contact's name contains the search term , print the contact details.
    If no contact is found, display "Contact not found".
    Return to the menu.

    4.Edit Contact
    Ask the user to enter the contact number to edit.
    If the input is invalid (contact number out of range), display an error message.
    Display the contact details of the selected contact.
    Input new details for the contact (name, phone number, email). If any field is left blank, skip editing that field.
    Validate the input:
        Ensure new phone numbers are valid (at least 10 digits) and emails are well-formed.
        Update the contact details with the new information.
    Display "Contact updated successfully".
    Return to the menu.

    5.Delete Contact
    sk the user to enter the contact number (1-based index) to delete.
    If the input is invalid (contact number out of range), display an error message.
    Delete the contact at the specified index by shifting the following contacts down in the list.
    Decrement the contact count.
    Display "Contact deleted successfully".
    Return to the menu.

    6.Initilize
    Open the contact.txt file for reading.
    File initialize in the address book with contact saved file.
    Scan each line of the file. And until it makes maximum contacts
    Return to the menu.
    
    7.Save
    Open the contact.txt file for writing.
    Write all contact details back to the file in the format name, phone, email.
    Close the file.
    Display "Contacts saved successfully".
    Return to the menu.

    8.Exit
    Display "Exit program".
    Terminate the program.


contact.txt file:
in this file we have to store the contact details int the text format in the format of , and \n.
*/