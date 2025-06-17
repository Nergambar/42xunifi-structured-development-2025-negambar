#include "task_scheduler.h"

// Select the best task to assign next based on the profile. Returns a task ID or -1 on failure.
int select_best_task(struct TaskProfile *profile);
// Create a ScheduleResult structure for the specified number of cores. Returns NULL on failure.
struct ScheduleResult *create_schedule_result(int core_count);
// Update the result schedule with a task assignment.
void update_schedule_entry(struct ScheduleResult *result, int core_id, int task_id);
// Free functions for cleanup
void free_task_profile(struct TaskProfile *profile);
void free_priority_map(struct PriorityMap *priorities);

struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
    struct TaskProfile *profile = profile_tasks(tasks);
    if (!profile)
        return (NULL);
    struct PriorityMap *map = compute_priorities_mock(profile);
    if (!map)
    {
        free_task_profile(profile);
        return (NULL);
    }
    int cores = get_available_core_count();
    int best = select_best_task(profile);
    if (cores == -1)
    {
        free_task_profile(profile);
        free_priority_map(map);
        return (NULL);
    }
    struct ScheduleResult *result = create_schedule_result(cores);
    if(!result)
    {
        free_task_profile(profile);
        free_priority_map(map);
        return (NULL);
    }
    update_schedule_entry(result, cores, best);
    return (result);
}