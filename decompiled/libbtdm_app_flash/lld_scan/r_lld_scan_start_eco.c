/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_lld_scan_start_eco(undefined4 param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char acStack_31 [5];
  
  acStack_31[0] = '\f';
  iVar4 = r_lld_scan_start();
  acStack_31[0] = (char)iVar4;
  if (iVar4 == 0) {
    iVar4 = r_ble_ll_qa_config_get();
    if (*(char *)(iVar4 + 1) == '\0') {
      iVar4 = r_sdk_config_get_opts_ext();
      if (*(short *)(iVar4 + 0x14) != 0) {
        _DAT_60031124 = 0x10001;
        iVar4 = r_sdk_config_get_opts_ext();
        uVar2 = *(ushort *)(iVar4 + 0x14);
        if ((uVar2 & 0xfe00) != 0) {
          r_assert_err(0,"lld_scan.c",0x29ed);
        }
        _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | (uint)uVar2;
      }
    }
    else {
      _DAT_60031124 = 0x10001;
      _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | 1;
    }
    if ((acStack_31[0] == '\0') && (_lld_scan_env != 0)) {
      iVar4 = 0;
      while( true ) {
        iVar7 = *(int *)(_lld_scan_env + iVar4 * 4);
        if (iVar7 != 0) {
          bVar1 = *(byte *)(iVar7 + 0x38);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          iVar3 = (uint)bVar1 * 0x5a;
          uVar2 = *(ushort *)(iVar5 + iVar3);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          uVar6 = *(undefined4 *)(iVar7 + 4);
          *(ushort *)(iVar5 + iVar3) = uVar2 & 0xffdf;
          (&_LANCHOR0)[iVar4] = uVar6;
        }
        if (iVar4 == 1) break;
        iVar4 = 1;
      }
    }
  }
  r_lld_scan_start_hook_part_1(acStack_31,param_1);
  return acStack_31[0];
}

