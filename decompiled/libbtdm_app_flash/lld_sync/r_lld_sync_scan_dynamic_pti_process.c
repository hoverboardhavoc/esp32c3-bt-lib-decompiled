/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_scan_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_scan_dynamic_pti_process(int param_1,int param_2)

{
  byte bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  
  if (param_1 == 0) {
    return;
  }
  iVar3 = r_bt_rf_coex_sync_scan_dynamic_pti_en_get();
  if (iVar3 != 0) {
    if (param_2 == 0) {
      iVar3 = r_rwip_time_get();
      if ((*(char *)(param_1 + 0x65) == '\0') &&
         (((iVar3 - *(int *)(param_1 + 0x6c) & 0xfffffffU) < 0x8000001 ||
          ((*(int *)(param_1 + 0x6c) - iVar3 & 0xfffffffU) == 0)))) {
        *(int *)(param_1 + 0x68) = iVar3;
        *(undefined1 *)(param_1 + 0x65) = 1;
      }
    }
    else if ((param_2 - 1U < 3) && (*(char *)(param_1 + 0x65) != '\0')) {
      iVar3 = r_rwip_time_get();
      iVar4 = *(int *)(_bt_rf_coex_cfg_p + 0x40);
      uVar6 = ((iVar3 - *(int *)(param_1 + 0x68) & 0xfffffffU) * (uint)*(byte *)(iVar4 + 7)) / 100;
      uVar5 = (uint)*(ushort *)(iVar4 + 8) << 1;
      if ((uVar6 < uVar5) || (uVar5 = (uint)*(ushort *)(iVar4 + 10) << 1, uVar5 < uVar6)) {
        uVar6 = uVar5;
      }
      *(uint *)(param_1 + 0x6c) = iVar3 + uVar6 & 0xfffffff;
      *(undefined1 *)(param_1 + 0x65) = 0;
    }
    pbVar7 = *(byte **)(_bt_rf_coex_cfg_p + 0x40);
    if (*(char *)(param_1 + 0x65) == '\0') {
      bVar1 = pbVar7[2];
      uVar6 = 0;
      uVar5 = 0;
      uVar9 = 0;
    }
    else {
      uVar9 = (uint)pbVar7[3];
      uVar5 = (uint)pbVar7[4];
      uVar6 = (uint)*pbVar7;
      bVar1 = pbVar7[1];
    }
    uVar8 = (uint)*(byte *)(param_1 + 0x55);
    if (0xb < uVar8) {
      r_assert_err(0,0x10000,0x299b);
    }
    if ((uVar6 & 0xf0) != 0) {
      r_assert_err(0,0x10000,0x299d);
    }
    puVar2 = (uint *)((uVar8 + 0x1800c4cb) * 4);
    *puVar2 = *puVar2 & 0xfffff0ff | uVar6 << 8;
    if (0xb < uVar8) {
      r_assert_err(0,0x10000,0x294a);
    }
    if ((bVar1 & 2) != 0) {
      r_assert_err(0,0x10000,0x294c);
    }
    *puVar2 = *puVar2 & 0xbfffffff | (uint)bVar1 << 0x1e;
    if (0xb < uVar8) {
      r_assert_err(0,0x10000,0x29bb);
    }
    if (0xf < uVar9) {
      r_assert_err(0,0x10000,0x29bd);
    }
    *puVar2 = *puVar2 & 0xfffffff0 | uVar9;
    if (0xb < uVar8) {
      r_assert_err(0,0x10000,0x295a);
    }
    if ((uVar5 & 6) != 0) {
      r_assert_err(0,0x10000,0x295c);
    }
    *puVar2 = *puVar2 & 0xdfffffff | uVar5 << 0x1d;
  }
  return;
}

