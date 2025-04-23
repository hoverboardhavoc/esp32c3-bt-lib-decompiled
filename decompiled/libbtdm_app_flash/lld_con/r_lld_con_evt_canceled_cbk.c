/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_evt_canceled_cbk(int param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_1 != 0) {
    uVar4 = r_lld_read_clock();
    bVar1 = *(byte *)(param_1 + 0x8e);
    cVar2 = *(char *)(param_1 + 0x8f);
    iVar5 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar5 + 0x28) & 0x20) != 0) &&
       (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x4043000c,
                 (uint)*(byte *)(param_1 + 0x8e) |
                 (uint)*(byte *)(param_1 + 0x16) << 0x10 | (uint)*(byte *)(param_1 + 0x8f) << 8);
    }
    if ((*(byte *)(param_1 + 0x8f) & 0xfd) != 0) {
      r_assert_param((uint)bVar1,"lld_con.c",0xbb0);
    }
    *(uint *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + *(int *)(param_1 + 100) & 0xfffffff;
    cVar3 = rwip_priority;
    *(short *)(param_1 + 0x7e) = *(short *)(param_1 + 0x7e) + 1;
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar3;
    r_lld_con_sched(*(undefined1 *)(param_1 + 0x8e),uVar4,0);
    if ((*(int *)(&lld_con_env + (uint)bVar1 * 4) != 0) && (cVar2 == '\x02')) {
      *(undefined1 *)(param_1 + 0x8f) = 2;
    }
    return;
  }
  r_assert_err("lld_con.c",0xbc4);
  return;
}

