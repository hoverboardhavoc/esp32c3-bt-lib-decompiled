/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  iVar2 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar2 + 0x28) & 2) != 0) &&
     (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40850010,param_2 << 0x10 | param_1);
  }
  r_ke_free(iVar3);
  return;
}

