#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
for (int i = 0; i < addressBook->contactCount; i++) 
    {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", addressBook->contacts[i].name);
        printf("Phone: %s\n", addressBook->contacts[i].phone);
        printf("Email: %s\n", addressBook->contacts[i].email);
        printf("\n");
    }
}
void createContact(AddressBook *addressBook) 
{
    if (addressBook->contactCount >= MAX_CONTACTS) 
    {
        printf("Address book is full Cannot add more contacts\n");
        return;
    }

    Contact newContact;
    //Get name
    printf("Enter name: ");
    int result = scanf(" %[^\n]", newContact.name);
    if (result != 1) 
    {
        printf("Error reading name.\n");
        return;
    }

    int isDigit(char c) 
    {
    return c >= '0' && c <= '9';      //  character is between '0' and '9'
    }
    //valuation without numbers
    for (int i = 0; newContact.name[i] != '\0'; i++)
    {   
        // Check the character is between '0' and '9'
        if (newContact.name[i] >= '0' && newContact.name[i] <= '9') 
        {
            printf("Name must not contain numbers\n");
            return;
        }
    }
    //get phone number
    printf("Enter phone number: ");
    int result2 = scanf(" %[^\n]", newContact.phone);
    if (result2 != 1)
    {
        printf("Error reading phone number\n");
        return;
    }
    //valuate phone number
    int digitCount = 0;
    for (int i = 0; newContact.phone[i] != '\0'; i++) 
    {
        // Check if the character is a number
        if (newContact.phone[i] >= '0' && newContact.phone[i] <= '9')
        {
            digitCount++;
        }
    }
    if (digitCount < 10)
    {
        printf("Phone number must be at least 10 digits\n");
        return;
    }
    //Get email
    printf("Enter email: ");
    int result3 = scanf(" %[^\n]", newContact.email);
    if (result3 != 1)
    {
        printf("Error reading email.\n");
        return;
    }
    //valuvate email conatin @ and end with .com
    if (strstr(newContact.email, "@") == NULL || strstr(newContact.email, ".com") == NULL)
    {
        printf("Email must contain '@' and end with '.com'.\n");
        return;
    }

    addressBook->contacts[addressBook->contactCount] = newContact;
    addressBook->contactCount++;
    printf("New contact add success\n");
}

void searchContact(AddressBook *addressBook) 
{
    char searchName[50];
    printf("Enter the name of the contact to search: ");
    scanf(" %[^\n]", searchName);

    int found = 0;
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        if (strstr(addressBook->contacts[i].name, searchName) != NULL) 
        {
            printf("Contact found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            printf("\n");
            found = 1;
        }
    }

    if (!found)
    {
        printf("Contact not found.\n");
    }
}

void editContact(AddressBook *addressBook) 
{
    int i;
    printf("Enter the contact number to edit (1-%d): ", addressBook->contactCount);
    scanf("%d", &i);

    if (i < 1 || i > addressBook->contactCount) 
    {
        printf("Invalid contact number.\n");
        return;
    }

    i--;

    printf("Edit contact details for %s:\n", addressBook->contacts[i].name);

    // Editing the name
    char newName[50];
    printf("Enter new name (press enter to skip): ");
    if (scanf(" %[^\n]", newName) == 1 && strlen(newName) > 0) 
    {
        if (strcmp(newName, addressBook->contacts[i].name) != 0) {
            strcpy(addressBook->contacts[i].name, newName);
            printf("Name updated.\n");
        } else {
            printf("Name is the same,skip\n");
        }
    } else {
        printf("Name not changed,skip\n");
    }

    // Editing the phone number
    char newPhone[20];
    printf("Enter new phone number (press enter to skip): ");
    if (scanf(" %[^\n]", newPhone) == 1 && strlen(newPhone) > 0)
    {
        if (strcmp(newPhone, addressBook->contacts[i].phone) != 0) 
        {
            strcpy(addressBook->contacts[i].phone, newPhone);
            printf("Phone number updated\n");
        } 
        else 
        {
            printf("Phone number is the same,skip\n");
        }
    }
    else
    {
        printf("Phone number not changed,skip\n");
    }

    // Editing the email
    char newEmail[50];
    printf("Enter new email (press enter to skip): ");
    if (scanf(" %[^\n]", newEmail) == 1 && strlen(newEmail) > 0)
    {
        if (strcmp(newEmail, addressBook->contacts[i].email) != 0) 
        {
            strcpy(addressBook->contacts[i].email, newEmail);
            printf("Email updated.\n");
        } 
        else 
        {
            printf("Email is the same,skip\n");
        }
    } 
    else 
    {
        printf("Email not changed,skip\n");
    }

    printf("Contact update complete.\n");
}

void deleteContact(AddressBook *addressBook)
{

    int i;
    printf("Enter the contact number to delete (1-%d): ", addressBook->contactCount);
    scanf("%d", &i);

    if (i < 1 || i > addressBook->contactCount) 
    {
        printf("Invalid contact number.\n");
        return;
    }

    i--;

    for (int j = i; j < addressBook->contactCount - 1; j++) 
    {
        addressBook->contacts[j] = addressBook->contacts[j + 1];
    }

    addressBook->contactCount--;
    printf("Contact deleted success\n");

}
void initialize(AddressBook *addressBook)
{
    addressBook->contactCount=0;
    FILE *fp;
    fp= fopen("contact.txt","r");
    if(fp ==NULL)
    {
        printf("File does not found\n");
    }
    int i=0;
    while((fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email))==3)
    {
        i++;
        addressBook->contactCount++;
        if (addressBook->contactCount >= MAX_CONTACTS)
         {
            printf("Reached maximum contacts. No more contacts can be added\n");
            break;
         }
    }
    fclose(fp);
}
void saveContact(AddressBook *addressBook) 
{
    FILE *fp;
    fp= fopen("contact.txt", "w");
    if (fp == NULL) 
    {
        printf("file does not opening file for sav2\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        fprintf(fp, "%s, %s, %s\n", addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(fp);
}