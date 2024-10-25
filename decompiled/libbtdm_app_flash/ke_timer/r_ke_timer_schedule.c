/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ke_timer.o -> r_ke_timer_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_timer_schedule(void)

{
  int iVar1;
  int iVar2;
  
  do {
    r_ke_event_clear(4);
    iVar2 = _r_ke_msg_send_basic;
    if (_r_ke_msg_send_basic == 0) {
      return;
    }
    iVar1 = r_ke_time_past(*(int *)(_r_ke_msg_send_basic + 8) + -1);
    if (iVar1 == 0) {
      r_rwip_timer_10ms_set(*(undefined4 *)(iVar2 + 8));
      iVar2 = r_ke_time_past(*(undefined4 *)(iVar2 + 8));
      if (iVar2 == 0) {
        return;
      }
      r_rwip_timer_10ms_set(0xffffffff);
    }
    iVar2 = r_co_list_pop_front(&ke_env);
    r_ke_msg_send_basic(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),0xff);
    r_ke_free(iVar2);
  } while( true );
}

