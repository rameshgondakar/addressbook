#include "contact.h"

int main()
{
    AddressBook addressBook; 
   initialize(&addressBook);
    /*
    printf(" Name   phone   email \n");
    printf("---------------------->\n");

    for(int i=0; i<addressbook.contactCount; i++)
    {
        printf("%s ",addressbook.contacts[i].name);
        printf("%s ",addressbook.contacts[i].phone);
        printf("%s\n",addressbook.contacts[i].email);
    }
}*/
    int num;
    while (1) 
    {
        printf("1. List Contacts\n2. Create Contact\n3. Search Contact\n4. Edit Contact\n5. Delete Contact\n6. Initilize\n7. Save\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &num);
        printf("\n");  //newline character

        switch (num) 
        {
            case 1:
                listContacts(&addressBook);
                break;
            case 2:
                createContact(&addressBook);
                break;
            case 3:
                searchContact(&addressBook);
                break;
            case 4:
                editContact(&addressBook);
                break;
            case 5:
                deleteContact(&addressBook);
                break;
            case 6:
                initialize(&addressBook);
                printf("initilized\n");
                break;
            case 7:
                saveContact(&addressBook);
                printf("saved\n");
                break;
            case 8:
                printf("Exit program\n");
                return 0;
            default:
                printf("Invalid choice. try again.\n");
        }
    }

    return 0;
}
