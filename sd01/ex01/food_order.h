#ifndef FOOD_ORDER_H
#define FOOD_ORDER_H

int     check_restaurant_status(struct OrderRequest *request);
struct OrderConfirmation *create_standard_confirmation(void);
struct OrderConfirmation *create_preorder_confirmation(void);
void send_confirmation_notification(struct OrderConfirmation *confirmation);

int process_food_order(struct OrderRequest *request)
{
    int open = check_restaurant_status(request);
    struct OrderConfirmation *order;
    if (!open)
    {
        order = create_preorder_confirmation();
        if (!order){
            free(order);
            return (0);}
    }
    else
    {
        order = create_standard_confirmation();
        if (!order){
            free(order);
            return (0);}
    }
    send_confirmation_notification(order);
    return (1);
}

#endif