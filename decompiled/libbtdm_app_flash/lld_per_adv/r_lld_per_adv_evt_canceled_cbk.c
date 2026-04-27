/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_evt_canceled_cbk(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == 0) {
    r_assert_err(0x10000,999);
    return;
  }
  r_ble_log_internal_x1
            (0x40440133,
             (uint)*(byte *)(param_1 + 0x52) |
             (uint)*(byte *)(param_1 + 0x53) << 8 | (uint)*(byte *)(param_1 + 0x16) << 0x10);
  if (*(char *)(param_1 + 0x53) != '\0') {
    r_assert_err(0,0x10000,0x3dd);
  }
  bVar1 = *(byte *)(param_1 + 0x52);
  *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
  iVar2 = *(int *)(&lld_per_adv_env + (uint)bVar1 * 4);
  *(uint *)(iVar2 + 4) = *(int *)(iVar2 + 4) + *(int *)(iVar2 + 0x40) & 0xfffffff;
  *(short *)(iVar2 + 0x4c) = *(short *)(iVar2 + 0x4c) + 1;
  iVar4 = r_lld_read_clock();
  while ((iVar4 - *(int *)(iVar2 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar2 + 4) = *(int *)(iVar2 + 4) + *(int *)(iVar2 + 0x40) & 0xfffffff;
    *(short *)(iVar2 + 0x4c) = *(short *)(iVar2 + 0x4c) + 1;
  }
  uVar3 = 0;
  do {
    iVar5 = r_sch_arb_insert(iVar2);
    if (iVar5 == 0) {
      iVar5 = 1;
      goto _L4;
    }
    uVar3 = uVar3 + 1 & 0xff;
    *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + DAT_0001301b;
    *(uint *)(iVar2 + 4) = *(int *)(iVar2 + 4) + *(int *)(iVar2 + 0x40) & 0xfffffff;
    *(short *)(iVar2 + 0x4c) = *(short *)(iVar2 + 0x4c) + 1;
  } while (uVar3 != 0xf);
  iVar5 = 0;
_L4:
  r_ble_log_internal_x1
            (0x4044012c,
             (uint)*(byte *)(iVar2 + 0x53) << 0x18 | (uint)bVar1 | iVar5 << 8 | uVar3 << 0x10);
  if (iVar5 == 0) {
    r_assert_param(*(undefined4 *)(iVar2 + 4),iVar4,0x10000,0x13f);
    return;
  }
  *(undefined1 *)(iVar2 + 0x53) = 0;
  return;
}

