/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> ke_timer.o -> r_ke_timer_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_timer_clear(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = _r_ke_msg_send_basic;
  if (_r_ke_msg_send_basic == 0) {
    return;
  }
  if ((*(ushort *)(_r_ke_msg_send_basic + 4) == param_1) &&
     (*(ushort *)(_r_ke_msg_send_basic + 6) == param_2)) {
    r_co_list_pop_front(&ke_env);
    iVar2 = _r_ke_msg_send_basic;
    uVar1 = 0xffffffff;
    if (_r_ke_msg_send_basic != 0) {
      uVar1 = *(undefined4 *)(_r_ke_msg_send_basic + 8);
    }
    r_rwip_timer_10ms_set(uVar1);
    if ((iVar2 != 0) && (iVar2 = r_ke_time_past(*(undefined4 *)(iVar2 + 8)), iVar2 != 0)) {
      r_ke_event_set(4);
    }
  }
  else {
    iVar3 = r_ke_queue_extract(&ke_env,r_cmp_timer_id,param_1 << 0x10 | param_2);
    if (iVar3 == 0) {
      return;
    }
  }
  r_ke_free(iVar3);
  return;
}

