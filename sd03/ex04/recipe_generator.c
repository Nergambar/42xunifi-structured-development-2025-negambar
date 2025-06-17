#include "recipe_generator.h"
#include <stdlib.h>

// Generate a new recipe candidate based on ingredients & taste. Returns a new Recipe* or NULL on failure.
struct Recipe *create_recipe(struct Ingredients *ingredients, struct TasteProfile *taste);
// Ask user approval for the given recipe. Returns 1 if approved, 0 otherwise.
int get_user_approval(struct Recipe *recipe);
// Free functions for cleanup:
void free_ingredients(struct Ingredients *ing);
void free_taste_profile(struct TasteProfile *tp);
void free_recipe(struct Recipe *recipe);


struct Recipe *create_custom_recipe(void)
{
    struct Ingredients *ingred = get_current_ingredients();
    if (!ingred)
        return (NULL);
    struct TasteProfile *profile = get_user_taste_profile();
    if (!profile)
        return(free_ingredients(ingred), NULL);
    struct Recipe *recipe = create_recipe(ingred, profile);
    if (!recipe)
        return (free_ingredients(ingred), free_taste_profile(profile), NULL);
    int app = get_user_approval(recipe);
    if (!app)
    {
        free_taste_profile(profile);
        free_ingredients(ingred);
        free_recipe(recipe);
        return (NULL);
    }
    else
        return (recipe);
}