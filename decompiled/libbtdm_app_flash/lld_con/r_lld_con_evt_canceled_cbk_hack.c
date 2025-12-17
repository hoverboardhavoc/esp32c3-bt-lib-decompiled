/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_canceled_cbk_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_evt_canceled_cbk_hack(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (param_1 != 0) {
    uVar4 = r_lld_read_clock();
    bVar1 = *(byte *)(param_1 + 0x8f);
    uVar3 = (uint)*(byte *)(param_1 + 0x8e);
    r_ble_log_internal_x1
              (0x40430089,(uint)*(byte *)(param_1 + 0x16) << 0x10 | (uint)bVar1 << 8 | uVar3);
    if ((*(byte *)(param_1 + 0x8f) & 0xfd) != 0) {
      r_assert_param(uVar3,"lld_con.c",0xbed);
    }
    *(uint *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + *(int *)(param_1 + 100) & 0xfffffff;
    cVar2 = rwip_priority;
    *(short *)(param_1 + 0x7e) = *(short *)(param_1 + 0x7e) + 1;
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar2;
    r_lld_con_sched_hack(*(undefined1 *)(param_1 + 0x8e),uVar4,0);
    if ((*(int *)(&lld_con_env + uVar3 * 4) != 0) && (bVar1 == 2)) {
      *(byte *)(param_1 + 0x8f) = bVar1;
    }
    return;
  }
  r_assert_err("lld_con.c",0xc01);
  return;
}

