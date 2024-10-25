/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  if (param_1 == 0) {
    return;
  }
  iVar4 = r_bt_rf_coex_sync_scan_dynamic_pti_en_get();
  if (iVar4 != 0) {
    if (param_2 == 0) {
      iVar4 = r_rwip_time_get();
      if ((*(char *)(param_1 + 0x65) == '\0') &&
         (((iVar4 - *(int *)(param_1 + 0x6c) & 0xfffffffU) < 0x8000001 ||
          ((*(int *)(param_1 + 0x6c) - iVar4 & 0xfffffffU) == 0)))) {
        *(int *)(param_1 + 0x68) = iVar4;
        *(undefined1 *)(param_1 + 0x65) = 1;
      }
    }
    else if (((-1 < param_2) && (param_2 < 4)) && (*(char *)(param_1 + 0x65) != '\0')) {
      iVar4 = r_rwip_time_get();
      iVar5 = *(int *)(_bt_rf_coex_cfg_p + 0x40);
      uVar9 = ((iVar4 - *(int *)(param_1 + 0x68) & 0xfffffffU) * (uint)*(byte *)(iVar5 + 7)) / 100;
      uVar3 = (uint)*(ushort *)(iVar5 + 8) << 1;
      if ((uVar9 < uVar3) || (uVar3 = (uint)*(ushort *)(iVar5 + 10) << 1, uVar3 < uVar9)) {
        uVar9 = uVar3;
      }
      *(uint *)(param_1 + 0x6c) = uVar9 + iVar4 & 0xfffffff;
      *(undefined1 *)(param_1 + 0x65) = 0;
    }
    pbVar6 = *(byte **)(_bt_rf_coex_cfg_p + 0x40);
    if (*(char *)(param_1 + 0x65) == '\0') {
      bVar1 = pbVar6[2];
      uVar9 = 0;
      uVar3 = 0;
      uVar8 = 0;
    }
    else {
      uVar8 = (uint)pbVar6[3];
      uVar3 = (uint)pbVar6[4];
      uVar9 = (uint)*pbVar6;
      bVar1 = pbVar6[1];
    }
    uVar7 = (uint)*(byte *)(param_1 + 0x55);
    if (0xb < uVar7) {
      r_assert_err(0,"lld_sync.c",0x299b);
    }
    if ((uVar9 << 8 & 0xf000) != 0) {
      r_assert_err(0,"lld_sync.c",0x299d);
    }
    puVar2 = (uint *)((uVar7 + 0x1800c4cb) * 4);
    *puVar2 = *puVar2 & 0xfffff0ff | uVar9 << 8;
    if (0xb < uVar7) {
      r_assert_err(0,"lld_sync.c",0x294a);
    }
    if ((int)((uint)bVar1 << 0x1e) < 0) {
      r_assert_err(0,"lld_sync.c",0x294c);
    }
    *puVar2 = *puVar2 & 0xbfffffff | (uint)bVar1 << 0x1e;
    if (0xb < uVar7) {
      r_assert_err(0,"lld_sync.c",0x29bb);
    }
    if ((uVar8 & 0xfffffff0) != 0) {
      r_assert_err(0,"lld_sync.c",0x29bd);
    }
    *puVar2 = *puVar2 & 0xfffffff0 | uVar8;
    if (0xb < uVar7) {
      r_assert_err(0,"lld_sync.c",0x295a);
    }
    if ((uVar3 << 0x1d & 0xc0000000) != 0) {
      r_assert_err(0,"lld_sync.c",0x295c);
    }
    *puVar2 = *puVar2 & 0xdfffffff | uVar3 << 0x1d;
  }
  return;
}

