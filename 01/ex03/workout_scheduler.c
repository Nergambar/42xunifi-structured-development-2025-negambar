#include "workout_scheduler.h"

void free_user_data(struct UserData *data);
void free_workout_plan(struct WorkoutPlan *plan);


struct WorkoutPlan *create_workout_schedule(char *username)
{
    struct UserData *user = get_user_data(username);
    if (!user)
        return(NULL);
    struct WorkoutPlan *plan = build_base_plan(user);
    if (!plan)
    {
        free_user_data(user);
        return (NULL);
    }
    free_workout_plan(plan);
    struct WorkoutPlan *refined =refine_plan(plan, user);
    if (!refined)
    {
        free_user_data(user);
        free_workout_plan(plan);
        return (NULL);
    }
    for (int day = 0; day < 6; day++)
    {
        assign_daily_exercises(plan, day);
        assign_daily_tips(plan, day);
    }
    return (refined);
}