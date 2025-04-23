/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  
  iVar6 = r_lld_scan_start();
  if (iVar6 != 0) goto _L911;
  iVar7 = r_ble_ll_qa_config_get();
  uVar4 = (uint)*(ushort *)(iVar7 + 0x20);
  if (uVar4 == 0) {
    iVar7 = r_sdk_config_get_opts_ext();
    if (*(short *)(iVar7 + 0x14) != 0) {
      _DAT_60031124 = 0x10001;
      iVar7 = r_sdk_config_get_opts_ext();
      uVar4 = (uint)*(ushort *)(iVar7 + 0x14);
      goto _L937;
    }
  }
  else {
    _DAT_60031124 = 0x10001;
_L937:
    if (0x1ff < uVar4) {
      r_assert_err(0,"lld_scan.c",0x29ed);
    }
    _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | uVar4;
  }
  if (_lld_scan_env != 0) {
    puVar10 = &scan_anchor_point;
    iVar7 = 0;
    do {
      iVar11 = *(int *)(_lld_scan_env + iVar7 * 4);
      if (iVar11 != 0) {
        bVar2 = *(byte *)(iVar11 + 0x38);
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        iVar5 = (uint)bVar2 * 0x5a;
        uVar3 = *(ushort *)(iVar8 + iVar5);
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        uVar9 = *(undefined4 *)(iVar11 + 4);
        *(ushort *)(iVar5 + iVar8) = uVar3 & 0xffdf;
        *puVar10 = uVar9;
      }
      puVar10 = puVar10 + 1;
      bVar1 = iVar7 != 1;
      iVar7 = 1;
    } while (bVar1);
  }
_L911:
  r_lld_scan_start_hook_part_0_isra_0(iVar6,param_2);
  iVar7 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar7 + 0x28) & 8) != 0) {
    iVar7 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar7 + 0x2c) < 3) {
      r_ble_log_internal_x1(0x40010000,(uint)*(byte *)(param_2 + 7) << 8 | param_1 | iVar6 << 0x10);
    }
  }
  iVar7 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar7 + 0x28) & 8) != 0) {
    iVar7 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar7 + 0x2c) < 3) {
      r_ble_log_internal_x2(0x40010005,_DAT_60031124,_DAT_60031364 & 0x1ff);
    }
  }
  return iVar6;
}

