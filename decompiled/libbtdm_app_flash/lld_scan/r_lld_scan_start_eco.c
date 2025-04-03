/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte r_lld_scan_start_eco(uint param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  byte bStack_31;
  
  bStack_31 = 0xc;
  iVar5 = r_lld_scan_start();
  bStack_31 = (byte)iVar5;
  if (iVar5 != 0) goto _L952;
  iVar5 = r_ble_ll_qa_config_get();
  uVar3 = (uint)*(ushort *)(iVar5 + 0x20);
  if (uVar3 == 0) {
    iVar5 = r_sdk_config_get_opts_ext();
    if (*(short *)(iVar5 + 0x14) != 0) {
      _DAT_60031124 = 0x10001;
      iVar5 = r_sdk_config_get_opts_ext();
      uVar3 = (uint)*(ushort *)(iVar5 + 0x14);
      goto _L984;
    }
  }
  else {
    _DAT_60031124 = 0x10001;
_L984:
    if ((uVar3 & 0xfffffe00) != 0) {
      r_assert_err(0,"lld_scan.c",0x29ed);
    }
    _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | uVar3;
  }
  if ((bStack_31 == 0) && (_lld_scan_env != 0)) {
    iVar5 = 0;
    while( true ) {
      iVar8 = *(int *)(_lld_scan_env + iVar5 * 4);
      if (iVar8 != 0) {
        bVar1 = *(byte *)(iVar8 + 0x38);
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        iVar4 = (uint)bVar1 * 0x5a;
        uVar2 = *(ushort *)(iVar6 + iVar4);
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        uVar7 = *(undefined4 *)(iVar8 + 4);
        *(ushort *)(iVar6 + iVar4) = uVar2 & 0xffdf;
        (&_LANCHOR0)[iVar5] = uVar7;
      }
      if (iVar5 == 1) break;
      iVar5 = 1;
    }
  }
_L952:
  r_lld_scan_start_hook_part_1(&bStack_31,param_2);
  iVar5 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar5 + 0x28) & 8) != 0) {
    iVar5 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar5 + 0x2c) < 3) {
      r_ble_log_internal_x1
                (0x40010000,(uint)*(byte *)(param_2 + 7) << 8 | (uint)bStack_31 << 0x10 | param_1);
    }
  }
  iVar5 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar5 + 0x28) & 8) != 0) {
    iVar5 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar5 + 0x2c) < 3) {
      r_ble_log_internal_x2(0x40010005,_DAT_60031124,_DAT_60031364 & 0x1ff);
    }
  }
  return bStack_31;
}

