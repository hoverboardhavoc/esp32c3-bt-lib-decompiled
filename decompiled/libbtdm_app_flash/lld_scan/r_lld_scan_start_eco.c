/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  
  iVar4 = r_lld_scan_start();
  if (iVar4 != 0) goto _L948;
  iVar5 = r_ble_ll_qa_config_get();
  uVar3 = (uint)*(ushort *)(iVar5 + 0x20);
  if (uVar3 == 0) {
    iVar5 = r_sdk_config_get_opts_ext();
    if (*(short *)(iVar5 + 0x14) != 0) {
      _DAT_60031124 = 0x10001;
      iVar5 = r_sdk_config_get_opts_ext();
      uVar3 = (uint)*(ushort *)(iVar5 + 0x14);
      goto _L979;
    }
  }
  else {
    _DAT_60031124 = 0x10001;
_L979:
    if ((uVar3 & 0xfffffe00) != 0) {
      r_assert_err(0,"lld_scan.c",0x29ed);
    }
    _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | uVar3;
  }
  if (_lld_scan_env != 0) {
    puVar9 = &scan_anchor_point;
    iVar5 = 0;
    while( true ) {
      iVar10 = *(int *)(_lld_scan_env + iVar5 * 4);
      if (iVar10 != 0) {
        bVar1 = *(byte *)(iVar10 + 0x38);
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        iVar8 = (uint)bVar1 * 0x5a;
        uVar2 = *(ushort *)(iVar6 + iVar8);
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        uVar7 = *(undefined4 *)(iVar10 + 4);
        *(ushort *)(iVar8 + iVar6) = uVar2 & 0xffdf;
        *puVar9 = uVar7;
      }
      puVar9 = puVar9 + 1;
      if (iVar5 == 1) break;
      iVar5 = 1;
    }
  }
_L948:
  r_lld_scan_start_hook_part_0_isra_0(iVar4,param_2);
  iVar5 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar5 + 0x28) & 8) != 0) {
    iVar5 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar5 + 0x2c) < 3) {
      r_ble_log_internal_x1(0x40010000,(uint)*(byte *)(param_2 + 7) << 8 | param_1 | iVar4 << 0x10);
    }
  }
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 8) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x40010005,_DAT_60031124,_DAT_60031364 & 0x1ff);
  }
  return iVar4;
}

