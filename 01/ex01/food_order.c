#include "food_order.h"

int     check_restaurant_status(struct OrderRequest *request);
struct OrderConfirmation *create_standard_confirmation(void);
struct OrderConfirmation *create_preorder_confirmation(void);