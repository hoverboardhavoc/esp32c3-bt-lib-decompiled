/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> ke_timer.o -> r_ke_timer_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_timer_set(uint param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0x3fffff;
  if ((param_3 < 0x400000) && (uVar5 = param_3, param_3 == 0)) {
    uVar5 = 1;
  }
  bVar1 = false;
  if ((_r_ke_msg_send_basic != 0) && (*(ushort *)(_r_ke_msg_send_basic + 4) == param_1)) {
    bVar1 = *(ushort *)(_r_ke_msg_send_basic + 6) == param_2;
  }
  iVar2 = r_ke_queue_extract(&ke_env,r_cmp_timer_id,param_1 << 0x10 | param_2);
  if (iVar2 == 0) {
    iVar2 = r_ke_malloc(0xc,2);
    if (iVar2 == 0) {
      r_assert_err("ke_timer.c",0xfa);
    }
    *(short *)(iVar2 + 4) = (short)param_1;
    *(short *)(iVar2 + 6) = (short)param_2;
  }
  iVar3 = r_ke_time();
  *(uint *)(iVar2 + 8) = iVar3 + uVar5 & 0x7fffff;
  r_ke_queue_insert(&ke_env,iVar2,0x10000);
  iVar4 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar4 + 0x28) & 2) != 0) {
    iVar4 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar4 + 0x2c) < 3) {
      r_ble_log_internal_x3(0x4085000f,param_2 << 0x10 | param_1,uVar5,*(undefined4 *)(iVar2 + 8));
    }
  }
  if ((bVar1) || (iVar2 == _r_ke_msg_send_basic)) {
    r_rwip_timer_10ms_set(*(undefined4 *)(_r_ke_msg_send_basic + 8));
  }
  iVar2 = r_ke_time_past(iVar3 + uVar5);
  if (iVar2 != 0) {
    r_ke_event_set(4);
    return;
  }
  return;
}

