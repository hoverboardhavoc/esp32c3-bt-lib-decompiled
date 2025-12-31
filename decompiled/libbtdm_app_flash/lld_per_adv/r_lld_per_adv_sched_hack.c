/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_sched_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_sched_hack(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(&lld_per_adv_env + param_1 * 4);
  *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + *(int *)(iVar1 + 0x40) & 0xfffffff;
  *(short *)(iVar1 + 0x4c) = *(short *)(iVar1 + 0x4c) + 1;
  iVar3 = r_lld_read_clock();
  while ((iVar3 - *(int *)(iVar1 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + *(int *)(iVar1 + 0x40) & 0xfffffff;
    *(short *)(iVar1 + 0x4c) = *(short *)(iVar1 + 0x4c) + 1;
  }
  uVar2 = 0;
  do {
    iVar4 = r_sch_arb_insert(iVar1);
    if (iVar4 == 0) {
      iVar4 = 1;
      goto _L4;
    }
    uVar2 = uVar2 + 1 & 0xff;
    *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + DAT_0001301b;
    *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + *(int *)(iVar1 + 0x40) & 0xfffffff;
    *(short *)(iVar1 + 0x4c) = *(short *)(iVar1 + 0x4c) + 1;
  } while (uVar2 != 0xf);
  iVar4 = 0;
_L4:
  r_ble_log_internal_x1
            (0x40440103,(uint)*(byte *)(iVar1 + 0x53) << 0x18 | param_1 | iVar4 << 8 | uVar2 << 0x10
            );
  if (iVar4 != 0) {
    *(undefined1 *)(iVar1 + 0x53) = 0;
    return;
  }
  r_assert_param(*(undefined4 *)(iVar1 + 4),iVar3,0x10000,0x13f);
  return;
}

