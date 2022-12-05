# Chronos Library
This library contains time management functions.
# Supported Hardware


# Functions Guide

Timelapse functions to measure the time between two events:
- `chronos_tl_init` : initializes the timelapse structure
- `chronos_tl_start` : to start the timelapse count
- `chronos_tl_stop` : to stop the timelapse count

Timeout functions to count time up to a timeout value:
- `chronos_tout_start` : starts counting ticks and sets the timeout.
- `chronos_tout_is_expired` : checks whether the timeout is expired or not (i.e. the number of ticks at this time is greater than the timeout or not)
- `chronos_tout_refresh` : restarts the count
- `chronos_tout_set_timeout`: sets the timeout

# How to use
- Include `lib-chronos.h` in your main
- Create an instance of  `timelapse_t`
- If you need to measure a certain period of time:
  - Use `chronos_tl_init` to initialize the structure for the timelapse
  - Use `chronos_tl_start` to start counting time and `chronos_tl_stop` to stop the count.
  - The `timelapse_t` structure (here timelapse_t `instance`) now contains the start tick (`instance.start_tick`), the end tick (`instance.end_tick`) and the time in ms between the two (`instance.diff_ms`)
  If you need to count time uo to a timeout value:
  - Use `chronos_tout_start` to set a timeout value and start counting.
  - Use `chronos_tout_is_expired` to check wether the count has surpassed the timeout value or not.
  - Use `chronos_tout_refresh` to restart the count.
  - Use `chronos_tout_set_timeout` to set a timeout without starting the count.
  - The `timelapse_t` structure (here timelapse_t `instance`) now contains the start tick (`instance.start_tick`), the end tick (`instance.end_tick`) and the timeout value (`instance.timeout`)
