void LLdelete(struct node ** head, int pos)
{
    if ( *head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    if(pos < 1)
    {
        printf("Invalid position \n");
        return;
    }
    struct node * temp = * head;
    if( pos == 1)
    {
        *head = temp -> next;
        printf("Deleting at pos 1 and the data is %d", temp -> data);
        free(temp);
        return;
    }
    int k=1;
    while(temp != NULL && k<pos)
    {
        temp = temp -> next;
        k++;
    }
    if (temp == NULL)
    {
        printf("Position not present\n");
        free(temp);
        return;
    }
    struct node * del = temp -> next;
    temp -> next = del -> next;
    printf("Deleting node at position %d having the data %d", pos, del -> data);
}