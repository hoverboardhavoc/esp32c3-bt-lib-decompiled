/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ke.o -> r_ke_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_init(void)

{
  _r_ke_task_init = 0;
  _r_ke_timer_init = 0;
  _ke_env = 0;
  _r_ke_event_init = 0;
  r_ke_event_init();
  _r_ke_task_init = 0;
  _r_ke_timer_init = 0;
  _ke_env = 0;
  _r_ke_event_init = 0;
  _r_co_list_pop_front = 0;
  _r_ke_free = 0;
  r_ke_task_init();
  r_ke_timer_init();
  return;
}

