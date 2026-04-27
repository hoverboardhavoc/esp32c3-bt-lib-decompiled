/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 1;
  if (param_3 != 0) {
    uVar2 = param_3;
  }
  if (0x3fffff < uVar2) {
    uVar2 = 0x3fffff;
  }
  bVar1 = false;
  if ((_r_ke_msg_send_basic != 0) && (*(ushort *)(_r_ke_msg_send_basic + 4) == param_1)) {
    bVar1 = *(ushort *)(_r_ke_msg_send_basic + 6) == param_2;
  }
  iVar3 = r_ke_queue_extract(&ke_env,r_cmp_timer_id,param_1 << 0x10 | param_2);
  if (iVar3 == 0) {
    iVar3 = r_ke_malloc(0xc,2);
    if (iVar3 == 0) {
      r_assert_err("ke_timer.c",0xfa);
    }
    *(short *)(iVar3 + 4) = (short)param_1;
    *(short *)(iVar3 + 6) = (short)param_2;
  }
  iVar4 = r_ke_time();
  *(uint *)(iVar3 + 8) = iVar4 + uVar2 & 0x7fffff;
  r_ke_queue_insert(&ke_env,iVar3,0x10000);
  r_ble_log_internal_x3(0x208a023c,uVar2,*(undefined4 *)(iVar3 + 8),param_2 << 0x10 | param_1);
  if ((bVar1) || (iVar3 == _r_ke_msg_send_basic)) {
    r_rwip_timer_10ms_set(*(undefined4 *)(_r_ke_msg_send_basic + 8));
  }
  iVar3 = r_ke_time_past(iVar4 + uVar2);
  if (iVar3 != 0) {
    r_ke_event_set(4);
    return;
  }
  return;
}

