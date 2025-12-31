/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_scan_start_eco(uint param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  
  iVar5 = r_lld_scan_start();
  if (iVar5 != 0) goto _L926;
  iVar6 = r_ble_ll_qa_config_get();
  uVar4 = (uint)*(ushort *)(iVar6 + 0x20);
  if (uVar4 == 0) {
    iVar6 = r_sdk_config_get_opts_ext();
    if (*(short *)(iVar6 + 0x14) != 0) {
      _DAT_60031124 = 0x10001;
      iVar6 = r_sdk_config_get_opts_ext();
      uVar4 = (uint)*(ushort *)(iVar6 + 0x14);
      goto _L951;
    }
  }
  else {
    _DAT_60031124 = 0x10001;
_L951:
    if ((uVar4 & 0xfffffe00) != 0) {
      r_assert_err(0,"lld_scan.c",0x29ed);
    }
    _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | uVar4;
  }
  if (_lld_scan_env != 0) {
    puVar11 = &scan_anchor_point;
    iVar6 = 0;
    while( true ) {
      iVar9 = *(int *)(_lld_scan_env + iVar6 * 4);
      if (iVar9 != 0) {
        bVar1 = *(byte *)(iVar9 + 0x38);
        iVar7 = r_emi_get_mem_addr_by_offset(0x400);
        iVar10 = (uint)bVar1 * 0x5a;
        uVar2 = *(ushort *)(iVar7 + iVar10);
        iVar7 = r_emi_get_mem_addr_by_offset(0x400);
        uVar8 = *(undefined4 *)(iVar9 + 4);
        *(ushort *)(iVar10 + iVar7) = uVar2 & 0xffdf;
        *puVar11 = uVar8;
        bVar1 = *(byte *)(iVar9 + 0x38);
        iVar7 = r_emi_get_mem_addr_by_offset(0x400);
        uVar3 = *(undefined2 *)((uint)bVar1 * 0x5a + 0x14 + iVar7);
        bVar1 = *(byte *)(iVar9 + 0x38);
        iVar7 = r_emi_get_mem_addr_by_offset(0x400);
        r_ble_log_internal_x2
                  (0x40010110,CONCAT22(*(undefined2 *)((uint)bVar1 * 0x5a + 0x2c + iVar7),uVar3),
                   *(undefined1 *)(iVar9 + 0x38));
      }
      puVar11 = puVar11 + 1;
      if (iVar6 == 1) break;
      iVar6 = 1;
    }
  }
_L926:
  r_lld_scan_start_hook_part_0_isra_0(iVar5,param_2);
  r_ble_log_internal_x3
            (0x40010111,_DAT_60031124,_DAT_60031364 & 0x1ff,
             iVar5 << 0x10 | (uint)*(byte *)(param_2 + 7) << 8 | param_1);
  return iVar5;
}

