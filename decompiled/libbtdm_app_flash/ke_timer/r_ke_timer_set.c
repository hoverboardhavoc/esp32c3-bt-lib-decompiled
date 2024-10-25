/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  
  uVar2 = 0x3fffff;
  if ((param_3 < 0x400000) && (uVar2 = param_3, param_3 == 0)) {
    uVar2 = 1;
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
  *(uint *)(iVar3 + 8) = uVar2 + iVar4 & 0x7fffff;
  r_ke_queue_insert(&ke_env,iVar3,0x10000);
  if ((bVar1) || (iVar3 == _r_ke_msg_send_basic)) {
    r_rwip_timer_10ms_set(*(undefined4 *)(_r_ke_msg_send_basic + 8));
  }
  iVar3 = r_ke_time_past(uVar2 + iVar4);
  if (iVar3 != 0) {
    r_ke_event_set(4);
    return;
  }
  return;
}

