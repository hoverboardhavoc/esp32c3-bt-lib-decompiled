/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_evt_canceled_cbk(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == 0) {
    r_assert_err(0x10000,0x3cc);
    return;
  }
  iVar6 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar6 + 0x28) & 0x40) != 0) &&
     (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x4048000a,*(undefined2 *)(param_1 + 0x52));
  }
  if (*(char *)(param_1 + 0x53) != '\0') {
    r_assert_err(0,0x10000,0x3c2);
  }
  bVar1 = *(byte *)(param_1 + 0x52);
  *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
  iVar6 = *(int *)(&lld_per_adv_env + (uint)bVar1 * 4);
  *(uint *)(iVar6 + 4) = *(int *)(iVar6 + 4) + *(int *)(iVar6 + 0x40) & 0xfffffff;
  *(short *)(iVar6 + 0x4c) = *(short *)(iVar6 + 0x4c) + 1;
  iVar3 = r_lld_read_clock();
  while ((iVar3 - *(int *)(iVar6 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar6 + 4) = *(int *)(iVar6 + 4) + *(int *)(iVar6 + 0x40) & 0xfffffff;
    *(short *)(iVar6 + 0x4c) = *(short *)(iVar6 + 0x4c) + 1;
  }
  uVar2 = 0;
  do {
    iVar4 = r_sch_arb_insert(iVar6);
    if (iVar4 == 0) {
      iVar4 = 1;
      goto _L4;
    }
    uVar2 = uVar2 + 1 & 0xff;
    *(char *)(iVar6 + 0x16) = *(char *)(iVar6 + 0x16) + DAT_0001301b;
    *(uint *)(iVar6 + 4) = *(int *)(iVar6 + 4) + *(int *)(iVar6 + 0x40) & 0xfffffff;
    *(short *)(iVar6 + 0x4c) = *(short *)(iVar6 + 0x4c) + 1;
  } while (uVar2 != 0xf);
  iVar4 = 0;
_L4:
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 0x40) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x4048000b,
               iVar4 << 8 | uVar2 << 0x10 | (uint)*(byte *)(iVar6 + 0x53) << 0x18 | (uint)bVar1);
  }
  if (iVar4 == 0) {
    r_assert_param(*(undefined4 *)(iVar6 + 4),iVar3,0x10000,0x13f);
    return;
  }
  *(undefined1 *)(iVar6 + 0x53) = 0;
  return;
}

