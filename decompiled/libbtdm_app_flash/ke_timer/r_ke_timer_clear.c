/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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

