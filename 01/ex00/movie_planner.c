#include "movie_planner.h"

struct Preferences *get_user_preferences(void);
struct MovieList *find_movies(struct Preferences *prefs);
struct Plan *build_plan(struct MovieList *list);


struct Plan *create_movie_night_plan(void)
{
    struct Plan *plan;
    struct Preferences *p = get_user_preferences();
    if (!p)
        return (NULL);
    
    struct MovieList *m = find_movies(p);
    if (!m)
    {
        free(p);
        return (NULL);
    }
    plan = build_plan(m);
    if (!plan)
    {
        free(m);
        free(p);
        return (NULL);
    }
    return (plan);
}